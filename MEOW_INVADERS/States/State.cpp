#include "State.h"

// Init Fonts
void State::initFonts()
{
    if (!font.loadFromFile("assets/fonts/Megrim-Regular.ttf"))
    {
        throw std::runtime_error("Error::State::Could not load fonts");
    }

    // Title Game Over font
    if (!titleFont.loadFromFile("assets/fonts/RubikGlitch-Regular.ttf"))
    {
        throw std::runtime_error("Error::GameState can't not load font RubikGlitch");
    }

    // Text below game over font
    if (!textBelowFont.loadFromFile("assets/fonts/SigmarOne-Regular.ttf"))
    {
        throw std::runtime_error("Error::GameState can't not load font SigmarOne-Regular.ttf");
    }
}

State::State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states, int &choice)
    : mWindow(window), quit(false), paused(false), chosen(choice)
{
    this->supportedKeys = supportedKeys;
    this->states = states;
    this->keytime = 0.f;
    this->keytimeMax = 15.f;

    initFonts();
    initPlayerTextures();
}

State::~State()
{
}

void State::initPlayerTextures()
{
    sf::Texture tmp;

    if (!tmp.loadFromFile("assets/images/spaceship1.png"))
    {
        throw std::runtime_error("Error::Failed to load spaceship1.png");
    }
    this->playerTextures.push_back(tmp);
    this->isUnlocked.push_back(true);

    if (!tmp.loadFromFile("assets/images/spaceship2.png"))
    {
        throw std::runtime_error("Error::Failed to load spaceship2.png");
    }
    this->playerTextures.push_back(tmp);
    this->isUnlocked.push_back(true);

    if (!tmp.loadFromFile("assets/images/spaceship3.png"))
    {
        throw std::runtime_error("Error::Failed to load spaceship3.png");
    }
    this->playerTextures.push_back(tmp);
    this->isUnlocked.push_back(true);

    if (!tmp.loadFromFile("assets/images/spaceship4.png"))
    {
        throw std::runtime_error("Error::Failed to load spaceship4.png");
    }
    this->playerTextures.push_back(tmp);
    this->isUnlocked.push_back(false);

    if (!tmp.loadFromFile("assets/images/spaceship5.png"))
    {
        throw std::runtime_error("Error::Failed to load spaceship5.png");
    }
    this->playerTextures.push_back(tmp);
    this->isUnlocked.push_back(false);
}

void State::updateKeys()
{
    keys.clear();
    
    std::ifstream ifs("config/gameState_keybinds.ini");

    if (ifs.is_open())
    {
        std::string key1 = "";
        std::string key2 = "";

        while (ifs >> key1 >> key2)
        {
            keys[key1] = key2;
        }
    }

    ifs.close();
}

void State::pausedState()
{
    paused = true;
}

void State::unPausedState()
{
    paused = false;
}

void State::endState()
{
    quit = true;
}

const bool State::getQuit() const
{
    return quit;
}

const bool State::getKeytime()
{
    if (this->keytime >= this->keytimeMax)
    {
        this->keytime = 0.f;
        return true;
    }

    return false;
}

void State::updateKeytime(const float &dt)
{
    if (this->keytime < this->keytimeMax)
        this->keytime += 100.f * dt;
}

void State::updateMousePosition()
{
    mousePosScreen = sf::Mouse::getPosition();
    mousePosWindow = sf::Mouse::getPosition(*this->mWindow);
    mousePosView = mWindow->mapPixelToCoords(sf::Mouse::getPosition(*this->mWindow));
}