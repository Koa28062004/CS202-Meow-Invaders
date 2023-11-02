#include "Button.h"

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
    this->text.setOutlineColor(sf::Color(255, 153, 255, 200));
    this->text.setOutlineThickness(1);
    this->text.setCharacterSize(40);
    this->text.setPosition(
        this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y + (this->shape.getGlobalBounds().height) / 2.f - this->text.getGlobalBounds().height / 2.f);

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->shape.setFillColor(this->idleColor);

    initTriangle();
}

Button::~Button()
{
}

// Init Triangle
void Button::initTriangle()
{
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(text.getPosition().x - 30 + 5, text.getPosition().y + text.getGlobalBounds().height / 2 + 7));
    triangle.setPoint(1, sf::Vector2f(text.getPosition().x - 50 + 5, text.getPosition().y + text.getGlobalBounds().height / 2 + 20 + 7));
    triangle.setPoint(2, sf::Vector2f(text.getPosition().x - 50 + 5, text.getPosition().y + text.getGlobalBounds().height / 2 - 20 + 7));
    triangle.setOutlineColor(sf::Color(255, 153, 255, 200)); // Set the outline color
}

void Button::update(const sf::Vector2f &mousePos)
{
    // Update the booleans for hover and pressed
    // Idle
    this->buttonState = BTN_IDLE;

    // Hover

    if (this->text.getGlobalBounds().contains(mousePos))
    {
        this->buttonState = BTN_HOVER;

        // Active
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = BTN_ACTIVE;
        }
    }

    switch (this->buttonState)
    {
    case BTN_IDLE:
        this->shape.setFillColor(this->idleColor);
        text.setStyle(sf::Text::Regular);
        triangle.setFillColor(sf::Color(0, 0, 0, 0));
        triangle.setOutlineThickness(0);
        break;

    case BTN_HOVER:
        this->shape.setFillColor(this->hoverColor);
        text.setStyle(sf::Text::Bold);
        triangle.setFillColor(sf::Color::White);
        triangle.setOutlineThickness(2);
        break;

    case BTN_ACTIVE:
        this->shape.setFillColor(this->activeColor);
        text.setStyle(sf::Text::Bold);
        triangle.setFillColor(sf::Color::White);
        triangle.setOutlineThickness(2);
        break;
    }
}

void Button::draw(sf::RenderTarget *target)
{
    target->draw(this->shape);
    target->draw(this->text);
    target->draw(this->triangle);
}

// Accessors
const bool Button::isPressed() const
{
    if (this->buttonState == BTN_ACTIVE)
    {
        return true;
    }
    return false;
}
