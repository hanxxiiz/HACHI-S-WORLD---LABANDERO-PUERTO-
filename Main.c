#include "raylib.h"
#include "Menu.h"
#include <stdio.h>
#include "Player.h"
#include "Animation.h"
#include "Level.h"

typedef enum GameState {

    STATE_NAME_INPUT,

    STATE_CHARACTER_SELECT,

    STATE_MAIN_MENU,

    STATE_LEVEL_SELECT,

    STATE_GAME,

    STATE_EXIT

} GameState;

int main(void)

{


    const int screenWidth = 1920;
        const int screenHeight = 1080;
    
        InitWindow(0, 0, "Hachi's World");
        ToggleFullscreen();
        InitAudioDevice();
        SetExitKey(KEY_NULL);
        SetTargetFPS(60);

    GameState currentState = STATE_NAME_INPUT;

    Menu menu;

    MainMenu_Init(&menu);

    menu.showNameInput = true;

    Player player;
    Level* currentLevel = NULL;
    Enemies enemies;
    Animation animation;


    while (!WindowShouldClose() && currentState != STATE_EXIT)

    {

        BeginDrawing();

        ClearBackground(BLACK);

        switch (currentState)

        {

        case STATE_NAME_INPUT:

            MainMenu_ShowNameInput(&menu);

            if (menu.showCharacterSelection) {

                currentState = STATE_CHARACTER_SELECT;

                menu.showNameInput = false;

            }



            break;

        case STATE_CHARACTER_SELECT:


            MainMenu_SelectingACharacter(&menu);

            if (!menu.showCharacterSelection) {

                if (menu.start_Game) {


                    menu.start_Game = false;

                    currentState = STATE_MAIN_MENU;

                }

            }

            break;

        case STATE_MAIN_MENU:

            MainMenu_LandingPage(&menu);


            if (CheckCollisionPointRec(GetMousePosition(), menu.startButton_position) &&

                IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

                currentState = STATE_LEVEL_SELECT;

                menu.showLevelSelection = true;

            }


            if (menu.showKeyBindings) {

                MainMenu_ShowKeyBindings(&menu);

            }


            if (menu.exit_Game) {

                currentState = STATE_EXIT;

            }

            break;

        case STATE_LEVEL_SELECT:

            MainMenu_ShowLevelSelection(&menu);


            DrawText("Press B to go back to menu",

                screenWidth / 2 - MeasureText("Press B to go back to menu", 20) / 2,

                screenHeight - 50, 20, WHITE);

            if (IsKeyPressed(KEY_B)) {

                menu.showLevelSelection = false;

                currentState = STATE_MAIN_MENU;

            }


            if (menu.currentLevel >= 0 && !menu.showLevelSelection) {

                Player_Init(&player, PLAYER_HACHI);
                Enemies_Init(&enemies);
                currentLevel = Level_Create(menu.currentLevel + 1); 

                if (currentLevel == NULL) {
                    TraceLog(LOG_ERROR, "Failed to create level %d", menu.currentLevel + 1);
                    currentState = STATE_MAIN_MENU;
                }
                else {
                    currentState = STATE_GAME;
                }


            }

            break;

        case STATE_GAME:
                        if (currentLevel != NULL) {
                            if (!currentLevel->startPlay) {
                                Level_Init(currentLevel);
                                Player_SetPos1(&player);
                                Enemies_Reset(&enemies);
                                currentLevel->levelCompleted = false;
            
                                switch (menu.currentLevel) {
                                case 0:
                                    SetMusicVolume(currentLevel->levelOne_music, currentLevel->levelOne_volume);
                                    PlayMusicStream(currentLevel->levelOne_music);
                                    break;
                                case 1:
                                    SetMusicVolume(currentLevel->levelTwo_music, currentLevel->levelTwo_volume);
                                    PlayMusicStream(currentLevel->levelTwo_music);
                                    break;
                                case 2:
                                    SetMusicVolume(currentLevel->levelThree_music, currentLevel->levelThree_volume);
                                    PlayMusicStream(currentLevel->levelThree_music);
                                    break;
                                }
            
                                currentLevel->startPlay = true;
                            }
            
                            switch (menu.currentLevel) {
                            case 0: UpdateMusicStream(currentLevel->levelOne_music); break;
                            case 1: UpdateMusicStream(currentLevel->levelTwo_music); break;
                            case 2: UpdateMusicStream(currentLevel->levelThree_music); break;
                            }
            
                            player.camera.target = (Vector2){ player.animation.player_disp.x, 580};
            
                            BeginMode2D(player.camera);
                            ClearBackground(SKYBLUE);
            
                            Level_Draw(currentLevel, &player);
                            Player_DrawUI(&player);
            
                            if (!menu.pause_Game) {
                                Player_CheckInput(&player);
                                Player_ManageInput(&player);
                                Player_SetAudioVolume(&player);
            
                                if (menu.currentLevel == 0) {
                                    Enemies_ManageRadish(&enemies);
                                    Enemies_ManageCassava(&enemies);
                                    Level_CheckCollisions(currentLevel, &player, &enemies);
            
                                    if (player.death) {
                                        Level_ManageDeath(currentLevel, &player, &enemies);
                                        if (player.hp <= 0) {
                                            Player_SetPos1(&player);
                                            Enemies_Reset(&enemies);
                                            currentLevel->startPlay = false;

                                            currentState = STATE_LEVEL_SELECT;
                                        }
                                    }
                                }
                                else if (menu.currentLevel == 1) {
                                    Enemies_ManageRadish(&enemies);
                                    Enemies_ManageCassava(&enemies);
                                    Level_CheckCollisions(currentLevel, &player, &enemies);
            
                                    if (player.death) {
                                        Level_ManageDeath(currentLevel, &player, &enemies);
                                        if (player.hp <= 0) {
                                            Player_SetPos1(&player);
                                            Enemies_Reset(&enemies);
                                            currentLevel->startPlay = false;
                                            currentState = STATE_LEVEL_SELECT;
                                        }
                                    }
                                }
                            }
            
            
                            EndMode2D();
            
                            DrawText(TextFormat("Level: %d", menu.currentLevel + 1), 10, 10, 20, WHITE);
                            DrawText(TextFormat("Level Status: %s", currentLevel->startPlay ? "Playing" : "Starting"), 10, 30, 20, WHITE);
            
                            if (currentLevel->levelCompleted) {
                                PlaySound(currentLevel->levelcompleted_sound);
                                currentLevel->levelCompleted = false;
                                currentState = STATE_LEVEL_SELECT;
                            }
            
                            if (currentLevel->game_over) {
                                PlaySound(currentLevel->gameover_sound);
                                currentLevel->game_over = false;
                                currentState = STATE_LEVEL_SELECT;
                            }
                        }
                        else {
                            DrawText("ERROR: Level is NULL", screenWidth / 2 - 100, screenHeight / 2, 20, RED);
                        }
            
                        if (IsKeyPressed(KEY_ESCAPE)) {
                            if (currentLevel != NULL) {
                                switch (menu.currentLevel) {
                                case 0: StopMusicStream(currentLevel->levelOne_music); break;
                                case 1: StopMusicStream(currentLevel->levelTwo_music); break;
                                case 2: StopMusicStream(currentLevel->levelThree_music); break;
                                }
                                free(currentLevel);
                                currentLevel = NULL;
                            }
                            currentState = STATE_MAIN_MENU;
                        }
                        break;
            
            
                    default:
            
                        break;
            
                    }
            
                    EndDrawing();
            
                }
            
                MainMenu_Unload(&menu);
            
                CloseWindow();
            
                return 0;
            
            }
