#include "GameState.h"

// Init Keybinds
void GameState::initKeybinds()
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

// Init Player
void GameState::initPlayer()
{
    this->player = new Player(playerPosition.x, playerPosition.y, &this->playerTextures[chosen]);
    this->player->setEntityScale(0.35, 0.35);
}

void GameState::initEnemyManager()
{
    enemyManager = new EnemyManager();
}

// Init Background
void GameState::initBackground()
{
    background.setSize(sf::Vector2f(
        static_cast<float>(mWindow->getSize().x),
        static_cast<float>(mWindow->getSize().y)));

    if (!backgroundTexture.loadFromFile("assets/images/InGameBG.png"))
    {
        throw std::runtime_error("Error::GameState::Failed to load InGameBG.png");
    }

    background.setTexture(&backgroundTexture);

    backgroundGameOver.setSize(sf::Vector2f((float)mWindow->getSize().x,
                                            (float)mWindow->getSize().y));
    backgroundGameOver.setFillColor(sf::Color(20, 20, 20, 100));
}

void GameState::initPausedMenu()
{
    pauseState = new PauseState(mWindow);
}

void GameState::initVariables()
{
    pauseKeyPressed = false;
    checkPausedButton = false;
    level = 0;
    isNextLevel = true;
    isReset = false;
    isEnterClicked = false;
    checkClock = false;
    gameOver = 0;
    this->choice = choice;
    playerPosition = {(float)mWindow->getSize().x / 2, (float)mWindow->getSize().y / 2};
}

void GameState::initPausedButton()
{
    pausedButtonIdle.setSize(sf::Vector2f(100.f, 80.f));
    if (!pausedButtonIdleTexture.loadFromFile("assets/images/pausedButtonIdle.png"))
    {
        throw std::runtime_error("Error::GameState::Failed to load pausedButtonIdle.png");
    }

    pausedButtonIdle.setTexture(&pausedButtonIdleTexture);
    pausedButtonIdle.setPosition(mWindow->getSize().x - 110.f, 30.f);

    pausedButtonHover.setSize(sf::Vector2f(119.f, 80.f));
    if (!pausedButtonHoverTexture.loadFromFile("assets/images/pausedButtonHover.png"))
    {
        throw std::runtime_error("Error::GameState::Failed to load pausedButtonHover.png");
    }

    pausedButtonHover.setTexture(&pausedButtonHoverTexture);
    pausedButtonHover.setPosition(mWindow->getSize().x - 121.f, 37.f);
}

void GameState::initFont()
{
}

void GameState::initGameOverButtons()
{
    sf::Text tmp;
    tmp.setString("YES");
    tmp.setCharacterSize(40);
    buttons["YES_GAME_OVER"] = new Button(mWindow->getSize().x / 2 - tmp.getGlobalBounds().width / 2, 550, 0, 0,
                                          &textBelowFont, "YES",
                                          sf::Color(0, 0, 0, 0),
                                          sf::Color(0, 0, 0, 0),
                                          sf::Color(0, 0, 0, 0));

    tmp.setString("NO");
    tmp.setCharacterSize(40);
    buttons["NO_GAME_OVER"] = new Button(mWindow->getSize().x / 2 - tmp.getGlobalBounds().width / 2, 680, 0, 0,
                                         &textBelowFont, "NO",
                                         sf::Color(0, 0, 0, 0),
                                         sf::Color(0, 0, 0, 0),
                                         sf::Color(0, 0, 0, 0));
}

void GameState::initPointer()
{
    enemy_bullets = &enemyManager->get_enemy_bullets();
    boss_bullets = &enemyManager->get_boss_bullets();
    enemies = &enemyManager->get_enemies();
    disasters = &enemyManager->get_disasters();
    randomDisasters = &enemyManager->get_randomDisasters();
    bosses = &enemyManager->get_bosses();
}

GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states, int &choice)
    : State(window, supportedKeys, states, choice),
      mWindow(window),
      random_engine(std::chrono::system_clock::now().time_since_epoch().count()),
      enemy_bullets(nullptr),
      enemies(nullptr)
{
    initVariables();
    initKeybinds();
    initBackground();
    initPausedButton();
    initFont();
    initGameOverButtons();
    initPlayer();
    initEnemyManager();
    initPausedMenu();

    initPointer();
}

GameState::~GameState()
{
    delete pauseState;
    delete enemyManager;

    auto it = buttons.begin();
    for (it = buttons.begin(); it != buttons.end(); ++it)
    {
        delete it->second;
    }
}

void GameState::movingByKeyBoard()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_LEFT"))))
    {
        player->move(-7.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_RIGHT"))))
    {
        player->move(7.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_UP"))))
    {
        player->move(0.f, -7.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_DOWN"))))
    {
        player->move(0.f, 7.f);
    }
}

void GameState::movingByMouse()
{
    player->moveByMouse(mousePosView);
}

void GameState::handleEvents(const sf::Event &event)
{
    switch (event.type)
    {
    case sf::Event::MouseButtonReleased:
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            // handleHomeButton();
            // handleGameOver();
        }
        break;
    }
    if (paused)
        pauseState->handleEvents(event);
}

void GameState::handleHomeButton()
{
    if (pauseState->getHome() && this->getKeytime())
    {
        this->endState();
    }
}

void GameState::handleSettingButton()
{
    if (pauseState->isClickedSettingButton && this->getKeytime())
    {
        pauseState->isClickedSettingButton = false;
        states->push(new SettingState(mWindow, supportedKeys, states, choice));
    }
}

void GameState::handleGameOver()
{
    if (gameOver)
    {
        if (buttons["YES_GAME_OVER"]->isPressed() && this->getKeytime())
        {
            isEnterClicked = true;
            checkClock = false;
            gameOver = 0;
            --level;
            enemy_bullets->clear();
            boss_bullets->clear();
            enemies->clear();
            disasters->clear();
            randomDisasters->clear();
            bosses->clear();
            player->reset();
            player->setEntityPosition((float)mWindow->getSize().x / 2, (float)mWindow->getSize().y / 2);
        }
        else if (buttons["NO_GAME_OVER"]->isPressed() && this->getKeytime())
        {
            this->endState();
        }
    }
}

void GameState::updatePausedInput()
{
    // Pause menu
    if (isNextLevel && sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("PAUSE"))))
    {
        if (!pauseKeyPressed)
        {
            pauseKeyPressed = true;
            if (!paused)
                this->pausedState();
            else
                this->unPausedState();
        }
    }
    else
    {
        pauseKeyPressed = false;
    }
}

// Paused button
void GameState::updatePausedButton()
{
    // Check if the mouse is within the bounds of the pausedButton
    if (pausedButtonIdle.getGlobalBounds().contains(mousePosView))
    {
        // Active
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->pausedState();
        }

        checkPausedButton = true;
    }
    else
    {
        checkPausedButton = false;
    }
}

void GameState::updateLevelUp()
{
    if (level != 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        isNextLevel = true;
        isEnterClicked = true;
    }
}

void GameState::update(const float &dt)
{
    if (State::isLoad)
        loadGame();

    updateKeys();
    initKeybinds();

    updateMousePosition();
    updatePausedInput();
    handleHomeButton();
    handleGameOver();
    handleSettingButton();
    updateKeytime(dt);

    if (1 == player->get_dead_animation_over())
    {
        gameOver = 1;
    }

    for (auto &it : buttons)
    {
        it.second->update(mousePosView);
    }

    // Unpaused update
    if (!paused)
    {
        if (!gameOver)
        {
            if (!isNextLevel)
                updateLevelUp();
            else
            {
                updatePausedButton();

                // Change the way of moving
                if (keybinds.at("MOVE_BY") == 1)
                    movingByMouse();
                else
                    movingByKeyBoard();

                updatingPlayingGame();
            }
        }
    }
    // Pause update
    else
    {
        if (!isNextLevel)
            return;
        pauseState->update(paused, mousePosView);
        pauseState->updateKeytime(dt);
    }
}

void GameState::updatingPlayingGame()
{
    if (isReset && enemyManager->get_enemies().size() == 0 && enemyManager->get_disasters().size() == 0 && enemyManager->get_bosses().size() == 0)
    {
        isReset = false;
        isEnterClicked = false;
        checkClock = false;
        enemyManager->reset(level++);
    }
    else
    {
        enemyManager->update(random_engine, level);
        enemy_bullets = &enemyManager->get_enemy_bullets();
        boss_bullets = &enemyManager->get_boss_bullets();
        enemies = &enemyManager->get_enemies();
        disasters = &enemyManager->get_disasters();
        randomDisasters = &enemyManager->get_randomDisasters();
        bosses = &enemyManager->get_bosses();
        player->update(*enemy_bullets, *enemies, *disasters, *randomDisasters, *bosses, *boss_bullets, mWindow);
    }
}

void GameState::drawPlayingGame(sf::RenderTarget *target)
{
    // Lose
    if (gameOver)
    {
        // Set text
        sf::Text textTitle;
        textTitle.setFont(titleFont);
        textTitle.setString("YOU ARE DEAD !!!");
        textTitle.setCharacterSize(120);
        textTitle.setFillColor(sf::Color(241, 26, 123, 255));
        textTitle.setPosition(mWindow->getSize().x / 2.0f - textTitle.getGlobalBounds().width / 2.0f, mWindow->getSize().y / 2.0f - textTitle.getGlobalBounds().height / 2.0f - 310.f);

        sf::Text textBelow;
        textBelow.setFont(titleFont);
        textBelow.setString("[IDIOT]");
        textBelow.setCharacterSize(50);
        textBelow.setFillColor(sf::Color(248, 141, 189, 255));
        textBelow.setPosition(mWindow->getSize().x / 2.0f - textBelow.getGlobalBounds().width / 2.0f, mWindow->getSize().y / 2.0f - textBelow.getGlobalBounds().height / 2.0f - 200.f);

        sf::Text textTryAgain;
        textTryAgain.setFont(titleFont);
        textTryAgain.setString("TRY AGAIN ?");
        textTryAgain.setCharacterSize(50);
        textTryAgain.setFillColor(sf::Color::White);
        textTryAgain.setPosition(mWindow->getSize().x / 2.0f - textTryAgain.getGlobalBounds().width / 2.0f, mWindow->getSize().y / 2.0f - textTryAgain.getGlobalBounds().height / 2.0f - 50.f);

        target->draw(backgroundGameOver);
        target->draw(textTitle);
        target->draw(textBelow);
        target->draw(textTryAgain);
        for (auto &it : buttons)
        {
            it.second->draw(target);
        }
    }
}

void GameState::drawLevelUp(sf::RenderTarget *target)
{
    sf::Text textTitle;
    textTitle.setFont(titleFont);
    textTitle.setString("VICTORY");
    textTitle.setCharacterSize(140);
    textTitle.setFillColor(sf::Color(255, 251, 115, 255));
    textTitle.setPosition(mWindow->getSize().x / 2.0f - textTitle.getGlobalBounds().width / 2.0f, mWindow->getSize().y / 2.0f - textTitle.getGlobalBounds().height / 2.0f - 250.f);

    sf::Text textBelow;
    textBelow.setFont(titleFont);
    textBelow.setString("[ORZ]");
    textBelow.setCharacterSize(50);
    textBelow.setFillColor(sf::Color(240, 184, 110, 255));
    textBelow.setPosition(mWindow->getSize().x / 2.0f - textBelow.getGlobalBounds().width / 2.0f, mWindow->getSize().y / 2.0f - textBelow.getGlobalBounds().height / 2.0f - 110.f);

    sf::Text textTryAgain;
    textTryAgain.setFont(titleFont);
    textTryAgain.setString("Press ENTER to continue...");
    textTryAgain.setCharacterSize(50);
    textTryAgain.setFillColor(sf::Color::White);
    textTryAgain.setPosition(mWindow->getSize().x / 2.0f - textTryAgain.getGlobalBounds().width / 2.0f, mWindow->getSize().y / 2.0f - textTryAgain.getGlobalBounds().height / 2.0f + 50.f);

    target->draw(backgroundGameOver);
    target->draw(textTitle);
    target->draw(textBelow);
    target->draw(textTryAgain);
}

void GameState::drawLevelScreen(sf::RenderTarget *target)
{
    std::string tmp = "Level " + std::to_string(level + 1);
    sf::Text text;
    text.setFont(titleFont);
    text.setCharacterSize(80);
    text.setFillColor(sf::Color::White);
    text.setString(tmp);
    text.setPosition(mWindow->getSize().x / 2.0f - text.getGlobalBounds().width / 2.0f, mWindow->getSize().y / 2.0f - text.getGlobalBounds().height / 2.0f - 230.f);

    static sf::Clock clock;
    float totalTimeToShowText = 2.0f;
    float totalTimeToSetFlag = 4.0f;

    if (isEnterClicked && !checkClock)
    {
        clock.restart();
        checkClock = true;
    }

    if (level == 0 && !checkClock)
    {
        clock.restart();
        checkClock = true;
    }

    float progressToShowText = clock.getElapsedTime().asSeconds() / totalTimeToShowText;
    float progressToSetFlag = clock.getElapsedTime().asSeconds() / totalTimeToSetFlag;

    unsigned int charactersToDisplay = static_cast<unsigned int>(progressToShowText * text.getString().getSize());
    charactersToDisplay = static_cast<unsigned int>(std::min(static_cast<std::size_t>(charactersToDisplay), text.getString().getSize()));
    text.setString(text.getString().substring(0, charactersToDisplay));

    target->draw(text);

    if (!isReset && progressToSetFlag >= 1.0f)
    {
        isReset = true;
    }
}

void GameState::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = mWindow;
    }

    target->draw(background);

    player->draw(target);
    enemyManager->draw(mWindow);

    drawPlayingGame(target);

    if (!isEnterClicked && level != 0 && enemyManager->get_enemies().size() == 0 && enemyManager->get_disasters().size() == 0 && enemyManager->get_bosses().size() == 0)
    {
        isNextLevel = false;
    }

    if (!gameOver)
    {
        // Draw the level up background
        if (!isNextLevel)
        {
            drawLevelUp(target);
        }
        else
        {
            if (enemyManager->get_enemies().size() == 0 && enemyManager->get_disasters().size() == 0 && enemyManager->get_bosses().size() == 0)
            {
                drawLevelScreen(target);
            }

            // Draw hover animation of paused button
            if (!checkPausedButton)
            {
                target->draw(pausedButtonIdle);
            }
            else
            {
                target->draw(pausedButtonHover);
            }

            // Pause menu
            if (paused)
            {
                pauseState->draw(target);
            }
        }
    }
}

void GameState::loadGame()
{
    std::ifstream ifs;
    ifs.open("config/save.txt");

    // chosen
    ifs >> chosen;
    // player position
    ifs >> playerPosition.x >> playerPosition.y;

    delete player;
    initPlayer();
    initVariables();

    // gameOver
    ifs >> gameOver;
    // isEnterClicked
    ifs >> isEnterClicked;
    // level
    ifs >> level;
    // isNextLevel
    ifs >> isNextLevel;
    // isReset
    ifs >> isReset;

    // paused menu
    if (!gameOver || !isNextLevel)
        paused = true;
    else
        paused = false;

    player->loadGame(ifs);

    enemyManager->loadGame(ifs);

    State::isLoad = false;
}

void GameState::saveGame(std::string fileName)
{
    std::ofstream ofs;
    ofs.open(fileName);

    // chosen of spaceship
    ofs << chosen << std::endl;
    // The position of spaceship
    playerPosition = player->getPlayerPos();
    ofs << playerPosition.x << " " << playerPosition.y << std::endl;
    // gameOver
    ofs << gameOver << std::endl;
    // isEnterClicked
    ofs << isEnterClicked << std::endl;
    // level
    ofs << level << std::endl;
    // isNextLevel
    ofs << isNextLevel << std::endl;
    // isReset
    ofs << isReset << std::endl;

    // player saves game
    player->saveGame(fileName);

    // enemyManager saves game
    enemyManager->saveGame(fileName);

    ofs.close();
}