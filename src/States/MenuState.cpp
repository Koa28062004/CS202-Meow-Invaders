#include "States/MenuState.h"

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
    // New Game
    buttons["GAME_STATE"] = new Button(mWindow->getSize().x / 2, 150, 170, 80,
                                       &font, "New Game",
                                       sf::Color(70, 70, 70, 200),
                                       sf::Color(150, 150, 150, 255),
                                       sf::Color(20, 20, 20, 200));

    // Pause Game
    buttons["CONTINUE_STATE"] = new Button(300, 280, 150, 50,
                                           &font, "Continue",
                                           sf::Color(70, 80, 70, 200),
                                           sf::Color(150, 150, 150, 255),
                                           sf::Color(20, 20, 20, 200));

    // Store
    buttons["STORE_STATE"] = new Button(300, 380, 150, 50,
                                        &font, "Store",
                                        sf::Color(70, 80, 70, 200),
                                        sf::Color(150, 150, 150, 255),
                                        sf::Color(20, 20, 20, 200));

    // Instructions
    buttons["INTRUCTIONS_STATE"] = new Button(300, 480, 150, 50,
                                              &font, "Instructions",
                                              sf::Color(70, 80, 70, 200),
                                              sf::Color(150, 150, 150, 255),
                                              sf::Color(20, 20, 20, 200));

    // Settings
    buttons["SETTINGS_STATE"] = new Button(300, 680, 150, 50,
                                              &font, "Settings",
                                              sf::Color(70, 80, 70, 200),
                                              sf::Color(150, 150, 150, 255),
                                              sf::Color(20, 20, 20, 200));

    // Quit
    buttons["EXIT_STATE"] = new Button(300, 780, 150, 50,
                                       &font, "Quit",
                                       sf::Color(100, 100, 100, 200),
                                       sf::Color(150, 150, 150, 255),
                                       sf::Color(20, 20, 20, 200));
}

MenuState::MenuState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states)
    : State(window, supportedKeys, states)
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

void MenuState::updateInput()
{
}
void MenuState::update()
{
    updateMousePosition();
    updateInput();
    updateButtons();
}

void MenuState::updateButtons()
{
    // Update all the buttons and handle their functions
    for (auto &it : buttons)
    {
        it.second->update(mousePosView);
    }

    // New game
    if (buttons["GAME_STATE"]->isPressed())
    {
        states->push(new GameState(mWindow, supportedKeys, states));
    }

    // Exit game
    if (buttons["EXIT_STATE"]->isPressed())
    {
        endState();
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