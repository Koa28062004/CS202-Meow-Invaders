#include "Application.h"

// Init window
void Application::initWindow()
{
    // Create a window using option from config/window.ini file
    std::ifstream ifs("config/window.ini");

    std::string title = "None";
    sf::VideoMode window_bounds(1000, 800);
    unsigned framerate_limit = 60;
    bool vertical_sync_enabled = false;

    if (ifs.is_open()) {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    mWindow = new sf::RenderWindow(window_bounds, title);
    mWindow->setFramerateLimit(framerate_limit);
    mWindow->setVerticalSyncEnabled(vertical_sync_enabled);
}

// Init Keys
void Application::initKeys() {
    std::ifstream ifs("config/supportedKeys.ini");

    if (ifs.is_open()) {
        std::string key = "";
        int key_value = 0;
        while (ifs >> key >> key_value) {
            supportedKeys[key] = key_value;
        }
    }

    ifs.close();
}

// Init States
void Application::initStates() {
    states.push(new MenuState(mWindow, &supportedKeys));
    states.push(new GameState(mWindow, &supportedKeys));
}

Application::Application()
{
    initWindow();
    initKeys(); 
    initStates();
}

Application::~Application()
{
    delete mWindow;

    while (!states.empty())
    {
        delete states.top();
        states.pop();
    }
    
}

// Functions
void Application::run()
{
    while (mWindow->isOpen())
    {
        handleEvents();
        update();
        draw();
    }
}

void Application::handleEvents()
{
    while (mWindow->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            mWindow->close();
            break;
        case sf::Event::GainedFocus:
            // CurrentState::isPaused = false;
            break;
        case sf::Event::LostFocus:
            // CurrentState::isPaused = true;
            break;
        // case sf::Event::KeyPressed:
        //     if (event.key.code == sf::Keyboard::Escape)
        //         mWindow->close();
        //     break;
        }
    }
}

void Application::update() {
    if (!states.empty()) {
        states.top()->update();

        if (states.top()->getQuit()) {
            states.top()->endState();
            delete states.top();
            states.pop();
        }
    }
}

void Application::draw() {
    mWindow->clear(sf::Color::White);

    // Draw items
    if (!states.empty()) {
        states.top()->draw();
    }

    mWindow->display();
}