#include "Entity.h"
#include "States/GameState.h"

// Init Variables
void Entity::initVariables()
{
    this->texture = nullptr;
    this->sprite = nullptr;
}

Entity::Entity()
{
    initVariables();
}

Entity::~Entity()
{
    delete sprite;
}

// Init Sprites
void Entity::initSprites(sf::Texture* texture)
{
    this->texture = texture;
    this->sprite = new sf::Sprite(*this->texture);
}

// Set Position
void Entity::setEntityPosition(const float &x, const float &y)
{
    if (this->sprite)
    {
        this->sprite->setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);
        this->sprite->setPosition(x, y);
    }
}

// Set Scale
void Entity::setEntityScale(const float &x, const float &y)
{
    if (this->sprite)
    {
        this->sprite->setScale(sf::Vector2f(x, y));
    }
}

void Entity::move(const float &x, const float &y)
{
    if (this->sprite)
    {
        sprite->move(x, y);
    }
}

void Entity::update()
{
}

void Entity::draw(sf::RenderTarget *target)
{
    if (this->sprite)
        target->draw(*this->sprite);
}