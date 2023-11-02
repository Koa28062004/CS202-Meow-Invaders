#include "PauseState.h"

void PauseState::initVariables()
{
    titleTexture = new sf::Texture();
    titleSprite = new sf::Sprite();
    background = new sf::RectangleShape();
}

void PauseState::initTitle()
{
    // title
    if (!titleTexture->loadFromFile("assets/images/gamePausedTitle.png"))
    {
        throw std::runtime_error("Error::Failed to load gamePausedTitle.png at PauseState");
    }

    titleSprite->setTexture(*this->titleTexture);
    titleSprite->setPosition(sf::Vector2f(mWindow->getSize().x / 2 - titleSprite->getGlobalBounds().width/2,
                                          titleSprite->getGlobalBounds().height/8 - 5.f));
}

void PauseState::initBackground()
{
    background->setSize(sf::Vector2f((float)mWindow->getSize().x,
                                     (float)mWindow->getSize().y));
    background->setFillColor(sf::Color(20, 20, 20, 100));
}

PauseState::PauseState(sf::RenderWindow *window) : mWindow(window)
{
    initVariables();
    initTitle();
    initBackground();
}

PauseState::~PauseState()
{
    delete titleSprite;
    delete titleTexture;
    delete background;
}

// Functions
void PauseState::update()
{
}

void PauseState::draw(sf::RenderTarget *target)
{
    if (!target)
        target = mWindow;
    if (background)
        target->draw(*this->background);
    if (titleSprite)
        target->draw(*this->titleSprite);
}