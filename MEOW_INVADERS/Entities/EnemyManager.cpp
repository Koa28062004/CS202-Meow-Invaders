#include "EnemyManager.h"

void EnemyManager::initDisaster()
{
    if (!disasterTex1.loadFromFile("assets/images/disaster1.png"))
    {
        throw std::runtime_error("Error::EnemyManager::Can not load disaster texture");
    }

    if (!disasterTex2.loadFromFile("assets/images/disaster2.png"))
    {
        throw std::runtime_error("Error::EnemyManager::Can not load disaster texture");
    }

    if (!disasterTex3.loadFromFile("assets/images/disaster3.png"))
    {
        throw std::runtime_error("Error::EnemyManager::Can not load enemy texture");
    }
}

EnemyManager::EnemyManager() : shoot_distribution(0, ENEMY_SHOOT_CHANCE),
                               shoot_boss(0, 60)

{
    if (!enemy_bullet_texture1.loadFromFile("assets/images/enemyBullet1.png"))
    {
        throw std::runtime_error("Error::EnemyManager::Can not load enemyBullet1.png");
    }
    enemy_bullet_sprite1.setTexture(enemy_bullet_texture1);
    enemy_bullet_sprite1.setScale(sf::Vector2f(0.2, 0.2));

    if (!enemy_bullet_texture2.loadFromFile("assets/images/enemyBullet2.png"))
    {
        throw std::runtime_error("Error::EnemyManager::Can not load enemyBullet2.png");
    }
    enemy_bullet_sprite2.setTexture(enemy_bullet_texture2);
    enemy_bullet_sprite2.setScale(sf::Vector2f(0.3, 0.3));

    if (!enemy_bullet_texture3.loadFromFile("assets/images/enemyBullet3.png"))
    {
        throw std::runtime_error("Error::EnemyManager::Can not load enemyBullet3.png");
    }
    enemy_bullet_sprite3.setTexture(enemy_bullet_texture3);
    enemy_bullet_sprite3.setScale(sf::Vector2f(0.3, 0.3));

    if (!boss_bullet_texture.loadFromFile("assets/images/bossBullet.png"))
    {
        throw std::runtime_error("Error::EnemyManager::Can not load bossBullet.png");
    }
    boss_bullet_sprite.setTexture(boss_bullet_texture);
    boss_bullet_sprite.setScale(sf::Vector2f(0.2, 0.2));

    initDisaster();
}

EnemyManager::~EnemyManager()
{
}

std::vector<Bullet> &EnemyManager::get_enemy_bullets()
{
    return enemy_bullets;
}

std::vector<Bullet> &EnemyManager::get_boss_bullets()
{
    return boss_bullets;
}

std::vector<Enemy> &EnemyManager::get_enemies()
{
    return enemies;
}

std::vector<Disaster> &EnemyManager::get_disasters()
{
    return disasters;
}

std::vector<Disaster> &EnemyManager::get_randomDisasters()
{
    return randomDisasters;
}

std::vector<Boss> &EnemyManager::get_bosses()
{
    return bosses;
}

bool EnemyManager::reached_player(int i_player_y) const
{
    for (const Enemy &enemy : enemies)
    {
        if (enemy.get_y() > i_player_y - 0.5f * BASE_SIZE)
        {
            // As soon as the enemies reach the player, the game is over!
            return 1;
        }
    }

    return 0;
}

void EnemyManager::reset(int level)
{
    Enemy::collectiveDirection = 1;

    std::string level_enemy = "";
    std::string level_disaster = "";
    std::string level_boss = "";

    // move_pause = std::max<int>(ENEMY_MOVE_PAUSE_START_MIN, ENEMY_MOVE_PAUSE_START - ENEMY_MOVE_PAUSE_DECREASE * level);
    // move_timer = move_pause;

    shoot_distribution = std::uniform_int_distribution<int>(0, std::max<int>(ENEMY_SHOOT_CHANCE_MIN, ENEMY_SHOOT_CHANCE - ENEMY_SHOOT_CHANCE_INCREASE * level));

    enemy_bullets.clear();
    boss_bullets.clear();
    enemies.clear();
    disasters.clear();
    randomDisasters.clear();
    bosses.clear();

        switch (level)
    {
    case 0:
    {
        level_enemy = "1 0 2 0 1 0 2 0 \n 2 1 0 1 0 1 0 2";
        level_boss = "A";
        break;
    }
    case 1:
    {
        level_enemy = "1 0 1 0 1 0 1 0 1 0 \n 1 0 0 1 0 1 0 1";
        level_disaster = "a c b a c a a b a b a b a b a b a";
        break;
    }
    case 2:
    {
        level_enemy = "1 0 1 0 1 0 1 0 1 2 1\n 0 1 2 1 2 1 0 1 0 1";
        level_disaster = "a c b a c a a b a b a b a b a b a c b a a c c c c c c c c";
        break;
    }
    case 3:
    {
        level_enemy = "2 1 1 1 1 1 1 1 0 0 \n 0 1 2 1 2 1 0 1 0 1 \n 0 1 2 1 2 1 0 1 0 1";
        level_disaster = "a c b a c a a b a b a b a b a b a c b a c c c c c c c b b b b b b";
        break;
    }
    case 4:
    {
        // CHECKBOARD PATTERN WITH A SOLID PATTERN! I'M A GENIUS!
        level_enemy = "2222222222222222\n1111111111111111\n1010101010101010\n0101010101010101";
        level_disaster = "a c b a c a a b a b a b a b a b a c b a c c c c c c c b b b b b b c b c b c a c a a a";
        break;
    }
    case 5:
    {
        // EASY ENEMIES AT THE TOP AND HARD ENEMIES AT THE BOTTOM! IT'S A REVOLUTION IN LEVEL DESIGN!
        level_enemy = "0000000000000000\n2222222222222222\n1111111111111111\n1111111111111111";
        level_disaster = "acbacaabababababacbacccccccbbbbbb";
        break;
    }
    }

    convertEnemy(level_enemy);
    convertDisaster(level_disaster);
    convertBoss(level_boss);
}

void EnemyManager::convertBoss(std::string level_boss)
{
    for (char boss_char : level_boss)
    {
        switch (boss_char)
        {
        case 'A':
            bosses.push_back(Boss(1, boss_bullet_sprite));
        }
    }
}

void EnemyManager::convertDisaster(std::string level_disaster)
{
    for (char disaster_character : level_disaster)
    {
        switch (disaster_character)
        {
        case 'a':
            disasters.push_back(Disaster(1, &disasterTex1));
            break;
        case 'b':
            disasters.push_back(Disaster(2, &disasterTex2));
            break;
        case 'c':
            disasters.push_back(Disaster(3, &disasterTex3));
            break;
        default:
            break;
        }
    }
}

void EnemyManager::convertEnemy(std::string level_enemy)
{
    int enemy_x = 0;
    int enemy_y = 0;
    int enemy_spacing = 7;

    // Here we're converting each character into an enemy.
    for (char sketch_character : level_enemy)
    {
        enemy_x += enemy_spacing;

        switch (sketch_character)
        {
        case '\n':
        {
            enemy_x = 0;
            enemy_y += enemy_spacing;

            break;
        }
        case '0':
        {
            enemies.push_back(Enemy(0, BASE_SIZE * (1 + enemy_x), BASE_SIZE * (2 + enemy_y), enemy_bullet_sprite1));
            break;
        }
        case '1':
        {
            enemies.push_back(Enemy(1, BASE_SIZE * (1 + enemy_x), BASE_SIZE * (2 + enemy_y), enemy_bullet_sprite2));

            break;
        }
        case '2':
        {
            enemies.push_back(Enemy(2, BASE_SIZE * (1 + enemy_x), BASE_SIZE * (2 + enemy_y), enemy_bullet_sprite3));
        }
        }
    }
}

void EnemyManager::updateEnemy(std::mt19937_64 &i_random_engine, int level)
{
    std::vector<Enemy>::iterator dead_enemies_start;

    for (Enemy &enemy : enemies)
    {
        enemy.movement(level);
    }

    for (Enemy &enemy : enemies)
    {
        enemy.update();

        if (0 == shoot_distribution(i_random_engine))
        {
            enemy.shoot(enemy_bullets);
        }
    }

    // delete enemy whenever it hit.
    enemies.erase(remove_if(enemies.begin(), enemies.end(), [](Enemy &enemy)
                            { return 0 == enemy.get_health(); }),
                  enemies.end());
}

void EnemyManager::updateEnemyBullets()
{
    for (Bullet &enemy_bullet : enemy_bullets)
    {
        enemy_bullet.update();
        checkBulletOutside(enemy_bullet);
    }

    // delete enemy bullets
    enemy_bullets.erase(remove_if(enemy_bullets.begin(), enemy_bullets.end(), [](Bullet &bullet)
                                  { return 1 == bullet.getDead(); }),
                        enemy_bullets.end());
}

void EnemyManager::updateRandomDisaster(std::mt19937_64 &i_random_engine, int level)
{
    if (1 == shoot_distribution(i_random_engine))
    {
        randomDisasters.push_back(Disaster(1, &disasterTex1));
    }
    if (2 == shoot_distribution(i_random_engine))
    {
        randomDisasters.push_back(Disaster(2, &disasterTex2));
    }
    if (3 == shoot_distribution(i_random_engine))
    {
        randomDisasters.push_back(Disaster(3, &disasterTex3));
    }

    for (Disaster &disaster : randomDisasters)
    {
        disaster.movement(level);
        disaster.update();
        disaster.checkOutside();
    }

    // delete disaster
    randomDisasters.erase(remove_if(randomDisasters.begin(), randomDisasters.end(), [](Disaster &disaster)
                                    { return 0 == disaster.getDead(); }),
                          randomDisasters.end());
}

void EnemyManager::updateDisaster(int level)
{
    for (Disaster &disaster : disasters)
    {
        disaster.movement(level);
        disaster.update();
        disaster.checkOutside();
    }

    // delete disaster
    disasters.erase(remove_if(disasters.begin(), disasters.end(), [](Disaster &disaster)
                              { return 0 == disaster.getDead(); }),
                    disasters.end());
}

void EnemyManager::updateBoss(std::mt19937_64 &i_random_engine)
{
    for (Boss &boss : bosses)
    {
        boss.movement();
        boss.update();

        if (0 == shoot_boss(i_random_engine))
        {
            boss.shoot(boss_bullets);
        }
    }

    // Delete Boss
    bosses.erase(remove_if(bosses.begin(), bosses.end(), [](Boss &boss)
                           { return 0 == boss.getDead(); }),
                 bosses.end());
}

void EnemyManager::updateBossBullets()
{
    for (Bullet &boss_bullet : boss_bullets)
    {
        boss_bullet.update();
        checkBulletOutside(boss_bullet);
    }

    // delete boss bullets
    boss_bullets.erase(remove_if(boss_bullets.begin(), boss_bullets.end(), [](Bullet &bullet)
                                 { return 1 == bullet.getDead(); }),
                       boss_bullets.end());
}

void EnemyManager::update(std::mt19937_64 &i_random_engine, int level)
{
    updateEnemy(i_random_engine, level);
    updateEnemyBullets();
    updateRandomDisaster(i_random_engine, level);
    if (!enemies.size())
        updateDisaster(level);
    if (!enemies.size() && !disasters.size())
    {
        updateBoss(i_random_engine);
        updateBossBullets();
    }
}

void EnemyManager::checkBulletOutside(Bullet &bullet)
{
    if (bullet.x <= 1.f || bullet.x >= SCREEN_WIDTH || bullet.y <= 1.f || bullet.y >= SCREEN_HEIGHT + 5.f)
    {
        bullet.bulletDead();
    }
}

void EnemyManager::draw(sf::RenderWindow *window)
{
    // Draw the bullet of the enemies
    for (Bullet &bullet : enemy_bullets)
    {
        
        if (bullet.type == 0) {
            enemy_bullet_sprite1.setPosition(bullet.x, bullet.y);
            window->draw(enemy_bullet_sprite1);
        }
            
        if (bullet.type == 1) {
            enemy_bullet_sprite2.setPosition(bullet.x, bullet.y);
            window->draw(enemy_bullet_sprite2);
        }
            
        if (bullet.type == 2) {
            enemy_bullet_sprite3.setPosition(bullet.x, bullet.y);
            window->draw(enemy_bullet_sprite3);
        }
    
        if (debug)
            bullet.drawHitBoxBullet(window);
    }

    // Draw the enemies
    for (Enemy &enemy : enemies)
    {
        enemy.draw(window);
    }

    // Draw the disasters
    for (Disaster &disaster : disasters)
    {
        disaster.draw(window);
    }

    // Draw the random Disasters
    for (Disaster &randomDisaster : randomDisasters)
    {
        randomDisaster.draw(window);
    }

    for (Bullet &bullet : boss_bullets)
    {
        boss_bullet_sprite.setPosition(bullet.x, bullet.y);

        window->draw(boss_bullet_sprite);
        if (debug)
            bullet.drawHitBoxBullet(window);
    }

    // Draw the boss
    for (Boss &boss : bosses)
    {
        boss.draw(window);
    }
}