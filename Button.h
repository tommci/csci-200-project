/* CSCI 200: Final Project: Tech Dumpster Dive
 *
 * Author: Thomas McInnes
 * 
 * Simulation of a technology dumpster dive, where random items of varying rarity are obtained, and profit/losses are tracked!
 *  Also has save/load functionality, and can keep track of your inventory!
 * 
 */
#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

/**
 * @brief Generic button that can hold different commands, text, and button sizes
 * 
 */
class Button {
public:

    /**
     * @brief Construct a new Button object
     * 
     */
    Button();
    /**
     * @brief Construct a new Button object
     * 
     * @param TEXT Text on the button
     * @param COMMAND Command string that the button will execute
     * @param RECT_WIDTH Width of the button rect
     * @param RECT_HEIGHT Height of the button rect
     * @param X X position of the button
     * @param Y Y position of the button
     */
    Button(const std::string TEXT, const std::string COMMAND, 
           const float RECT_WIDTH, const float RECT_HEIGHT, 
           const float X, const float Y);
    /**
     * @brief Destroy the Button object
     * 
     */
    ~Button();
    /**
     * @brief Get the Command object
     * 
     * @return std::string command string
     */
    std::string getCommand() const;
    /**
     * @brief Draws the button to the given SFML RenderWindow object
     * 
     * @param window SFML RenderWindow object
     * @param font SFML Font (to display button text)
     */
    void draw(sf::RenderWindow& window, sf::Font& font) const;
    /**
     * @brief Checks if the location where the mouse button was released coincides with the button
     * 
     * @param MOUSE_X X position of the mouse relative to the window
     * @param MOUSE_Y Y position of the mouse relative to the window
     * @return true Button was clicked
     * @return false Button was not clicked
     */
    bool checkIfClicked(const int MOUSE_X, const int MOUSE_Y) const;

private:
    std::string _buttonText;    // string of text to display on button
    std::string _buttonCommand; // string command that the button will execute once clicked
    float _buttonWidth;         // width of the button in pixels
    float _buttonHeight;        // height of the button in pixels
    float _x;                   // x position of the button
    float _y;                   // y position of the button
};

#endif