#include "MenuState.h"
#include <chrono>

// Init Variables
void MenuState::initVariables()
{
}

// Init Background
void MenuState::initBackground()
{
    background.setSize(sf::Vector2f(
        static_cast<float>(mWindow->getSize().x),
        static_cast<float>(mWindow->getSize().y)));

    if (!backgroundTexture.loadFromFile("assets/images/background.png"))
    {
        throw std::runtime_error("Error::Menu State::Failed to load background.png");
    }

    background.setTexture(&backgroundTexture);
}

// Init Keybinds
void MenuState::initKeybinds()
{
    std::ifstream ifs("config/gameState_keybinds.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";

        while (ifs >> key >> key2)
        {
            keybinds[key] = supportedKeys->at(key2);
        }
    }

    ifs.close();
}

// Init Buttons
void MenuState::initButtons()
{
    sf::Text tmp;
    tmp.setString("New Game");
    tmp.setCharacterSize(40);

    // New Game
    buttons["GAME_STATE"] = new Button(mWindow->getSize().x / 2 - tmp.getGlobalBounds().width / 2, 300, 0, 0,
                                       &font, "New Game",
                                       sf::Color(0, 0, 0, 0),
                                       sf::Color(0, 0, 0, 0),
                                       sf::Color(0, 0, 0, 0));

    tmp.setString("Continue");
    tmp.setCharacterSize(40);
    // Pause Game
    buttons["CONTINUE_STATE"] = new Button(mWindow->getSize().x / 2 - tmp.getGlobalBounds().width / 2, 400, 0, 0,
                                           &font, "Continue",
                                           sf::Color(0, 0, 0, 0),
                                           sf::Color(0, 0, 0, 0),
                                           sf::Color(0, 0, 0, 0));

    tmp.setString("Options");
    tmp.setCharacterSize(40);
    // Options
    buttons["OPTIONS_STATE"] = new Button(mWindow->getSize().x / 2 - tmp.getGlobalBounds().width / 2, 500, 0, 0,
                                          &font, "Options",
                                          sf::Color(0, 0, 0, 0),
                                          sf::Color(0, 0, 0, 0),
                                          sf::Color(0, 0, 0, 0));

    tmp.setString("Settings");
    tmp.setCharacterSize(40);
    // Settings
    buttons["SETTINGS_STATE"] = new Button(mWindow->getSize().x / 2 - tmp.getGlobalBounds().width / 2, 600, 0, 0,
                                           &font, "Settings",
                                           sf::Color(0, 0, 0, 0),
                                           sf::Color(0, 0, 0, 0),
                                           sf::Color(0, 0, 0, 0));

    tmp.setString("Quit");
    tmp.setCharacterSize(40);
    // Quit
    buttons["EXIT_STATE"] = new Button(mWindow->getSize().x / 2 - tmp.getGlobalBounds().width / 2, 700, 0, 0,
                                       &font, "Quit",
                                       sf::Color(0, 0, 0, 0),
                                       sf::Color(0, 0, 0, 0),
                                       sf::Color(0, 0, 0, 0));
}

MenuState::MenuState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states, int &choice)
    : State(window, supportedKeys, states, choice)
{
    initVariables();
    initBackground();
    initKeybinds();
    initButtons();
}

MenuState::~MenuState()
{
    auto it = buttons.begin();
    for (it = buttons.begin(); it != buttons.end(); ++it)
    {
        delete it->second;
    }
}

void MenuState::movingByKeyBoard()
{
}

void MenuState::update(const float &dt)
{
    updateKeys();
    updateMousePosition();
    movingByKeyBoard();
    handleButtonPressed();
    updateKeytime(dt);

    // Update all the buttons and handle their functions
    for (auto &it : buttons)
    {
        it.second->update(mousePosView);
    }
}

void MenuState::handleEvents(const sf::Event &event)
{
    switch (event.type)
    {
    case sf::Event::MouseButtonReleased:
        if (event.mouseButton.button == sf::Mouse::Left)
        {
        }
        break;
    }
}

void MenuState::handleButtonPressed()
{
    int choice = 0;

    // New game
    if (buttons["GAME_STATE"]->isPressed() && this->getKeytime())
    {
        states->push(new PreparedState(mWindow, supportedKeys, states, choice));
    }

    // Continue
    if (buttons["CONTINUE_STATE"]->isPressed() && this->getKeytime())
    {
        states->top()->setIsLoad(true);
        states->push(new GameState(mWindow, supportedKeys, states, choice));
    }

    // Setting
    if (buttons["SETTINGS_STATE"]->isPressed() && this->getKeytime())
    {
        states->push(new SettingState(mWindow, supportedKeys, states, choice));
    }

    // Exit game

    if (buttons["EXIT_STATE"]->isPressed() && this->getKeytime())
    {
        this->endState();
    }
}

void MenuState::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = mWindow;
    }

    target->draw(background);
    this->drawButtons(target);

    // Watch the position of mouse position view
    // sf::Text mouseText;
    // mouseText.setPosition(mousePosView.x, mousePosView.y - 30);
    // mouseText.setFont(font);
    // mouseText.setCharacterSize(20);
    // std::stringstream ss;
    // ss << mousePosView.x << ' ' << mousePosView.y;
    // mouseText.setString(ss.str());

    // target->draw(mouseText);
}

void MenuState::drawButtons(sf::RenderTarget *target)
{
    for (auto &it : buttons)
    {
        it.second->draw(target);
    }
}