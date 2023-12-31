#include "Player.h"

void Player::initExplosion()
{
    sf::Texture tmpTex;
    sf::Sprite tmpSprite;
    if (!tmpTex.loadFromFile("assets/images/explosion1.png"))
    {
    }
    // tmpSprite.setTexture(tmpTex);
    // tmpSprite.setScale(sf::Vector2f(0.4, 0.4));
    playerExplosions.push_back(tmpTex);

    if (!tmpTex.loadFromFile("assets/images/explosion2.png"))
    {
    }
    // tmpSprite.setTexture(tmpTex);
    // tmpSprite.setScale(sf::Vector2f(0.4, 0.4));
    playerExplosions.push_back(tmpTex);

    if (!tmpTex.loadFromFile("assets/images/explosion3.png"))
    {
    }
    // tmpSprite.setTexture(tmpTex);
    // tmpSprite.setScale(sf::Vector2f(0.4, 0.4));
    playerExplosions.push_back(tmpTex);

    if (!tmpTex.loadFromFile("assets/images/explosion4.png"))
    {
    }
    // tmpSprite.setTexture(tmpTex);
    // tmpSprite.setScale(sf::Vector2f(0.4, 0.4));
    playerExplosions.push_back(tmpTex);

    if (!tmpTex.loadFromFile("assets/images/explosion5.png"))
    {
    }
    // tmpSprite.setTexture(tmpTex);
    // tmpSprite.setScale(sf::Vector2f(0.4, 0.4));
    playerExplosions.push_back(tmpTex);
}

// Init Keys
void Player::initKeys()
{
    std::ifstream ifs("config/supportedKeys.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        int key_value = 0;
        while (ifs >> key >> key_value)
        {
            supportedKeys[key] = key_value;
        }
    }

    ifs.close();
}

// Init Keybinds
void Player::initKeybinds()
{
    std::ifstream ifs("config/gameState_keybinds.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";

        while (ifs >> key >> key2)
        {
            keybinds[key] = supportedKeys.at(key2);
        }
    }

    ifs.close();
}

void Player::reset()
{
    dead = 0;
    reload_timer = 0;
    power_timer = 0;
    current_power = 0;
    dead_animation_over = 0;
    shield_animation_over = 0;

    player_bullets.clear();
    powers.clear();
}

Player::Player(const float &x, const float &y, sf::Texture *texture) : generator(std::chrono::system_clock::now().time_since_epoch().count()),
                                                                       explosion(EXPLOSION_ANIMATION_SPEED, 140, 4),
                                                                       fire_timer(-1),
                                                                       timer(-1)
{
    initSprites(texture);
    reset();
    setEntityPosition(x, y);

    initKeys();
    initKeybinds();
    initExplosion();

    // Set bullet sprites
    if (!bullet_texture.loadFromFile("assets/images/playerBullet.png"))
    {
        throw std::runtime_error("Error::Player::Can not load playerBullet.png");
    }
    bullet_sprite.setTexture(bullet_texture);
    bullet_sprite.setScale(sf::Vector2f(0.25, 0.25));
}

Player::~Player()
{
    playerExplosions.clear();
}

void Player::die()
{
    if (current_power == 3)
    {
        shield_animation_over = 0;
        current_power = 0;
        timer = 10;
    }
    else if (current_power != 3 && timer <= 0)
        dead = 1;
}

sf::Vector2f Player::getPlayerPos()
{
    sf::Vector2f playerPosition = {playerSprite->getPosition().x, playerSprite->getPosition().y};
    return playerPosition;
}

bool Player::get_dead() const
{
    return dead;
}

bool Player::get_dead_animation_over() const
{
    return dead_animation_over;
}

void Player::checkBulletOutside(Bullet &bullet)
{
    if (bullet.y <= 2)
    {
        bullet.bulletDead();
    }
}

void Player::updatePlayerPosition(sf::RenderWindow *mWindow)
{
    if (!playerSprite)
        return;

    sf::Vector2f playerPos = playerSprite->getPosition();

    if (playerPos.x <= playerSprite->getGlobalBounds().width / 2.f)
        playerPos.x = playerSprite->getGlobalBounds().width / 2.f;
    if (playerPos.x >= mWindow->getSize().x - playerSprite->getGlobalBounds().width / 2.f)
        playerPos.x = mWindow->getSize().x - playerSprite->getGlobalBounds().width / 2.f;
    if (playerPos.y <= playerSprite->getGlobalBounds().height / 2.f)
        playerPos.y = playerSprite->getGlobalBounds().height / 2.f;
    if (playerPos.y >= mWindow->getSize().y - playerSprite->getGlobalBounds().height / 2.f)
        playerPos.y = mWindow->getSize().y - playerSprite->getGlobalBounds().height / 2.f;

    playerSprite->setPosition(playerPos);
}

void Player::updateBullets()
{
    if (reload_timer == 0 && !dead)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("FIRE"))))
        {
            playerSprite->setPosition(playerSprite->getPosition().x, playerSprite->getPosition().y + 11.f);

            if (1 == current_power)
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

            if (2 == current_power)
            {
                player_bullets.push_back(Bullet(2, -PLAYER_BULLET_SPEED, playerCenter.x - 0.375f * BASE_SIZE, playerCenter.y, bullet_sprite));
                player_bullets.push_back(Bullet(-2, -PLAYER_BULLET_SPEED, playerCenter.x + 0.375f * BASE_SIZE, playerCenter.y, bullet_sprite));
            }
        }
    }
    else
    {
        --reload_timer;
    }
}

void Player::updatePower()
{
    std::uniform_int_distribution<int> distribution(0, 2500);
    int randomPower = distribution(generator);
    switch (randomPower)
    {
    case 1:
        powers.push_back(Power(1, &powerTex1));
        break;
    case 2:
        powers.push_back(Power(2, &powerTex2));
        break;
    case 3:
        powers.push_back(Power(3, &powerTex3));
        break;
    default:
        break;
    }

    if (!dead)
    {
        for (Power &power : powers)
        {
            power.move();
            power.checkPowerOutside();
            if (get_hitbox().intersects(power.get_hitbox()))
            {
                current_power = power.getType();
                if (power.getType() == 3)
                {
                }
                power.hit();
            }
        }
    }

    // delete power whenever it hit.
    powers.erase(remove_if(powers.begin(), powers.end(), [](Power &power)
                           { return 1 == power.getDead(); }),
                 powers.end());
}

void Player::restartPower()
{
    if (current_power > 0)
    {
        if (power_timer <= 0)
        {
            power_timer = POWER_DURATION;
        }
        else
        {
            --power_timer;
        }
    }
    else
    {
        power_timer = 0;
    }

    if (power_timer == 0)
    {
        current_power = -1;
    }
    // if (0 == shield_animation_over)
    // {
    //     shield_animation_over = explosion.update();
    // }
}

void Player::update(std::vector<Bullet> &enemy_bullets,
                    std::vector<Enemy> &enemies,
                    std::vector<Disaster> &disasters,
                    std::vector<Disaster> &randomDisasters,
                    std::vector<Boss> &bosses,
                    std::vector<Bullet> &boss_bullets,
                    sf::RenderWindow *mWindow)
{
    --timer;
    initKeybinds();
    updatePlayerPosition(mWindow);
    restartPower();
    updatePower();
    updateBullets();

    for (Bullet &bullet : player_bullets)
    {
        bullet.update();
        checkBulletOutside(bullet);

        if (0 == bullet.getDead())
        {
            // Optionally, you can add logic for handling collisions with enemies here
            for (Enemy &enemy : enemies)
            {
                if (bullet.get_hitbox().intersects(enemy.get_hitbox()) && enemy.get_health() > 0)
                {
                    bullet.bulletDead();
                    enemy.hit();
                }
            }

            for (Disaster &disaster : disasters)
            {
                if (bullet.get_hitbox().intersects(disaster.get_hitbox()) && disaster.get_health() > 0)
                {
                    bullet.bulletDead();
                    disaster.hit();
                }
            }

            for (Disaster &disaster : randomDisasters)
            {
                if (bullet.get_hitbox().intersects(disaster.get_hitbox()) && disaster.get_health() > 0)
                {
                    bullet.bulletDead();
                    disaster.hit();
                }
            }

            for (Boss &boss : bosses)
            {
                if (bullet.get_hitbox().intersects(boss.get_hitbox()) && boss.get_health() > 0)
                {
                    bullet.bulletDead();
                    boss.hit();
                }
            }
        }
    }

    if (!dead)
    {
        for (Bullet &enemyBullet : enemy_bullets)
        {
            if (get_hitbox().intersects(enemyBullet.get_hitbox()))
            {
                die();
                enemyBullet.bulletDead();
            }
        }

        for (Bullet &bossBullet : boss_bullets)
        {
            if (get_hitbox().intersects(bossBullet.get_hitbox()))
            {
                die();
                bossBullet.bulletDead();
            }
        }

        for (Enemy &enemy : enemies)
        {
            if (get_hitbox().intersects(enemy.get_hitbox()) && enemy.get_health() > 0)
            {
                die();
                enemy.hit();
            }
        }

        for (Disaster &disaster : disasters)
        {
            if (get_hitbox().intersects(disaster.get_hitbox()) && disaster.get_health() > 0)
            {
                die();
                disaster.hit();
            }
        }

        for (Disaster &randomDisaster : randomDisasters)
        {
            if (get_hitbox().intersects(randomDisaster.get_hitbox()) && randomDisaster.get_health() > 0)
            {
                die();
                randomDisaster.hit();
            }
        }

        for (Boss &boss : bosses)
        {
            if (get_hitbox().intersects(boss.get_hitbox()) && boss.get_health() > 0)
            {
                die();
                boss.hit();
            }
        }
    }
    else if (0 == dead_animation_over)
    {
        dead_animation_over = explosion.update();
    }

    player_bullets.erase(remove_if(player_bullets.begin(), player_bullets.end(), [](Bullet &bullet)
                                   { return 1 == bullet.getDead(); }),
                         player_bullets.end());
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

void Player::drawBounds(sf::RenderTarget *target)
{
    sf::Vector2f playerPos = playerSprite->getPosition();
    float playerRadius = std::max(playerSprite->getGlobalBounds().width, playerSprite->getGlobalBounds().height) / 2.0f;

    sf::CircleShape boundsCircle(playerRadius);
    boundsCircle.setOrigin(playerRadius, playerRadius);
    boundsCircle.setPosition(playerPos);
    boundsCircle.setFillColor(sf::Color::Transparent);
    boundsCircle.setOutlineThickness(5.0f);
    boundsCircle.setOutlineColor(sf::Color::White);

    if (current_power == 1)
        boundsCircle.setOutlineColor(sf::Color(0x4A, 0xBA, 0x59, 0xFF));
    if (current_power == 2)
        boundsCircle.setOutlineColor(sf::Color(0xF0, 0x33, 0x4C, 0xFF));
    if (current_power == 3)
        boundsCircle.setOutlineColor(sf::Color(0x20, 0xAF, 0xB1, 0xFF));

    target->draw(boundsCircle);
}

void Player::draw(sf::RenderTarget *target)
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

    for (Power &power : powers)
    {
        power.draw(target);
    }

    if (current_power > 0)
        drawBounds(target);

    // Draw the player
    if (this->playerSprite)
    {
        if (!dead)
            target->draw(*this->playerSprite);
        else if (0 == dead_animation_over && dead)
        {
            int current_frame = explosion.getCurrentFrame();
            explosion.drawExplosion(playerSprite->getPosition().x - playerSprite->getGlobalBounds().width / 2, playerSprite->getPosition().y - playerSprite->getGlobalBounds().height / 2, target, playerExplosions[current_frame]);
        }
    }
}

sf::IntRect Player::get_hitbox() const
{
    return sf::IntRect(playerSprite->getGlobalBounds().left + 7,
                       playerSprite->getGlobalBounds().top + 13,
                       playerSprite->getGlobalBounds().width - 14,
                       playerSprite->getGlobalBounds().height - 25);
}

void Player::setVars(bool dead, bool isShoot)
{
    this->dead = dead;
    this->isShoot = isShoot;
}

void Player::setTimer(int reload_timer, int fire_timer, int timer, int power_timer)
{
    this->reload_timer = reload_timer;
    this->fire_timer = fire_timer;
    this->timer = timer;
    this->power_timer = power_timer;
}

void Player::setAnimation(int current_power, bool dead_animation_over, bool shield_animation_over)
{
    this->current_power = current_power;
    this->dead_animation_over = dead_animation_over;
    this->shield_animation_over = shield_animation_over;
}

void Player::loadGame(std::ifstream &ifs)
{
    ifs >> dead >> isShoot >> reload_timer >> fire_timer >>
        timer >> power_timer >> current_power >> dead_animation_over >> shield_animation_over;

    // player bullets
    player_bullets.clear();
    int size;
    ifs >> size;
    int step_x, step_y, x, y, type;
    for (int i = 0; i < size; ++i)
    {
        ifs >> step_x >> step_y >> x >> y >> type;
        player_bullets.push_back(Bullet(step_x, step_y, x, y, bullet_sprite));
    }

    // powers
    powers.clear();
    int power_size;
    int power_type, i_x, i_y;
    bool power_dead, power_isSetPos;
    ifs >> power_size;
    for (int i = 0; i < power_size; ++i)
    {
        ifs >> power_type >> power_dead >> power_isSetPos >> i_x >> i_y;
        switch (power_type)
        {
        case 1:
            powers.push_back(Power(1, &powerTex1));
            break;
        case 2:
            powers.push_back(Power(2, &powerTex2));
            break;
        case 3:
            powers.push_back(Power(3, &powerTex3));
            break;
        }
        powers[powers.size() - 1].setDead(power_dead);
        powers[powers.size() - 1].setIsSetPos(power_isSetPos);
        powers[powers.size() - 1].setPosition(i_x, i_y);
    }

    // explosions
    int animation_iterator;
    int animation_speed;
    int current_frame;
    int frame_width;

    ifs >> animation_iterator >> animation_speed >> current_frame >> frame_width;
    explosion.setVars(animation_iterator, animation_speed, current_frame, frame_width);
}

void Player::saveGame(std::string fileName)
{
    std::ofstream ofs;
    ofs.open(fileName, std::ios::app);

    ofs << dead << " " << isShoot << " "
        << " " << reload_timer << " " << fire_timer << " " << timer << " "
        << power_timer << " " << current_power << " " << dead_animation_over << " " << shield_animation_over
        << std::endl;

    // player bullets
    ofs << player_bullets.size() << std::endl;
    for (Bullet &bullet : player_bullets)
    {
        bullet.saveGame(fileName);
    }

    // powers
    ofs << powers.size() << std::endl;
    for (Power &power : powers)
    {
        power.saveGame(fileName);
    }

    // Animation
    explosion.saveGame(fileName);

    ofs.close();
}