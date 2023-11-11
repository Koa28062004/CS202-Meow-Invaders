#include "GameState.h"

// Init Keybinds
void GameState::initKeybinds()
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

// Init Textures
void GameState::initTextures()
{
    // Need to fix
    sf::Texture tmp;
    if (!tmp.loadFromFile("assets/images/spaceship1.png"))
    {
        throw std::runtime_error("Error::Failed to load spaceship1.png");
    }
    this->textures["PLAYER_IDLE"] = tmp;

    // if (!tmp.loadFromFile("assets/images/spaceship2.png"))
    // {
    //     throw std::runtime_error("Error::Failed to load spaceship2.png");
    // }
    // this->textures.push_back(tmp);

    // if (!tmp.loadFromFile("assets/images/spaceship3.png"))
    // {
    //     throw std::runtime_error("Error::Failed to load spaceship3.png");
    // }
    // this->textures.push_back(tmp);
}

// Init Player
void GameState::initPlayer()
{
    this->player = new Player((float)mWindow->getSize().x / 2, (float)mWindow->getSize().y / 2, &this->textures["PLAYER_IDLE"]);
    this->player->setEntityScale(0.3, 0.3);
    //  this->players.push_back(player);
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
    // Title Game Over font
    if (!gameOverFont.loadFromFile("assets/fonts/RubikGlitch-Regular.ttf"))
    {
        throw std::runtime_error("Error::GameState can't not load font RubikGlitch");
    }

    // Text below game over font
    if (!textBelowFont.loadFromFile("assets/fonts/RubikGlitch-Regular.ttf"))
    {
        throw std::runtime_error("Error::GameState can't not load font Montserrat-Medium");
    }
}

void GameState::initGameOverButtons()
{
    sf::Text tmp;
    tmp.setString("YES");
    tmp.setCharacterSize(40);
    buttons["YES_GAME_OVER"] = new Button(mWindow->getSize().x / 2 - tmp.getGlobalBounds().width / 2, 550, 0, 0,
                                          &font, "YES",
                                          sf::Color(0, 0, 0, 0),
                                          sf::Color(0, 0, 0, 0),
                                          sf::Color(0, 0, 0, 0));

    tmp.setString("NO");
    tmp.setCharacterSize(40);
    buttons["NO_GAME_OVER"] = new Button(mWindow->getSize().x / 2 - tmp.getGlobalBounds().width / 2, 680, 0, 0,
                                         &font, "NO",
                                         sf::Color(0, 0, 0, 0),
                                         sf::Color(0, 0, 0, 0),
                                         sf::Color(0, 0, 0, 0));
}

GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states)
    : State(window, supportedKeys, states),
      mWindow(window),
      random_engine(std::chrono::system_clock::now().time_since_epoch().count()),
      enemy_bullets(nullptr),
      enemies(nullptr)
{
    initVariables();
    initKeybinds();
    initTextures();
    initBackground();
    initPlayer();
    initEnemyManager();
    initPausedMenu();
    initPausedButton();
    initFont();
    initGameOverButtons();
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

    // Escape the current state
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("CLOSE"))))
    {
        endState();
    }
}

void GameState::updatePausedInput()
{
    // Pause menu
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("PAUSE"))))
    {
        if (!pauseKeyPressed)
        {
            pauseKeyPressed = true;
            if (!paused)
                pausedState();
            else
                unPausedState();
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
            pausedState();
        }

        checkPausedButton = true;
    }
    else
    {
        checkPausedButton = false;
    }
}

void GameState::updateGameOver()
{
    for (auto &it : buttons)
    {
        it.second->update(mousePosView);
    }

    if (buttons["YES_GAME_OVER"]->isPressed())
    {
        --level;
        enemies->clear();
        player->reset();
        player->setEntityPosition((float)mWindow->getSize().x / 2, (float)mWindow->getSize().y / 2);
    }
    else if (buttons["NO_GAME_OVER"]->isPressed())
    {
        endState();
    }
}

void GameState::update()
{
    updateMousePosition();
    updatePausedInput();

    // Unpaused update
    if (!paused)
    {
        if (!player->get_dead())
        {
            updatePausedButton();
            movingByKeyBoard();
            updatingPlayingGame();
        }
        else updateGameOver();
    }
    // Pause update
    else
    {
        pauseState->update(quit, paused, mousePosView);
    }
}

void GameState::updatingPlayingGame()
{
    if (enemyManager->get_enemies().size() == 0)
    {
        std::cout << "reset" << '\n';
        player->reset();
        if (level <= 5)
            enemyManager->reset(level++);
    }
    else
    {
        enemyManager->update(random_engine);
        enemy_bullets = &enemyManager->get_enemy_bullets();
        enemies = &enemyManager->get_enemies();
        player->update(*enemy_bullets, *enemies);
    }
}

void GameState::drawPlayingGame(sf::RenderTarget *target)
{
    enemyManager->draw(mWindow);

    // Lose
    if (player->get_dead())
    {
        // Set text
        sf::Text textTitle;
        textTitle.setFont(gameOverFont);
        textTitle.setString("YOU ARE DEAD !!!");
        textTitle.setCharacterSize(120);
        textTitle.setFillColor(sf::Color(241, 26, 123, 255));
        textTitle.setPosition(mWindow->getSize().x / 2.0f - textTitle.getGlobalBounds().width / 2.0f, mWindow->getSize().y / 2.0f - textTitle.getGlobalBounds().height / 2.0f - 310.f);

        sf::Text textBelow;
        textBelow.setFont(gameOverFont);
        textBelow.setString("[IDIOT]");
        textBelow.setCharacterSize(50);
        textBelow.setFillColor(sf::Color(248, 141, 189, 255));
        textBelow.setPosition(mWindow->getSize().x / 2.0f - textBelow.getGlobalBounds().width / 2.0f, mWindow->getSize().y / 2.0f - textBelow.getGlobalBounds().height / 2.0f - 200.f);

        sf::Text textTryAgain;
        textTryAgain.setFont(gameOverFont);
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

void GameState::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = mWindow;
    }

    target->draw(background);
    player->draw(target);

    drawPlayingGame(target);

    if (!player->get_dead())
    {
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