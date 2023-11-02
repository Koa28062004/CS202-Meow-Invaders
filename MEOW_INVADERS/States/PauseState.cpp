#include "PauseState.h"

void PauseState::initVariables()
{
    titleTexture = new sf::Texture();
    titleSprite = new sf::Sprite();
    background = new sf::RectangleShape();

    checkPlayButton = false;
}

void PauseState::initTitle()
{
    // title
    if (!titleTexture->loadFromFile("assets/images/gamePausedTitle.png"))
    {
        throw std::runtime_error("Error::Failed to load gamePausedTitle.png at PauseState");
    }

    titleSprite->setTexture(*this->titleTexture);
    titleSprite->setPosition(sf::Vector2f(mWindow->getSize().x / 2 - titleSprite->getGlobalBounds().width / 2,
                                          titleSprite->getGlobalBounds().height / 8 - 5.f));
}

void PauseState::initBackground()
{
    background->setSize(sf::Vector2f((float)mWindow->getSize().x,
                                     (float)mWindow->getSize().y));
    background->setFillColor(sf::Color(20, 20, 20, 100));
}

void PauseState::initPlayButton()
{
    // Play button idle
    playButtonIdle.setSize(sf::Vector2f(130.f, 110.f));
    if (!playButtonIdleTexture.loadFromFile("assets/images/playButtonIdle.png"))
    {
        throw std::runtime_error("Error::GameState::Failed to load playButtonIdle.png");
    }

    playButtonIdle.setTexture(&playButtonIdleTexture);
    playButtonIdle.setPosition(mWindow->getSize().x / 2 - playButtonIdle.getGlobalBounds().width / 2, 270.f);

    // Play button hover
    playButtonHover.setSize(sf::Vector2f(130.f, 110.f));
    if (!playButtonHoverTexture.loadFromFile("assets/images/playButtonHover.png"))
    {
        throw std::runtime_error("Error::GameState::Failed to load playButtonHover.png");
    }

    playButtonHover.setTexture(&playButtonHoverTexture);
    playButtonHover.setPosition(mWindow->getSize().x / 2 - playButtonHover.getGlobalBounds().width / 2, 270.f);
}

PauseState::PauseState(sf::RenderWindow* window) : mWindow(window)
{
    initVariables();
    initTitle();
    initBackground();
    initPlayButton();
}

PauseState::~PauseState()
{
    delete titleSprite;
    delete titleTexture;
    delete background;
}

void PauseState::updatePlayButton()
{
    // Check if the mouse is within the bounds of the pausedButton
    // if (playButtonIdle.getGlobalBounds().contains(mousePosView))
    // {
    //     // Active
    //     if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    //     {
    //         unPausedState();
    //     }

    //     checkPlayButton = true;
    // }
    // else
    // {
    //     checkPlayButton = false;
    // }
}

// Functions
void PauseState::update()
{
    updatePlayButton();
}

void PauseState::draw(sf::RenderTarget *target)
{
    if (!target)
        target = mWindow;
    if (background)
        target->draw(*this->background);
    if (titleSprite)
        target->draw(*this->titleSprite);

    if (!checkPlayButton) {
        target->draw(playButtonIdle);
    }
    else {
        target->draw(playButtonHover);
    }
}