/* CSCI 200: Final Project: Tech Dumpster Dive
 *
 * Author: Thomas McInnes
 * 
 * Simulation of a technology dumpster dive, where random items of varying rarity are obtained, and profit/losses are tracked!
 *  Also has save/load functionality, and can keep track of your inventory!
 * 
 */
#include "Button.h"

Button::Button() {
    _buttonText = "empty";
    _buttonCommand = "NONE";
    _buttonHeight = 0;
    _buttonWidth = 0;
    _x = 0;
    _y = 0;
}

Button::Button(const std::string TEXT, const std::string COMMAND, 
               const float RECT_WIDTH, const float RECT_HEIGHT, 
               const float X, const float Y) {
    _buttonText = TEXT;
    _buttonCommand = COMMAND;
    _buttonWidth = RECT_WIDTH;
    _buttonHeight = RECT_HEIGHT;
    _x = X;
    _y = Y;
}

Button::~Button() {
    delete this;
}

std::string Button::getCommand() const {
    return _buttonCommand;
}

void Button::draw(sf::RenderWindow& window, sf::Font& font) const {
    sf::RectangleShape button;
    sf::Text buttonText;

    button.setSize({_buttonWidth, _buttonHeight});
    button.setPosition(_x, _y);
    button.setFillColor(sf::Color::White);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(3);

    buttonText.setString(_buttonText);
    buttonText.setFont(font);
    buttonText.setPosition(_x + 10, _y + 8);
    buttonText.setFillColor(sf::Color::Black);
    
    window.draw(button);
    window.draw(buttonText);
}

bool Button::checkIfClicked(const int MOUSE_X, const int MOUSE_Y) const {
    if( (MOUSE_X > _x && MOUSE_X < (_x + _buttonWidth)) && (MOUSE_Y > _y && MOUSE_Y < (_y + _buttonHeight)) ) { return true; }
    else { return false; }
}