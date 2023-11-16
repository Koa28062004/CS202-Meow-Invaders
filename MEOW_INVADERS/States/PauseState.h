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
    void update(bool &paused, sf::Vector2f &mousePosView);
    void draw(sf::RenderTarget *target = nullptr);
    void handleEvents(const sf::Event &event);
    const bool getHome();
    void handlePlayButton();

private:
    // Initialization
    void initVariables();
    void initTitle();
    void initBackground();

    // Play button
    void initPlayButton();
    void updatePlayButton(bool &paused, sf::Vector2f &mousePosView);

    // Setting button
    void initSettingButton();
    void updateSettingButton(sf::Vector2f &mousePosView);

    // Home button
    void initHomeButton();
    void updateHomeButton(sf::Vector2f &mousePosView);

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

    // Setting button idle
    sf::RectangleShape settingButtonIdle;
    sf::Texture settingButtonIdleTexture;

    // Setting button hover
    bool checkSettingButton;
    sf::RectangleShape settingButtonHover;
    sf::Texture settingButtonHoverTexture;

    // Home button idle
    sf::RectangleShape homeButtonIdle;
    sf::Texture homeButtonIdleTexture;

    // Home button hover
    bool checkHomeButton;
    sf::RectangleShape homeButtonHover;
    sf::Texture homeButtonHoverTexture;

    bool isClickedHomeButton;

    std::chrono::steady_clock::time_point lastButtonClickTime;
    const std::chrono::milliseconds clickCooldown{500};
};

#endif