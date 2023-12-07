#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"

class Animation
{
public:
    Animation(int i_animation_speed, int i_frame_width, const std::string &i_texture_location);

    bool update();

    void drawExplosion(int i_x, int i_y, sf::RenderTarget *target);
    void reset();

private:
    // init
    void initExplosion();

    int animation_iterator;
    int animation_speed;
    int current_frame;
    int frame_width;
    int total_frames;

    std::vector<sf::Texture> explosions;
};

#endif