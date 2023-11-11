#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <chrono>
#include <random>

#include "State.h"
#include "PauseState.h"
#include "Entities/EnemyManager.h"

class GameState : public State
{
public:
    GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states);
    virtual ~GameState();

    // Functions
    void updatePausedInput();
    void update();
    void draw(sf::RenderTarget *target = nullptr);
    void movingByKeyBoard();

    // Playing game
    void updatingPlayingGame();
    void drawPlayingGame();

private:
    // Initialization
    void initVariables();
    void initPlayer();
    void initTextures();
    void initKeybinds();
    void initPausedMenu();
    void initBackground();
    void initPausedButton();
    void initEnemyManager();

    // Functions
    void updatePausedButton();

    Player *player;
    EnemyManager *enemyManager;

    PauseState *pauseState;
    sf::RenderWindow *mWindow;

    sf::RectangleShape background;
    sf::Texture backgroundTexture;

    // Paused button idle
    sf::RectangleShape pausedButtonIdle;
    sf::Texture pausedButtonIdleTexture;

    // Paused button hover
    bool checkPausedButton;
    sf::RectangleShape pausedButtonHover;
    sf::Texture pausedButtonHoverTexture;

    bool pauseKeyPressed;

    int level;

    std::mt19937_64 random_engine;

    std::vector<Bullet>* enemy_bullets;
    std::vector<Enemy>* enemies;
};

#endif