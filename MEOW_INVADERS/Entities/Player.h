#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Bullet.h"
#include "GlobalVars/GlobalVars.h"

class Player : public Entity
{
public:
    Player(const float &x, const float &y, sf::Texture *texture);
    virtual ~Player();

    // Functions
    void reset();
    void update();
    void draw(sf::RenderTarget* target);
    void die();

    void updateBullets();
    void checkBulletOutside(Bullet &bullet);

private:
    // Variables
    bool dead;
    bool dead_animation_over;
    bool shield_animation_over;

    unsigned char current_power;
    unsigned char reload_timer;

    unsigned short power_timer;

    sf::Vector2f playerCenter;

    sf::Texture bullet_texture;
    sf::Sprite bullet_sprite;
    std::vector<Bullet> bullets;
};

#endif