#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"

class GameState : public State {
public:
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

    // Functions
    void update();
    void draw(sf::RenderTarget* target = nullptr);
    void movingByKeyBoard();

private:
    // Initialization
    void initPlayer();
    void initTextures();
    void initKeybinds();

    Player* player; 
    sf::RenderWindow* mWindow;
};

#endif