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

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Bullet
{
public:
    Bullet(float i_step_x, float i_step_y, short i_x, short i_y);
    virtual ~Bullet();

    // Functions
    void update();
    void bulletDead();
    // sf::IntRect get_hitbox() const;

    short x;
    short y;

    bool dead;

private:

    float real_x;
    float real_y;
    float step_x;
    float step_y;

    std::array<short, 3> previous_x;
    std::array<short, 3> previous_y;

    sf::RenderWindow* mWindow;
};

#endif