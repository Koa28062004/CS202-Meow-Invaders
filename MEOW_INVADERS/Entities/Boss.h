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
#include "Animations/Animation.h"

class Boss {
public:
    Boss(int i_type, sf::Sprite boss_bullet_sprite);
    ~Boss();

    void update();
    void draw(sf::RenderTarget* target);

    void movement();
    void hit();
    void shoot(std::vector<Bullet>& i_boss_bullets);

    bool getDead();
    int get_health();

    sf::IntRect get_hitbox() const;
    void drawHitBoxBoss(sf::RenderTarget* target);

    // setter
    void setHealth(int health);
    void setIsSetPos(bool isSetPos);
    void setPosition(int x, int y);

    // save 
    void saveGame(std::string fileName);
    // load game
    void loadGameExplosion(std::ifstream& ifs);
private:
    // Init 
    void initBoss();

    int type;
    int timer;

    sf::Texture bossTex1;
    sf::Texture bossTex2;
    
    sf::Sprite bossSprite;

    sf::Texture bulletTex;
    sf::Sprite bulletSprite;

    int health;

    bool isSetPos;

    int direction;
    float randomValueX = 2.0f;
    float randomValueY = 3.0f;
    Animation explosion;
    bool dead_animation_over;
};

#endif