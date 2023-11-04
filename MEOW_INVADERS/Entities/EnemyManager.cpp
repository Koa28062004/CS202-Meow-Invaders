#include "EnemyManager.h"

EnemyManager::EnemyManager() : shoot_distribution(0, ENEMY_SHOOT_CHANCE)
{
    // We have a function that sets everything to the initial state, so why not use it?
    reset(0);

    if (!enemy_bullet_texture.loadFromFile("assets/images/enemyBullet1.png"))
    {
        throw std::runtime_error("Error::EnemyManager::Can not load enemyBullet1.png");
    }
    enemy_bullet_sprite.setTexture(enemy_bullet_texture);
    enemy_bullet_sprite.setScale(sf::Vector2f(0.2, 0.2));

    if (!enemyTex1.loadFromFile("assets/images/enemy1.png"))
    {
        throw std::runtime_error("Error::EnemyManager::Can not load enemy1.png");
    }
    enemySprite1.setTexture(enemyTex1);
    enemySprite1.setScale(sf::Vector2f(0.2, 0.2));

    if (!enemyTex2.loadFromFile("assets/images/enemy2.png"))
    {
        throw std::runtime_error("Error::EnemyManager::Can not load enemy2.png");
    }
    enemySprite2.setTexture(enemyTex2);
    enemySprite2.setScale(sf::Vector2f(0.2, 0.2));

    if (!enemyTex3.loadFromFile("assets/images/enemy3.png"))
    {
        throw std::runtime_error("Error::EnemyManager::Can not load enemy3.png");
    }
    enemySprite3.setTexture(enemyTex3);
    enemySprite3.setScale(sf::Vector2f(0.25, 0.25));

    // for (unsigned char a = 0; a < ENEMY_TYPES; a++)
    // {
    //     enemy_animations.push_back(Animation(1 + move_pause, BASE_SIZE, "Resources/Images/Enemy" + std::to_string(static_cast<unsigned short>(a)) + ".png"));
    // }
}

EnemyManager::~EnemyManager()
{
}

std::vector<Bullet> &EnemyManager::get_enemy_bullets()
{
    return enemy_bullets;
}

std::vector<Enemy> &EnemyManager::get_enemies()
{
    return enemies;
}

bool EnemyManager::reached_player(unsigned short i_player_y) const
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

void EnemyManager::reset(unsigned short i_level)
{
    unsigned char enemy_x = 0;
    unsigned char enemy_y = 0;
    unsigned char enemy_spacing = 4;

    std::string level_sketch = "";

    move_pause = std::max<short>(ENEMY_MOVE_PAUSE_START_MIN, ENEMY_MOVE_PAUSE_START - ENEMY_MOVE_PAUSE_DECREASE * i_level);
    move_timer = move_pause;

    shoot_distribution = std::uniform_int_distribution<unsigned short>(0, std::max<short>(ENEMY_SHOOT_CHANCE_MIN, ENEMY_SHOOT_CHANCE - ENEMY_SHOOT_CHANCE_INCREASE * i_level));

    // for (Animation& enemy_animation : enemy_animations)
    // {
    // 	enemy_animation.reset();
    // }

    enemy_bullets.clear();

    enemies.clear();

    // if (TOTAL_LEVELS <= i_level)
    // {
    // 	i_level = 0.5f * TOTAL_LEVELS + i_level % static_cast<unsigned char>(0.5f * TOTAL_LEVELS);
    // }

    switch (i_level)
    {
    case 0:
    {
        level_sketch = "0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 \n 0 0 0 0 0 0 0 0";

        break;
    }
    case 1:
    {
        level_sketch = "0000000000000000\n0000000000000000\n0000000000000000\n0000000000000000";

        break;
    }
    case 2:
    {
        // OH MY GOD, IS THAT A CHECKBOARD PATTERN?!
        level_sketch = "1010101010101010\n0101010101010101\n1010101010101010\n0101010101010101";

        break;
    }
    case 3:
    {
        level_sketch = "1111111111111111\n1111111111111111\n1111111111111111\n1111111111111111";

        break;
    }
    case 4:
    {
        // CHECKBOARD PATTERN WITH A SOLID PATTERN! I'M A GENIUS!
        level_sketch = "2222222222222222\n1111111111111111\n1010101010101010\n0101010101010101";

        break;
    }
    case 5:
    {
        // EASY ENEMIES AT THE TOP AND HARD ENEMIES AT THE BOTTOM! IT'S A REVOLUTION IN LEVEL DESIGN!
        level_sketch = "0000000000000000\n2222222222222222\n1111111111111111\n1111111111111111";

        break;
    }
    case 6:
    {
        // CHECKBOARD PATTERN AGAIN?!
        level_sketch = "2121212121212121\n1212121212121212\n2121212121212121\n1212121212121212";

        break;
    }
    case 7:
    {
        level_sketch = "2222222222222222\n2222222222222222\n2222222222222222\n2222222222222222";
    }
    }

    // Here we're converting each character into an enemy.
    for (char sketch_character : level_sketch)
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
            enemies.push_back(Enemy(0, BASE_SIZE * (1 + enemy_x), BASE_SIZE * (2 + enemy_y)));

            break;
        }
        case '1':
        {
            enemies.push_back(Enemy(1, BASE_SIZE * (1 + enemy_x), BASE_SIZE * (2 + enemy_y)));

            break;
        }
        case '2':
        {
            enemies.push_back(Enemy(2, BASE_SIZE * (1 + enemy_x), BASE_SIZE * (2 + enemy_y)));
        }
        }
    }
}

void EnemyManager::update(std::mt19937_64 &i_random_engine)
{
    std::vector<Enemy>::iterator dead_enemies_start;
    if (0 == move_timer)
    {
        move_timer = move_pause;

        for (Enemy &enemy : enemies)
        {
            enemy.move();
        }

        // for (Animation &enemy_animation : enemy_animations)
        // {
        //     // The enemies change their frame after each move.
        //     enemy_animation.change_current_frame();
        // }
    }
    else
    {
        move_timer--;
    }

    for (Enemy &enemy : enemies)
    {
        enemy.update();

        if (0 == shoot_distribution(i_random_engine))
        {
            enemy.shoot(enemy_bullets);
        }
    }

    dead_enemies_start = remove_if(enemies.begin(), enemies.end(), [](const Enemy &i_enemy)
                                   { return 0 == i_enemy.get_health(); });

    // The more enemies we kill, the faster they become.
    move_pause = std::max<int>(ENEMY_MOVE_PAUSE_MIN, move_pause - ENEMY_MOVE_PAUSE_DECREASE * (enemies.end() - dead_enemies_start));

    enemies.erase(dead_enemies_start, enemies.end());

    for (Bullet &enemy_bullet : enemy_bullets)
    {
        enemy_bullet.update();
    }

    enemy_bullets.erase(remove_if(enemy_bullets.begin(), enemy_bullets.end(), [](const Bullet &i_bullet)
                                  { return 1 == i_bullet.dead; }),
                        enemy_bullets.end());
}

void EnemyManager::draw(sf::RenderWindow* window)
{
    // Draw the bullet of the enemies
    for (const Bullet &bullet : enemy_bullets)
    {
        enemy_bullet_sprite.setPosition(bullet.x, bullet.y);

        window->draw(enemy_bullet_sprite);
    }

    // Draw the enemies
    for (Enemy &enemy : enemies)
    {
        if (0 == enemy.get_hit_timer())
        {

            switch (enemy.get_type())
            {
            case 0:
            {
                enemyTmp = enemySprite1;
                break;
            }
            case 1:
            {
                enemyTmp = enemySprite2;
                break;
            }
            case 2:
            {
                enemyTmp = enemySprite3;
                break;
            }
            }
        }
        enemyTmp.setPosition(enemy.get_x(), enemy.get_y());
        window->draw(enemyTmp);
    }
}