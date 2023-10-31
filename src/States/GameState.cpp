#include "States/GameState.h"

GameState::GameState(sf::RenderWindow* window)
     : State(window), mWindow(window) {

}

GameState::~GameState() {

}

void GameState::updateKeybinds() {
    checkForQuit();
}

void GameState::endState() {
    std::cout << "End States\n";
}

void GameState::update() {
    updateKeybinds();
    
    player.update();
}

void GameState::draw(sf::RenderTarget* target) {
    player.draw(mWindow);
}