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
    Enemy(int i_type, int i_x, int i_y, sf::Texture* enemyTex);
    virtual ~Enemy();

    // Movements
	void movement(int level);
    void move0();
    // void move1();
    // void move2();

    // Functions
    void hit();
	void shoot(std::vector<Bullet>& i_enemy_bullets);
	void update();
    void draw(sf::RenderTarget* target);

    // Access
	sf::IntRect get_hitbox() const;
    int get_health() const;
	int get_hit_timer() const;
	int get_type() const;
	int get_x() const;
	int get_y() const;

    static int collectiveDirection;
    
private:
    //-1 - Left
    // 0 - Down
    // 1 - Right
    int direction;

    int health;
    
    int hit_timer;

    // type of enemy
    int type;

    int x;
    int y;

    sf::Texture enemyTex;
    sf::Sprite enemySprite;
};

#endif