#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "States/State.h"
#include "Entities/Entity.h"

class GameState : public State {
public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    // Functions
    void endState();
    void update();
    void draw(sf::RenderTarget* target = nullptr);
    void updateKeybinds();

private:
    Entity player; 
    sf::RenderWindow* mWindow;
};

#endif