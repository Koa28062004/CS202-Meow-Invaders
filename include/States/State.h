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

class State {
public:
    State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~State();

    const bool& getQuit() const;
    virtual void checkForQuit();

    // Pure Functions
    virtual void endState() = 0;
    virtual void updateInput() = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderTarget* target = nullptr) = 0;

protected:
    virtual void initKeybinds() = 0;
    sf::RenderWindow* mWindow;
    bool quit;
    std::map<std::string, int>* supportedKeys;

    // Resources 
    std::vector<sf::Texture> textures;
};

#endif