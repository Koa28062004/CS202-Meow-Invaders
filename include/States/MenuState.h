#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "GameState.h"
#include "GUI/Button.h"

class MenuState : public State
{
public:
    MenuState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys);
    virtual ~MenuState();

    // Functions
    void endState();
    void update();
    void draw(sf::RenderTarget *target = nullptr);
    void updateInput();

    // Initialization
    void initKeybinds();

protected:
    sf::RenderWindow *mWindow;
    std::map<std::string, int> keybinds;
};

#endif