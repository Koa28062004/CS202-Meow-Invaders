#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "GameState.h"
#include "PreparedState.h"
#include "SettingState.h"
#include "GUI/Button.h"

class MenuState : public State
{
public:
    MenuState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states, int &choice);
    virtual ~MenuState();

    // Functions
    void update(const float &dt);
    void draw(sf::RenderTarget *target = nullptr);
    void handleEvents(const sf::Event &event);
    void drawButtons(sf::RenderTarget *target = nullptr);
    void movingByKeyBoard();
    void handleButtonPressed();

    // Initialization
    void initVariables();
    void initBackground();
    void initKeybinds();
    void initButtons();

protected:
private:
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    std::map<std::string, Button *> buttons;
};

#endif