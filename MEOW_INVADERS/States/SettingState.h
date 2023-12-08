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
    void update(const float &dt);
    void draw(sf::RenderTarget *target);
    void handleEvents(const sf::Event &event);
    void initKeybinds();

    void saveGame(std::string fileName) {}

private:
    // Init
    void initBackground();
    void initTextBox();
    void initButtons();
    void initRecs();
    void initRectangle(std::string name);

    // Draw
    void drawTitle(sf::RenderTarget *target);
    void drawProperties(sf::RenderTarget *target);
    void drawButtons(sf::RenderTarget *target);
    void drawRecs(sf::RenderTarget *target);
    void drawTextBox(sf::RenderTarget *target);

    void handleButtons();
    void checkButtons(std::string name);
    void checkKeys();
    void checkKey(std::string name);
    // bool invalidKeys();

    void setUpTextBox(std::string name);

    sf::RenderWindow *mWindow;

    // Background
    sf::RectangleShape background;
    sf::Texture backgroundTexture;
    sf::RectangleShape backgroundOver;

    sf::Font roboto;

    std::map<std::string, Button *> buttons;
    std::map<std::string, TextBox *> textboxs;
    std::map<std::string, sf::RectangleShape *> rectangles;

    sf::Text moveLeft;
    sf::Text fire;
    sf::Text moveBy;
    sf::Text moveRight;
    sf::Text moveUp;
    sf::Text moveDown;

    sf::Vector2f left, right, up, down, vFire, vBy;
};

#endif