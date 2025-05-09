#pragma once
#include "Player.h"
#include "Enemies.h"

#define MAP_ROWS 17
#define MAP_COLS 131

extern char levelOne_map[MAP_ROWS][MAP_COLS + 1];
extern char levelOne_background[MAP_ROWS][MAP_COLS + 1];

extern char levelTwo_map[MAP_ROWS][MAP_COLS + 1];
extern char levelTwo_background[MAP_ROWS][MAP_COLS + 1];

extern char levelThree_map[MAP_ROWS][MAP_COLS + 1];
extern char levelThree_background[MAP_ROWS][MAP_COLS + 1];


typedef struct Level {
	Sound dead_sound;
	Sound explosion_sound;
	Sound gameover_sound;
	Sound hit_sound;
	Sound jump_sound;
	Sound levelcompleted_sound;
	Sound loot_sound;
	Sound unlock_sound;

	Music levelOne_music;
	Music levelTwo_music;
	Music levelThree_music;

	Texture2D loot;

	//Level one
	Texture2D levelOneBackground;

	Texture2D levelOneBridge;

	Texture2D levelOnePlatform_right;
	Texture2D levelOnePlatform_left;
	Texture2D levelOnePlatform_mid;

	Texture2D levelOneGround_topleft;
	Texture2D levelOneGround_topmid;
	Texture2D levelOneGround_topright;
	Texture2D levelOneGround_midleft;
	Texture2D levelOneGround_center;
	Texture2D levelOneGround_midright;

	//Level two
	Texture2D levelTwoBackground;

	Texture2D levelTwoBridge;

	Texture2D levelTwoPlatform_right;
	Texture2D levelTwoPlatform_left;
	Texture2D levelTwoPlatform_mid;

	Texture2D levelTwoGround_topleft;
	Texture2D levelTwoGround_topmid;
	Texture2D levelTwoGround_topright;
	Texture2D levelTwoGround_midleft;
	Texture2D levelTwoGround_center;
	Texture2D levelTwoGround_midright;

	//Level three
	Texture2D levelThreeBackground;
	Texture2D levelThreeBridge;

	Texture2D levelThreePlatform_right;
	Texture2D levelThreePlatform_left;
	Texture2D levelThreePlatform_mid;

	Texture2D levelThreeGround_topleft;
	Texture2D levelThreeGround_topmid;
	Texture2D levelThreeGround_topright;
	Texture2D levelThreeGround_midleft;
	Texture2D levelThreeGround_center;
	Texture2D levelThreeGround_midright;

	Rectangle background_src;
	Rectangle background_disp_1;
	Rectangle background_disp_2;
	Rectangle background_disp_3;
	Rectangle background_disp_4;
	Rectangle background_disp_5;

	Rectangle tile_src;
	Rectangle tile_disp;

	Rectangle loot_src;
	Rectangle loot_disp;

	Rectangle portal_src;
	Rectangle portal1_disp;
	Rectangle portal2_disp;
	Rectangle portal3_disp;

	Vector2 gameOver_pos;
	Vector2 levelInit_pos;
	Vector2 origin;

	int levelID;
	bool startLevel;
	bool startPlay;
	bool swap;
	bool levelCompleted;
	bool levelRestart;

	float levelOne_volume;
	float levelTwo_volume;
	float levelThree_volume;

	bool got_hit;
	bool damage_timer;
	bool game_over;
} Level;

Level* Level_Create(int id);
void Level_SetAudioVolume(Level* level);
void Level_Init(Level* level);
void Level_DrawTiles(Level* level);
void Level_Draw(Level* level, Player* player);
void Level_ManageTiles(Level* level, int i, int j);
void Level_CheckCollisions(Level* level, Player* player, Enemies* enemy);
void Level_ManageCollisions(Level* level, Player* player, Enemies* enemy, int i, int j);
void Level_GameOverScreen(Level* level, Player* player);
void Level_ManageDeath(Level* level, Player* player, Enemies* enemy);
void Level_ResetMusic();

bool CheckCollisionRecsOr(Rectangle rec1, Rectangle rec2, Vector2 origin);
