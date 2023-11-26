#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Bullet.h"
#include "Disaster.h"
#include "GlobalVars/GlobalVars.h"
#include "EnemyManager.h"

class Player : public Entity
{
public:
    Player(const float &x, const float &y, sf::Texture *texture);
    virtual ~Player();

    // Functions
    void reset();
    void update(std::vector<Bullet> &enemy_bullets,
                std::vector<Enemy> &enemies, 
                std::vector<Disaster> &disasters,
                std::vector<Disaster> &randomDisasters,
                sf::RenderWindow* mWindow);
    void draw(sf::RenderTarget *target);
    void die();

    bool get_dead() const;

    void updateBullets();
    void updatePlayerPosition(sf::RenderWindow* mWindow);
    
    void checkBulletOutside(Bullet &bullet);
    void drawHitBoxPlayer(sf::RenderTarget *target);

    void initKeys();
    void initKeybinds();

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

    std::map<std::string, int> supportedKeys;
    std::map<std::string, int> keybinds;
};

#endif