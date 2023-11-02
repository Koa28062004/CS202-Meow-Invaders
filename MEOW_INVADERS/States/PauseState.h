#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H

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

#include "GUI/Button.h"

class PauseState
{
public:
    PauseState(sf::RenderWindow* window);
    virtual ~PauseState();

    // Functions
    void update();
    void draw(sf::RenderTarget* target = nullptr);

private:
    sf::RectangleShape background;
    sf::RectangleShape container;
    std::map<std::string, Button*> buttons;
};

#endif