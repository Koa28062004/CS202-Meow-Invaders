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
    State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~State();

    // Functions
    const bool &getQuit() const;
    virtual void updateMousePosition();
    void pausedState();
    void unPausedState();

    // Pure Functions
    virtual void endState();
    virtual void movingByKeyBoard() = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderTarget* target = nullptr) = 0;

    // Initialization
    virtual void initKeybinds() = 0;
    virtual void initFonts();

    bool paused;

protected:
    sf::RenderWindow* mWindow;
    std::stack<State*>* states;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;

    bool quit;
    sf::Font font;

    // Resources
    std::map<std::string, sf::Texture> textures;

    // Mouse Positions
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
};

#endif