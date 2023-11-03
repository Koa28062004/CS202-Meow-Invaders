#include "Bullet.h"

Bullet::Bullet(float i_step_x, float i_step_y, short i_x, short i_y) : dead(0),
                   real_x(i_x),
                   real_y(i_y),
                   step_x(i_step_x),
                   step_y(i_step_y),
                   x(i_x),
                   y(i_y)
{
    previous_x.fill(x);
    previous_y.fill(y);
}

Bullet::~Bullet()
{
}

void Bullet::bulletDead()
{
    dead = 1;
}

void Bullet::update()
{
    if (!dead)
    {
        real_x += step_x;
        real_y += step_y;

        for (unsigned char a = 0; a < previous_x.size() - 1; a++)
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

// sf::IntRect get_hitbox() const
// {
//     // Smaller hitboxes make the game so much better!
//     return sf::IntRect(x + 0.375f * 16, y + 0.375f * 16, 0.25f * 16, 0.25f * 16);
// }