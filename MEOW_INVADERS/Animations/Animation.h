#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"
#include <fstream>

class Animation
{
public:
    Animation(int i_animation_speed, int i_frame_width, int total_frame);

    bool update();

    void drawExplosion(int i_x, int i_y, sf::RenderTarget *target);
    void drawEnemyExplosion(int i_x, int i_y, sf::RenderTarget *target);

    void reset();

    // setter
    void setVars(int animation_iterator,
                 int animation_speed,
                 int current_frame,
                 int frame_width);

    // save
    void saveGame(std::string fileName);

private:
    // init
    void initExplosion();
    void initEnemyExplosion();

    int animation_iterator;
    int animation_speed;
    int current_frame;
    int frame_width;

    int total_frames;

    std::vector<sf::Texture> explosions; // explosions for player
    std::vector<sf::Texture> enemyExplosions;
};

#endif