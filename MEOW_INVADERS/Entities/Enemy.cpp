#include "Enemy.h"

Enemy::Enemy(int i_type, int i_x, int i_y) : direction(0 == (i_y / BASE_SIZE) % 2 ? -1 : 1),
                                                                        health(1 + i_type),
                                                                        hit_timer(0),
                                                                        type(i_type),
                                                                        x(i_x),
                                                                        y(i_y)
{
}

Enemy::~Enemy()
{
}

int Enemy::get_health() const
{
    return health;
}

int Enemy::get_hit_timer() const
{
    return hit_timer;
}

int Enemy::get_type() const
{
    return type;
}

int Enemy::get_x() const
{
    return x;
}

int Enemy::get_y() const
{
    return y;
}

void Enemy::hit()
{
    hit_timer = ENEMY_HIT_TIMER_DURATION;
}

void Enemy::move()
{
    if (0 != direction)
    {
        if ((1 == direction && x == BOUNDARY_WIDTH - 2 * BASE_SIZE) || (-1 == direction && x == BASE_SIZE))
        {
            // Once we reach the edge, we start moving down until we reach the next row.
            direction = 0;

            y += ENEMY_MOVE_SPEED;
        }
        else
        {
            // Moving horizontally.
            // x = std::clamp<short>(x + ENEMY_MOVE_SPEED * direction, BASE_SIZE, BOUNDARY_WIDTH - 2 * BASE_SIZE);
            x += ENEMY_MOVE_SPEED;
        }
    }
    else
    {
        y = std::min<int>(y + ENEMY_MOVE_SPEED, BASE_SIZE * ceil(y / static_cast<float>(BASE_SIZE)));

        if (y == BASE_SIZE * ceil(y / static_cast<float>(BASE_SIZE)))
        {
            // Moving in a snake pattern. We use the modulo operator to decide whether to move left or right.
            direction = 0 == (y / BASE_SIZE) % 2 ? -1 : 1;
        }
    }
}

void Enemy::shoot(std::vector<Bullet> &i_enemy_bullets)
{
    switch (type)
    {
    case 0:
    {
        i_enemy_bullets.push_back(Bullet(0, ENEMY_BULLET_SPEED, x, y));
        break;
    }
    case 1:
    {
        i_enemy_bullets.push_back(Bullet(0.125f * ENEMY_BULLET_SPEED, ENEMY_BULLET_SPEED, x, y));
        i_enemy_bullets.push_back(Bullet(-0.125f * ENEMY_BULLET_SPEED, ENEMY_BULLET_SPEED, x, y));
        break;
    }
    case 2:
    {
        i_enemy_bullets.push_back(Bullet(0, ENEMY_BULLET_SPEED, x, y));
        i_enemy_bullets.push_back(Bullet(0.25f * ENEMY_BULLET_SPEED, ENEMY_BULLET_SPEED, x, y));
        i_enemy_bullets.push_back(Bullet(-0.25f * ENEMY_BULLET_SPEED, ENEMY_BULLET_SPEED, x, y));
        break;
    }
    }
}

void Enemy::update()
{
    if (0 < hit_timer)
    {
        if (1 == hit_timer)
        {
            // Use a conditional statement to handle the comparison
            if (health > 0)
            {
                --health;
            }
            else
            {
                health = 0; // Ensure health doesn't go negative
            }
        }

        --hit_timer;
    }
}

sf::IntRect Enemy::get_hitbox() const
{
    return sf::IntRect(x + 0.25f * BASE_SIZE, y + 0.25f * BASE_SIZE, 0.5f * BASE_SIZE, 0.5f * BASE_SIZE);
}