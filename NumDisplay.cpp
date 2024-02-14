/* CSCI 200: Final Project: Tech Dumpster Dive
 *
 * Author: Thomas McInnes
 * 
 * Simulation of a technology dumpster dive, where random items of varying rarity are obtained, and profit/losses are tracked!
 *  Also has save/load functionality, and can keep track of your inventory!
 * 
 */
#include "NumDisplay.h"
#include <iostream>

NumberDisplay::NumberDisplay() {
    _value = 0;
    _x = 0;
    _y = 0;
}

NumberDisplay::NumberDisplay(const int VALUE, const std::string DESC, const float X, const float Y) {
    _value = VALUE;
    _descriptor = DESC;
    _x = X;
    _y = Y;
}

NumberDisplay::~NumberDisplay() {
    delete this;
}

void NumberDisplay::setValue(const int VALUE) {
    _value = VALUE;
}

void NumberDisplay::draw(sf::RenderWindow& window, sf::Font& font) const {
    sf::Text text;
    std::string fullString = _descriptor + " " + std::to_string(_value);

    text.setString(fullString);
    text.setFillColor(sf::Color::Black);
    text.setFont(font);
    text.setPosition(_x, _y);

    window.draw(text);
}