#ifndef BOSS_H
#define BOSS_H

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

class Boss {
public:
    Boss(int i_type, sf::Sprite boss_bullet_sprite);
    ~Boss();

    void update();
    void draw(sf::RenderTarget* target);

    void movement();
    void hit();
    void shoot(std::vector<Bullet>& i_boss_bullets);

    int getDead();

    sf::IntRect get_hitbox() const;
    void drawHitBoxBoss(sf::RenderTarget* target);
private:
    // Init 
    void initBoss();

    int type;

    sf::Texture bossTex;
    sf::Sprite bossSprite;

    sf::Texture bulletTex;
    sf::Sprite bulletSprite;

    int health;

    bool isSetPos;

    int direction;
    float randomValueX = 2.0f;
    float randomValueY = 3.0f;
};

#endif