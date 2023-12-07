#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "GlobalVars/GlobalVars.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Disaster.h"
#include "Boss.h"
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
  std::vector<Bullet> &get_boss_bullets();
  std::vector<Enemy> &get_enemies();
  std::vector<Disaster> &get_disasters();
  std::vector<Disaster> &get_randomDisasters();
  std::vector<Boss> &get_bosses();

  void checkBulletOutside(Bullet &bullet);

  void convertEnemy(std::string level_enemy);
  void convertDisaster(std::string level_disaster);
  void convertBoss(std::string level_boss);

private:
  // Init
  void initDisaster();

  void updateEnemy(std::mt19937_64 &i_random_engine, int level);
  void updateEnemyBullets();
  void updateBossBullets();
  void updateDisaster(int level);
  void updateRandomDisaster(std::mt19937_64 &i_random_engine, int level);
  void updateBoss(std::mt19937_64 &i_random_engine);

  std::string generateRandomLevelEnemy();
  std::string generateRandomLevelDisaster();
  std::string generateRandomLevelBoss();

  int getRandomNumber(int min, int max);

  int move_pause;
  int move_timer;
  int randomMove;

  // To use the randomness from the <random> library, we need to define the distribution.
  std::uniform_int_distribution<int> shoot_distribution;
  std::uniform_int_distribution<int> shoot_boss;

  std::vector<Bullet> enemy_bullets;
  std::vector<Bullet> boss_bullets;
  std::vector<Enemy> enemies;
  std::vector<Disaster> disasters;
  std::vector<Disaster> randomDisasters;
  std::vector<Boss> bosses;

  sf::Texture disasterTex1;
  sf::Texture disasterTex2;
  sf::Texture disasterTex3;

  sf::Sprite enemy_bullet_sprite1;
  sf::Sprite enemy_bullet_sprite2;
  sf::Sprite enemy_bullet_sprite3;

  sf::Texture enemy_bullet_texture1;
  sf::Texture enemy_bullet_texture2;
  sf::Texture enemy_bullet_texture3;

  sf::Sprite boss_bullet_sprite;
  sf::Texture boss_bullet_texture;
};

#endif