#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include "Entities/Entity.h"

class GameState : public State {
public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~GameState();

    // Functions
    void endState();
    void update();
    void draw(sf::RenderTarget* target = nullptr);
    void updateInput();

protected:
    void initKeybinds();
    Entity player; 
    sf::RenderWindow* mWindow;
    std::map<std::string, int> keybinds;
};

#endif