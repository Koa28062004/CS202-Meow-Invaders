#include "PauseState.h"

PauseState::PauseState(sf::RenderWindow* window)
{
    // Init background
    background.setSize(sf::Vector2f((float)window->getSize().x,
                                    (float)window->getSize().y));
    background.setFillColor(sf::Color(20, 20, 20, 100));

    // Init container
    container.setSize(sf::Vector2f((float)window->getSize().x / 4.f,
                                   (float)window->getSize().y));

    container.setFillColor(sf::Color(20, 20, 20, 200));
    container.setPosition((float)window->getSize().x / 2.f - container.getSize().x / 2.f, 0.f);
}

PauseState::~PauseState()
{
    auto it = buttons.begin();
    for (it = buttons.begin(); it != buttons.end(); ++it)
    {
        delete it->second;
    }
}

// Functions
void PauseState::update()
{
}

void PauseState::draw(sf::RenderTarget* target)
{
    target->draw(background);
    target->draw(container);

    for (auto &it : this->buttons)
    {
        it.second->draw(target);
    }
}