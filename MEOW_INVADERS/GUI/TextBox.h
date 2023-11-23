#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cstring>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#define DELETE_KEY 8
#define ENTER_KEY 10
#define ESCAPE_KEY 27

class TextBox
{
public:
    TextBox(int size, sf::Color color, bool sel);
    ~TextBox();

    // Functions
    void setText(std::string text);
    void setFont(sf::Font &font);
    void setPosition(sf::Vector2f pos);
    void setLimit(bool ToF);
    void setLimit(bool ToF, int lim);
    void setSelected(bool sel);
    std::string getText();
    void drawText(sf::RenderTarget *target);
    void typeOn(const sf::Event &input);

    const bool getKeytime();
    void updateKeytime(const float &dt);

private:
    void inputLogic(int charTyped);
    void deleteLastChar();

    sf::Text textBox;
    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit;

    float keytime;
	float keytimeMax;
};

#endif