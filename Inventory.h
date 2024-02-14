/* CSCI 200: Final Project: Tech Dumpster Dive
 *
 * Author: Thomas McInnes
 * 
 * Simulation of a technology dumpster dive, where random items of varying rarity are obtained, and profit/losses are tracked!
 *  Also has save/load functionality, and can keep track of your inventory!
 * 
 */
#ifndef INVENTORY_H
#define INVENTORY_H

/**
 * @brief Inventory object that stores the counts of the items within Tech Dumpster Dive
 * 
 */
struct Inventory {

    /**
     * @brief Construct a new Inventory object
     * 
     * @param INDEX_COUNT Number of Valve Indexes
     * @param SPEAKER_COUNT Number of JBL Flip 6s
     * @param DVD_COUNT Number of Sony DVD Players
     * @param EARBUD_COUNT Number of Dollar Store Earbuds
     */
    Inventory(const int INDEX_COUNT, const int SPEAKER_COUNT, 
              const int DVD_COUNT, const int EARBUD_COUNT);

    int indexCount;   // Number of Valve Indexes
    int speakerCount; // Number of JBL Flip 6s
    int dvdCount;     // Number of Sony DVD Players
    int earbudCount;  // Number of Dollar Store Earbuds

};

#endif