#pragma once
#include "raylib.h"
#include "Animation.h"	
#include <stdio.h>
#include <stdbool.h>

typedef struct Player
{
	Animation animation;

	Sound death_sound;
	Sound hit_sound;
	Sound jump_sound;

	Texture2D heart;

	Rectangle heart_src;
	Rectangle heart1_disp;
	Rectangle heart2_disp;
	Rectangle heart3_disp;
	Rectangle coll;
	Rectangle foot_coll;

	Color transparent;

	Vector2 score_pos;
	Vector2 heart1_pos;
	Vector2 heart2_pos;
	Vector2 heart3_pos;
	Vector2 speed;
	Vector2 origin;
	Vector2 position;

	Camera2D camera;

	char name[100];

	float gravity;

	bool isMoving_right;
	bool isMoving_left;
	bool isRunning;
	bool hasJumped;
	bool hasTurned_right;
	bool hasTurned_left;
	bool isGoing_up;
	bool jumpBreak;
	bool moveCamera;

	bool idleRightAnim;
	bool idleLeftAnim;
	bool runRightAnim;
	bool runLeftAnim;
	bool jumpRightAnim;
	bool jumpLeftAnim;

	int hp;
	int score;
	int increment;
	bool death;
	int hit_timer;
	int hit_duration;

	float jump_volume;
	float death_volume;
	float hit_volume;
	float playJump_sound;

	bool onFloor;
	bool collision;
}Player;

void Player_Init(Player* player, PlayerCharacter character);
void Player_SetAudioVolume(Player* player);
void Player_DrawUI(Player* player);
void Player_CheckInput(Player* player);
void Player_ManageInput(Player* player);
void Player_SetPos1(Player* player);
void Player_SetPos2(Player* player);
void Player_SetPos3(Player* player);



