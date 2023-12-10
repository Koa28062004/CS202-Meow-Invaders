#ifndef INSTRUCTION_STATE_H
#define INSTRUCTION_STATE_H

#include "State.h"
#include "GUI/Button.h"

class InstructionState : public State
{
public:
    InstructionState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states, int &choice);
    ~InstructionState();

    void movingByKeyBoard() {}
    void update(const float &dt);
    void draw(sf::RenderTarget *target);
    void handleEvents(const sf::Event &event);
    void initKeybinds() {}
    void saveGame(std::string fileName) {}

private:
    // init
    void initBackground();
    void initButton();

    void updateButtons();

    void drawButtons(sf::RenderTarget *target);
    void drawTitle(sf::RenderTarget *target);
    void drawText(sf::RenderTarget *target);

    sf::RenderWindow *mWindow;

    sf::Font roboto;

    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::RectangleShape *backgroundOver;

    std::map<std::string, Button *> buttons;
};

#endif