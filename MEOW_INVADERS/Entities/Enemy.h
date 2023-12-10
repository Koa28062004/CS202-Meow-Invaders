#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <stack>
#include <map>
#include <vector>
#include <string>
#include <random>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Bullet.h"
#include "Animations/Animation.h"
#include "GlobalVars/GlobalVars.h"

class Enemy
{
public:
    Enemy(int i_type, int i_x, int i_y, sf::Sprite enemyBulletSprite);
    virtual ~Enemy();

    // Movements
	void movement(int level, int randomMove);
    void move0();
    void move1();
    void move2();

    // Functions
    void hit();
	void shoot(std::vector<Bullet>& i_enemy_bullets);
	void update();
    void draw(sf::RenderTarget* target);

    // Access
	sf::IntRect get_hitbox() const;
    int get_health() const;
	int get_hit_timer() const;
	int get_type() const;
	int get_x() const;
	int get_y() const;
    bool get_dead() const;
    void drawHitBoxEnemy(sf::RenderTarget* target);
    
    static int collectiveDirection;

    // setter
    void setPosition(int x, int y);
    void setDirection(int direction);
    void setHealth(int health);
    void setType(int type);
    void setTime(int hit_timer, int timeMovement);
    void setIsSetPos(bool isSetPos);
    void setCurrentFrame(int current_frame);

    // save
    void saveGame(std::string fileName);
    // load game
    void loadGameExplosion(std::ifstream& ifs);
private:
    // Init
    void initEnemy1();
    void initEnemy2();
    void initEnemy3();

    // change Frame
    void update_current_frame();
    int getRandomNumber(int min, int max);

    int direction;
    int health;
    
    int hit_timer;
    int timeMovement;
    bool dead_animation_over;

    // type of enemy
    int type;

    int x;
    int y;

    sf::Texture enemyTex;
    sf::Sprite enemySprite;
    sf::Sprite enemyBullet;

    bool isSetPos;
    float randomValueX = 1.0f;
    float randomValueY = 2.0f;

    std::vector<std::vector<sf::Texture> > enemies;
    std::vector<sf::Texture> animations; 

    int current_frame;
    Animation explosion;
};

#endif