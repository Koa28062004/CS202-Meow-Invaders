#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class Menu {
public:
    Menu();
    void run();

private:
    void processEvent();
    void update();
    void draw();

private:    
    sf::RenderWindow mWindow;
    sf::Event event;
    sf::Font font;
};