#include "Player.h"

void Player::reset()
{
    dead = 0;
    dead_animation_over = 0;
    shield_animation_over = 1;

    current_power = 0;
    reload_timer = 0;

    power_timer = 0;

    player_bullets.clear();
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

bool Player::get_dead() const
{
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
                                        playerSprite->getPosition().y - playerSprite->getGlobalBounds().height / 2);

            player_bullets.push_back(Bullet(0, -PLAYER_BULLET_SPEED, playerCenter.x, playerCenter.y, bullet_sprite));
        }
    }
    else
    {
        --reload_timer;
    }
}

void Player::checkBulletOutside(Bullet &bullet)
{
    if (bullet.y <= 2)
    {
        bullet.bulletDead();
    }
}

void Player::update(std::vector<Bullet> &enemy_bullets,
                    std::vector<Enemy> &enemies)
{
    if (!dead)
    {
        updateBullets();
        for (Bullet &enemyBullet : enemy_bullets)
        {
            if (get_hitbox().intersects(enemyBullet.get_hitbox()))
            {
                // dead = 1;
                enemyBullet.dead = 1;
                std::cout << "Dead" << '\n';
            }
        }

        for (Enemy &enemy : enemies)
        {
            if (get_hitbox().intersects(enemy.get_hitbox()))
            {
                // dead = 1;
                enemy.dead = 1;
                std::cout << "Dead" << '\n';
            }
        }
    }

    for (Bullet &bullet : player_bullets)
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

    player_bullets.erase(remove_if(player_bullets.begin(), player_bullets.end(), [](const Bullet &bullet)
                                   { return 1 == bullet.dead; }),
                         player_bullets.end());

    enemy_bullets.erase(remove_if(enemy_bullets.begin(), enemy_bullets.end(), [](const Bullet &enemyBullet)
                                  { return 1 == enemyBullet.dead; }),
                        enemy_bullets.end());

    enemies.erase(remove_if(enemies.begin(), enemies.end(), [](const Enemy &enemy)
                            { return 1 == enemy.dead; }),
                  enemies.end());
}

void Player::drawHitBoxPlayer(sf::RenderTarget *target)
{
    // Draw the outline of get_hitbox of player
    sf::IntRect hitbox = get_hitbox();
    sf::RectangleShape hitboxOutline(sf::Vector2f(hitbox.width, hitbox.height));
    hitboxOutline.setPosition(sf::Vector2f(hitbox.left, hitbox.top));
    hitboxOutline.setFillColor(sf::Color::Transparent);
    hitboxOutline.setOutlineColor(sf::Color::Yellow); // Set the outline color
    hitboxOutline.setOutlineThickness(2.0f);          // Set the outline thickness
    target->draw(hitboxOutline);
}

void Player::draw(sf::RenderTarget *target)
{
    if (!dead)
    {
        if (debug)
            drawHitBoxPlayer(target);

        // Draw the bullet
        for (Bullet &bullet : player_bullets)
        {
            bullet_sprite.setPosition(bullet.x, bullet.y);
            target->draw(bullet_sprite);
            
            if (debug)
                bullet.drawHitBoxBullet(target);
        }

        // Draw the player
        if (this->playerSprite)
            target->draw(*this->playerSprite);
    }
    else
    {
    }
}

sf::IntRect Player::get_hitbox() const
{
    return sf::IntRect(playerSprite->getGlobalBounds().left,
                       playerSprite->getGlobalBounds().top,
                       playerSprite->getGlobalBounds().width,
                       playerSprite->getGlobalBounds().height);
}