/* CSCI 200: Final Project: Tech Dumpster Dive
 *
 * Author: Thomas McInnes
 * 
 * Simulation of a technology dumpster dive, where random items of varying rarity are obtained, and profit/losses are tracked!
 *  Also has save/load functionality, and can keep track of your inventory!
 * 
 */
#ifndef NUM_DISPLAY_H
#define NUM_DISPLAY_H

#include <SFML/Graphics.hpp>
#include <string>

/**
 * @brief A number display that is capable of dynamically updating on the screen
 * 
 */
class NumberDisplay {
public:

    /**
     * @brief Construct a new Number Display object
     * 
     */
    NumberDisplay();
    /**
     * @brief Construct a new Number Display object
     * 
     * @param VALUE Numerical value to display
     * @param DESC Number description in text that is displayed before the value
     * @param X Value X Position
     * @param Y Value Y Position
     */
    NumberDisplay(const int VALUE, const std::string DESC, const float X, const float Y);
    /**
     * @brief Destroy the Number Display object
     * 
     */
    ~NumberDisplay();
    /**
     * @brief Set the _value object
     * 
     * @param VALUE Numerical value to set to
     */
    void setValue(const int VALUE);
    /**
     * @brief Draws the number display to the given window
     * 
     * @param window SFML RenderWindow object
     * @param font SFML Font object
     */
    void draw(sf::RenderWindow& window, sf::Font& font) const;

private:

    int _value;                 // numerical value to display
    std::string _descriptor;    // text description of value
    float _x;                   // value x position
    float _y;                   // value y position

};

#endif