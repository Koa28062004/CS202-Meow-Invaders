#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "GameState.h"
#include "GUI/Button.h"

class MenuState : public State
{
public:
    MenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~MenuState();

    // Functions
    void endState();
    void update();
    void draw(sf::RenderTarget* target = nullptr);
    void drawButtons(sf::RenderTarget* target = nullptr);
    void updateInput();
    void updateButtons();

    // Initialization
    void initVariables();
    void initBackground();
    void initKeybinds();
    void initButtons();

protected:
    // sf::RenderWindow* mWindow;
    // std::map<std::string, int> keybinds;

private:
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    std::map<std::string, Button*> buttons;
};

#endif