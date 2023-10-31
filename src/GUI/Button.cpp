#include "GUI/Button.h"

Button::Button(float x, float y, float width, float height,
               sf::Font *font, std::string text,
               sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->buttonState = BTN_IDLE;

    this->shape.setPosition(sf::Vector2f(sf::Vector2f(x, y)));
    this->shape.setSize(sf::Vector2f(width, height));

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->setCharacterSize(12);
    this->text.setPosition(
        this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y + (this->shape.getGlobalBounds().height) / 2.f - this->text.getGlobalBounds().height / 2.f);

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->shape.setFillColor(this->idleColor);
}

void Button::update(const sf::Vector2f &mousePos)
{
    // Update the booleans for hover and pressed
    // Idle
    this->buttonState = BTN_IDLE;

    // Hover

    if (this->shape.getGlobalBounds().contains(mousePos))
    {
        this->buttonState = BTN_HOVER;

        // Active
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = BTN_ACTIVE;
        }
    }

    switch (this->button)
    {
    case BTN_IDLE:
        this->shape.setFillColor(this->idleColor);
        break;

    case BTN_HOVER:
        this->shape.setFillColor(this->hoverColor);
        break;

    case BTN_ACTIVE:
        this->shape.setFillColor(this->activeColor);
        break;
    }
}

void Button::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}

// Accessors
const bool Button::isPressed() const 
{
    if (this->buttonState == BTN_ACTIVE) {
        return true;
    }
    return false;
}