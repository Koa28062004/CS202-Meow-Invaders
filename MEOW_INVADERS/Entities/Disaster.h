#ifndef DISASTER_H
#define DISASTER_H

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
#include "GlobalVars/GlobalVars.h"
#include "Animations/Animation.h"

class Disaster
{
public:
    Disaster(int type, sf::Texture* disasterTex);
    ~Disaster();

    void update();
    void draw(sf::RenderTarget* target, sf::Texture texture);
    void hit();
    void movement(int level, int randomMove);
    void drawHitBoxEnemy(sf::RenderTarget* target);
    sf::IntRect get_hitbox() const;

    bool getDead();
    int get_health();
    int getCurrentFrame();
    void checkOutside();

    void move1();
    void move2();
    void move3();

    // setter
    void setHealth(int health);
    void setIsSetPos(bool isSetPos);
    void setPosition(int x, int y);

    // save game
    void saveGame(std::string fileName);
    // load game
    void loadGameExplosion(std::ifstream& ifs);
private:
    int health;
    sf::Sprite disasterSprite;
    bool isSetPos;
    int value;
    int type;
    Animation explosion;
    bool dead_animation_over;
};

#endif