#include "States/GameState.h"

// Init Keybinds
void GameState::initKeybinds() {
    keybinds.emplace("MOVE_LEFT", supportedKeys->at("A"));
    keybinds.emplace("MOVE_RIGHT", supportedKeys->at("D"));
    keybinds.emplace("MOVE_UP", supportedKeys->at("W"));
    keybinds.emplace("MOVE_DOWN", supportedKeys->at("S"));
}

GameState::GameState(sf::RenderWindow *window, std::map<std::string, int>* supportedKeys)
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_LEFT")))) {
        player.move(-5.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_RIGHT")))) {
        player.move(5.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_UP")))) {
        player.move(0.f, -5.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_DOWN")))) {
        player.move(0.f, 5.f);
    }
}

void GameState::endState()
{
    std::cout << "End States\n";
}

void GameState::update()
{
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