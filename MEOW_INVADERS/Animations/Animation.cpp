#include "Animation.h"

void Animation::initExplosion()
{
    sf::Texture tmpTex;
    sf::Sprite tmpSprite;
    if (!tmpTex.loadFromFile("assets/images/explosion1.png"))
    {
    }
    // tmpSprite.setTexture(tmpTex);
    // tmpSprite.setScale(sf::Vector2f(0.4, 0.4));
    explosions.push_back(tmpTex);

    if (!tmpTex.loadFromFile("assets/images/explosion2.png"))
    {
    }
    // tmpSprite.setTexture(tmpTex);
    // tmpSprite.setScale(sf::Vector2f(0.4, 0.4));
    explosions.push_back(tmpTex);

    if (!tmpTex.loadFromFile("assets/images/explosion3.png"))
    {
    }
    // tmpSprite.setTexture(tmpTex);
    // tmpSprite.setScale(sf::Vector2f(0.4, 0.4));
    explosions.push_back(tmpTex);

    if (!tmpTex.loadFromFile("assets/images/explosion4.png"))
    {
    }
    // tmpSprite.setTexture(tmpTex);
    // tmpSprite.setScale(sf::Vector2f(0.4, 0.4));
    explosions.push_back(tmpTex);

    if (!tmpTex.loadFromFile("assets/images/explosion5.png"))
    {
    }
    // tmpSprite.setTexture(tmpTex);
    // tmpSprite.setScale(sf::Vector2f(0.4, 0.4));
    explosions.push_back(tmpTex);
}

Animation::Animation(int i_animation_speed, int i_frame_width, const std::string &i_texture_location) : animation_iterator(0),
                                                                                                        animation_speed(std::max<int>(1, i_animation_speed)),
                                                                                                        current_frame(0),
                                                                                                        frame_width(i_frame_width)
{
    initExplosion();
    // texture.loadFromFile(i_texture_location);
    total_frames = 4;
    // sprite.setTexture(texture);
    // sprite.setScale(sf::Vector2f(0.4, 0.4));
}

bool Animation::update()
{
    bool output = 0;

    animation_iterator++;

    while (animation_iterator >= animation_speed)
    {
        animation_iterator -= animation_speed;
        current_frame++;

        if (current_frame == total_frames)
        {
            output = 1;
            current_frame = 0;
        }
    }

    return output;
}

void Animation::drawExplosion(int i_x, int i_y, sf::RenderTarget *target)
{
    sf::Sprite sprite;
    sprite.setTexture(explosions[current_frame]);
    sprite.setScale(sf::Vector2f(0.2, 0.2));
    sprite.setPosition(i_x, i_y);

    target->draw(sprite);
}

void Animation::reset()
{
    animation_iterator = 0;
    current_frame = 0;
}