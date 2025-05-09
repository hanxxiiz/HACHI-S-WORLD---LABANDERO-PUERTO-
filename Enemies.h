#pragma once
#include "Animation.h"
#include "raylib.h"

typedef struct Enemies
{
	Animation animation;

	Rectangle radish_enemy_collision;
	Rectangle cassava_enemy_collision;

	Vector2 radish_enemy_speed;
	Vector2 cassava_enemy_speed;

	int radish_enemy_gravity;
	int cassava_enemy_gravity;

	bool radish_enemy_moveRight;
	bool cassava_enemy_moveRight;
	bool radish_enemy_goUp;
	bool cassava_enemy_goUp;
} Enemies;

void Enemies_Init(Enemies* enemies);
void Enemies_ManageRadish(Enemies* enemies);
void Enemies_ManageCassava(Enemies* enemies);
void Enemies_Reset(Enemies* enemies);

