#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "GlobalVars/GlobalVars.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Disaster.h"
#include "Boss.h"
#include <random>
#include <fstream>

class EnemyManager
{
public:
  EnemyManager();
  virtual ~EnemyManager();

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

  void convertEnemy();
  void convertDisaster();
  void convertBoss();

  // Save
  void saveGame(std::string fileName);

  // Load
  void loadGame(std::ifstream& ifs);
  void loadReset(std::ifstream& ifs);
  void loadBullets(std::ifstream& ifs);
  void loadEnemy(std::ifstream& ifs);
  void loadDisasters(std::ifstream& ifs);
  void loadBoss(std::ifstream& ifs);

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

  std::ifstream ifs;
  bool isLoad;

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

  std::string level_enemy = "";
  std::string level_disaster = "";
  std::string level_boss = "";
};

#endif