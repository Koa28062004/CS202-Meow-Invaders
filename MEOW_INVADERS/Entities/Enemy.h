#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <stack>
#include <map>
#include <vector>
#include <string>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Bullet.h"
#include "GlobalVars/GlobalVars.h"

class Enemy
{
public:
    Enemy(unsigned char i_type, unsigned short i_x, unsigned short i_y);
    virtual ~Enemy();

    // Functions
    void hit();
	void move();
	void shoot(std::vector<Bullet>& i_enemy_bullets);
	void update();

	sf::IntRect get_hitbox() const;

    unsigned char get_health() const;
	unsigned char get_hit_timer() const;
	unsigned char get_type() const;

	unsigned short get_x() const;
	unsigned short get_y() const;
    
private:
    //-1 - Left
    // 0 - Down
    // 1 - Right
    char direction;

    unsigned char health;
    
    unsigned char hit_timer;

    // type of enemy
    unsigned char type;

    unsigned short x;
    unsigned short y;
};

#endif