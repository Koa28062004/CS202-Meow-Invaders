#ifndef SETTING_STATE_H
#define SETTING_STATE_H

#include "State.h"
#include "GUI/TextBox.h"
#include "GUI/Button.h"

class SettingState : public State
{
public:
    SettingState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states, int &choice);
    ~SettingState();

    void movingByKeyBoard() {}
    void update();
    void draw(sf::RenderTarget *target);
    void handleEvents(const sf::Event &event);
    void initKeybinds() {}

private:
    // Init
    void initBackground();
    void initTextBox();
    void initButtons();

    // Draw
    void drawTitle(sf::RenderTarget *target);
    void drawProperties(sf::RenderTarget *target);
    void drawButtons(sf::RenderTarget *target);

    void handleButtons();

    sf::RenderWindow *mWindow;

    // Background
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::RectangleShape backgroundOver;

    sf::Font roboto;

    std::map<std::string, Button *> buttons;
    std::map<std::string, TextBox *> textboxs;
};

#endif