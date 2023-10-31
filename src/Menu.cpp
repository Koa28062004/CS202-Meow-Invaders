#include "Menu.h"
#include "GlobalVars.h"

Menu::Menu() : mWindow(sf::VideoMode(1000, 800), "CS202 Meow Invaders", sf::Style::Close)
{
}

void Menu::run()
{
    mWindow.setFramerateLimit(60);
    while (mWindow.isOpen())
    {
        processEvent();
        update();
        draw();
    }
}

void Menu::processEvent()
{
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            mWindow.close();
            break;
        case sf::Event::GainedFocus:
            CurrentState::isPaused = false;
            break;
        case sf::Event::LostFocus:
            CurrentState::isPaused = true;
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            mWindow.close();
            break;
        }
    }
}

void Menu::update() {

}

void Menu::draw() {
    mWindow.clear(sf::Color::White);

    mWindow.display();
}