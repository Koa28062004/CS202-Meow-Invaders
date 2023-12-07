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
                                                        bulletSprite(boss_bullet_sprite)
{
    initBoss();
    bossSprite.setPosition(100, -300);
}

Boss::~Boss()
{
}

int Boss::getDead()
{
    return health;
}

void Boss::hit()
{
    if (health > 0)
    {
        --health;
    }
    else
    {
        health = 0;
    }
}

void Boss::movement()
{
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
}

void Boss::shoot(std::vector<Bullet> &i_boss_bullets)
{
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