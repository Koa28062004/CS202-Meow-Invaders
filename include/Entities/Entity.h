#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <stack>
#include <map>
#include <vector>
#include <string>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Entity {
public:
    Entity();
    virtual ~Entity();

    // Functions
    virtual void move(const float &x, const float &y);
    virtual void update();
    virtual void draw(sf::RenderTarget* target);

protected:
    sf::RectangleShape shape;

private:

};

#endif