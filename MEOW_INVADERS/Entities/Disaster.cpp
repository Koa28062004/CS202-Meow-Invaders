#include "Disaster.h"

Disaster::Disaster(int type, sf::Texture *disasterTex) : health(type),
                                                         isSetPos(false),
                                                         explosion(EXPLOSION_ANIMATION_SPEED, 140, 4),
                                                         dead_animation_over(0)
{
    disasterSprite.setTexture(*disasterTex);
    disasterSprite.setScale(sf::Vector2f(0.25, 0.25));
    disasterSprite.setPosition(-200.f, -200.f);
    this->type = type;
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
    return dead_animation_over;
}

int Disaster::get_health() {
    return health;
}

void Disaster::checkOutside()
{
    if (disasterSprite.getPosition().y >= SCREEN_HEIGHT + 5.f)
    {
        health = 0;
    }
}

void Disaster::movement(int level, int randomMove)
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
    default:
        switch (randomMove)
        {
        case 0:
            move3();
            break;
        case 1:
            move1();
            break;
        case 2:
            move2();
            break;
        default:
            // Handle unexpected cases or errors
            break;
        }
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

void Disaster::setHealth(int health)
{
    this->health = health;
}

void Disaster::setIsSetPos(bool isSetPos)
{
    this->isSetPos = isSetPos;
}

void Disaster::setPosition(int x, int y)
{
    disasterSprite.setPosition(x, y);
}

void Disaster::update()
{
    if (health == 0)
    {
        dead_animation_over = explosion.update();
    }
}

void Disaster::draw(sf::RenderTarget *target)
{
    if (health != 0)
    {
        if (isSetPos)
            target->draw(disasterSprite);
    }
    else
    {
        int i_x = disasterSprite.getPosition().x;
        int i_y = disasterSprite.getPosition().y;
        explosion.drawEnemyExplosion(i_x, i_y, target);
    }

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
    return sf::IntRect(disasterSprite.getGlobalBounds().left + 15,
                       disasterSprite.getGlobalBounds().top + 13,
                       disasterSprite.getGlobalBounds().width - 25,
                       disasterSprite.getGlobalBounds().height - 25);
}

void Disaster::loadGameExplosion(std::ifstream &ifs)
{
    // explosions
    int animation_iterator;
    int animation_speed;
    int current_frame;
    int frame_width;

    ifs >> animation_iterator >> animation_speed >> current_frame >> frame_width;
    explosion.setVars(animation_iterator, animation_speed, current_frame, frame_width);
}

void Disaster::saveGame(std::string fileName)
{
    std::ofstream ofs;
    ofs.open(fileName, std::ios::app);

    ofs << type << " " << health << " " << isSetPos << " " << disasterSprite.getPosition().x << " " << disasterSprite.getPosition().y << std::endl;

    // save explosion
    explosion.saveGame(fileName);
    ofs.close();
}