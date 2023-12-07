#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Bullet.h"
#include "Disaster.h"
#include "GlobalVars/GlobalVars.h"
#include "EnemyManager.h"
#include "Power.h"
#include "Animations/Animation.h"

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
                std::vector<Boss> &bosses,
                sf::RenderWindow* mWindow);
    void draw(sf::RenderTarget *target);
    void die();

    bool get_dead() const;

    void updateBullets();
    void updatePlayerPosition(sf::RenderWindow* mWindow);
    void restartPower();
    
    void checkBulletOutside(Bullet &bullet);
    void drawHitBoxPlayer(sf::RenderTarget *target);

    void initKeys();
    void initKeybinds();

    sf::IntRect get_hitbox() const;
    bool get_dead_animation_over() const;

private:
    void initPower();

    void updatePower();

    void drawBounds(sf::RenderTarget* target);

    // Variables
    bool dead;

    int reload_timer;
    int fire_timer;

    int power_timer;
    int current_power;
    bool dead_animation_over;
	bool shield_animation_over;

    std::vector<Power> powers;

    sf::Vector2f playerCenter;

    sf::Texture bullet_texture;
    sf::Sprite bullet_sprite;
    std::vector<Bullet> player_bullets;

    std::map<std::string, int> supportedKeys;
    std::map<std::string, int> keybinds;

    std::default_random_engine generator;

    Animation explosion;
};

#endif