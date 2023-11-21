#include "PauseState.h"

void PauseState::initVariables()
{
    titleTexture = new sf::Texture();
    titleSprite = new sf::Sprite();
    background = new sf::RectangleShape();

    checkPlayButton = false;
    isClickedHomeButton = false;
    isClickedSettingButton = false;
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

// Init play button
void PauseState::initPlayButton()
{
    // Play button idle
    playButtonIdle.setSize(sf::Vector2f(130.f, 110.f));
    if (!playButtonIdleTexture.loadFromFile("assets/images/playButtonIdle.png"))
    {
        throw std::runtime_error("Error::GameState::Failed to load playButtonIdle.png");
    }

    playButtonIdle.setTexture(&playButtonIdleTexture);
    playButtonIdle.setPosition(mWindow->getSize().x / 2 - playButtonIdle.getGlobalBounds().width / 2, 272.f);

    // Play button hover
    playButtonHover.setSize(sf::Vector2f(130.f, 110.f));
    if (!playButtonHoverTexture.loadFromFile("assets/images/playButtonHover.png"))
    {
        throw std::runtime_error("Error::GameState::Failed to load playButtonHover.png");
    }

    playButtonHover.setTexture(&playButtonHoverTexture);
    playButtonHover.setPosition(mWindow->getSize().x / 2 - playButtonHover.getGlobalBounds().width / 2, 272.f);
}

// Init setting button
void PauseState::initSettingButton()
{
    // Setting button idle
    settingButtonIdle.setSize(sf::Vector2f(140.f, 120.f));
    if (!settingButtonIdleTexture.loadFromFile("assets/images/settingButtonIdle.png"))
    {
        throw std::runtime_error("Error::GameState::Failed to load settingButtonIdle.png");
    }

    settingButtonIdle.setTexture(&settingButtonIdleTexture);
    settingButtonIdle.setPosition(mWindow->getSize().x / 2 - settingButtonIdle.getGlobalBounds().width / 2, 446.f);

    // Setting button hover
    settingButtonHover.setSize(sf::Vector2f(139.f, 120.f));
    if (!settingButtonHoverTexture.loadFromFile("assets/images/settingButtonHover.png"))
    {
        throw std::runtime_error("Error::GameState::Failed to load settingButtonHover.png");
    }

    settingButtonHover.setTexture(&settingButtonHoverTexture);
    settingButtonHover.setPosition(mWindow->getSize().x / 2 - settingButtonHover.getGlobalBounds().width / 2 + 3.f, 444.f);
}

// Init Home button
void PauseState::initHomeButton()
{
    // home button idle
    homeButtonIdle.setSize(sf::Vector2f(130.f, 117.f));
    if (!homeButtonIdleTexture.loadFromFile("assets/images/homeButtonIdle.png"))
    {
        throw std::runtime_error("Error::GameState::Failed to load homeButtonIdle.png");
    }

    homeButtonIdle.setTexture(&homeButtonIdleTexture);
    homeButtonIdle.setPosition(mWindow->getSize().x / 2 - homeButtonIdle.getGlobalBounds().width / 2, 640.f);

    // home button hover
    homeButtonHover.setSize(sf::Vector2f(117.f, 114.f));
    if (!homeButtonHoverTexture.loadFromFile("assets/images/homeButtonHover.png"))
    {
        throw std::runtime_error("Error::GameState::Failed to load homeButtonHover.png");
    }

    homeButtonHover.setTexture(&homeButtonHoverTexture);
    homeButtonHover.setPosition(mWindow->getSize().x / 2 - homeButtonHover.getGlobalBounds().width / 2, 637.f);
}

PauseState::PauseState(sf::RenderWindow *window) : mWindow(window)
{
    initVariables();
    initTitle();
    initBackground();

    initPlayButton();
    initSettingButton();
    initHomeButton();
}

PauseState::~PauseState()
{
    delete titleSprite;
    delete titleTexture;
    delete background;
}

void PauseState::handleEvents(const sf::Event &event)
{
    switch (event.type)
    {
    case sf::Event::MouseButtonReleased:
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            // handlePlayButton();
        }
        break;
    }
}

void PauseState::handlePlayButton()
{
    // if (checkPlayButton)
    // {
    //     isClickedPlayButton = true;
    // }
}

// Play button
void PauseState::updatePlayButton(bool &paused, sf::Vector2f &mousePosView)
{
    // Check if the mouse is within the bounds of the playButton
    if (playButtonIdle.getGlobalBounds().contains(mousePosView))
    {
        // Active
        isClickedHomeButton = false;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            paused = false;
        }
        checkPlayButton = true;
    }
    else
    {
        checkPlayButton = false;
    }
}

void PauseState::updateSettingButton(sf::Vector2f &mousePosView)
{
    // Check if the mouse is within the bounds of the playButton
    if (settingButtonIdle.getGlobalBounds().contains(mousePosView))
    {
        // Active
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            isClickedSettingButton = true;
        }
        else
            isClickedSettingButton = false;

        checkSettingButton = true;
    }
    else
    {
        checkSettingButton = false;
    }
}

void PauseState::updateHomeButton(sf::Vector2f &mousePosView)
{
    // Check if the mouse is within the bounds of the playButton
    if (homeButtonIdle.getGlobalBounds().contains(mousePosView))
    {
        // Active
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // if (!isClickedHomeButton)
            isClickedHomeButton = true;
        }
        else
        {
            isClickedHomeButton = false;
        }
        checkHomeButton = true;
    }
    else
    {
        checkHomeButton = false;
    }
}

const bool PauseState::getHome()
{
    return isClickedHomeButton;
}

// Functions
void PauseState::update(bool &paused, sf::Vector2f &mousePosView)
{
    updatePlayButton(paused, mousePosView);
    updateSettingButton(mousePosView);
    updateHomeButton(mousePosView);
}

void PauseState::draw(sf::RenderTarget *target)
{
    if (!target)
        target = mWindow;

    // Draw background layer
    if (background)
        target->draw(*this->background);

    // Draw pause state title
    if (titleSprite)
        target->draw(*this->titleSprite);

    // Draw play button
    if (!checkPlayButton)
    {
        target->draw(playButtonIdle);
    }
    else
    {
        target->draw(playButtonHover);
    }

    // Draw setting button
    if (!checkSettingButton)
    {
        target->draw(settingButtonIdle);
    }
    else
    {
        target->draw(settingButtonHover);
    }

    // Draw home button
    if (!checkHomeButton)
    {
        target->draw(homeButtonIdle);
    }
    else
    {
        target->draw(homeButtonHover);
    }
}