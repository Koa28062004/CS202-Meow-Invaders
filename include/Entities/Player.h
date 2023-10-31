#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
    Player();
    virtual ~Player();

    // Pure Functions
    virtual void move(const float &x, const float &y) = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderTarget* target) = 0;

private:
    sf::RectangleShape shape;
};

#endif