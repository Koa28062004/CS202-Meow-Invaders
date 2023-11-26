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
    Power(int nType, sf::RenderTexture *powerTex);
    ~Power();

    void update();
    void draw(sf::RenderTarget *target);
    void move();

    bool getDead();
    void checkPowerOutside();

private:
    // Power Up
    // 0 - shield
    // 1 - Fast fire
    // 2 - 3 bullets
    // 3 - +1 blood
    // Power Down
    // 3 - mirror move
    int type;
    bool dead;
    sf::RenderSprite *powerSprite;
    bool isSetPos;
};

#endif