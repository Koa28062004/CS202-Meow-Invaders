#include "Player.h"

// Init Variables
void Player::initVariables()
{
}

// Init Components
void Player::initComponents()
{
}

Player::Player(const float& x, const float& y, sf::Texture *texture)
{
    initVariables();
    initComponents();
    initSprites(texture);
    setEntityPosition(x, y);
}

Player::~Player()
{
}