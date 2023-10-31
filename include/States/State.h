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
    State(sf::RenderWindow* window);
    virtual ~State();

    const bool& getQuit() const;
    virtual void checkForQuit();

    // Pure Functions
    virtual void endState() = 0;
    virtual void updateKeybinds() = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderTarget* target = nullptr) = 0;

private:
    sf::RenderWindow* mWindow;
    std::vector<sf::Texture> textures;
    bool quit;
};

#endif