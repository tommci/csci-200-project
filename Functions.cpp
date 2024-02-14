/* CSCI 200: Final Project: Tech Dumpster Dive
 *
 * Author: Thomas McInnes
 * 
 * Simulation of a technology dumpster dive, where random items of varying rarity are obtained, and profit/losses are tracked!
 *  Also has save/load functionality, and can keep track of your inventory!
 * 
 */
#include "Functions.h"

#include <SFML/Graphics.hpp>
#include <string>
#include "Button.h"
#include "Screen.h"
#include <iostream>

sf::Text* text_box(const std::string STRING, sf::Font& font, const float X, const float Y) {
    sf::Text* pText = new sf::Text;
    pText->setString(STRING);
    pText->setFont(font);
    pText->setFillColor(sf::Color::Black);
    pText->setPosition(X, Y);
    return pText;
}

void screen_update(Button* pButton, Screen& screen) {
    if(pButton->getCommand() == "MENU" || pButton->getCommand() == "LOAD" ) {
        screen.id = 1, screen.name = "menu";
        screen.buttonCount = 4, screen.buttonLoopIndexStart = 2;
        screen.textCount = 1, screen.textLoopIndexStart = 1;
        screen.numCount = 3, screen.numLoopIndexStart = 0;
    }

    if(pButton->getCommand() == "OPENDUMP") {
        screen.id = 2, screen.name = "open_dumpster";
        screen.buttonCount = 0, screen.buttonLoopIndexStart = 0;
        screen.textCount = 0, screen.textLoopIndexStart = 0;
        screen.numCount = 0, screen.numLoopIndexStart = 0;
    }

    if(pButton->getCommand() == "INVEN") {
        screen.id = 3, screen.name = "inventory";
        screen.buttonCount = 1, screen.buttonLoopIndexStart = 7;
        screen.textCount = 4, screen.textLoopIndexStart = 6;
        screen.numCount = 4, screen.numLoopIndexStart = 3;
    }

    if(pButton->getCommand() == "QUIT") {
        screen.id = 4, screen.name = "quit";
        screen.buttonCount = 2, screen.buttonLoopIndexStart = 8;
        screen.textCount = 1, screen.textLoopIndexStart = 10;
        screen.numCount = 0, screen.numLoopIndexStart = 0;
    }

    if(pButton->getCommand() == "SAVE") {
        screen.id = 5, screen.name = "save_confirm";
        screen.buttonCount = 1, screen.buttonLoopIndexStart = 6;
        screen.textCount = 1, screen.textLoopIndexStart = 11;
        screen.numCount = 0, screen.numLoopIndexStart = 0;
    }
}
