#include "Power.h"

Power::Power(int nType, sf::Texture *powerTex) : type(nType),
                                                 dead(0),
                                                 isSetPos(0)
{
    powerSprite.setTexture(*powerTex);
    powerSprite.setScale(sf::Vector2f(0.25, 0.25));
    powerSprite.setPosition(-200.f, -200.f);
}

Power::~Power()
{
}

int Power::getType()
{
    return type;
}

bool Power::getDead()
{
    return dead;
}

void Power::hit()
{
    dead = 1;
}

void Power::checkPowerOutside()
{
    if (powerSprite.getPosition().y >= SCREEN_HEIGHT + 5.f)
    {
        dead = 1;
    }
}

void Power::move()
{
    if (!isSetPos)
    {
        isSetPos = true;
        int x = (rand() % SCREEN_WIDTH - 20) + 30;
        int y = (rand() % 1500) + 100;
        powerSprite.setPosition(x, -y);
    }
    powerSprite.move(0, 1.5f);
}

void Power::update()
{
}

void Power::draw(sf::RenderTarget *target)
{
    if (isSetPos)
        target->draw(powerSprite);

    if (debug)
        drawHitBoxPower(target);
}

void Power::drawHitBoxPower(sf::RenderTarget *target)
{
    // Draw the outline of get_hitbox of power
    sf::IntRect hitbox = get_hitbox();
    sf::RectangleShape hitboxOutline(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxOutline.setPosition(sf::Vector2f(hitbox.left, hitbox.top));
    hitboxOutline.setFillColor(sf::Color::Transparent);
    hitboxOutline.setOutlineColor(sf::Color::Yellow); // Set the outline color
    hitboxOutline.setOutlineThickness(2.0f);          // Set the outline thickness
    target->draw(hitboxOutline);
}

sf::IntRect Power::get_hitbox() const
{
    return sf::IntRect(powerSprite.getGlobalBounds().left,
                       powerSprite.getGlobalBounds().top,
                       powerSprite.getGlobalBounds().width,
                       powerSprite.getGlobalBounds().height);
}