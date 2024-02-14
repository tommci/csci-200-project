/* CSCI 200: Final Project: Tech Dumpster Dive
 *
 * Author: Thomas McInnes
 * 
 * Simulation of a technology dumpster dive, where random items of varying rarity are obtained, and profit/losses are tracked!
 *  Also has save/load functionality, and can keep track of your inventory!
 * 
 */
#ifndef SCREEN_H
#define SCREEN_H

#include <string>

/**
 * @brief Holds the id, name, button, text, number of each screen
 * 
 */
struct Screen {

    /**
     * @brief Construct a new Screen object
     * 
     * @param ID Numerical ID of the screen
     * @param NAME Name of the screen in text (serves as a descriptor)
     * @param BUTTON_COUNT Number of buttons on the screen of given ID
     * @param BTN_IDX_STRT The start index of the button list to iterate through
     * @param TEXT_COUNT Number of text boxes on the screen of given ID
     * @param TXT_IDX_STRT The start index of the text box list to iterate through
     * @param NUM_COUNT Number of number displays on the screen of given ID
     * @param NUM_IDX_STRT The start index of the number display list to iterate through
     */
    Screen(const int ID, const std::string NAME, 
           const int BUTTON_COUNT, const int BTN_IDX_STRT,
           const int TEXT_COUNT, const int TXT_IDX_STRT,
           const int NUM_COUNT, const int NUM_IDX_STRT);

    int id;                     // numerical id of scree
    std::string name;           // name of screen

    int buttonCount;            // number of buttons on screen
    int buttonLoopIndexStart;   // start index of button loop

    int textCount;              // number of text boxes on screen
    int textLoopIndexStart;     // start index of text box loop

    int numCount;               // number of number displays on screen
    int numLoopIndexStart;      // start index of number display loop

};

#endif