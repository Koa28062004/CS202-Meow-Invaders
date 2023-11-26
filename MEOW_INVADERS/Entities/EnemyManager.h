#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "GlobalVars/GlobalVars.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Disaster.h"
#include <random>

class EnemyManager
{
public:
  EnemyManager();
  virtual ~EnemyManager();

  bool reached_player(int i_player_y) const;

  void draw(sf::RenderWindow *window);
  void reset(int i_level);
  void update(std::mt19937_64 &i_random_engine, int level);

  std::vector<Bullet> &get_enemy_bullets();
  std::vector<Enemy> &get_enemies();
  std::vector<Disaster> &get_disasters();
  void checkBulletOutside(Bullet &bullet);

  void convertEnemy(std::string level_enemy);
  void convertDisaster(std::string level_disaster);

private:
  // Init
  void initEnemy();
  void initDisaster();

  void updateEnemy(std::mt19937_64 &i_random_engine, int level);
  void updateEnemyBullets();
  void updateDisaster(int level);

  int move_pause;
  int move_timer;

  // To use the randomness from the <random> library, we need to define the distribution.
  std::uniform_int_distribution<int> shoot_distribution;

  //  std::vector<Animation> enemy_animations;

  std::vector<Bullet> enemy_bullets;
  std::vector<Enemy> enemies;
  std::vector<Disaster> disasters;

  sf::Texture enemyTex1;
  sf::Texture enemyTex2;
  sf::Texture enemyTex3;

  sf::Texture disasterTex1;
  sf::Texture disasterTex2;
  sf::Texture disasterTex3;

  sf::Sprite enemy_bullet_sprite;
  sf::Texture enemy_bullet_texture;
};

#endif