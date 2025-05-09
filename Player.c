#include "Player.h"
#include "Animation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Player_Init(Player* player, PlayerCharacter character) {
    Animation_Init(&player->animation, character);

    player->death_sound = LoadSound("Resources/SoundEffects/dead.wav");
    player->hit_sound = LoadSound("Resources/SoundEffects/hit.wav");
    player->jump_sound = LoadSound("Resources/SoundEffects/jump.wav");

    player->heart = LoadTexture("Resources/UI/heart.png");

    player->heart_src = (Rectangle){ 0, 0, player->heart.width, player->heart.height };
    player->position = (Vector2){ 100, 100 };
    player->heart1_disp = (Rectangle){ 0, 0, 48, 48 };
    player->heart2_disp = (Rectangle){ 0, 0, 48, 48 };
    player->heart3_disp = (Rectangle){ 0, 0, 48, 48 };

    player->coll = (Rectangle){ 0, 0, 100, 130 };
    player->foot_coll = (Rectangle){ 0, 0, 0, 0 };

    player->transparent = (Color){ 0, 0, 0, 0 };

    player->score_pos = (Vector2){ 0, 0 };
    player->heart1_pos = (Vector2){ 0,0 };
    player->heart2_pos = (Vector2){ 0,0 };
    player->heart3_pos = (Vector2){ 0,0 };

    player->speed = (Vector2){ 8, 24.5 };
    player->origin = (Vector2){ 0,0 };

    player->camera.target = (Vector2){ player->animation.player_disp.x,  576 };
    player->camera.offset = (Vector2){ player->animation.player_disp.x, 576};
    player->camera.rotation = 0;
    player->camera.zoom = 1;

    player->gravity = 0;

    player->isRunning = false;
    player->hasJumped = false;
    player->hasTurned_left = false;
    player->hasTurned_right = false;
    player->isGoing_up = false;
    player->jumpBreak = false;
    player->moveCamera = false;

    player->idleRightAnim = false;
    player->idleLeftAnim = false;
    player->runRightAnim = false;
    player->runLeftAnim = false;
    player->jumpRightAnim = false;
    player->jumpLeftAnim = false;

    player->hp = 3;
    player->score = 0;
    player->increment = 1;
    player->death = false;
    player->hit_timer = 0;
    player->hit_duration = 200000;

    player->jump_volume = 0.06;
    player->death_volume = 0.08;
    player->hit_volume = 0.06;
    player->playJump_sound = false;

    Player_SetAudioVolume(player);
}

void Player_SetAudioVolume(Player* player) {
    SetSoundVolume(player->jump_sound, player->jump_volume);
    SetSoundVolume(player->hit_sound, player->hit_volume);
    SetSoundVolume(player->death_sound, player->death_volume);
}

void Player_DrawUI(Player* player) {
    player->score_pos = GetScreenToWorld2D((Vector2) { 1500, 40 }, player->camera);
    player->heart1_pos = GetScreenToWorld2D((Vector2) { 50, 40 }, player->camera);
    player->heart2_pos = GetScreenToWorld2D((Vector2) { 110, 40 }, player->camera);
    player->heart3_pos = GetScreenToWorld2D((Vector2) { 170, 40 }, player->camera);
    player->heart1_disp.x = player->heart1_pos.x;
    player->heart1_disp.y = player->heart1_pos.y;
    player->heart2_disp.x = player->heart2_pos.x;
    player->heart2_disp.y = player->heart2_pos.y;
    player->heart3_disp.x = player->heart3_pos.x;
    player->heart3_disp.y = player->heart3_pos.y;

    if (player->hp == 3)
    {
        DrawTexturePro(player->heart, player->heart_src, player->heart3_disp, player->origin, 0, RAYWHITE);
        DrawTexturePro(player->heart, player->heart_src, player->heart2_disp, player->origin, 0, RAYWHITE);
        DrawTexturePro(player->heart, player->heart_src, player->heart1_disp, player->origin, 0, RAYWHITE);
    }
    if (player->hp == 2)
    {
        DrawTexturePro(player->heart, player->heart_src, player->heart2_disp, player->origin, 0, RAYWHITE);
        DrawTexturePro(player->heart, player->heart_src, player->heart1_disp, player->origin, 0, RAYWHITE);
    }
    if (player->hp == 1)
    {
        DrawTexturePro(player->heart, player->heart_src, player->heart1_disp, player->origin, 0, RAYWHITE);
        DrawText(("Score: %d", player->score), player->score_pos.x, 40, 5, WHITE);
    }
}

void Player_CheckInput(Player* player) {
    if (IsKeyDown(KEY_A))
        player->isMoving_left = true;
    if (IsKeyDown(KEY_D))
        player->isMoving_right = true;
    if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))
        player->isRunning = true;
    if (IsKeyPressed(KEY_SPACE))
    {
        player->hasJumped = true;
        player->playJump_sound = true;
    }
    if (IsKeyUp(KEY_A))
        player->isMoving_left = false;
    if (IsKeyUp(KEY_D))
        player->isMoving_right = false;
    if (IsKeyUp(KEY_Q))
        player->isRunning = false;
}

void Player_ManageInput(Player* player) {
    if (player->animation.player_disp.x > 548 && player->animation.player_disp.x < 6952) {
        player->moveCamera = true;
        player->camera.target = (Vector2){ player->animation.player_disp.x - 500, 580 };
    }
    else {
        player->moveCamera = false;
    }

    if (!player->isMoving_left && !player->isMoving_right && !player->hasJumped || player->isMoving_left && player->isMoving_right) {
        if (player->hasTurned_right) {
            if (player->hit_timer < 0) {
                AnimationPlayer_idleRight(&player->animation);
            }
            else if (player->hit_timer > 0 && player->hit_timer % 3 == 0) {
                AnimationPlayer_idleRight(&player->animation);
            }
        }
        else if (player->hasTurned_left) {
            if (player->hit_timer < 0) {
                AnimationPlayer_idleLeft(&player->animation);
            }
            else if (player->hit_timer > 0 && player->hit_timer % 3 == 0) {
                AnimationPlayer_idleRight(&player->animation);
            }
        }
    }
    else if (player->isMoving_left) {
        if (!player->hasJumped) {
            if (player->hit_timer < 0) {
                AnimationPlayer_runLeft(&player->animation);
            }
            else if (player->hit_timer > 0 && player->hit_timer % 3 == 0) {
                AnimationPlayer_runLeft(&player->animation);
            }
            if (player->coll.x > 0) {
                player->animation.player_disp.x -= player->speed.x;
            }

            player->hasTurned_left = true;
            player->hasTurned_right = false;
        }
    }
    else if (player->isMoving_right) {
        if (!player->hasJumped) {
            if (player->hit_timer < 0) {
                AnimationPlayer_runRight(&player->animation);
            }
            else if (player->hit_timer > 0 && player->hit_timer % 3 == 0) {
                AnimationPlayer_runRight(&player->animation);
            }
            if (player->coll.x < 8250) {
                player->animation.player_disp.x += player->speed.x;
            }

            player->hasTurned_right = true;
            player->hasTurned_left = false;
        }
    }

    if (player->isRunning && player->speed.x < 12) {
        player->speed.x += 0.25;
    }
    if (!player->isRunning && player->speed.x > 7) {
        player->speed.x -= 0.25;
    }

    if (player->hasJumped && player->hasTurned_left) {
        if (player->playJump_sound) {
            PlaySound(player->jump_sound);
        }
        if (player->hit_timer < 0) {
            AnimationPlayer_jumpLeft(&player->animation);
        }
        else if (player->hit_timer > 0 && player->hit_timer % 3 == 0)
        {
            AnimationPlayer_jumpLeft(&player->animation);
        }

        player->animation.player_disp.y -= (player->speed.y - player->gravity);

        if (player->gravity < 50) {
            player->gravity++;
        }
        if (player->gravity >= player->speed.y) {
            player->isGoing_up = false;
        }
        else {
            player->isGoing_up = true;
        }

        player->playJump_sound = false;
    }

    if (player->hasJumped && player->hasTurned_right) {
        if (player->playJump_sound) {
            PlaySound(player->jump_sound);
        }
        if (player->hit_timer < 0) {
            AnimationPlayer_jumpRight(&player->animation);
        }
        else if (player->hit_timer > 0 && player->hit_timer % 3 == 0)
        {
            AnimationPlayer_jumpRight(&player->animation);
        }

        player->animation.player_disp.y -= (player->speed.y - player->gravity);

        if (player->gravity < 49) {
            player->gravity++;
        }
        if (player->gravity >= player->speed.y) {
            player->isGoing_up = false;
        }
        else {
            player->isGoing_up = true;
        }

        player->playJump_sound = false;
    }

    if (!player->isGoing_up)
        player->jumpBreak = true;
}


void Player_SetPos1(Player* player) {
    player->hit_timer = 0;
    player->hp = 3;
    player->score = 0;
    player->gravity = 0;
    player->hasJumped = false;
    player->animation.player_disp = (Rectangle){ 50, 704, 192, 192 };
    player->camera.target = (Vector2){ player->animation.player_disp.x, 580 };
}
void Player_SetPos2(Player* player) {
    player->hit_timer = 0;
    player->gravity = 0;
    player->hasJumped = false;
    player->animation.player_disp = (Rectangle){ 50, 704, 192, 192 };
    player->camera.target = (Vector2){ player->animation.player_disp.x, 580 };
}
void Player_SetPos3(Player* player) {
    player->hit_timer = 0;
    player->gravity = 0;
    player->hp = 3;
    player->hasJumped = false;
    player->animation.player_disp = (Rectangle){ 50, 704, 192, 192 };
    player->camera.target = (Vector2){ player->animation.player_disp.x, 580 };
}