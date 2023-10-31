#include "States/State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : mWindow(window) {
    quit = false;
    this->supportedKeys = supportedKeys;
}

State::~State() {

}

const bool& State::getQuit() const {
    return quit;
}

void State::checkForQuit () {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        quit = true;
    }
} 