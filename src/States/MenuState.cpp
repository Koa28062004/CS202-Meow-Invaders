#include "States/MenuState.h"

// Init Keybinds
void MenuState::initKeybinds()
{
    // std::ifstream ifs("config/keybinds.ini");

    // if (ifs.is_open())
    // {
    //     std::string key = "";
    //     std::string key2 = "";

    //     while (ifs >> key >> key2) {
    //         keybinds[key] = supportedKeys->at(key2);
    //     }
    // }

    // ifs.close();
}

// Init Fonts


MenuState::MenuState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys)
    : State(window, supportedKeys), mWindow(window)
{
    initFonts();
    initKeybinds();
}

MenuState::~MenuState()
{
}

void MenuState::updateInput()
{
    checkForQuit();

    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_LEFT"))))
    // {
    //     player.move(-5.f, 0.f);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_RIGHT"))))
    // {
    //     player.move(5.f, 0.f);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_UP"))))
    // {
    //     player.move(0.f, -5.f);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_DOWN"))))
    // {
    //     player.move(0.f, 5.f);
    // }
}

void MenuState::endState()
{
    std::cout << "End States\n";
}

void MenuState::update()
{
    updateMousePosition();
    updateInput();
}

void MenuState::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = mWindow;
    }

    // player.draw(target);
}