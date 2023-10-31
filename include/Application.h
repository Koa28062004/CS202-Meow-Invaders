#ifndef APPLICATION_H
#define APPLICATION_H

#include "States/GameState.h"
#include "States/MenuState.h"

class Application
{
public:
    Application();
    virtual ~Application();

    // Initialization
    void initWindow();
    void initKeys();
    void initStates();

    // Functions
    void run();
    void handleEvents();
    void update();
    void draw();

private:
    // Variables
    sf::RenderWindow *mWindow;
    sf::Event event;

    std::map<std::string, int> supportedKeys;

    std::stack<State *> states;
};

#endif