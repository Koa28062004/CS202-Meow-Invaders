#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"

class Animation
{
public:
    Animation(int i_animation_speed, int i_frame_width, const std::string &i_texture_location);

    bool update();

    void draw(int i_x, int i_y, sf::RenderWindow &i_window, const sf::Color &i_color = sf::Color(255, 255, 255));
    void reset();

private:
    int animation_iterator;
    int animation_speed;
    int current_frame;
    int frame_width;
    int total_frames;

    sf::Sprite sprite;

    sf::Texture texture;
};

#endif