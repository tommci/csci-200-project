/* CSCI 200: Final Project: Tech Dumpster Dive
 *
 * Author: Thomas McInnes
 * 
 * Simulation of a technology dumpster dive, where random items of varying rarity are obtained, and profit/losses are tracked!
 *  Also has save/load functionality, and can keep track of your inventory!
 * 
 */
#include "Inventory.h"

Inventory::Inventory(const int INDEX_COUNT, const int SPEAKER_COUNT, 
                     const int DVD_COUNT, const int EARBUD_COUNT) { 
    indexCount = INDEX_COUNT;
    speakerCount = SPEAKER_COUNT;
    dvdCount = DVD_COUNT;
    earbudCount = EARBUD_COUNT;
}