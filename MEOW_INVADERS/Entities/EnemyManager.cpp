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
                               shoot_boss(0, 60),
                               randomMove(0)

{
    if (!enemy_bullet_texture1.loadFromFile("assets/images/enemyBullet1.png"))
    {
        throw std::runtime_error("Error::EnemyManager::Can not load enemyBullet1.png");
    }
    enemy_bullet_sprite1.setTexture(enemy_bullet_texture1);
    enemy_bullet_sprite1.setScale(sf::Vector2f(0.3, 0.3));

    if (!enemy_bullet_texture2.loadFromFile("assets/images/enemyBullet2.png"))
    {
        throw std::runtime_error("Error::EnemyManager::Can not load enemyBullet2.png");
    }
    enemy_bullet_sprite2.setTexture(enemy_bullet_texture2);
    enemy_bullet_sprite2.setScale(sf::Vector2f(0.35, 0.35));

    if (!enemy_bullet_texture3.loadFromFile("assets/images/enemyBullet3.png"))
    {
        throw std::runtime_error("Error::EnemyManager::Can not load enemyBullet3.png");
    }
    enemy_bullet_sprite3.setTexture(enemy_bullet_texture3);
    enemy_bullet_sprite3.setScale(sf::Vector2f(0.4, 0.4));

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
    enemy_bullets.clear();
    boss_bullets.clear();
    enemies.clear();
    disasters.clear();
    randomDisasters.clear();
    bosses.clear();
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

std::string EnemyManager::generateRandomLevelEnemy()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);

    std::string i_level_enemy = "";
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            i_level_enemy += std::to_string(dis(gen)) + " ";
        }
        i_level_enemy += "\n";
    }
    return i_level_enemy;
}

std::string EnemyManager::generateRandomLevelDisaster()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);

    std::string i_level_disaster = "";
    for (int i = 0; i < 10; ++i)
    {
        char random_char = 'a' + dis(gen);
        i_level_disaster += random_char;
    }
    return i_level_disaster;
}

std::string EnemyManager::generateRandomLevelBoss()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    char i_boss_char = 'A' + dis(gen);
    std::string i_level_boss(1, i_boss_char);
    return i_level_boss;
}

int EnemyManager::getRandomNumber(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void EnemyManager::reset(int level)
{
    Enemy::collectiveDirection = 1;

    randomMove = getRandomNumber(0, 2);

    shoot_distribution = std::uniform_int_distribution<int>(0, std::max<int>(ENEMY_SHOOT_CHANCE_MIN, ENEMY_SHOOT_CHANCE - ENEMY_SHOOT_CHANCE_INCREASE * level));

    // enemy_bullets.clear();
    // boss_bullets.clear();
    enemies.clear();
    disasters.clear();
    // randomDisasters.clear();
    bosses.clear();

    switch (level)
    {
    case 0:
    {
        // level_enemy = "0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0";
        level_enemy = "1 0 2 0 1 0 2 0 \n 2 1 0 1 0 1 0 2";
        level_disaster = "a a c b a c a a b a b a b a b a b a";
        level_boss = "A";
        break;
    }
    case 1:
    {
        level_enemy = "1 0 1 0 1 0 1 0 1 0 \n 1 0 0 1 0 1 0 1";
        level_disaster = "a c b a c a a b a b a b a b a b a";
        level_boss = "B";
        break;
    }
    case 2:
    {
        level_enemy = "1 0 1 0 1 0 1 0 1 2 1\n 0 1 2 1 2 1 0 1 0 1";
        level_disaster = "a c b a c a a b a b a b a b a b a c b a a c c c c c c c c";
        level_boss = "B";
        break;
    }
    default:
        level_enemy = generateRandomLevelEnemy();
        level_disaster = generateRandomLevelDisaster();
        level_boss = generateRandomLevelBoss();
        break;
    }

    convertEnemy();
    convertDisaster();
    convertBoss();
}

void EnemyManager::loadGame(std::ifstream &ifs)
{
    loadReset(ifs);
    loadBullets(ifs);
    loadEnemy(ifs);
    loadDisasters(ifs);
    loadBoss(ifs);
}

void EnemyManager::loadBoss(std::ifstream &ifs)
{
    bosses.clear();
    int size;
    int type, health, isSetPos, i_x, i_y;
    ifs >> size;
    for (int i = 0; i < size; ++i)
    {
        ifs >> type >> health >> isSetPos >> i_x >> i_y;
        bosses.push_back(Boss(type, boss_bullet_sprite));
        bosses[bosses.size() - 1].setHealth(health);
        bosses[bosses.size() - 1].setIsSetPos(isSetPos);
        bosses[bosses.size() - 1].setPosition(i_x, i_y);
    }
}

void EnemyManager::loadDisasters(std::ifstream &ifs)
{
    disasters.clear();
    int size;
    int type, health, isSetPos, i_x, i_y;
    ifs >> size;
    for (int i = 0; i < size; ++i)
    {
        ifs >> type >> health >> isSetPos >> i_x >> i_y;
        if (type == 1)
            disasters.push_back(Disaster(1, &disasterTex1));
        if (type == 2)
            disasters.push_back(Disaster(2, &disasterTex2));
        if (type == 3)
            disasters.push_back(Disaster(3, &disasterTex3));
        disasters[disasters.size() - 1].setHealth(health);
        disasters[disasters.size() - 1].setIsSetPos(isSetPos);
        disasters[disasters.size() - 1].setPosition(i_x, i_y);
        disasters[disasters.size() - 1].loadGameExplosion(ifs);
    }

    randomDisasters.clear();
    ifs >> size;
    for (int i = 0; i < size; ++i)
    {
        ifs >> type >> health >> isSetPos >> i_x >> i_y;
        if (type == 1)
            randomDisasters.push_back(Disaster(1, &disasterTex1));
        if (type == 2)
            randomDisasters.push_back(Disaster(2, &disasterTex2));
        if (type == 3)
            randomDisasters.push_back(Disaster(3, &disasterTex3));
        randomDisasters[randomDisasters.size() - 1].setHealth(health);
        randomDisasters[randomDisasters.size() - 1].setIsSetPos(isSetPos);
        randomDisasters[randomDisasters.size() - 1].setPosition(i_x, i_y);
        randomDisasters[randomDisasters.size() - 1].loadGameExplosion(ifs);
    }
}

void EnemyManager::loadEnemy(std::ifstream &ifs)
{
    enemies.clear();
    int size;
    int direction, health, hit_timer, timeMovement, type, i_x, i_y,
        isSetPos, current_frame;
    ifs >> size;
    for (int i = 0; i < size; ++i)
    {
        ifs >> i_x >> i_y >> direction >> health >> type >>
            hit_timer >> timeMovement >> isSetPos >> current_frame;
        if (type == 0)
            enemies.push_back(Enemy(type, i_x, i_y, enemy_bullet_sprite1));
        if (type == 1)
            enemies.push_back(Enemy(type, i_x, i_y, enemy_bullet_sprite2));
        if (type == 2)
            enemies.push_back(Enemy(type, i_x, i_y, enemy_bullet_sprite3));

        enemies[enemies.size() - 1].setDirection(direction);
        enemies[enemies.size() - 1].setHealth(health);
        enemies[enemies.size() - 1].setTime(hit_timer, timeMovement);
        enemies[enemies.size() - 1].setIsSetPos(isSetPos);
        enemies[enemies.size() - 1].setCurrentFrame(current_frame);
        enemies[enemies.size() - 1].setPosition(i_x, i_y);
        enemies[enemies.size() - 1].loadGameExplosion(ifs);
    }
}

void EnemyManager::loadBullets(std::ifstream &ifs)
{
    // Enemy bullets
    long long size;
    ifs >> size;
    int step_x, step_y, x, y, type;
    for (int i = 0; i < size; ++i)
    {
        ifs >> step_x >> step_y >> x >> y >> type;
        if (type == 0)
            enemy_bullets.push_back(Bullet(step_x, step_y, x, y, enemy_bullet_sprite1));
        if (type == 1)
            enemy_bullets.push_back(Bullet(step_x, step_y, x, y, enemy_bullet_sprite2));
        if (type == 2)
            enemy_bullets.push_back(Bullet(step_x, step_y, x, y, enemy_bullet_sprite3));

        enemy_bullets[enemy_bullets.size() - 1].type = type;
    }

    // Boss bullets
    ifs >> size;
    for (int i = 0; i < size; ++i)
    {
        ifs >> step_x >> step_y >> x >> y >> type;
        boss_bullets.push_back(Bullet(step_x, step_y, x, y, boss_bullet_sprite));
    }
}

void EnemyManager::loadReset(std::ifstream &ifs)
{
    // randomMove
    ifs >> randomMove;
}

void EnemyManager::convertBoss()
{
    for (char boss_char : level_boss)
    {
        switch (boss_char)
        {
        case 'A':
            bosses.push_back(Boss(1, boss_bullet_sprite));
            break;
        case 'B':
            bosses.push_back(Boss(2, boss_bullet_sprite));
            break;
        }
    }
}

void EnemyManager::convertDisaster()
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

void EnemyManager::convertEnemy()
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
        enemy.movement(level, randomMove);
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
                            { return 1 == enemy.get_dead(); }),
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
        disaster.movement(level, randomMove);
        disaster.update();
        disaster.checkOutside();
    }

    // delete disaster
    randomDisasters.erase(remove_if(randomDisasters.begin(), randomDisasters.end(), [](Disaster &disaster)
                                    { return 1 == disaster.getDead(); }),
                          randomDisasters.end());
}

void EnemyManager::updateDisaster(int level)
{
    for (Disaster &disaster : disasters)
    {
        disaster.movement(level, randomMove);
        disaster.update();
        disaster.checkOutside();
    }

    // delete disaster
    disasters.erase(remove_if(disasters.begin(), disasters.end(), [](Disaster &disaster)
                              { return 1 == disaster.getDead(); }),
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
    updateBossBullets();
    if (!enemies.size())
         updateDisaster(level);
    if (!enemies.size() && !disasters.size())
    {
        updateBoss(i_random_engine);
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

        if (bullet.type == 0)
        {
            enemy_bullet_sprite1.setPosition(bullet.x, bullet.y);
            window->draw(enemy_bullet_sprite1);
        }

        if (bullet.type == 1)
        {
            enemy_bullet_sprite2.setPosition(bullet.x, bullet.y);
            window->draw(enemy_bullet_sprite2);
        }

        if (bullet.type == 2)
        {
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

void EnemyManager::saveGame(std::string fileName)
{
    std::ofstream ofs;
    ofs.open(fileName, std::ios::app);

    // randomMove
    ofs << randomMove << std::endl;

    // save enemy bullets
    ofs << enemy_bullets.size() << std::endl;
    for (Bullet &bullet : enemy_bullets)
    {
        bullet.saveGame(fileName);
    }

    // save boss bullets
    ofs << boss_bullets.size() << std::endl;
    for (Bullet &bullet : boss_bullets)
    {
        bullet.saveGame(fileName);
    }

    // save enemies
    ofs << enemies.size() << std::endl;
    for (Enemy &enemy : enemies)
    {
        enemy.saveGame(fileName);
    }

    // save disasters
    ofs << disasters.size() << std::endl;
    for (Disaster &disaster : disasters)
    {
        disaster.saveGame(fileName);
    }

    // save random disasters
    ofs << randomDisasters.size() << std::endl;
    for (Disaster &randomDisaster : randomDisasters)
    {
        randomDisaster.saveGame(fileName);
    }

    // save boss
    ofs << bosses.size() << std::endl;
    for (Boss &boss : bosses)
    {
        boss.saveGame(fileName);
    }

    ofs.close();
}