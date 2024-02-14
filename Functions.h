/* CSCI 200: Final Project: Tech Dumpster Dive
 *
 * Author: Thomas McInnes
 * 
 * Simulation of a technology dumpster dive, where random items of varying rarity are obtained, and profit/losses are tracked!
 *  Also has save/load functionality, and can keep track of your inventory!
 * 
 */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Button.h"
#include "Screen.h"

/**
 * @brief Creates a text object based on given font, string, x and y coordinates
 * 
 * @param STRING Text to display
 * @param font Font to use
 * @param X X position of text
 * @param Y Y position of text
 * @return sf::Text* Returns a pointer to a Text object
 */
sf::Text* text_box(const std::string STRING, sf::Font& font, const float X, const float Y);

/**
 * @brief Updates the screen based on the command of the button pressed
 * 
 * @param pButton Button clicked by user
 * @param screen Screen object to update
 */
void screen_update(Button* pButton, Screen& screen);

#endif