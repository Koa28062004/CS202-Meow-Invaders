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
    this->player->setEntityScale(0.4, 0.4);
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
}

void GameState::initPausedMenu()
{
    pauseState = new PauseState(mWindow);
}

void GameState::initVariables()
{
    pauseKeyPressed = false;
    checkPausedButton = false;
    gameOver = false;
    isReset = false;
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

GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states)
    : State(window, supportedKeys, states), mWindow(window), random_engine(std::chrono::system_clock::now().time_since_epoch().count())
{
    initVariables();
    initKeybinds();
    initTextures();
    initBackground();
    initPlayer();
    initEnemyManager();
    initPausedMenu();
    initPausedButton();
}

GameState::~GameState()
{
    delete pauseState;
    delete enemyManager;
    // for (int i = 0; i < players.size(); ++i)
    // {
    //     delete this->players[i];
    // }
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

void GameState::update()
{
    updateMousePosition();
    updatePausedInput();

    // Unpaused update
    if (!paused)
    {
        updatePausedButton();
        movingByKeyBoard();
        player->update();

        updatingPlayingGame();
    }
    // Pause update
    else
    {
        pauseState->update(quit, paused, mousePosView);
    }
}

void GameState::updatingPlayingGame()
{
    if (gameOver)
    {
        // lose
    }
    else
    {
        // Fix later
        if (!isReset)
        {
            isReset = true;
            std::cout << "CoN cac" << '\n';
            player->reset();
            enemyManager->reset(0);
        }
        else
        {
            player->update();
            enemyManager->update(random_engine);
        }
    }
}

void GameState::drawPlayingGame()
{
    if (!player->get_dead())
    {
        enemyManager->draw(mWindow);
    }
}

void GameState::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = mWindow;
    }

    target->draw(background);

    drawPlayingGame();

    player->draw(target);

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