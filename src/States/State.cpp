#include "States/State.h"

// Init Fonts
void State::initFonts() {
    if (!font.loadFromFile("assets/fonts/Roboto-Bold.ttf")) {
        throw std::runtime_error("Error::State::Could not load fonts");
    }
}

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
     : mWindow(window) {
    quit = false;

    this->supportedKeys = supportedKeys;
    this->states = states;
    
    initFonts();
}

State::~State() {

}

const bool& State::getQuit() const {
    return quit;
}

void State::checkForQuit () {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("CLOSE")))) {
        quit = true;
    }
} 

void State::updateMousePosition() {
    mousePosScreen = sf::Mouse::getPosition();
    mousePosWindow = sf::Mouse::getPosition(*this->mWindow);
    mousePosView = mWindow->mapPixelToCoords(sf::Mouse::getPosition(*this->mWindow));
}