#include "Player.h"

void Player::reset()
{
    dead = 0;
    dead_animation_over = 0;
    shield_animation_over = 1;

    current_power = 0;
    reload_timer = 0;

    power_timer = 0;

    bullets.clear();
}

Player::Player(const float &x, const float &y, sf::Texture *texture)
{
    initSprites(texture);
    reset();
    setEntityPosition(x, y);

    // Set bullet sprites
    if (!bullet_texture.loadFromFile("assets/images/playerBullet.png"))
    {
        throw std::runtime_error("Error::Player::Can not load playerBullet.png");
    }
    bullet_sprite.setTexture(bullet_texture);
    bullet_sprite.setScale(sf::Vector2f(0.3, 0.3));
}

Player::~Player()
{
}

void Player::die()
{
    dead = true;
}

bool Player::get_dead() const {
    return dead;
}

void Player::updateBullets()
{
    if (reload_timer == 0)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (2 == current_power)
            {
                reload_timer = FAST_RELOAD_DURATION;
            }
            else
            {
                reload_timer = RELOAD_DURATION;
            }
            playerCenter = sf::Vector2f(playerSprite->getPosition().x - playerSprite->getGlobalBounds().width / 2,
                                        playerSprite->getPosition().y -  playerSprite->getGlobalBounds().height / 2);

            bullets.push_back(Bullet(0, -PLAYER_BULLET_SPEED, playerCenter.x, playerCenter.y));
        }
    }
    else
    {
        --reload_timer;
    }
}

void Player::checkBulletOutside(Bullet &bullet) {
    if (bullet.y <= 2.f) {
        bullet.bulletDead();    
    }
}

void Player::update()
{
    if (!dead)
    {
        updateBullets();
    }

    for (Bullet &bullet : bullets)
    {
        bullet.update();
        checkBulletOutside(bullet);

        if (0 == bullet.dead)
        {
            // if (1 == i_ufo.check_bullet_collision(i_random_engine, bullet.get_hitbox()))
            // {
            // 	bullet.dead = 1;
            // }
        }
    }

    bullets.erase(remove_if(bullets.begin(), bullets.end(), [](const Bullet& i_bullet)
    {
    	return 1 == i_bullet.dead;
    }), bullets.end());
}

void Player::draw(sf::RenderTarget *target)
{
    if (!dead)
    {
        // Draw the bullet
        for (const Bullet &bullet : bullets)
        {
            bullet_sprite.setPosition(bullet.x, bullet.y);
            target->draw(bullet_sprite);
        }

        // Draw the player
        if (this->playerSprite)
            target->draw(*this->playerSprite);
    }
    else
    {
    }
}