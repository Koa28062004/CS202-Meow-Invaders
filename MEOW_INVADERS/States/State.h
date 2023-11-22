#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <stack>
#include <map>
#include <vector>
#include <string>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Entities/Player.h"

class State
{
public:
    State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states, int &choice);
    virtual ~State();

    // Functions
    const bool getQuit() const;
    void updateMousePosition();
    void pausedState();
    void unPausedState();
    void endState();

    // Pure Functions
    virtual void movingByKeyBoard() = 0;
    virtual void update(const float &dt) = 0;
    virtual void draw(sf::RenderTarget *target = nullptr) = 0;
    virtual void handleEvents(const sf::Event &event) = 0;
    virtual void initKeybinds() = 0;

    // Initialization
    void initFonts();
    void initPlayerTextures();

    const bool getKeytime();
    void updateKeytime(const float& dt);

    bool paused;

protected:
    sf::RenderWindow *mWindow;
    std::stack<State *> *states;
    std::map<std::string, int> *supportedKeys;
    std::map<std::string, int> keybinds;

    sf::Font font;
    sf::Font titleFont;
    sf::Font textBelowFont;

    bool quit;

    // Mouse Positions
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // Resources
    std::vector<sf::Sprite> playerSprites;
    std::vector<sf::Texture> playerTextures;
    std::vector<bool> isUnlocked;

    Player *player;
    EnemyManager *enemyManager;
    int chosen;

    float keytime;
	float keytimeMax;
};

#endif