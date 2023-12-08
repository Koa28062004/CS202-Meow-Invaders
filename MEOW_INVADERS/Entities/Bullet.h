#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <stack>
#include <map>
#include <vector>
#include <string>
#include <array>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Bullet
{
public:
    Bullet(int i_step_x, int i_step_y, int i_x, int i_y, sf::Sprite bulletSprite);
    virtual ~Bullet();

    // Functions
    void update();
    void bulletDead();
    sf::IntRect get_hitbox() const;
    void drawHitBoxBullet(sf::RenderTarget *target);
    bool getDead();

    void saveGame(std::string fileName);

    int x;
    int y;

    int type;

    std::array<int, 3> previous_x;
    std::array<int, 3> previous_y;

private:
    int real_x;
    int real_y;
    int step_x;
    int step_y;

    bool dead;

    sf::RenderWindow *mWindow;
    sf::Sprite bullet;
};

#endif