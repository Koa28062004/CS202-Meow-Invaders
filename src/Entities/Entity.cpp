#include "Entities/Entity.h"

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        move(-1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        move(1.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        move(0.f, -1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        move(0.f, 1.f);
    }
}

void Entity::draw(sf::RenderTarget* target) {
    target->draw(shape);
}