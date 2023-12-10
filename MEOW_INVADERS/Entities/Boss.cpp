#include "Boss.h"

void Boss::initBoss()
{
    if (!bossTex1.loadFromFile("assets/images/boss" + std::to_string(type) + ".png"))
    {
    }

    if (!bossTex2.loadFromFile("assets/images/boss" + std::to_string(type) + ".png"))
    {
    }

    if (!bulletTex.loadFromFile("assets/images/bossBullet.png"))
    {
    }
}

Boss::Boss(int i_type, sf::Sprite boss_bullet_sprite) : type(i_type),
                                                        health(BOSS_HEALTH),
                                                        isSetPos(false),
                                                        direction(1),
                                                        bulletSprite(boss_bullet_sprite),
                                                        timer(10),
                                                        explosion(EXPLOSION_BOSS_ANIMATION_SPEED, 140, 6),
                                                        dead_animation_over(0)

{
    initBoss();
    bossSprite.setPosition(100, -300);

    if (type == 1)
    {
        bossSprite.setTexture(bossTex1);
        bossSprite.setScale(sf::Vector2f(0.9, 0.9));
    }

    if (type == 2)
    {
        bossSprite.setTexture(bossTex2);
        bossSprite.setScale(sf::Vector2f(0.7, 0.7));
    }
}

Boss::~Boss()
{
}

bool Boss::getDead()
{
    return dead_animation_over;
}

int Boss::get_health()
{
    return health;
}

void Boss::hit()
{
    if (health > 0 && timer >= 0)
    {
        --health;
        timer = 10;
    }
    else
    {
        health = 0;
    }
}

void Boss::movement()
{
    if (health <= 0)
        return;
    if (!isSetPos)
    {
        bossSprite.setPosition(100, -300);
        isSetPos = true;
    }

    int values1[] = {3, 4};
    int values2[] = {-3, -4};

    if (bossSprite.getPosition().y <= -100.f)
    {
        randomValueY = values1[rand() % 2];
    }
    else if (bossSprite.getPosition().y + bossSprite.getGlobalBounds().height / 2 >= SCREEN_HEIGHT - 0.f)
    {
        randomValueY = values2[rand() % 2];
    }

    if (bossSprite.getPosition().x <= -20.f)
    {
        randomValueX = values1[rand() % 2];
    }
    else if (bossSprite.getPosition().x + bossSprite.getGlobalBounds().width / 2 >= SCREEN_WIDTH - 0.f)
    {
        randomValueX = values2[rand() % 2];
    }

    bossSprite.move(randomValueX, randomValueY);
}

void Boss::update()
{
    if (timer > 0)
    {
        --timer;
    }
    else
    {
        timer = 0;
    }

    if (health == 0)
    {
        dead_animation_over = explosion.update();
    }
}

void Boss::shoot(std::vector<Bullet> &i_boss_bullets)
{
    if (health <= 0)
        return;

    sf::Vector2f bossCenter = {bossSprite.getPosition().x + bossSprite.getGlobalBounds().width / 2,
                               bossSprite.getPosition().y + bossSprite.getGlobalBounds().height / 2};

    i_boss_bullets.push_back(Bullet(0, ENEMY_BULLET_SPEED, bossCenter.x, bossCenter.y, bulletSprite));
    i_boss_bullets.push_back(Bullet(2, -ENEMY_BULLET_SPEED, bossCenter.x, bossCenter.y, bulletSprite));
    i_boss_bullets.push_back(Bullet(2, ENEMY_BULLET_SPEED, bossCenter.x, bossCenter.y, bulletSprite));
    i_boss_bullets.push_back(Bullet(-2, -ENEMY_BULLET_SPEED, bossCenter.x, bossCenter.y, bulletSprite));
    i_boss_bullets.push_back(Bullet(-2, ENEMY_BULLET_SPEED, bossCenter.x, bossCenter.y, bulletSprite));
    i_boss_bullets.push_back(Bullet(0, -ENEMY_BULLET_SPEED, bossCenter.x, bossCenter.y, bulletSprite));
}

void Boss::draw(sf::RenderTarget *target)
{
    if (isSetPos)
    {
        if (health > 0)
        {
            if (type == 1)
            {
                bossSprite.setTexture(bossTex1);
                bossSprite.setScale(sf::Vector2f(0.9, 0.9));
            }

            if (type == 2)
            {
                bossSprite.setTexture(bossTex2);
                bossSprite.setScale(sf::Vector2f(0.7, 0.7));
            }

            target->draw(bossSprite);
        }
        else
        {
            int i_x = bossSprite.getPosition().x;
            int i_y = bossSprite.getPosition().y;
            explosion.drawBossExplosion(i_x, i_y, target);
        }
    }

    if (debug)
        drawHitBoxBoss(target);
}

void Boss::drawHitBoxBoss(sf::RenderTarget *target)
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

sf::IntRect Boss::get_hitbox() const
{
    return sf::IntRect(bossSprite.getGlobalBounds().left + 50,
                       bossSprite.getGlobalBounds().top + 30,
                       bossSprite.getGlobalBounds().width - 100,
                       bossSprite.getGlobalBounds().height - 60);
}

void Boss::setHealth(int health)
{
    this->health = health;
}

void Boss::setIsSetPos(bool isSetPos)
{
    this->isSetPos = isSetPos;
}

void Boss::setPosition(int x, int y)
{
    bossSprite.setPosition(x, y);
}

void Boss::loadGameExplosion(std::ifstream &ifs)
{
    // explosions
    int animation_iterator;
    int animation_speed;
    int current_frame;
    int frame_width;

    ifs >> animation_iterator >> animation_speed >> current_frame >> frame_width;
    explosion.setVars(animation_iterator, animation_speed, current_frame, frame_width);
}

void Boss::saveGame(std::string fileName)
{
    std::ofstream ofs;
    ofs.open(fileName, std::ios::app);

    ofs << type << " " << health << " " << isSetPos << " "
        << bossSprite.getPosition().x << " " << bossSprite.getPosition().y << std::endl;

    ofs.close();
}