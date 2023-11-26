#include "Entity.h"
#include "States/GameState.h"

// Init Variables
void Entity::initVariables()
{
    this->playerTexture = nullptr;
    this->playerSprite = nullptr;
}

void Entity::initPower()
{
    if (!powerTex0.loadFromFile("assets/images/power0.png"))
    {
        throw std::runtime_error("Error::Entity::Can not load power texture");
    }

    if (!powerTex1.loadFromFile("assets/images/power1.png"))
    {
        throw std::runtime_error("Error::Entity::Can not load power texture");
    }

    if (!powerTex2.loadFromFile("assets/images/power2.png"))
    {
        throw std::runtime_error("Error::Entity::Can not load power texture");
    }

    if (!powerTex3.loadFromFile("assets/images/power3.png"))
    {
        throw std::runtime_error("Error::Entity::Can not load power texture");
    }
}

Entity::Entity()
{
    initVariables();
    initPower();
}

Entity::~Entity()
{
    delete playerTexture;
}

// Init Sprites
void Entity::initSprites(sf::Texture *texture)
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

void Entity::moveByMouse(sf::Vector2f mousePosView)
{
    if (this->playerSprite)
    {
        playerSprite->setPosition(mousePosView);
    }
}