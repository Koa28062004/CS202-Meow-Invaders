#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "GlobalVars/GlobalVars.h"
#include "Enemy.h"
#include "Bullet.h"
#include <random>

class EnemyManager
{
public:
    EnemyManager();
    virtual ~EnemyManager();

    bool reached_player(int i_player_y) const;

    void draw(sf::RenderWindow* window);
    void reset(int i_level);
    void update(std::mt19937_64 &i_random_engine);

    std::vector<Bullet> &get_enemy_bullets();
    std::vector<Enemy> &get_enemies();
    void checkBulletOutside(Bullet &bullet);

private:
    int move_pause;
    int move_timer;

    // To use the randomness from the <random> library, we need to define the distribution.
    std::uniform_int_distribution<int> shoot_distribution;

  //  std::vector<Animation> enemy_animations;

    std::vector<Bullet> enemy_bullets;

    std::vector<Enemy> enemies;

    sf::Texture enemyTex1;
    sf::Texture enemyTex2;
    sf::Texture enemyTex3;

    sf::Sprite enemy_bullet_sprite;
    sf::Texture enemy_bullet_texture;
};

#endif