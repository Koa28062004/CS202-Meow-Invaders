#include "States/GameState.h"

// Init Keybinds
void GameState::initKeybinds()
{
    std::ifstream ifs("config/gameState_keybinds.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";

        while (ifs >> key >> key2) {
            keybinds[key] = supportedKeys->at(key2);
        }
    }

    ifs.close();
}

// Init Textures
void GameState::initTextures() {
    sf::Texture tmp;
    if (!tmp.loadFromFile("assets/images/spaceship1.png")) {
        throw std::runtime_error("Error::Failed to load spaceship1.png");
    }
    this->textures["PLAYER_1"] = tmp;
}

// Init Player
void GameState::initPlayer() {
    this->player = new Player((float)mWindow->getSize().x / 2, (float)mWindow->getSize().y / 2, &this->textures["PLAYER_1"]);
    this->player->setEntityScale(0.4, 0.4);
}

GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State*>* states)
    : State(window, supportedKeys, states), mWindow(window)
{
    initKeybinds();
    initTextures();
    initPlayer();
}

GameState::~GameState()
{
    delete this->player;
}

void GameState::updateInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_LEFT"))))
    {
        player->move(-10.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_RIGHT"))))
    {
        player->move(10.f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_UP"))))
    {
        player->move(0.f, -10.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("MOVE_DOWN"))))
    {
        player->move(0.f, 10.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("CLOSE"))))
    {
        endState();
    }
}

void GameState::update()
{
    updateMousePosition();
    updateInput();
    player->update();
}

void GameState::draw(sf::RenderTarget* target)
{
    if (!target)
    {
        target = mWindow;
    }

    player->draw(target);
}