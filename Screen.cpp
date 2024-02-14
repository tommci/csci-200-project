/* CSCI 200: Final Project: Tech Dumpster Dive
 *
 * Author: Thomas McInnes
 * 
 * Simulation of a technology dumpster dive, where random items of varying rarity are obtained, and profit/losses are tracked!
 *  Also has save/load functionality, and can keep track of your inventory!
 * 
 */
#include "Screen.h"

Screen::Screen(const int ID, const std::string NAME, 
               const int BUTTON_COUNT, const int BTN_IDX_STRT,
               const int TEXT_COUNT, const int TXT_IDX_STRT,
               const int NUM_COUNT, const int NUM_IDX_STRT) {
    id = ID;
    name = NAME;
    buttonCount = BUTTON_COUNT;
    buttonLoopIndexStart = BTN_IDX_STRT;
    textCount = TEXT_COUNT;
    textLoopIndexStart = TXT_IDX_STRT;
    numCount = NUM_COUNT;
    numLoopIndexStart = NUM_IDX_STRT;
}