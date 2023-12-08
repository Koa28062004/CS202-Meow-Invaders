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
    void draw();

    //Update
	void updateDt();
    void update();

private:
    // Variables
    sf::RenderWindow *mWindow;
    sf::Event event;
    std::vector<sf::VideoMode> videoModes;
    sf::ContextSettings window_settings;

    std::map<std::string, int> supportedKeys;

    std::stack<State *> states;

    sf::Clock dtClock;
	float dt;

    std::string fileName;
};

#endif