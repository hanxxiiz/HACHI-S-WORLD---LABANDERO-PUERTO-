#include "raylib.h"
#include "Animation.h"
#include "Player.h"

void Animation_Init(Animation* anim, PlayerCharacter character)
{
    if (!anim) return;

    switch (character) {
    case PLAYER_HACHI:
        anim->player_texture_idle = LoadTexture("Resources/MainCharacters/Hachi_IDLE.png");
        anim->player_texture_run = LoadTexture("Resources/MainCharacters/Hachi_RUN.png");
        anim->player_texture_jump = LoadTexture("Resources/MainCharacters/Hachi_JUMP.png");
        break;
    case PLAYER_SOPHIE:
        anim->player_texture_idle = LoadTexture("Resources/MainCharacters/Sophie_IDLE.png");
        anim->player_texture_run = LoadTexture("Resources/MainCharacters/Sophie_RUN.png");
        anim->player_texture_jump = LoadTexture("Resources/MainCharacters/Sophie_JUMP.png");
        break;
    case PLAYER_BUBBLES:
        anim->player_texture_idle = LoadTexture("Resources/MainCharacters/Bubbles_IDLE.png");
        anim->player_texture_run = LoadTexture("Resources/MainCharacters/Bubbles_RUN.png");
        anim->player_texture_jump = LoadTexture("Resources/MainCharacters/Bubbles_JUMP.png");
        break;
    default:
        anim->player_texture_idle = LoadTexture("Resources/MainCharacters/Hachi_IDLE.png");
        anim->player_texture_run = LoadTexture("Resources/MainCharacters/Hachi_RUN.png");
        anim->player_texture_jump = LoadTexture("Resources/MainCharacters/Hachi_JUMP.png");
        break;
    }

    //enemies
    /*anim->radish_texture_move = LoadTexture("Resources/MainCharacters/");
    anim->cassava_texture_move = LoadTexture("Resources/MainCharacters/");*/

    anim->cassava_src_right = (Rectangle){ 0, 0, 100, 100 };
    anim->cassava_src_left = (Rectangle){ 0, 0, -100, 100 };
    anim->radish_src_right = (Rectangle){ 0, 0, 100, 100 };
    anim->radish_src_left = (Rectangle){ 0, 0, -100, 100 };

    anim->player_src_right = (Rectangle){ 0, 0, 192, 192 };
    anim->player_src_left = (Rectangle){ 0, 0, -192, 192 };

    anim->cassava_disp = (Rectangle){ 2460, 450, 256, 192 };
    anim->radish_disp = (Rectangle){ 4800, 704, 256, 192 };

    anim->player_disp = (Rectangle){ 50, 704, 192, 192 };

    anim->origin = (Vector2){ 0, 0 };

    anim->timer_playerIdleRight = 0;
    anim->timer_playerIdleLeft = 0;
    anim->timer_playerRunLeft = 0;
    anim->timer_playerRunRight = 0;
    anim->timer_playerJumpRight = 0;
    anim->timer_playerJumpLeft = 0;
    anim->timer_radishMoveRight = 0;
    anim->timer_radishMoveLeft = 0;
    anim->timer_cassavaMoveRight = 0;
    anim->timer_cassavaMoveLeft = 0;
}

//TO BE IMPLEMENTED
//void Animation_Unload(Animation* animation)
//{
//    UnloadTexture(animation->player_texture_idle);
//    UnloadTexture(animation->player_texture_walk);
//}

void AnimationPlayer_runLeft(Animation* anim) {
    if (!anim) return;

    if (anim->timer_playerRunLeft % 6 == 0) {
        anim->player_src_left.x += 192;
    }
    DrawTexturePro(anim->player_texture_run, anim->player_src_left, anim->player_disp, anim->origin, 0, RAYWHITE);
    anim->timer_playerRunLeft++;
    if (anim->timer_playerRunLeft == 48) {
        anim->timer_playerRunLeft = 0;
    }
}

void AnimationPlayer_runRight(Animation* anim) {
    if (!anim) return;

    if (anim->timer_playerRunRight % 6 == 0) {
        anim->player_src_right.x += 192;
    }
    DrawTexturePro(anim->player_texture_run, anim->player_src_right, anim->player_disp, anim->origin, 0, RAYWHITE);
    anim->timer_playerRunRight++;
    if (anim->timer_playerRunRight == 48) {
        anim->timer_playerRunRight = 0;
    }
}

void AnimationPlayer_idleLeft(Animation* anim) {
    if (!anim) return;

    if (anim->timer_playerIdleLeft % 6 == 0) {
        anim->player_src_left.x += 192;
    }
    DrawTexturePro(anim->player_texture_idle, anim->player_src_left, anim->player_disp, anim->origin, 0, RAYWHITE);
    anim->timer_playerIdleLeft++;
    if (anim->timer_playerIdleLeft == 48) {
        anim->timer_playerIdleLeft = 0;
    }
}

void AnimationPlayer_idleRight(Animation* anim) {
    if (!anim) return;

    if (anim->timer_playerIdleRight % 6 == 0) {
        anim->player_src_right.x += 192;
    }
    DrawTexturePro(anim->player_texture_idle, anim->player_src_right, anim->player_disp, anim->origin, 0, RAYWHITE);
    anim->timer_playerIdleRight++;
    if (anim->timer_playerIdleRight == 48) {
        anim->timer_playerIdleRight = 0;
    }
}

void AnimationPlayer_jumpLeft(Animation* anim) {
    DrawTexturePro(anim->player_texture_jump, anim->player_src_left, anim->player_disp, anim->origin, 0, RAYWHITE);
}

void AnimationPlayer_jumpRight(Animation* anim) {
    DrawTexturePro(anim->player_texture_jump, anim->player_src_right, anim->player_disp, anim->origin, 0, RAYWHITE);
}


// TO BE MODIFIED ONCE THE LEVELS ARE WORKING
//void AnimationRadish_moveLeft(Animation* anim) {
//    if (!anim) return;
//
//    if (anim->timer_radishMoveLeft % 6 == 0) {
//        anim->radish_src_left.x += 100; 
//    }
//    DrawTexturePro(anim->radish_texture_move, anim->radish_src_left, anim->radish_disp, anim->origin, 0, RAYWHITE);
//    anim->timer_radishMoveLeft++;
//    if (anim->timer_radishMoveLeft == 48) {
//        anim->timer_radishMoveLeft = 0;
//    }
//}
//
//void AnimationRadish_moveRight(Animation* anim) {
//    if (!anim) return;
//
//    if (anim->timer_radishMoveRight % 6 == 0) {
//        anim->radish_src_right.x += 100;
//    }
//    DrawTexturePro(anim->radish_texture_move, anim->radish_src_right, anim->radish_disp, anim->origin, 0, RAYWHITE);
//    anim->timer_radishMoveRight++;
//    if (anim->timer_radishMoveRight == 48) {
//        anim->timer_radishMoveRight = 0;
//    }
//}
//
//void AnimationCassava_moveLeft(Animation* anim) {
//    if (!anim) return;
//
//    if (anim->timer_cassavaMoveLeft % 6 == 0) {
//        anim->cassava_src_left.x += 100;
//    }
//    DrawTexturePro(anim->cassava_texture_move, anim->cassava_src_left, anim->cassava_disp, anim->origin, 0, RAYWHITE);
//    anim->timer_cassavaMoveLeft++;
//    if (anim->timer_cassavaMoveLeft == 48) {
//        anim->timer_cassavaMoveLeft = 0;
//    }
//}
//
//void AnimationCassava_moveRight(Animation* anim) {
//    if (!anim) return;
//
//    if (anim->timer_cassavaMoveRight % 6 == 0) {
//        anim->cassava_src_right.x += 100;
//    }
//    DrawTexturePro(anim->cassava_texture_move, anim->cassava_src_right, anim->cassava_disp, anim->origin, 0, RAYWHITE);
//    anim->timer_cassavaMoveRight++;
//    if (anim->timer_cassavaMoveRight == 48) {
//        anim->timer_cassavaMoveRight = 0;
//    }
//}


