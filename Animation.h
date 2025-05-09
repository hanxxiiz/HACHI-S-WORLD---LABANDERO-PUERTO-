#pragma once
#include "raylib.h"
#include<stdio.h>
#include<stdbool.h>

typedef enum PlayerType {
    PLAYER_HACHI,
    PLAYER_SOPHIE,
    PLAYER_BUBBLES
} PlayerCharacter;

typedef struct Animation {

    Texture2D player_texture_idle;
    Texture2D player_texture_run;
    Texture2D player_texture_jump;

    Texture2D radish_texture_move;
    Texture2D cassava_texture_move;

    Rectangle player_src_left;
    Rectangle player_src_right;

    Rectangle cassava_src_left;
    Rectangle cassava_src_right;
    Rectangle radish_src_left;
    Rectangle radish_src_right; 

    Rectangle cassava_disp;
    Rectangle radish_disp;

    Rectangle player_disp;

    Vector2 origin;

    int timer_playerIdleLeft;
    int timer_playerIdleRight;
    int timer_playerRunLeft;
    int timer_playerRunRight;
    int timer_playerJumpLeft;
    int timer_playerJumpRight;
    int timer_radishMoveRight;
    int timer_cassavaMoveRight;
    int timer_radishMoveLeft;
    int timer_cassavaMoveLeft;
}Animation;

void Animation_Init(Animation* anim, PlayerCharacter character);
void AnimationPlayer_runLeft(Animation* anim);
void AnimationPlayer_runRight(Animation* anim);
void AnimationPlayer_idleLeft(Animation* anim);
void AnimationPlayer_idleRight(Animation* anim);
void AnimationPlayer_jumpLeft(Animation* anim);
void AnimationPlayer_jumpRight(Animation* anim);


void AnimationRadish_moveLeft(Animation* anim);
void AnimationCassava_moveLeft(Animation* anim);
void AnimationRadish_moveRight(Animation* anim);
void AnimationCassava_moveRight(Animation* anim);

