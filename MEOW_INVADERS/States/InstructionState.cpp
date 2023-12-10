#include "InstructionState.h"

void InstructionState::initButton()
{
    sf::Text tmp;
    tmp.setString("Quit");
    tmp.setCharacterSize(40);
    buttons["BACK_GAME"] = new Button(mWindow->getSize().x / 2 - tmp.getGlobalBounds().width / 2, 750, 0, 0,
                                      &titleFont, "Quit",
                                      sf::Color(0, 0, 0, 0),
                                      sf::Color(0, 0, 0, 0),
                                      sf::Color(0, 0, 0, 0));
}

void InstructionState::initBackground()
{
    background.setSize(sf::Vector2f(
        static_cast<float>(mWindow->getSize().x),
        static_cast<float>(mWindow->getSize().y)));

    if (!backgroundTexture.loadFromFile("assets/images/instructionBG.png"))
    {
        throw std::runtime_error("Error::SettingState::Failed to load instructionBG.png");
    }

    background.setTexture(&backgroundTexture);

    backgroundOver = new sf::RectangleShape();
    backgroundOver->setSize(sf::Vector2f((float)mWindow->getSize().x,
                                         (float)mWindow->getSize().y));
    backgroundOver->setFillColor(sf::Color(20, 20, 20, 100));
}

InstructionState::InstructionState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states, int &choice)
    : State(window, supportedKeys, states, choice),
      mWindow(window)
{
    if (!roboto.loadFromFile("assets/fonts/Roboto-Bold.ttf"))
    {
        throw std::runtime_error("Error::SettingState::Failed to load Roboto");
    }

    initBackground();
    initButton();
}

InstructionState::~InstructionState()
{
    delete backgroundOver;
    auto it = buttons.begin();
    for (it = buttons.begin(); it != buttons.end(); ++it)
    {
        delete it->second;
    }
}

void InstructionState::handleEvents(const sf::Event &event)
{
}

void InstructionState::updateButtons()
{
    // Quit
    if (buttons["BACK_GAME"]->isPressed() && this->getKeytime())
    {
        this->endState();
    }
}

void InstructionState::update(const float &dt)
{
    updateKeytime(dt);
    updateMousePosition();
    updateButtons();

    // Update all the buttons and handle their functions
    for (auto &it : buttons)
    {
        it.second->update(mousePosView);
    }
}

void InstructionState::draw(sf::RenderTarget *target)
{
    if (!target)
        target = mWindow;
    target->draw(background);
    target->draw(*backgroundOver);
    drawButtons(target);
    drawTitle(target);
    drawText(target);
}

void InstructionState::drawText(sf::RenderTarget *target)
{
    sf::Text text1;
    sf::Vector2f textPos1;
    float x = 0;
    text1.setFont(roboto);
    text1.setString("- Save Earth by defeating the enemy invaders!");
    text1.setCharacterSize(45);
    text1.setOutlineColor(sf::Color(255, 153, 255, 200));
    text1.setOutlineThickness(1);
    text1.setFillColor(sf::Color::White);

    textPos1 = sf::Vector2f{mWindow->getSize().x / 2.0f - text1.getGlobalBounds().width / 2.0f - 180.f,
                            mWindow->getSize().y / 2.0f - text1.getGlobalBounds().height / 2.0f - 210.f};

    text1.setPosition(textPos1.x, textPos1.y);
    x = textPos1.x;
    target->draw(text1);

    text1.setString("- Use WASD keys by default to navigate your spaceship.");
    textPos1 = sf::Vector2f{mWindow->getSize().x / 2.0f - text1.getGlobalBounds().width / 2.0f - 180.f,
                            mWindow->getSize().y / 2.0f - text1.getGlobalBounds().height / 2.0f - 130.f};

    text1.setPosition(x, textPos1.y);
    target->draw(text1);

    text1.setString("- Use P keys for pause and unpaused game.");
    textPos1 = sf::Vector2f{mWindow->getSize().x / 2.0f - text1.getGlobalBounds().width / 2.0f - 180.f,
                            mWindow->getSize().y / 2.0f - text1.getGlobalBounds().height / 2.0f - 50.f};

    text1.setPosition(x, textPos1.y);
    target->draw(text1);

    text1.setString("- You can change any keys you like in Setting.");
    textPos1 = sf::Vector2f{mWindow->getSize().x / 2.0f - text1.getGlobalBounds().width / 2.0f - 180.f,
                            mWindow->getSize().y / 2.0f - text1.getGlobalBounds().height / 2.0f + 30.f};

    text1.setPosition(x, textPos1.y);
    target->draw(text1);

    text1.setString("- Meow Invaders offers an unlimited number of levels.");
    textPos1 = sf::Vector2f{mWindow->getSize().x / 2.0f - text1.getGlobalBounds().width / 2.0f - 180.f,
                            mWindow->getSize().y / 2.0f - text1.getGlobalBounds().height / 2.0f + 110.f};

    text1.setPosition(x, textPos1.y);
    target->draw(text1);

    text1.setString("- Access 3 unique power-ups during gameplay.");
    textPos1 = sf::Vector2f{mWindow->getSize().x / 2.0f - text1.getGlobalBounds().width / 2.0f - 180.f,
                            mWindow->getSize().y / 2.0f - text1.getGlobalBounds().height / 2.0f + 190.f};

    text1.setPosition(x, textPos1.y);
    target->draw(text1);
}

void InstructionState::drawTitle(sf::RenderTarget *target)
{
    sf::Text textTitle;
    textTitle.setFont(titleFont);
    textTitle.setString("Welcome to Meow Invaders");
    textTitle.setCharacterSize(90);
    textTitle.setFillColor(sf::Color::White);
    textTitle.setPosition(mWindow->getSize().x / 2.0f - textTitle.getGlobalBounds().width / 2.0f, mWindow->getSize().y / 2.0f - textTitle.getGlobalBounds().height / 2.0f - 350.f);

    target->draw(textTitle);
}

void InstructionState::drawButtons(sf::RenderTarget *target)
{
    for (auto &it : buttons)
    {
        it.second->draw(target);
    }
}