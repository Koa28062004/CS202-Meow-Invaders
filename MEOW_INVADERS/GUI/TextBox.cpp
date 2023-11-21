#include "TextBox.h"

TextBox::TextBox(int size, sf::Color color, bool sel) 
{
    textBox.setCharacterSize(size);
    textBox.setColor(color);
    isSelected = sel;
    if (sel) {
        textBox.setString("_");
    }
    else {
        textBox.setString("");
    }
}

TextBox::~TextBox() {

}

void TextBox::inputLogic(int charTyped)
{
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
        text << static_cast<char>(charTyped);
    }
    else if (charTyped == DELETE_KEY) {
        if (text.str().length() > 0) {
            deleteLastChar();
        }
    }
    textBox.setString(text.str() + "_");
}

void TextBox::deleteLastChar() {
    std::string t = text.str();
    std::string newT = "";
    for (int i = 0; i < t.length() - 1; ++i) {
        newT += t[i];
    }
    text.str("");
    text << newT;

    textBox.setString(text.str());
}

void TextBox::setFont(sf::Font &font) {
    textBox.setFont(font);
}

void TextBox::setPosition(sf::Vector2f pos) {
    textBox.setPosition(pos);
}

void TextBox::setLimit(bool ToF) {
    hasLimit = ToF;
}

void TextBox::setLimit(bool ToF, int lim) {
    hasLimit = ToF;
    limit = lim;
}

void TextBox::setSelected(bool sel) {
    isSelected = sel;
    if (!sel) {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length(); ++i) {
            newT += t[i];
        }
        textBox.setString(newT);
    }
}

std::string TextBox::getText() {
    return text.str();
}

void TextBox::drawText(sf::RenderTarget *target) {
    target->draw(textBox);
}

void TextBox::typeOn(const sf::Event &input) {
    if (isSelected) {
        int charTyped = input.text.unicode;
        if (charTyped < 128) {
            if (hasLimit) {
                if (text.str().length() <= limit) {
                    inputLogic(charTyped);
                }
                else if (text.str().length() > limit && charTyped == DELETE_KEY) {
                    deleteLastChar();
                }
            }
            else 
                inputLogic(charTyped);
        }
    }
}