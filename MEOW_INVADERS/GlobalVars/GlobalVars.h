#ifndef GLOBAL_VARS_H
#define GLOBAL_VARS_H

constexpr int SCREEN_WIDTH = 1300;
constexpr int SCREEN_HEIGHT = 800;

constexpr int BASE_SIZE = 16;
constexpr int FAST_RELOAD_DURATION = 7;
constexpr int RELOAD_DURATION = 31;
constexpr int PLAYER_BULLET_SPEED = 5;

// Enemy
constexpr int ENEMY_HIT_TIMER_DURATION = 2;
constexpr int ENEMY_MOVE_SPEED = 25;
constexpr int ENEMY_TYPES = 3;
constexpr int ENEMY_SHOOT_CHANCE = 4000;
constexpr int ENEMY_SHOOT_CHANCE_INCREASE = 64;
constexpr int ENEMY_SHOOT_CHANCE_MIN = 1024;
constexpr int ENEMY_MOVE_PAUSE_MIN = 3;
constexpr int ENEMY_MOVE_PAUSE_DECREASE = 1;
constexpr int ENEMY_MOVE_PAUSE_START_MIN = 47;
constexpr int ENEMY_MOVE_PAUSE_START = 63;
constexpr int ENEMY_BULLET_SPEED = 2;

// Draw the outline hit box to debug
constexpr bool debug = 1;


#endif