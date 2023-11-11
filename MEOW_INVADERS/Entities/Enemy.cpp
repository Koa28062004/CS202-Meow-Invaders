#include "Enemy.h"

int Enemy::collectiveDirection = 1;

Enemy::Enemy(int i_type, int i_x, int i_y, sf::Texture *enemyTex, sf::Sprite enemyBulletSprite) : direction(0 == (i_y / BASE_SIZE) % 2 ? -1 : 1),
                                                                                                  health(1 + i_type),
                                                                                                  hit_timer(0),
                                                                                                  type(i_type),
                                                                                                  x(i_x),
                                                                                                  y(i_y),

                                                                                                  enemyBullet(enemyBulletSprite)
{
    enemySprite.setTexture(*enemyTex);
    enemySprite.setScale(sf::Vector2f(0.2, 0.2));
    enemySprite.setPosition(x, y);
}

Enemy::~Enemy()
{
    // delete enemySprite;
    // delete enemyTex;
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
    if (health > 0)
    {
        --health;
    }
    else
    {
        health = 0; // Ensure health doesn't go negative
    }
}

void Enemy::movement(int level)
{
    switch (level)
    {
    case 0:
        move0();
        break;
        // case 1:
        //     move1();
        //     break;
        // case 2:
        //     move2();
        //     break;
    }
}

void Enemy::move0()
{
    if (enemySprite.getPosition().x <= 10.f)
        collectiveDirection = 1;
    if (enemySprite.getPosition().x >= SCREEN_WIDTH)
    {
        collectiveDirection = -1;
    }
    if (collectiveDirection == 1)
        enemySprite.move(2.f, 0);
    else
        enemySprite.move(-2.f, 0);
}

void Enemy::shoot(std::vector<Bullet> &i_enemy_bullets)
{
    switch (type)
    {
    case 0:
    {
        i_enemy_bullets.push_back(Bullet(0, ENEMY_BULLET_SPEED, enemySprite.getPosition().x, enemySprite.getPosition().y, enemyBullet));
        break;
    }
    case 1:
    {
        i_enemy_bullets.push_back(Bullet(0.125f * ENEMY_BULLET_SPEED, ENEMY_BULLET_SPEED, enemySprite.getPosition().x, enemySprite.getPosition().y, enemyBullet));
        i_enemy_bullets.push_back(Bullet(-0.125f * ENEMY_BULLET_SPEED, ENEMY_BULLET_SPEED, enemySprite.getPosition().x, enemySprite.getPosition().y, enemyBullet));
        break;
    }
    case 2:
    {
        i_enemy_bullets.push_back(Bullet(0, ENEMY_BULLET_SPEED, enemySprite.getPosition().x, enemySprite.getPosition().y, enemyBullet));
        i_enemy_bullets.push_back(Bullet(0.25f * ENEMY_BULLET_SPEED, ENEMY_BULLET_SPEED, enemySprite.getPosition().x, enemySprite.getPosition().y, enemyBullet));
        i_enemy_bullets.push_back(Bullet(-0.25f * ENEMY_BULLET_SPEED, ENEMY_BULLET_SPEED, enemySprite.getPosition().x, enemySprite.getPosition().y, enemyBullet));
        break;
    }
    }
}

void Enemy::update()
{
}

void Enemy::draw(sf::RenderTarget *target)
{
    target->draw(enemySprite);

    if (debug)
        drawHitBoxEnemy(target);
}

void Enemy::drawHitBoxEnemy(sf::RenderTarget *target)
{
    // Draw the outline of the hitbox
    sf::IntRect hitbox = get_hitbox();
    sf::RectangleShape hitboxOutline(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxOutline.setPosition(sf::Vector2f(hitbox.left, hitbox.top));
    hitboxOutline.setFillColor(sf::Color::Transparent);
    hitboxOutline.setOutlineColor(sf::Color::Red); // Set the outline color
    hitboxOutline.setOutlineThickness(2.0f);       // Set the outline thickness
    target->draw(hitboxOutline);
}

sf::IntRect Enemy::get_hitbox() const
{
    return sf::IntRect(enemySprite.getGlobalBounds().left,
                       enemySprite.getGlobalBounds().top,
                       enemySprite.getGlobalBounds().width,
                       enemySprite.getGlobalBounds().height);
}