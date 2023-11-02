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

GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states)
    : State(window, supportedKeys, states), mWindow(window), pauseState(window)
{
    initKeybinds();
    initTextures();
    initPlayer();
}

GameState::~GameState()
{
    delete this->player;
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
    // Pause menu
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("PAUSE"))))
    {
        if (!paused) pausedState();
        else unPausedState();
    }
}

void GameState::update()
{
    // Unpaused update
    if (!paused)
    {
        updateMousePosition();
        movingByKeyBoard();
        player->update();
    }
    // Pause update
    else {
        pauseState.update();
    }
}

void GameState::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = mWindow;
    }

    player->draw(target);

    // Pause menu
    if (paused) {
       pauseState.draw(target);
    }
}