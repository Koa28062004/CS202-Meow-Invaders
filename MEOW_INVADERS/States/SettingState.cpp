#include "SettingState.h"

void SettingState::initBackground()
{
    background.setSize(sf::Vector2f(
        static_cast<float>(mWindow->getSize().x),
        static_cast<float>(mWindow->getSize().y)));

    if (!backgroundTexture.loadFromFile("assets/images/SettingBG.png"))
    {
        throw std::runtime_error("Error::SettingState::Failed to load PreparedStateBG.png");
    }

    background.setTexture(&backgroundTexture);

    backgroundOver.setSize(sf::Vector2f((float)mWindow->getSize().x,
                                        (float)mWindow->getSize().y));
    backgroundOver.setFillColor(sf::Color(20, 20, 20, 100));
}

void SettingState::initTextBox()
{
    if (!roboto.loadFromFile("assets/fonts/Roboto-Bold.ttf"))
    {
        throw std::runtime_error("Error::SettingState::Failed to load Roboto");
    }

    // textboxs["MOVING_LEFT"] = new TextBox(40, sf::Color::White, false);

    // textBox1->setFont(roboto);
    // textBox1->setPosition({100, 100});
    // textBox1->setLimit(true, 10);
}

void SettingState::initButtons()
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

SettingState::SettingState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states, int &choice)
    : State(window, supportedKeys, states, choice),
      mWindow(window)
{
    initBackground();
    initTextBox();
    initButtons();
}

SettingState::~SettingState()
{
    // delete textBox1;

    auto it = buttons.begin();
    for (it = buttons.begin(); it != buttons.end(); ++it)
    {
        delete it->second;
    }

    // it = textboxs.begin();
    // for (it = textbox.begin(); it != textboxs.end(); ++i)
    // {
    //     delete it->second;
    // }
}

void SettingState::handleEvents(const sf::Event &event)
{
    // if (event.type == sf::Event::TextEntered)
    // {
    //     textBox1->typeOn(event);
    // }

    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    // {
    //     textBox1->setSelected(true);
    // }
    // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    // {
    //     textBox1->setSelected(false);
    // }
}

void SettingState::handleButtons()
{
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    std::chrono::milliseconds elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastButtonClickTime);

    if (buttons["BACK_GAME"]->isPressed())
    {
        if (elapsedTime > clickCooldown)
        {
            lastButtonClickTime = now;
            this->endState();
        }
    }
}

void SettingState::update()
{
    updateMousePosition();
    handleButtons();

    // Update all the buttons and handle their functions
    for (auto &it : buttons)
    {
        it.second->update(mousePosView);
    }
}

void SettingState::draw(sf::RenderTarget *target)
{
    if (!target)
        target = mWindow;
    target->draw(background);
    target->draw(backgroundOver);
    drawTitle(target);
    drawProperties(target);
    drawButtons(target);
}

void SettingState::drawTitle(sf::RenderTarget *target)
{
    sf::Text textTitle;
    textTitle.setFont(titleFont);
    textTitle.setString("SETTINGS");
    textTitle.setCharacterSize(90);
    textTitle.setFillColor(sf::Color::White);
    textTitle.setPosition(mWindow->getSize().x / 2.0f - textTitle.getGlobalBounds().width / 2.0f, mWindow->getSize().y / 2.0f - textTitle.getGlobalBounds().height / 2.0f - 350.f);

    target->draw(textTitle);
}

void SettingState::drawProperties(sf::RenderTarget *target)
{
    sf::Text moveLeft;
    moveLeft.setFont(titleFont);
    moveLeft.setString("MOVING LEFT : ");
    moveLeft.setCharacterSize(50);
    moveLeft.setFillColor(sf::Color::White);
    moveLeft.setPosition(mWindow->getSize().x / 2.0f - moveLeft.getGlobalBounds().width / 2.0f - 270.f, mWindow->getSize().y / 2.0f - moveLeft.getGlobalBounds().height / 2.0f - 100.f);

    sf::Text moveBy;
    moveBy.setFont(titleFont);
    moveBy.setString("MOVING BY : ");
    moveBy.setCharacterSize(50);
    moveBy.setFillColor(sf::Color::White);
    moveBy.setPosition(mWindow->getSize().x / 2.0f - moveLeft.getGlobalBounds().width / 2.0f - 270.f, mWindow->getSize().y / 2.0f - moveBy.getGlobalBounds().height / 2.0f - 180.f);

    sf::Text moveRight;
    moveRight.setFont(titleFont);
    moveRight.setString("MOVING RIGHT : ");
    moveRight.setCharacterSize(50);
    moveRight.setFillColor(sf::Color::White);
    moveRight.setPosition(mWindow->getSize().x / 2.0f - moveLeft.getGlobalBounds().width / 2.0f - 270.f, mWindow->getSize().y / 2.0f - moveRight.getGlobalBounds().height / 2.0f - 20.f);

    sf::Text moveUp;
    moveUp.setFont(titleFont);
    moveUp.setString("MOVING UP : ");
    moveUp.setCharacterSize(50);
    moveUp.setFillColor(sf::Color::White);
    moveUp.setPosition(mWindow->getSize().x / 2.0f - moveLeft.getGlobalBounds().width / 2.0f - 270.f, mWindow->getSize().y / 2.0f - moveUp.getGlobalBounds().height / 2.0f + 60.f);

    sf::Text moveDown;
    moveDown.setFont(titleFont);
    moveDown.setString("MOVING DOWN : ");
    moveDown.setCharacterSize(50);
    moveDown.setFillColor(sf::Color::White);
    moveDown.setPosition(mWindow->getSize().x / 2.0f - moveLeft.getGlobalBounds().width / 2.0f - 270.f, mWindow->getSize().y / 2.0f - moveDown.getGlobalBounds().height / 2.0f + 140.f);

    target->draw(moveBy);
    target->draw(moveLeft);
    target->draw(moveRight);
    target->draw(moveUp);
    target->draw(moveDown);
}

void SettingState::drawButtons(sf::RenderTarget *target)
{
    for (auto &it : buttons)
    {
        it.second->draw(target);
    }
}