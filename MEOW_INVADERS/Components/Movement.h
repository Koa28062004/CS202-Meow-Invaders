#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cstring>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class Movement {
public:
    Movement();
    virtual ~Movement();
};

#endif