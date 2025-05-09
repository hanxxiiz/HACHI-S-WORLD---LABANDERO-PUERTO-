#include "Enemies.h"
#include "raylib.h"

void Enemies_Init(Enemies* enemies)
{
    if (enemies == NULL) {
        printf("Error: Enemies pointer is NULL\n");
        return;
    }

    enemies->radish_enemy_collision = (Rectangle){ 0, 0, 100, 40 };
    enemies->cassava_enemy_collision = (Rectangle){ 0, 0, 100, 40 };

    enemies->radish_enemy_speed = (Vector2){ 8, 22 };
    enemies->cassava_enemy_speed = (Vector2){ 8, 22 };

    enemies->radish_enemy_moveRight = false;
    enemies->cassava_enemy_moveRight = false;
    enemies->radish_enemy_goUp = true;
    enemies->cassava_enemy_goUp = true;

    enemies->radish_enemy_gravity = 0;
    enemies->cassava_enemy_gravity = 0;
}

void Enemies_ManageRadish(Enemies* enemies)
{
    if (enemies->radish_enemy_moveRight) {
        enemies->radish_enemy_collision.x += enemies->radish_enemy_speed.x;
    }
    else {
        enemies->radish_enemy_collision.x -= enemies->radish_enemy_speed.x;
    }

    if (enemies->radish_enemy_goUp) {
        enemies->radish_enemy_gravity -= 1;
        if (enemies->radish_enemy_gravity < -enemies->radish_enemy_speed.y) {
            enemies->radish_enemy_gravity = -enemies->radish_enemy_speed.y;
        }
    }
    else {
        enemies->radish_enemy_gravity += 1;
        if (enemies->radish_enemy_gravity > enemies->radish_enemy_speed.y) {
            enemies->radish_enemy_gravity = enemies->radish_enemy_speed.y;
        }
    }
    enemies->radish_enemy_collision.y += enemies->radish_enemy_gravity;

}

void Enemies_ManageCassava(Enemies* enemies)
{
    if (enemies->cassava_enemy_moveRight)
    {
        enemies->cassava_enemy_collision.x += enemies->cassava_enemy_speed.x;
    }
    else
    {
        enemies->cassava_enemy_collision.x -= enemies->cassava_enemy_speed.x;
    }

    if (enemies->cassava_enemy_goUp)
    {
        enemies->cassava_enemy_gravity -= 1;
        if (enemies->cassava_enemy_gravity < -enemies->cassava_enemy_speed.y) {
            enemies->cassava_enemy_gravity = -enemies->cassava_enemy_speed.y;
        }
    }
    else
    {
        enemies->cassava_enemy_gravity += 1;
        if (enemies->cassava_enemy_gravity > enemies->cassava_enemy_speed.y) {
            enemies->cassava_enemy_gravity = enemies->cassava_enemy_speed.y;
        }
    }
    enemies->cassava_enemy_collision.y += enemies->cassava_enemy_gravity;
}

void Enemies_Reset(Enemies* enemies)
{
    enemies->radish_enemy_collision.x = 100;
    enemies->radish_enemy_collision.y = 200;
    enemies->cassava_enemy_collision.x = 400;
    enemies->cassava_enemy_collision.y = 300;

    enemies->radish_enemy_gravity = 0;
    enemies->cassava_enemy_gravity = 0;

    enemies->radish_enemy_moveRight = false;
    enemies->cassava_enemy_moveRight = false;
    enemies->radish_enemy_goUp = true;
    enemies->cassava_enemy_goUp = true;
}