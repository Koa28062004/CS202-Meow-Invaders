#include "Application.h"

// Init window
void Application::initWindow()
{
    // Create a window using option from config/window.ini file
    std::ifstream ifs("config/window.ini");
    videoModes = sf::VideoMode::getFullscreenModes();

    std::string title = "None";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
    bool fullscreen = false;
    unsigned framerate_limit = 60;
    bool vertical_sync_enabled = false;
    unsigned antialiasing_level = 0;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> fullscreen;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
        ifs >> antialiasing_level;
    }

    window_settings.antialiasingLevel = antialiasing_level;
    if (fullscreen)
    {
        mWindow = new sf::RenderWindow(window_bounds, title, sf::Style::Default, window_settings);
    }
    else
    {
        mWindow = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, window_settings);
    }

    mWindow->setFramerateLimit(framerate_limit);
    mWindow->setVerticalSyncEnabled(vertical_sync_enabled);
}

// Init Keys
void Application::initKeys()
{
    std::ifstream ifs("config/supportedKeys.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        int key_value = 0;
        while (ifs >> key >> key_value)
        {
            supportedKeys[key] = key_value;
        }
    }

    ifs.close();
}

// Init States
void Application::initStates()
{
    states.push(new MenuState(mWindow, &supportedKeys, &states));
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
        }
    }
}

void Application::update()
{
    if (!states.empty())
    {
        states.top()->update();

        if (states.top()->getQuit())
        {
            states.top()->endState();
            delete states.top();
            states.pop();
            if (states.empty())
                mWindow->close();
        }
    }
}

void Application::draw()
{
    mWindow->clear(sf::Color::White);

    // Draw items
    if (!states.empty())
    {
        states.top()->draw();
    }

    mWindow->display();
}