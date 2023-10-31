#include "Entities/Entity.h"
#include "States/GameState.h"

Entity::Entity() {
    shape.setFillColor(sf::Color::Red);
    shape.setSize(sf::Vector2f(50.f, 50.f));
}

Entity::~Entity() {

}

void Entity::move(const float &x, const float &y) {
    shape.move(x, y);
} 

void Entity::update() {
    
}

void Entity::draw(sf::RenderTarget* target) {
    target->draw(shape);
}