#include "Bullet.h"

Bullet::Bullet(int i_step_x, int i_step_y, int i_x, int i_y, sf::Sprite bulletSprite) : dead(0),
                                                                                        real_x(i_x),
                                                                                        real_y(i_y),
                                                                                        step_x(i_step_x),
                                                                                        step_y(i_step_y),
                                                                                        x(i_x),
                                                                                        y(i_y),
                                                                                        bullet(bulletSprite),
                                                                                        type(0)
{
    previous_x.fill(x);
    previous_y.fill(y);
}

Bullet::~Bullet()
{
}

void Bullet::saveGame(std::string fileName)
{
    std::ofstream ofs;
    ofs.open(fileName, std::ios::app);

    ofs << step_x << " " << step_y << " " << x << " " << y << " " << type << std::endl;

    ofs.close();
}

void Bullet::bulletDead()
{
    this->dead = 1;
}

bool Bullet::getDead()
{
    return this->dead;
}

void Bullet::update()
{
    if (!dead)
    {
        real_x += step_x;
        real_y += step_y;

        for (unsigned int a = 0; a < previous_x.size() - 1; a++)
        {
            previous_x[a] = previous_x[1 + a];
            previous_y[a] = previous_y[1 + a];
        }

        previous_x[previous_x.size() - 1] = x;
        previous_y[previous_y.size() - 1] = y;

        x = round(real_x);
        y = round(real_y);
    }
}

sf::IntRect Bullet::get_hitbox() const
{
    return sf::IntRect(x + 12, y + 5,
                       bullet.getGlobalBounds().width - 22,
                       bullet.getGlobalBounds().height - 7);
}

void Bullet::drawHitBoxBullet(sf::RenderTarget *target)
{
    // Draw the outline of the hitbox
    sf::IntRect hitbox = get_hitbox();
    sf::RectangleShape hitboxOutline(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxOutline.setPosition(sf::Vector2f(hitbox.left, hitbox.top));
    hitboxOutline.setFillColor(sf::Color::Transparent);
    hitboxOutline.setOutlineColor(sf::Color::Magenta); // Set the outline color
    hitboxOutline.setOutlineThickness(2.0f);           // Set the outline thickness
    target->draw(hitboxOutline);
}