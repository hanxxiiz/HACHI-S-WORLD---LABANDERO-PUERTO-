#include "Player.h"
#include "Animation.h"
#include "Level.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char levelOne_map[MAP_ROWS][MAP_COLS + 1] = {
    "                                                                                                                                   ",
    "                          o o o o o                                                                                                ",
    "                                                                                                                                   ",
    "                                                                                                                    oo             ",
    "                  oo                                                                                               2113            ",
    "                2111377777777777777777772113                                                                       4005            ",
    "                40005                   4005                                               oooo                 oo 4005            ",
    "                40005                   4005211113             oooooo      89a                                 21134005            ",
    "              oo40021113                4005400005             89999a                                          40054005            ",
    "             21111340005       o        4005400005                                                          oo 40054005            ",
    "             40000540005                4005400005   o                              211377777777772113     211340054005            ",
    "             40000540005      bcd       4005400005  89a               89a           4005          4005     400540054005            ",
    "             40000540005                4005400005       bcd    o                 oo4005          4005     400540054005            ",
    "11111111111111111111111113        8a   21111111113           8889a                2111113        21111111111111111111111111111111  ",
    "00000000000000000000000005 8a          40000000005                                4000005        400000000000000000000000000000000 ",
    "00000000000000000000000005             40000000005                                4000005        400000000000000000000000000000000 ",
    "00000000000000000000000005             40000000005                                4000005        400000000000000000000000000000000 "
};


char levelOne_background[MAP_ROWS][MAP_COLS + 1] = {
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   "
};


char levelTwo_map[MAP_ROWS][MAP_COLS + 1] = {
    "                                                                                                                                  ",
    "                                                                                                                                  ",
    "                                                                                                                                  ",
    "                                              oooo                                                                                ",
    "                                                                              o  o  o  o             o                 o          ",
    "                         o                   211113                         211111111111113       2111113                         ",
    "                                             400005                         400000000000005       4000005             bcd         ",
    "                 o                      oooo 400005 oooo     89a            400000000000005       4000005                         ",
    "                    o         o              400005                         400000000000005       4000005211113   89a     89a     ",
    "                                       211113400005211113               2113400000000000005       4000005400005                   ",
    "                                       400005400005400005               4005400000000000005       4000005400005                   ",
    "              89a  89a  89a  89a       400005400005400005               400540000000o0o0o05       40o0o05400005                   ",
    "                                       400005400005400005               4005400000000000005       4000005400005                   ",
    "111111111113                      21111111111111111111111            1111111111111111111111       1111111111111111                ",
    "000000000005                      40000000000000000000000            0000000000000000000000       0000000000000000                ",
    "000000000005666666666666666666666640000000000000000000000666666666666000000000000000000000066666660000000000000000                ",
    "000000000005                      40000000000000000000000            0000000000000000000000       0000000000000000                "
};

char levelTwo_background[MAP_ROWS][MAP_COLS + 1] = {
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   "
};

char levelThree_map[MAP_ROWS][MAP_COLS + 1] = {
    "                                                                                                                                   ",
    "                          o o o o o                                                                                                ",
    "                                                                                                                                   ",
    "                                                                                                                    oo             ",
    "                  oo                                                                                               2113            ",
    "                2111377777777777777777772113                                                                       4005            ",
    "                40005                   4005                                               oooo                 oo 4005            ",
    "                40005                   4005211113             oooooo      89a                                 21134005            ",
    "              oo40021113                4005400005             89999a                                          40054005            ",
    "             21111340005       o        4005400005                                                          oo 40054005            ",
    "             40000540005                4005400005   o                              211377777777772113     211340054005            ",
    "             40000540005      bcd       4005400005  89a               89a           4005          4005     400540054005            ",
    "             40000540005                4005400005       bcd    o                 oo4005          4005     400540054005            ",
    "11111111111111111111111113        8a   21111111113           8889a                2111113        21111111111111111111111111111111  ",
    "00000000000000000000000005 8a          40000000005                                4000005        400000000000000000000000000000000 ",
    "00000000000000000000000005             40000000005                                4000005        400000000000000000000000000000000 ",
    "00000000000000000000000005             40000000005                                4000005        400000000000000000000000000000000 "
};


char levelThree_background[MAP_ROWS][MAP_COLS + 1] = {
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                    00                                                                                                             ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   ",
    "                                                                                                                                   "
};

Level* Level_Create(int id) {
    Level* level = (Level*)malloc(sizeof(Level));
    if (!level) {
        printf("Failed to allocate memory for Levels\n");
        return NULL;
    }

    memset(level, 0, sizeof(Level));

    level->dead_sound = LoadSound("Resources/SoundEffects/dead.wav");
    level->explosion_sound = LoadSound("Resources/SoundEffects/explosion.wav");
    level->gameover_sound = LoadSound("Resources/SoundEffects/gameover.wav");
    level->hit_sound = LoadSound("Resources/SoundEffects/hit.wav");
    level->jump_sound = LoadSound("Resources/SoundEffects/jump.wav");
    level->levelcompleted_sound = LoadSound("Resources/SoundEffects/levelcompleted.wav");
    level->loot_sound = LoadSound("Resources/SoundEffects/loot.wav");
    level->unlock_sound = LoadSound("Resources/SoundEffects/unlock.wav");

    //level->loot = LoadTexture("Resources/");

    //Level One
    if (id == 1) {
        level->levelOne_music = LoadMusicStream("Resources/Music/LevelOne.mp3");
        level->levelOneBackground = LoadTexture("Resources/Levels/LevelOne/sky_background1.png");
        level->levelOneBridge = LoadTexture("Resources/Levels/LevelOne/bridge.png");
        level->levelOnePlatform_right = LoadTexture("Resources/Levels/LevelOne/right.png");
        level->levelOnePlatform_left = LoadTexture("Resources/Levels/LevelOne/left.png");
        level->levelOnePlatform_mid = LoadTexture("Resources/Levels/LevelOne/mid.png");
        level->levelOneGround_topright = LoadTexture("Resources/Levels/LevelOne/topright.png");
        level->levelOneGround_topleft = LoadTexture("Resources/Levels/LevelOne/topleft.png");
        level->levelOneGround_topmid = LoadTexture("Resources/Levels/LevelOne/topmid.png");
        level->levelOneGround_midright = LoadTexture("Resources/Levels/LevelOne/midright.png");
        level->levelOneGround_midleft = LoadTexture("Resources/Levels/LevelOne/midleft.png");
        level->levelOneGround_center = LoadTexture("Resources/Levels/LevelOne/center.png");
    }

    //Level Two
    else if (id == 2) {
        level->levelTwo_music = LoadMusicStream("Resources/Music/LevelTwo.mp3");
        level->levelTwoBackground = LoadTexture("Resources/Levels/LevelTwo/sky_background1.png");
        level->levelTwoBridge = LoadTexture("Resources/Levels/LevelTwo/bridge.png");
        level->levelTwoPlatform_right = LoadTexture("Resources/Levels/LevelTwo/right.png");
        level->levelTwoPlatform_left = LoadTexture("Resources/Levels/LevelTwo/left.png");
        level->levelTwoPlatform_mid = LoadTexture("Resources/Levels/LevelTwo/mid.png");
        level->levelTwoGround_topright = LoadTexture("Resources/Levels/LevelTwo/topright.png");
        level->levelTwoGround_topleft = LoadTexture("Resources/Levels/LevelTwo/topleft.png");
        level->levelTwoGround_topmid = LoadTexture("Resources/Levels/LevelTwo/topmid.png");
        level->levelTwoGround_midright = LoadTexture("Resources/Levels/LevelTwo/midright.png");
        level->levelTwoGround_midleft = LoadTexture("Resources/Levels/LevelTwo/midleft.png");
        level->levelTwoGround_center = LoadTexture("Resources/Levels/LevelTwo/center.png");
    }

    ////Level Three
    else if (id == 3) {
        level->levelThree_music = LoadMusicStream("Resources/Music/LevelThree.mp3");
        level->levelThreeBackground = LoadTexture("Resources/Levels/LevelThree/castle_background.png");
        level->levelThreeBridge = LoadTexture("Resources/Levels/LevelOne/bridge.png");
        level->levelThreePlatform_right = LoadTexture("Resources/Levels/LevelOne/right.png");
        level->levelThreePlatform_left = LoadTexture("Resources/Levels/LevelOne/mid.png");
        level->levelThreePlatform_mid = LoadTexture("Resources/Levels/LevelOne/left.png");
        level->levelThreeGround_topright = LoadTexture("Resources/Levels/LevelThree/topright.png");
        level->levelThreeGround_topleft = LoadTexture("Resources/Levels/LevelThree/topleft.png");
        level->levelThreeGround_topmid = LoadTexture("Resources/Levels/LevelThree/topmid.png");
        level->levelThreeGround_midright = LoadTexture("Resources/Levels/LevelThree/midright.png");
        level->levelThreeGround_midleft = LoadTexture("Resources/Levels/LevelThree/midleft.png");
        level->levelThreeGround_center = LoadTexture("Resources/Levels/LevelThree/center.png");
    }

    level->background_src = (Rectangle){ 0, 0, 320, 180 };
    level->background_disp_1 = (Rectangle){ 0, 0, 1920, 1080 };
    level->background_disp_2 = (Rectangle){ 1920, 0, 1920, 1080 };
    level->background_disp_3 = (Rectangle){ 2 * 1920, 0, 1920, 1080 };
    level->background_disp_4 = (Rectangle){ 3 * 1920, 0, 1920, 1080 };
    level->background_disp_5 = (Rectangle){ 4 * 1920, 0, 1920, 1080 };

    level->tile_src = (Rectangle){ 0, 0, 16, 16 };
    level->tile_disp = (Rectangle){ 0, 0, 192, 192 };

    level->loot_src = (Rectangle){ 0, 0, 16, 16 };
    level->loot_disp = (Rectangle){ 0, 0, 64, 64 };

    //TO BE IMPLEMENTED
    /*level->portal_src = (Rectangle)
    level->portal1_disp = (Rectangle)
    level->portal2_disp = (Rectangle)
    level->portal3_disp = (Rectangle)*/

    level->gameOver_pos = (Vector2){ 500, 500 };
    level->levelInit_pos = (Vector2){ 820, 500 };
    level->origin = (Vector2){ 0, 0 };

    level->startLevel = false;
    level->startPlay = false;
    level->swap = false;
    level->levelCompleted = false;
    level->levelRestart = false;

    level->levelOne_volume = 0.03;
    level->levelTwo_volume = 0.03;
    level->levelThree_volume = 0.03;

    level->got_hit = false;
    level->damage_timer = 0;
    level->game_over = false;

    level->levelID = id;

    return level;
}

void Level_SetAudioVolume(Level* level)
{
    SetMusicVolume(level->levelOne_music, level->levelOne_volume);
    SetMusicVolume(level->levelTwo_music, level->levelTwo_volume);
    SetMusicVolume(level->levelThree_music, level->levelThree_volume);
    SetSoundVolume(level->loot_sound, 1.0f);
    SetSoundVolume(level->levelcompleted_sound, 1.0f);
}

void Level_Init(Level* level)
{
    Color textColor = WHITE;
    textColor.a = 0;

    while (!level->startLevel)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(TextFormat("Level %d", level->levelID), level->levelInit_pos.x, level->levelInit_pos.y, 50, textColor);

        if (textColor.a < 255 && !level->swap)
        {
            if (textColor.a + 2 > 255)
                textColor.a--;
            textColor.a += 2;
        }

        if (textColor.a == 255)
            level->swap = true;

        if (level->swap)
        {
            if (textColor.a - 2 < 0)
                textColor.a++;
            textColor.a -= 2;
        }

        if (textColor.a == 0)
        {
            level->swap = false;
            level->startLevel = true;
        }

        EndDrawing();
    }
}

void Level_Draw(Level* level, Player* player)
{

    if (level->levelID == 1)
    {
        if (level->levelOneBackground.id != 0) {
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_1, level->origin, 0, RAYWHITE);
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_2, level->origin, 0, RAYWHITE);
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_3, level->origin, 0, RAYWHITE);
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_4, level->origin, 0, RAYWHITE);
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_5, level->origin, 0, RAYWHITE);
        }
        else {
            DrawRectangle(0, 0, 1920 * 5, 1080, SKYBLUE);
            DrawText("Level 1", 100, 100, 30, WHITE);
        }
    }
    else if (level->levelID == 2)
    {
        if (level->levelTwoBackground.id != 0) {
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_1, level->origin, 0, RAYWHITE);
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_2, level->origin, 0, RAYWHITE);
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_3, level->origin, 0, RAYWHITE);
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_4, level->origin, 0, RAYWHITE);
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_5, level->origin, 0, RAYWHITE);
        }
        else {
            DrawRectangle(0, 0, 1920 * 5, 1080, SKYBLUE);
            DrawText("Level 2", 100, 100, 30, WHITE);
        }
    }
    else if (level->levelID == 3)
    {
        if (level->levelThreeBackground.id != 0) {
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_1, level->origin, 0, RAYWHITE);
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_2, level->origin, 0, RAYWHITE);
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_3, level->origin, 0, RAYWHITE);
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_4, level->origin, 0, RAYWHITE);
            DrawTexturePro(level->levelOneBackground, level->background_src, level->background_disp_5, level->origin, 0, RAYWHITE);
        }
        else {
            DrawRectangle(0, 0, 1920 * 5, 1080, SKYBLUE);
            DrawText("Level 3", 100, 100, 30, WHITE);
        }
    }

    Level_DrawTiles(level);
}

void Level_DrawTiles(Level* level)
{
    char (*map)[MAP_COLS + 1];
    char (*map_background)[MAP_COLS + 1];

    switch (level->levelID) {
    case 1:
        map = levelOne_map;
        map_background = levelOne_background;
        break;
    case 2:
        map = levelTwo_map;
        map_background = levelTwo_background;
        break;
    case 3:
        map = levelThree_map;
        map_background = levelThree_background;
        break;
    default:
        map = levelOne_map;
        map_background = levelOne_background;
    }

    for (int i = 0; i < MAP_ROWS; i++)
    {
        for (int j = 0; j < MAP_COLS; j++)
        {
            level->tile_disp.x = j * level->tile_disp.width;
            level->tile_disp.y = i * level->tile_disp.height;
            level->tile_disp.width = 64;
            level->tile_disp.height = 64;

            switch (map_background[i][j])
            {
            case '0':
                if (level->levelID == 1)
                    DrawTexturePro(level->levelOneBackground, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
                else if (level->levelID == 2)
                    DrawTexturePro(level->levelTwoBackground, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
                else if (level->levelID == 3)
                    DrawTexturePro(level->levelThreeBackground, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
                break;
            }

            Level_ManageTiles(level, i, j);
        }
    }
}

void Level_ManageTiles(Level* level, int i, int j)
{
    char (*map)[MAP_COLS + 1];

    switch (level->levelID) {
    case 1:
        map = levelOne_map;
        break;
    case 2:
        map = levelTwo_map;
        break;
    case 3:
        map = levelThree_map;
        break;
    default:
        map = levelOne_map;
    }

    switch (map[i][j])
    {
    case '0':
        if (level->levelID == 1)
            DrawTexturePro(level->levelOneGround_center, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 2)
            DrawTexturePro(level->levelTwoGround_center, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 3)
            DrawTexturePro(level->levelThreeGround_center, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        break;

    case '1':
        if (level->levelID == 1)
            DrawTexturePro(level->levelOneGround_topmid, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 2)
            DrawTexturePro(level->levelTwoGround_topmid, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 3)
            DrawTexturePro(level->levelThreeGround_topmid, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        break;

    case '2':
        if (level->levelID == 1)
            DrawTexturePro(level->levelOneGround_topleft, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 2)
            DrawTexturePro(level->levelTwoGround_topleft, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 3)
            DrawTexturePro(level->levelThreeGround_topleft, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        break;

    case '3':
        if (level->levelID == 1)
            DrawTexturePro(level->levelOneGround_topright, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 2)
            DrawTexturePro(level->levelTwoGround_topright, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 3)
            DrawTexturePro(level->levelThreeGround_topright, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        break;

    case '4':
        if (level->levelID == 1)
            DrawTexturePro(level->levelOneGround_midleft, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 2)
            DrawTexturePro(level->levelTwoGround_midleft, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 3)
            DrawTexturePro(level->levelThreeGround_midleft, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        break;

    case '5':
        if (level->levelID == 1)
            DrawTexturePro(level->levelOneGround_midright, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 2)
            DrawTexturePro(level->levelTwoGround_midright, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 3)
            DrawTexturePro(level->levelThreeGround_midright, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        break;

    case '7':
        if (level->levelID == 1)
            DrawTexturePro(level->levelOneBridge, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 2)
            DrawTexturePro(level->levelTwoBridge, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 3)
            DrawTexturePro(level->levelThreeBridge, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        break;

    case '8':
        if (level->levelID == 1)
            DrawTexturePro(level->levelOnePlatform_left, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 2)
            DrawTexturePro(level->levelTwoPlatform_left, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 3)
            DrawTexturePro(level->levelThreePlatform_left, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        break;

    case '9':
        if (level->levelID == 1)
            DrawTexturePro(level->levelOnePlatform_mid, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 2)
            DrawTexturePro(level->levelTwoPlatform_mid, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 3)
            DrawTexturePro(level->levelThreePlatform_mid, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        break;

    case 'a':
        if (level->levelID == 1)
            DrawTexturePro(level->levelOnePlatform_right, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 2)
            DrawTexturePro(level->levelTwoPlatform_right, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        else if (level->levelID == 3)
            DrawTexturePro(level->levelThreePlatform_right, level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
        break;

    //case 'o': 
    //    DrawTexturePro(LoadTexture("resources/items/coin.png"), level->tile_src, level->tile_disp, level->origin, 0, RAYWHITE);
    //    break;
    }
}

void Level_CheckCollisions(Level* level, Player* player, Enemies* enemy)
{
    player->coll.x = player->animation.player_disp.x + 72;
    player->coll.y = player->animation.player_disp.y;
    player->coll.width = 100;
    player->coll.height = 13;

    player->foot_coll.x = player->coll.x;
    player->foot_coll.y = player->coll.y;
    player->foot_coll.width = 28;  
    player->foot_coll.height = 1;  

    enemy->cassava_enemy_collision.x = enemy->animation.cassava_disp.x;
    enemy->cassava_enemy_collision.y = enemy->animation.cassava_disp.y;
    enemy->cassava_enemy_collision.width = enemy->animation.cassava_disp.width;
    enemy->cassava_enemy_collision.height = enemy->animation.cassava_disp.height;

    enemy->radish_enemy_collision.x = enemy->animation.radish_disp.x;
    enemy->radish_enemy_collision.y = enemy->animation.radish_disp.y;
    enemy->radish_enemy_collision.width = enemy->animation.radish_disp.width;
    enemy->radish_enemy_collision.height = enemy->animation.radish_disp.height;


    for (int i = 0; i < MAP_ROWS; i++)
    {
        for (int j = 0; j < MAP_COLS; j++)
        {
            level->tile_disp.x = j * level->tile_disp.width;
            level->tile_disp.y = i * level->tile_disp.height;
            level->tile_disp.width = 64;
            level->tile_disp.height = 64;

            Level_ManageCollisions(level, player, enemy, i, j);
        }
    }
}

void Level_ManageCollisions(Level* level, Player* player, Enemies* enemy, int i, int j) {
    char (*map)[MAP_COLS + 1];
    switch (level->levelID) {
    case 1:
        map = levelOne_map;
        break;
    case 2:
        map = levelTwo_map;
        break;
    case 3:
        map = levelThree_map;
        break;
    default:
        map = levelOne_map;
    }

    if (CheckCollisionRecs(player->foot_coll, level->tile_disp)) {

        //FOR THE GROUND, BRIDGES, AND PLATFORMS
        if ((map[i][j] == '1' || (map[i][j] == '2' || map[i][j] == '3' || map[i][j] == '8' || map[i][j] == '9' || map[i][j] == 'a') && player->foot_coll.y < level->tile_disp.y + 30
            || map[i][j] == '7') && !player->isGoing_up) {
            if (player->foot_coll.y > level->tile_disp.y && (player->foot_coll.x + player->foot_coll.width > level->tile_disp.x + level->tile_disp.width || player->foot_coll.x < level->tile_disp.x))
                player->animation.player_disp.y -= (player->foot_coll.y - level->tile_disp.y) / 2;
            else if (player->foot_coll.y > level->tile_disp.y)
                player->animation.player_disp.y -= (player->foot_coll.y - level->tile_disp.y);
            player->jumpBreak = false;
            player->hasJumped = false;
            player->gravity = 0;
        }
        if ((map[i][j] == ' ' || map[i][j] == '0'
            || (map[i][j] == '2' || map[i][j] == '3' || map[i][j] == '8' || map[i][j] == '9' || map[i][j] == 'a') && player->foot_coll.y >= level->tile_disp.y
            || map[i][j] == '4' || map[i][j] == '5') && !player->hasJumped)
        {
            if ((player->foot_coll.x + player->foot_coll.width > level->tile_disp.x + level->tile_disp.width
                || player->foot_coll.x < level->tile_disp.x) && player->gravity < 5)
                player->gravity += 0.2;
            else
                player->gravity += 0.4;
            player->animation.player_disp.y += player->gravity;
        }
        if ((map[i][j] == '4' || map[i][j] == '5' || map[i][j] == '2' || map[i][j] == '3') && player->foot_coll.y > 870)
            player->speed.x = 0;
        if (map[i][j] == 'b' || map[i][j] == 'c' || map[i][j] == 'd' || map[i][j] == '6' || player->foot_coll.y >= 1030)
            player->death = true;
    }

    //FOR LOOTS
    if (CheckCollisionRecs(player->coll, level->loot_disp))
    {
        if (map[i][j] == 'o')
        {
            PlaySound(level->loot_sound);
            player->score += 1000;
            map[i][j] = ' ';
        }
    }

    //FOR PORTALS
    if (CheckCollisionRecs(player->coll, level->portal1_disp) && level->levelID == 1)
    {
        level->levelCompleted = true;
        Player_SetPos2(player);
        Enemies_Reset(enemy);
    }
    if (CheckCollisionRecs(player->coll, level->portal2_disp) && level->levelID == 2)
    {
        level->levelCompleted = true;
        Player_SetPos3(player);
        Enemies_Reset(enemy);
    }
    if (CheckCollisionRecs(player->coll, level->portal3_disp) && level->levelID == 3)
    {
        level->levelCompleted = true;
    }

    //FOR ENEMIES

    //FOR LEVEL 1
    if ((CheckCollisionRecsOr(player->coll, enemy->cassava_enemy_collision, (Vector2) { 96, 96 }) ||
        CheckCollisionRecs(player->coll, enemy->radish_enemy_collision) &&
        level->levelID == 1 && player->hit_timer < 0))
    {
        PlaySound(player->hit_sound);
        player->hp--;
        player->hit_timer = player->hit_duration;
    }

    //FOR LEVEL 2
    if ((CheckCollisionRecsOr(player->coll, enemy->cassava_enemy_collision, (Vector2) { 96, 96 }) ||
        CheckCollisionRecs(player->coll, enemy->radish_enemy_collision) &&
        level->levelID == 2 && player->hit_timer < 0))
    {
        PlaySound(player->hit_sound);
        player->hp--;
        player->hit_timer = player->hit_duration;
    }

    if (player->hp == 0) {
        player->death = true;
    }

    player->hit_timer--;
}

void Level_GameOverScreen(Level* level, Player* player) {
    Color textColor = WHITE;
    textColor.a = 0;
    level->levelCompleted = false;
    level->swap = false;
    level->game_over = false;

    while (!level->game_over) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("Game Over", level->gameOver_pos.x, level->gameOver_pos.y, 150, textColor);
        if (textColor.a < 255 && !level->swap)
        {
            if (textColor.a + 2 > 255)
                textColor.a--;
            textColor.a += 2;
        }

        if (textColor.a == 255)
            level->swap = true;

        if (level->swap)
        {
            if (textColor.a - 2 < 0)
                textColor.a++;
            textColor.a -= 2;
        }

        if (textColor.a == 0)
        {
            level->swap = false;
            level->game_over = true;
        }

        EndDrawing();
    }
}

void Level_ManageDeath(Level* level, Player* player, Enemies* enemy)
{
    if (player->death)
    {
        level->game_over = false;
        PlaySound(level->dead_sound);

        if (player->hp <= 0)
        {
            Level_GameOverScreen(level, player);
        }

        player->position.x = 100;
        player->position.y = 300;

        Enemies_Reset(enemy);

        player->speed.x = 7;
        player->death = false;
    }
}

void Level_ResetMusic(Level* level)
{
    StopMusicStream(level->levelOne_music);
    StopMusicStream(level->levelTwo_music);
    StopMusicStream(level->levelThree_music);

    PlayMusicStream(level->levelOne_music);
    PlayMusicStream(level->levelTwo_music);
    PlayMusicStream(level->levelThree_music);
}

bool CheckCollisionRecsOr(Rectangle rec1, Rectangle rec2, Vector2 origin)
{
    return
        rec1.x + rec1.width > rec2.x - origin.x && rec1.x < rec2.x + rec2.width - 75 &&
        rec1.y + rec1.height > rec2.y - origin.y && rec1.y < rec2.y + rec2.height - 75;
}