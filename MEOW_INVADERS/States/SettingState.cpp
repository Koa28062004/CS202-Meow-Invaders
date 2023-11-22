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

void SettingState::setUpTextBox(std::string name)
{
    textboxs[name]->setFont(roboto);
    textboxs[name]->setLimit(true, 10);
    textboxs[name]->setText(keys[name]);
}

void SettingState::initTextBox()
{
    if (!roboto.loadFromFile("assets/fonts/Roboto-Bold.ttf"))
    {
        throw std::runtime_error("Error::SettingState::Failed to load Roboto");
    }

    textboxs["FIRE"] = new TextBox(30, sf::Color::White, false);
    textboxs["MOVE_UP"] = new TextBox(30, sf::Color::White, false);
    textboxs["MOVE_DOWN"] = new TextBox(30, sf::Color::White, false);
    textboxs["MOVE_LEFT"] = new TextBox(30, sf::Color::White, false);
    textboxs["MOVE_RIGHT"] = new TextBox(30, sf::Color::White, false);
    textboxs["MOVE_BY"] = new TextBox(30, sf::Color::White, false);

    setUpTextBox("FIRE");
    setUpTextBox("MOVE_UP");
    setUpTextBox("MOVE_DOWN");
    setUpTextBox("MOVE_LEFT");
    setUpTextBox("MOVE_RIGHT");
    setUpTextBox("MOVE_BY");
}

void SettingState::initRectangle(std::string name)
{
    rectangles[name] = new sf::RectangleShape();
    rectangles[name]->setOutlineColor(sf::Color::White);
    rectangles[name]->setOutlineThickness(2.f);
    rectangles[name]->setFillColor(sf::Color(255, 0, 0, 0));
    rectangles[name]->setSize(sf::Vector2f(200.f, 40.f));
}

void SettingState::initRecs()
{
    initRectangle("FIRE");
    initRectangle("MOVE_UP");
    initRectangle("MOVE_DOWN");
    initRectangle("MOVE_LEFT");
    initRectangle("MOVE_RIGHT");
    initRectangle("MOVE_BY");
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
    updateKeys();

    initBackground();
    initTextBox();
    initButtons();
    initRecs();
}

SettingState::~SettingState()
{
    // delete textBox1;

    auto it = buttons.begin();
    for (it = buttons.begin(); it != buttons.end(); ++it)
    {
        delete it->second;
    }

    auto ti = textboxs.begin();
    for (ti = textboxs.begin(); ti != textboxs.end(); ++ti)
    {
        delete ti->second;
    }

    auto mi = rectangles.begin();
    for (mi = rectangles.begin(); mi != rectangles.end(); ++mi)
    {
        delete mi->second;
    }
}

void SettingState::handleEvents(const sf::Event &event)
{
    if (event.type == sf::Event::TextEntered)
    {
        for (auto &it : textboxs)
        {
            it.second->typeOn(event);
        }
    }
}

void SettingState::checkButtons(std::string name)
{
    if (rectangles[name]->getGlobalBounds().contains(mousePosView))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            textboxs[name]->setSelected(true);
    }
    else
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            textboxs[name]->setSelected(false);
    }
}

// Init Keybinds
void SettingState::initKeybinds()
{
    std::ifstream ifs("config/gameState_keybinds.ini");

    keybinds.clear();

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

void SettingState::handleButtons()
{
    checkButtons("FIRE");
    checkButtons("MOVE_LEFT");
    checkButtons("MOVE_RIGHT");
    checkButtons("MOVE_UP");
    checkButtons("MOVE_DOWN");

    // Quit
    if (buttons["BACK_GAME"]->isPressed() && this->getKeytime())
    {
        this->endState();
        // Check whether the keys change or not and update it
        checkKeys();
        updateKeys();
        initKeybinds();
    }
}

void SettingState::checkKey(std::string name)
{
    keys[name] = textboxs[name]->getText();
}

void SettingState::checkKeys()
{
    std::ofstream ofs("config/gameState_keybinds.ini");

    checkKey("FIRE");
    checkKey("MOVE_LEFT");
    checkKey("MOVE_RIGHT");
    checkKey("MOVE_UP");
    checkKey("MOVE_DOWN");

    if (ofs.is_open())
    {
        for (auto &it : keys)
        {
            ofs << it.first << ' ' << it.second << std::endl;
        }
    }
}

void SettingState::update(const float &dt)
{
    // Change the buttons
    updateKeys();

    updateMousePosition();
    handleButtons();
    updateKeytime(dt);

    // Update all the buttons and handle their functions
    for (auto &it : buttons)
    {
        it.second->update(mousePosView);
    }

    for (auto &it : textboxs)
    {
        it.second->updateKeytime(dt);
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
    drawRecs(target);
    drawTextBox(target);
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
    moveLeft.setFont(titleFont);
    moveLeft.setString("MOVING LEFT : ");
    moveLeft.setCharacterSize(50);
    moveLeft.setFillColor(sf::Color::White);

    left = sf::Vector2f{mWindow->getSize().x / 2.0f - moveLeft.getGlobalBounds().width / 2.0f - 270.f,
                        mWindow->getSize().y / 2.0f - moveLeft.getGlobalBounds().height / 2.0f - 70.f};

    moveLeft.setPosition(left.x, left.y);

    fire.setFont(titleFont);
    fire.setString("FIRE : ");
    fire.setCharacterSize(50);
    fire.setFillColor(sf::Color::White);

    vFire = sf::Vector2f{
        mWindow->getSize().x / 2.0f - moveLeft.getGlobalBounds().width / 2.0f - 270.f,
        mWindow->getSize().y / 2.0f - fire.getGlobalBounds().height / 2.0f - 230.f};

    fire.setPosition(vFire.x, vFire.y);

    moveBy.setFont(titleFont);
    moveBy.setString("MOVING BY : ");
    moveBy.setCharacterSize(50);
    moveBy.setFillColor(sf::Color::White);

    vBy = sf::Vector2f{mWindow->getSize().x / 2.0f - moveLeft.getGlobalBounds().width / 2.0f - 270.f,
                       mWindow->getSize().y / 2.0f - moveBy.getGlobalBounds().height / 2.0f - 150.f};

    moveBy.setPosition(vBy.x, vBy.y);

    moveRight.setFont(titleFont);
    moveRight.setString("MOVING RIGHT : ");
    moveRight.setCharacterSize(50);
    moveRight.setFillColor(sf::Color::White);

    right = sf::Vector2f{mWindow->getSize().x / 2.0f - moveLeft.getGlobalBounds().width / 2.0f - 270.f,
                         mWindow->getSize().y / 2.0f - moveRight.getGlobalBounds().height / 2.0f + 10.f};

    moveRight.setPosition(right.x, right.y);

    moveUp.setFont(titleFont);
    moveUp.setString("MOVING UP : ");
    moveUp.setCharacterSize(50);
    moveUp.setFillColor(sf::Color::White);

    up = sf::Vector2f{mWindow->getSize().x / 2.0f - moveLeft.getGlobalBounds().width / 2.0f - 270.f,
                      mWindow->getSize().y / 2.0f - moveUp.getGlobalBounds().height / 2.0f + 90.f};

    moveUp.setPosition(up.x, up.y);

    moveDown.setFont(titleFont);
    moveDown.setString("MOVING DOWN : ");
    moveDown.setCharacterSize(50);
    moveDown.setFillColor(sf::Color::White);

    down = sf::Vector2f{mWindow->getSize().x / 2.0f - moveLeft.getGlobalBounds().width / 2.0f - 270.f,
                        mWindow->getSize().y / 2.0f - moveDown.getGlobalBounds().height / 2.0f + 170.f};

    moveDown.setPosition(down.x, down.y);

    target->draw(fire);
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

void SettingState::drawRecs(sf::RenderTarget *target)
{
    rectangles["FIRE"]->setPosition(vFire.x + 550.f, vFire.y + 10.f);
    rectangles["MOVE_UP"]->setPosition(vFire.x + 550.f, up.y + 10.f);
    rectangles["MOVE_DOWN"]->setPosition(vFire.x + 550.f, down.y + 10.f);
    rectangles["MOVE_LEFT"]->setPosition(vFire.x + 550.f, left.y + 10.f);
    rectangles["MOVE_RIGHT"]->setPosition(vFire.x + 550.f, right.y + 10.f);
    rectangles["MOVE_BY"]->setPosition(vFire.x + 550.f, vBy.y + 10.f);

    for (auto &it : rectangles)
    {
        target->draw(*it.second);
    }
}

void SettingState::drawTextBox(sf::RenderTarget *target)
{
    textboxs["FIRE"]->setPosition({vFire.x + 560.f, vFire.y + 8.f});
    textboxs["MOVE_UP"]->setPosition({vFire.x + 560.f, up.y + 8.f});
    textboxs["MOVE_DOWN"]->setPosition({vFire.x + 560.f, down.y + 8.f});
    textboxs["MOVE_LEFT"]->setPosition({vFire.x + 560.f, left.y + 8.f});
    textboxs["MOVE_RIGHT"]->setPosition({vFire.x + 560.f, right.y + 8.f});
    textboxs["MOVE_BY"]->setPosition({vFire.x + 560.f, vBy.y + 8.f});

    for (auto &it : textboxs)
    {
        it.second->drawText(target);
    }
}