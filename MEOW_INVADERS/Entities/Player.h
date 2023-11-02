#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
    Player(const float& x, const float& y, sf::Texture* texture);
    virtual ~Player();

    // Functions

private:
    // Initialization
    void initVariables();
    void initComponents();

    // Variables
    sf::RectangleShape shape;
};

#endif