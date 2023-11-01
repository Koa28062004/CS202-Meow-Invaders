#include "Entities/Entity.h"
#include "States/GameState.h"

// Init Variables
void Entity::initVariables() {
    this->texture = nullptr;
    this->sprite = nullptr;
}

Entity::Entity() {
    initVariables();
}

Entity::~Entity() {
    delete sprite;
}

// Init Sprites
void Entity::initSprites(sf::Texture* texture) {
    this->texture = texture;
    this->sprite->setTexture(*this->texture);
}

void Entity::move(const float &x, const float &y) {
    if (sprite) shape.move(x, y);
} 

void Entity::update() {
    
}

void Entity::draw(sf::RenderTarget* target) {
    if (this->sprite) target->draw(*this->sprite);
}