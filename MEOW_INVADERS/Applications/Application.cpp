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
    int choice = 0;
    states.push(new MenuState(mWindow, &supportedKeys, &states, choice));
}

Application::Application()
{
    initWindow();
    initKeys();
    initStates();

    fileName = "config/save.txt";
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
        updateDt();
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
    if (!states.empty())
    {
        states.top()->handleEvents(event);
    }
}

void Application::update()
{
    if (!states.empty())
    {
        states.top()->update(this->dt);

        while (!states.empty() && states.top()->getQuit())
        {
            if (states.top()->isSaved)
                states.top()->saveGame(fileName);
            delete states.top();
            states.pop();
        }
        if (states.empty())
            mWindow->close();
    }
}

void Application::updateDt()
{
    /*Updates the dt variable with the time it takes to update and render one frame.*/
    this->dt = this->dtClock.restart().asSeconds();
}

void Application::draw()
{
    // Draw items
    if (!states.empty() && !states.top()->isLoad)
    {
        mWindow->clear(sf::Color::White);
        states.top()->draw();
        mWindow->display();
    }
}