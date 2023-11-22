#ifndef PREPARED_STATE_H
#define PREPARED_STATE_H

#include "State.h"
#include "GUI/Button.h"
#include "GameState.h"

class PreparedState : public State
{
public:
    PreparedState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states, int &choice);
    ~PreparedState();

    // Functions
    void movingByKeyBoard() {}
    void initKeybinds() {}

    void handleEvents(const sf::Event &event);
    void update(const float &dt);
    void draw(sf::RenderTarget *target);

private:
    // Initialization
    void initBackground();
    void initNextButtons();
    void initButtons();

    // Next Buttons
    void updateNextButtons();
    void drawNextButtons(sf::RenderTarget *target);

    void drawButtons(sf::RenderTarget *target);
    void handleButtons();

    // Draw Spaceship
    void drawSpaceship(sf::RenderTarget *target);

    // Draw preparation
    void drawTitle(sf::RenderTarget *target);

    sf::RenderWindow *mWindow;

    // Background
    sf::RectangleShape background;
    sf::Texture backgroundTexture;

    // left next button
    sf::Texture nextButtonLeftTex;
    sf::Sprite nextButtonLeftSprite;

    // right right button
    sf::Texture nextButtonRightTex;
    sf::Sprite nextButtonRightSprite;

    sf::RectangleShape backgroundOver;
    std::map<std::string, Button*> buttons;
};

#endif