#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <chrono>
#include <random>

#include "State.h"
#include "PauseState.h"
#include "Entities/EnemyManager.h"
#include "GUI/Button.h"

class GameState : public State
{
public:
    GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states, int &choice);
    virtual ~GameState();

    // Functions
    void updatePausedInput();
    void update(const float &dt);
    void draw(sf::RenderTarget *target = nullptr);
    void handleEvents(const sf::Event &event);

    void movingByKeyBoard();
    void movingByMouse();

    // Playing game
    void updatingPlayingGame();
    void drawPlayingGame(sf::RenderTarget *target);
    void drawLevelUp(sf::RenderTarget *target);
    void drawLevelScreen(sf::RenderTarget *target);

    void handlePlayButton();
    void handleHomeButton();
    void handleSettingButton();

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
    void initFont();
    void initGameOverButtons();

    // Functions
    void updatePausedButton();
    void handleGameOver();
    void updateLevelUp();
    void updatePlayerPosition();

    PauseState *pauseState;
    sf::RenderWindow *mWindow;

    sf::RectangleShape background;
    sf::Texture backgroundTexture;

    // Game over background
    sf::RectangleShape backgroundGameOver;

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

    std::vector<Bullet> *enemy_bullets;
    std::vector<Enemy> *enemies;
    std::vector<Disaster> *disasters;
    std::vector<Disaster> *randomDisasters;

    std::map<std::string, Button *> buttons;

    bool isNextLevel;
    bool isReset;
    bool isEnterClicked;
    bool checkClock;
    int choice;
};

#endif