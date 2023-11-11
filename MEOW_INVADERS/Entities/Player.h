#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Bullet.h"
#include "GlobalVars/GlobalVars.h"
#include "EnemyManager.h"

class Player : public Entity
{
public:
    Player(const float &x, const float &y, sf::Texture *texture);
    virtual ~Player();

    // Functions
    void reset();
    void update(std::vector<Bullet>&enemy_bullets,
                std::vector<Enemy> &enemies);
    void draw(sf::RenderTarget *target);
    void die();

    bool get_dead() const;

    void updateBullets();
    void checkBulletOutside(Bullet &bullet);
    void drawHitBoxPlayer(sf::RenderTarget* target);

    sf::IntRect get_hitbox() const;

private:
    // Variables
    bool dead;
    bool dead_animation_over;
    bool shield_animation_over;

    int current_power;
    int reload_timer;

    int power_timer;

    sf::Vector2f playerCenter;

    sf::Texture bullet_texture;
    sf::Sprite bullet_sprite;
    std::vector<Bullet> player_bullets;
};

#endif