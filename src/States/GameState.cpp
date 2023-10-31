#include "States/GameState.h"

// Init Keybinds
void GameState::initKeybinds()
{
    std::ifstream ifs("config/keybinds.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";

        while (ifs >> key >> key2) {
            keybinds[key] = supportedKeys->at(key2);
        }
    }

    ifs.close();
}

GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys)
    : State(window, supportedKeys), mWindow(window)
{
    initKeybinds();
}

GameState::~GameState()
{
}

void GameState::updateInput()
{
    checkForQuit();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_LEFT"))))
    {
        player.move(-5.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_RIGHT"))))
    {
        player.move(5.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_UP"))))
    {
        player.move(0.f, -5.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_DOWN"))))
    {
        player.move(0.f, 5.f);
    }
}

void GameState::endState()
{
    std::cout << "End States\n";
}

void GameState::update()
{
    updateMousePosition();
    updateInput();
    player.update();
}

void GameState::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = mWindow;
    }

    player.draw(target);
}