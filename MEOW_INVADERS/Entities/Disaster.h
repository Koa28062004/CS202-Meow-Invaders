#ifndef DISASTER_H
#define DISASTER_H

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
#include "GlobalVars/GlobalVars.h"

class Disaster
{
public:
    Disaster(int type, sf::Texture* disasterTex);
    ~Disaster();

    void update();
    void draw(sf::RenderTarget* target);
    void hit();
    void movement(int level);
    void drawHitBoxEnemy(sf::RenderTarget* target);
    sf::IntRect get_hitbox() const;

    bool getDead();
    void checkOutside();

    void move1();
    void move2();
    void move3();
private:
    int health;
    sf::Sprite disasterSprite;
    bool isSetPos;
    int value;
};

#endif