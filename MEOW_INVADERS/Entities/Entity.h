#ifndef ENTITY_H
#define ENTITY_H

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

class Entity
{
public:
    Entity();
    virtual ~Entity();

    // Initialization
    void initSprites(sf::Texture *texture);

    // Functions
    void setEntityScale(const float &x, const float &y);
    void setEntityPosition(const float &x, const float &y);
    virtual void move(const float &x, const float &y);
    virtual void moveByMouse(sf::Vector2f mousePosView);
    virtual void draw(sf::RenderTarget *target) = 0;

protected:
    // Init Variables
    void initVariables();
    void initPower();

    // Variables
    sf::Texture *playerTexture;
    sf::Sprite *playerSprite;

    // Shield
    sf::Texture *powerTex0;
    // Fast fire
    sf::Texture *powerTex1;
    // 3 bullets
    sf::Texture *powerTex2;
    // +1 blood
    sf::Texture *powerTex3;
    // Mirror move
};

#endif