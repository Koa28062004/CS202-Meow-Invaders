#ifndef POWER_H
#define POWER_H

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

class Power
{
public:
    Power(int nType, sf::Texture *powerTex);
    ~Power();

    void update();
    void draw(sf::RenderTarget *target);
    void move();
    void hit();

    bool getDead();
    int getType();

    void checkPowerOutside();
    void drawHitBoxPower(sf::RenderTarget *target);
    sf::IntRect get_hitbox() const;

private:
    // Power Up
    // 1 - Fast fire
    // 2 - 3 bullets
    // 3 - +1 blood
    int type;
    bool dead;
    sf::Sprite powerSprite;
    bool isSetPos;
};

#endif