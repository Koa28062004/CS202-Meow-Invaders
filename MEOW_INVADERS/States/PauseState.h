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
#include "State.h"

class PauseState
{
public:
    PauseState(sf::RenderWindow *window);
    virtual ~PauseState();

    // Functions
    void update();
    void draw(sf::RenderTarget *target = nullptr);
    
private:
    // Initialization
    void initVariables();
    void initTitle();
    void initBackground();
    void initPlayButton();

    // Functions
    void updatePlayButton();

    sf::RenderWindow *mWindow;
    sf::RectangleShape *background;
    sf::Texture *titleTexture;
    sf::Sprite *titleSprite;

    std::map<std::string, sf::Texture *> textures;

    // Play button idle
    sf::RectangleShape playButtonIdle;
    sf::Texture playButtonIdleTexture;

    // Play button hover
    bool checkPlayButton;
    sf::RectangleShape playButtonHover;
    sf::Texture playButtonHoverTexture;
};

#endif