#include "PreparedState.h"

void PreparedState::initBackground()
{
    background.setSize(sf::Vector2f(
        static_cast<float>(mWindow->getSize().x),
        static_cast<float>(mWindow->getSize().y)));

    if (!backgroundTexture.loadFromFile("assets/images/PreparedStateBG.png"))
    {
        throw std::runtime_error("Error::PreparedState::Failed to load PreparedStateBG.png");
    }

    background.setTexture(&backgroundTexture);

    backgroundOver.setSize(sf::Vector2f((float)mWindow->getSize().x,
                                        (float)mWindow->getSize().y));
    backgroundOver.setFillColor(sf::Color(20, 20, 20, 100));
}

void PreparedState::initNextButtons()
{
    // Init left button
    if (!nextButtonLeftTex.loadFromFile("assets/images/nextButtonLeft.png"))
    {
        throw std::runtime_error("Error::PreparedState::Failed to load nextButtonLeft.png");
    }
    nextButtonLeftSprite.setTexture(nextButtonLeftTex);

    // Init right button
    if (!nextButtonRightTex.loadFromFile("assets/images/nextButtonRight.png"))
    {
        throw std::runtime_error("Error::PreparedState::Failed to load nextButtonRight.png");
    }
    nextButtonRightSprite.setTexture(nextButtonRightTex);
}

void PreparedState::initButtons()
{
    sf::Text tmp;
    tmp.setString("Play");
    tmp.setCharacterSize(40);
    buttons["PLAY_GAME"] = new Button(mWindow->getSize().x / 2 - tmp.getGlobalBounds().width / 2, 650, 0, 0,
                                      &titleFont, "Play",
                                      sf::Color(0, 0, 0, 0),
                                      sf::Color(0, 0, 0, 0),
                                      sf::Color(0, 0, 0, 0));

    tmp.setString("Quit");
    tmp.setCharacterSize(40);
    buttons["BACK_GAME"] = new Button(mWindow->getSize().x / 2 - tmp.getGlobalBounds().width / 2, 750, 0, 0,
                                      &titleFont, "Quit",
                                      sf::Color(0, 0, 0, 0),
                                      sf::Color(0, 0, 0, 0),
                                      sf::Color(0, 0, 0, 0));
}

PreparedState::PreparedState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states, int &choice)
    : State(window, supportedKeys, states, choice),
      mWindow(window)
{
    initBackground();
    initNextButtons();
    initButtons();

    chosen = 0;
}

PreparedState::~PreparedState()
{
    auto it = buttons.begin();
    for (it = buttons.begin(); it != buttons.end(); ++it)
    {
        delete it->second;
    }
}

void PreparedState::handleEvents(const sf::Event &event)
{
    switch (event.type)
    {
    case sf::Event::MouseButtonReleased:
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            // updateNextButtons();
        }
        break;

    default:
        break;
    }
}

void PreparedState::updateNextButtons()
{
    if (nextButtonLeftSprite.getGlobalBounds().contains(mousePosView))
    {
        // Active
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeytime())
        {
            if (chosen > 0)
                --chosen;
            else
                chosen = 4;
        }
    }

    if (nextButtonRightSprite.getGlobalBounds().contains(mousePosView))
    {
        // Active
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getKeytime())
        {
            if (chosen < 4)
                ++chosen;
            else
                chosen = 0;
        }
    }
}

void PreparedState::handleButtons()
{
    if (buttons["PLAY_GAME"]->isPressed() && this->getKeytime())
    {
        this->endState();
        states->push(new GameState(mWindow, supportedKeys, states, chosen));
    }

    if (buttons["BACK_GAME"]->isPressed() && this->getKeytime())
    {
        this->endState();
    }
}

void PreparedState::update(const float &dt)
{
    updateMousePosition();
    updateNextButtons();
    updateKeytime(dt);
    handleButtons();

    // Update all the buttons and handle their functions
    for (auto &it : buttons)
    {
        it.second->update(mousePosView);
    }
}

void PreparedState::draw(sf::RenderTarget *target)
{
    if (!target)
        target = mWindow;

    target->draw(background);
    target->draw(backgroundOver);
    drawTitle(target);
    drawNextButtons(target);
    drawSpaceship(target);
    drawButtons(target);
}

void PreparedState::drawTitle(sf::RenderTarget *target)
{
    sf::Text textTitle;
    textTitle.setFont(titleFont);
    textTitle.setString("CHOOSE YOUR SPACESHIP");
    textTitle.setCharacterSize(80);
    textTitle.setFillColor(sf::Color::White);
    textTitle.setPosition(mWindow->getSize().x / 2.0f - textTitle.getGlobalBounds().width / 2.0f, mWindow->getSize().y / 2.0f - textTitle.getGlobalBounds().height / 2.0f - 350.f);

    target->draw(textTitle);
}

void PreparedState::drawNextButtons(sf::RenderTarget *target)
{
    // Set properties
    nextButtonLeftSprite.setScale(sf::Vector2f(0.55, 0.55));
    nextButtonLeftSprite.setPosition(mWindow->getSize().x / 2.0f - nextButtonLeftSprite.getGlobalBounds().width / 2.0f - 370.f, mWindow->getSize().y / 2.0f - nextButtonLeftSprite.getGlobalBounds().height / 2.0f);

    nextButtonRightSprite.setScale(sf::Vector2f(0.55, 0.55));
    nextButtonRightSprite.setPosition(mWindow->getSize().x / 2.0f + nextButtonRightSprite.getGlobalBounds().width / 2.0f + 300.f, mWindow->getSize().y / 2.0f - nextButtonRightSprite.getGlobalBounds().height / 2.0f);

    target->draw(nextButtonLeftSprite);
    target->draw(nextButtonRightSprite);
}

void PreparedState::drawSpaceship(sf::RenderTarget *target)
{
    sf::Sprite tmp;
    tmp.setTexture(playerTextures[chosen]);
    tmp.setScale(sf::Vector2f(0.75, 0.75));
    tmp.setPosition(mWindow->getSize().x / 2.0f - tmp.getGlobalBounds().width / 2.0f, mWindow->getSize().y / 2.0f - tmp.getGlobalBounds().height / 2.0f);
    target->draw(tmp);
}

void PreparedState::drawButtons(sf::RenderTarget *target)
{
    for (auto &it : buttons)
    {
        it.second->draw(target);
    }
}