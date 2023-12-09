#include "Enemy.h"

int Enemy::collectiveDirection = 1;

void Enemy::initEnemy1()
{
    sf::Texture tmp;
    if (!tmp.loadFromFile("assets/images/enemy11.png"))
    {
    }
    animations.push_back(tmp);

    if (!tmp.loadFromFile("assets/images/enemy12.png"))
    {
    }
    animations.push_back(tmp);
    enemies.push_back(animations);
    animations.clear();
}

void Enemy::initEnemy2()
{
    sf::Texture tmp;
    if (!tmp.loadFromFile("assets/images/enemy21.png"))
    {
    }
    animations.push_back(tmp);

    if (!tmp.loadFromFile("assets/images/enemy22.png"))
    {
    }
    animations.push_back(tmp);
    enemies.push_back(animations);
    animations.clear();
}

void Enemy::initEnemy3()
{
    sf::Texture tmp;
    if (!tmp.loadFromFile("assets/images/enemy31.png"))
    {
    }
    animations.push_back(tmp);

    if (!tmp.loadFromFile("assets/images/enemy32.png"))
    {
    }
    animations.push_back(tmp);
    enemies.push_back(animations);
    animations.clear();
}

Enemy::Enemy(int i_type, int i_x, int i_y, sf::Sprite enemyBulletSprite) : health(1 + i_type),
                                                                           hit_timer(0),
                                                                           type(i_type),
                                                                           x(i_x),
                                                                           y(i_y),
                                                                           enemyBullet(enemyBulletSprite),
                                                                           current_frame(0),
                                                                           timeMovement(0),
                                                                           isSetPos(false)

{
    initEnemy1();
    initEnemy2();
    initEnemy3();

    direction = 1;
    // enemySprite.setTexture(*enemyTex);
    // enemySprite.setScale(sf::Vector2f(0.45, 0.45));
    enemySprite.setPosition(-200.f, -200.f);
}

Enemy::~Enemy()
{
    // delete enemySprite;
    // delete enemyTex;
}

// setter
void Enemy::setPosition(int x, int y) {
    enemySprite.setPosition(x, y);
}

void Enemy::setDirection(int direction) {
    this->direction = direction;
}

void Enemy::setHealth(int health) {
    this->health = health;
}

void Enemy::setType(int type) {
    this->type = type;
}

void Enemy::setTime(int hit_timer, int timeMovement) {
    this->hit_timer = hit_timer;
    this->timeMovement = timeMovement;
}


void Enemy::setIsSetPos(bool isSetPos) {
    this->isSetPos = isSetPos;
}

void Enemy::setCurrentFrame(int current_frame) {
    this->current_frame = current_frame;
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

void Enemy::movement(int level, int randomMove)
{
    switch (level)
    {
    case 1:
        move0();
        break;
    case 2:
        move2();
        break;
    case 3:
        move1();
        break;
    default:
        switch (randomMove)
        {
        case 0:
            move0();
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

void Enemy::move2()
{
    if (!isSetPos)
    {
        x = (rand() % SCREEN_WIDTH - 20) + 30;
        y = (rand() % 1700) + 100;
        enemySprite.setPosition(x, -y);
        isSetPos = true;
    }

    if (enemySprite.getPosition().y <= 5.f)
        direction = 1;
    if (enemySprite.getPosition().y >= SCREEN_HEIGHT - 50.f)
    {
        direction = -1;
    }
    if (direction == 1)
        enemySprite.move(0, 1.f);
    else
        enemySprite.move(0, -1.f);
}

void Enemy::move1()
{
    if (!isSetPos)
    {
        enemySprite.setPosition(x, y - 200);
        isSetPos = true;
    }

    int values1[] = {1, 2};
    int values2[] = {-1, -2};

    if (enemySprite.getPosition().y <= 0.f)
    {
        randomValueY = values1[rand() % 2];
    }
    else if (enemySprite.getPosition().y >= SCREEN_HEIGHT - 0.f)
    {
        randomValueY = values2[rand() % 2];
    }

    if (enemySprite.getPosition().x <= 0.f)
    {
        randomValueX = values1[rand() % 2];
    }
    else if (enemySprite.getPosition().x >= SCREEN_WIDTH - 0.f)
    {
        randomValueX = values2[rand() % 2];
    }

    enemySprite.move(randomValueX, randomValueY);
}

void Enemy::move0()
{
    if (!isSetPos)
    {
        enemySprite.setPosition(-x - 50, y);
        isSetPos = true;
    }

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
        i_enemy_bullets[i_enemy_bullets.size() - 1].type = type;
        break;
    }
    case 1:
    {
        i_enemy_bullets.push_back(Bullet(1, ENEMY_BULLET_SPEED, enemySprite.getPosition().x, enemySprite.getPosition().y, enemyBullet));
        i_enemy_bullets[i_enemy_bullets.size() - 1].type = type;

        i_enemy_bullets.push_back(Bullet(-1, ENEMY_BULLET_SPEED, enemySprite.getPosition().x, enemySprite.getPosition().y, enemyBullet));
        i_enemy_bullets[i_enemy_bullets.size() - 1].type = type;
        break;
    }
    case 2:
    {
        i_enemy_bullets.push_back(Bullet(0, ENEMY_BULLET_SPEED, enemySprite.getPosition().x, enemySprite.getPosition().y, enemyBullet));
        i_enemy_bullets[i_enemy_bullets.size() - 1].type = type;

        i_enemy_bullets.push_back(Bullet(2, ENEMY_BULLET_SPEED, enemySprite.getPosition().x, enemySprite.getPosition().y, enemyBullet));
        i_enemy_bullets[i_enemy_bullets.size() - 1].type = type;

        i_enemy_bullets.push_back(Bullet(-2, ENEMY_BULLET_SPEED, enemySprite.getPosition().x, enemySprite.getPosition().y, enemyBullet));
        i_enemy_bullets[i_enemy_bullets.size() - 1].type = type;
        break;
    }
    }
}

void Enemy::update_current_frame()
{
    ++timeMovement;
    while (timeMovement >= ENEMY_ANIMATION_SPEED)
    {
        current_frame++;
        timeMovement = 0;

        if (current_frame == 2)
        {
            current_frame = 0;
        }
    }
}

void Enemy::update()
{
    update_current_frame();
}

void Enemy::draw(sf::RenderTarget *target)
{
    if (isSetPos)
    {
        enemySprite.setTexture(enemies[type][current_frame]);
        if (type == 0)
            enemySprite.setScale(sf::Vector2f(0.55, 0.55));
        else
            enemySprite.setScale(sf::Vector2f(0.75, 0.75));
        target->draw(enemySprite);
    }

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
    return sf::IntRect(enemySprite.getGlobalBounds().left + 8,
                       enemySprite.getGlobalBounds().top + 10,
                       enemySprite.getGlobalBounds().width - 18,
                       enemySprite.getGlobalBounds().height - 20);
}

void Enemy::saveGame(std::string fileName)
{
    std::ofstream ofs;
    ofs.open(fileName, std::ios::app);

    ofs << enemySprite.getPosition().x << " " << enemySprite.getPosition().y << " " << direction << " " << health << " " 
        << type << " " << hit_timer << " " << timeMovement
        << " " << isSetPos << " " << current_frame << std::endl;

    ofs.close();
}