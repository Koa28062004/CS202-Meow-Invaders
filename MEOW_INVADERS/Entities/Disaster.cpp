#include "Disaster.h"

Disaster::Disaster(int type, sf::Texture *disasterTex) : health(1 + type),
                                                         isSetPos(false)
{
    disasterSprite.setTexture(*disasterTex);
    disasterSprite.setScale(sf::Vector2f(0.25, 0.25));
    disasterSprite.setPosition(-200.f, -200.f);
}

Disaster::~Disaster()
{
}

void Disaster::hit()
{
    if (health > 0)
    {
        --health;
    }
    else
    {
        health = 0; // Ensure health doesn't go negative
    }
}

bool Disaster::getDead()
{
    return health;
}

void Disaster::checkOutside()
{
    if (disasterSprite.getPosition().y >= SCREEN_HEIGHT + 5.f)
    {
        health = 0;
    }
}

void Disaster::movement(int level)
{
    switch (level)
    {
    case 1:
        move1();
        break;
    case 2:
        move2();
        break;
    case 3:
        move3();
        break;
    case 4:
        move1();
    case 5:
        move2();
        break;
    case 6:
        move3();
        break;
    default:
        break;
    }
}

void Disaster::move1()
{
    if (!isSetPos)
    {
        isSetPos = true;
        int x = (rand() % SCREEN_WIDTH - 20) + 30;
        int y = (rand() % 1500) + 100;
        disasterSprite.setPosition(x, -y);
    }
    disasterSprite.move(0, 3.f);
}

void Disaster::move2()
{
    if (!isSetPos)
    {
        isSetPos = true;
        int x = (rand() % SCREEN_WIDTH / 2) - 50;
        int y = (rand() % 1500) + 100;
        disasterSprite.setPosition(x, -y);
        int valueRandom[] = {0, 1, 2};
        value = valueRandom[rand() % 3];
    }
    disasterSprite.move(value, 3.f);
}

void Disaster::move3()
{
    if (!isSetPos)
    {
        isSetPos = true;
        int x = (rand() % SCREEN_WIDTH / 2 + 30) + SCREEN_WIDTH / 2;
        int y = (rand() % 1500) + 100;
        disasterSprite.setPosition(x, -y);
        int valueRandom[] = {0, -1, -2};
        value = valueRandom[rand() % 3];
    }
    disasterSprite.move(value, 3.f);
}

void Disaster::update()
{
}

void Disaster::draw(sf::RenderTarget *target)
{
    if (isSetPos)
        target->draw(disasterSprite);

    if (debug)
        drawHitBoxEnemy(target);
}

void Disaster::drawHitBoxEnemy(sf::RenderTarget *target)
{
    // Draw the outline of the hitbox
    sf::IntRect hitbox = get_hitbox();
    sf::RectangleShape hitboxOutline(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxOutline.setPosition(sf::Vector2f(hitbox.left, hitbox.top));
    hitboxOutline.setFillColor(sf::Color::Transparent);
    hitboxOutline.setOutlineColor(sf::Color::White); // Set the outline color
    hitboxOutline.setOutlineThickness(2.0f);         // Set the outline thickness
    target->draw(hitboxOutline);
}

sf::IntRect Disaster::get_hitbox() const
{
    return sf::IntRect(disasterSprite.getGlobalBounds().left,
                       disasterSprite.getGlobalBounds().top,
                       disasterSprite.getGlobalBounds().width,
                       disasterSprite.getGlobalBounds().height);
}