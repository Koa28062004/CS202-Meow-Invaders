#ifndef GLOBAL_VARS_H
#define GLOBAL_VARS_H

constexpr unsigned char BOUNDARY_WIDTH = 1400;
constexpr unsigned char BASE_SIZE = 16;
constexpr unsigned char FAST_RELOAD_DURATION = 7;
constexpr unsigned char RELOAD_DURATION = 31;
constexpr unsigned char PLAYER_BULLET_SPEED = 5;

// Enemy
constexpr unsigned char ENEMY_HIT_TIMER_DURATION = 2;
constexpr unsigned char ENEMY_MOVE_SPEED = 5;
constexpr unsigned char ENEMY_TYPES = 3;
constexpr unsigned short ENEMY_SHOOT_CHANCE = 4096;
constexpr unsigned short ENEMY_SHOOT_CHANCE_INCREASE = 64;
constexpr unsigned short ENEMY_SHOOT_CHANCE_MIN = 1024;
constexpr unsigned char ENEMY_MOVE_PAUSE_MIN = 3;
constexpr unsigned char ENEMY_MOVE_PAUSE_DECREASE = 1;
constexpr unsigned char ENEMY_MOVE_PAUSE_START_MIN = 47;
constexpr unsigned char ENEMY_MOVE_PAUSE_START = 63;
constexpr unsigned char ENEMY_BULLET_SPEED = 2;


#endif