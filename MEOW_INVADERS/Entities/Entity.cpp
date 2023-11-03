#include "Entity.h"
#include "States/GameState.h"

// Init Variables
void Entity::initVariables()
{
    this->playerTexture = nullptr;
    this->playerSprite = nullptr;
}

Entity::Entity()
{
    initVariables();
}

Entity::~Entity()
{
    delete playerTexture;
}

// Init Sprites
void Entity::initSprites(sf::Texture* texture)
{
    this->playerTexture = texture;
    this->playerSprite = new sf::Sprite(*this->playerTexture);
  //  this->playerSprite->setTextureRect(sf::IntRect(32, 0, 32, 32));
}

// Set Position
void Entity::setEntityPosition(const float &x, const float &y)
{
    if (this->playerSprite)
    {
        this->playerSprite->setOrigin(playerTexture->getSize().x / 2, playerTexture->getSize().y / 2);
        this->playerSprite->setPosition(x, y);
    }
}

// Set Scale
void Entity::setEntityScale(const float &x, const float &y)
{
    if (this->playerSprite)
    {
        this->playerSprite->setScale(sf::Vector2f(x, y));
    }
}

void Entity::move(const float &x, const float &y)
{
    if (this->playerSprite)
    {
        playerSprite->move(x, y);
    }
}