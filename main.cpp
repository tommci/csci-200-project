/* CSCI 200: Final Project: Tech Dumpster Dive
 *
 * Author: Thomas McInnes
 * 
 * Simulation of a technology dumpster dive, where random items of varying rarity are obtained, and profit/losses are tracked!
 *  Also has save/load functionality, and can keep track of your inventory!
 * 
 */
#include "Button.h"
#include "Screen.h"
#include "NumDisplay.h"
#include "Inventory.h"
#include "Functions.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// note: included 'dumpster_save.txt' file is an example save file

int main() {
        // ---------- initial setup ----------
    srand(time(0));
    rand();

    // window setup
    int winWidth = 800, winHeight = 800;
    sf::RenderWindow window( sf::VideoMode(winWidth, winHeight), "Tech Dumpster Dive" );

    // font setup
    sf::Font font;
    font.loadFromFile("data/arial.ttf");
    if(!font.loadFromFile("data/arial.ttf")) { return -1; }

    // clock/animation setup
    sf::Clock clock;
    int cycles = 0, frame = 0;

    // inventory setup
    Inventory playerInventory(0, 0, 0, 0);

    // text box setup
    vector<sf::Text*> textList;
    // load data text:
    textList.push_back(text_box("Would you like to load data from a file?", font, 150, 100));                                                       // 0
    // menu screen text:
    textList.push_back(text_box("Cost: 10", font, 345, 410));                                                                                       // 1
    // item roll text:
    textList.push_back(text_box("Item: Valve Index\n\nRarity: 4 (Legendary)\nValue: 1000", font, 200, 50));                                         // 2
    textList.push_back(text_box("Item: JBL Flip 6\n\nRarity: 3 (Rare)\nValue: 100", font, 200, 50));                                                // 3
    textList.push_back(text_box("Item: Sony DVD Player\n\nRarity: 2 (Uncommon)\nValue: 35", font, 200, 50));                                        // 4
    textList.push_back(text_box("Item: Dollar Store Earbuds\n\nRarity: 1 (Common)\nValue: 5", font, 200, 50));                                      // 5
    // inventory text:
    textList.push_back(text_box("Item: Valve Index\nRarity: 4 (Legendary)\nValue: 1000", font, 50, 30));                                            // 6
    textList.push_back(text_box("Item: JBL Flip 6\nRarity: 3 (Rare)\nValue: 100", font, 50, 230));                                                  // 7
    textList.push_back(text_box("Item: Sony DVD Player\nRarity: 2 (Uncommon)\nValue: 35", font, 50, 430));                                          // 8
    textList.push_back(text_box("Item: Dollar Store Earbuds\nRarity: 1 (Common)\nValue: 5", font, 50, 630));                                        // 9
    // quit text:
    textList.push_back(text_box("Are you sure you want to quit?\nMake sure to save!", font, 200, 100));                                             // 10
    // save text:
    textList.push_back(text_box("Data saved to 'dumpster_save.txt'\nInsert this file in the current directory to load it later", font, 50, 100));  // 11

    // dynamic number setup (numbers that can update visually)
    int dumpBuxSpent = 0, dumpBuxEarned = 0, profit = 0;
    vector<NumberDisplay*> numDisplayList;
    // dumpbux display
    numDisplayList.push_back(new NumberDisplay(dumpBuxSpent, "DumpBux Spent:", 30, 30));            // 0
    numDisplayList.push_back(new NumberDisplay(dumpBuxEarned, "DumpBux Earned:", 30, 80));          // 1
    numDisplayList.push_back(new NumberDisplay(dumpBuxEarned, "Profit/Debt:", 30, 130));            // 2
    // inventory display
    numDisplayList.push_back(new NumberDisplay(playerInventory.indexCount, "Owned:", 250, 100));    // 3
    numDisplayList.push_back(new NumberDisplay(playerInventory.speakerCount, "Owned:", 250, 300));  // 4
    numDisplayList.push_back(new NumberDisplay(playerInventory.dvdCount, "Owned:", 250, 500));      // 5
    numDisplayList.push_back(new NumberDisplay(playerInventory.earbudCount, "Owned:", 250, 700));   // 6

    // button setup (buttons that can be pressed with varying commands)
    vector<Button*> buttonList;
    // file load buttons:
    buttonList.push_back(new Button("Yes", "LOAD", 70, 50, 200, 500));               // 0
    buttonList.push_back(new Button("No", "MENU", 70, 50, 550, 500));                // 1
    // menu screen buttons:
    buttonList.push_back(new Button("Dumpster", "OPENDUMP", 150, 50, 325, 350));     // 2
    buttonList.push_back(new Button("Inventory", "INVEN", 150, 50, 325, 700));       // 3
    buttonList.push_back(new Button("Save", "SAVE", 85, 50, 50, 700));               // 4
    buttonList.push_back(new Button("Quit", "QUIT", 80, 50, 650, 700));              // 5
    // item roll buttons (save confirm screen also uses this button):
    buttonList.push_back(new Button("Continue", "MENU", 150, 50, 325, 600));         // 6
    // inventory buttons:
    buttonList.push_back(new Button("Back", "MENU", 85, 50, 680, 50));              // 7
    // quit screen buttons:
    buttonList.push_back(new Button("Yes", "KILL", 70, 50, 200, 500));               // 8
    buttonList.push_back(new Button("No", "MENU", 70, 50, 550, 500));                // 9

    // load textures (each texture is 400 x 400)
    sf::Texture indexTexture, dvdTexture, earbudTexture, speakerTexture;
    if(!indexTexture.loadFromFile("data/index.png")) { return -1; }
    if(!dvdTexture.loadFromFile("data/dvd.png")) { return -1; }
    if(!earbudTexture.loadFromFile("data/earbuds.png")) { return -1; }
    if(!speakerTexture.loadFromFile("data/speaker.png")) { return -1; }

    // setup sprites
    sf::Sprite indexSprite, dvdSprite, earbudSprite, speakerSprite;
    indexSprite.setTexture(indexTexture), dvdSprite.setTexture(dvdTexture), earbudSprite.setTexture(earbudTexture), speakerSprite.setTexture(speakerTexture);
    indexSprite.setPosition(200, 200), speakerSprite.setPosition(200, 200), dvdSprite.setPosition(200, 200), earbudSprite.setPosition(200, 200);

    // item setup
    int chance;

    // screen object to keep track of buttons and text boxes
    Screen currentScreen(0, "file", 
                         2, 0,      // buttons
                         1, 0,      // text
                         0, 0);     // numbers

    // file i/o setup
    ofstream fileOut;
    ifstream fileIn;

    sf::Event event;

        // end of setup
// -------------------------------------------------------------------
        // simulation loop begins here

    while( window.isOpen() ) {
    // ------------ draw loop begin ------------
        window.clear(sf::Color::White);

        // sets dumpbux display values
        numDisplayList.at(0)->setValue(dumpBuxSpent);
        numDisplayList.at(1)->setValue(dumpBuxEarned);
        profit = dumpBuxEarned - dumpBuxSpent;
        numDisplayList.at(2)->setValue(profit);

        // draws screen elements
        for(int i = currentScreen.textLoopIndexStart; i < currentScreen.textLoopIndexStart + currentScreen.textCount; i++) {
            window.draw(*textList.at(i));
        }
        for(int i = currentScreen.numLoopIndexStart; i < currentScreen.numLoopIndexStart + currentScreen.numCount; i++) {
            numDisplayList.at(i)->draw(window, font);
        }        
        for(int i = currentScreen.buttonLoopIndexStart; i < currentScreen.buttonLoopIndexStart + currentScreen.buttonCount; i++) {
            buttonList.at(i)->draw(window, font);
        }

        // opening dumpster sequence
        if( currentScreen.id == 2 ) {
            // animation of items cycling
            if( cycles <= 8 ) {
                if( frame == 0 ) {
                    window.draw(indexSprite);
                } else if( frame == 1 ) {
                    window.draw(speakerSprite);
                } else if( frame == 2 ) {
                    window.draw(earbudSprite);
                } else if( frame == 3 ) {
                    window.draw(dvdSprite);
                }
            // after animation concludes
            } else {
                // only picks random item once, updates values once
                if( cycles == 9 ) {
                    cycles++;
                    chance = rand() % ((100 + 1) - 1) + 1;  // generates value from 1 to 100
                    if( chance == 1 ) {             // chance for valve index
                        dumpBuxEarned += 1000;
                        indexSprite.setPosition(200, 200);
                        playerInventory.indexCount++;
                    } else if( chance < 12 ) {      // chance for speaker
                        dumpBuxEarned += 100;
                        speakerSprite.setPosition(200, 200);
                        playerInventory.speakerCount++;
                    } else if( chance < 31 ) {      // chance for dvd player
                        dumpBuxEarned += 35;
                        dvdSprite.setPosition(200, 200);
                        playerInventory.dvdCount++;
                    } else {                        // chance for earbuds
                        dumpBuxEarned += 5;
                        earbudSprite.setPosition(200, 200);
                        playerInventory.earbudCount++;
                    }
                    currentScreen.buttonCount = 1, currentScreen.buttonLoopIndexStart = 6;
                } else if( chance == 1 ) {
                    window.draw(indexSprite);
                    window.draw(*textList.at(2));
                } else if( chance < 12 ) {
                    window.draw(speakerSprite);
                    window.draw(*textList.at(3));
                } else if( chance < 31 ) {
                    window.draw(dvdSprite);
                    window.draw(*textList.at(4));
                } else { 
                    window.draw(earbudSprite);
                    window.draw(*textList.at(5));
                }
            }
        }

        // inventory render
        if( currentScreen.id == 3 ) {
            numDisplayList.at(3)->setValue(playerInventory.indexCount);
            numDisplayList.at(4)->setValue(playerInventory.speakerCount);
            numDisplayList.at(5)->setValue(playerInventory.dvdCount);
            numDisplayList.at(6)->setValue(playerInventory.earbudCount);
        }

        window.display();
    // ------------ draw loop end ------------

    // ------------  poll events  ------------
        while( window.pollEvent(event) ) {
            // closes window
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            // checks if onscreen buttons have been pressed
            if(event.type == sf::Event::MouseButtonReleased) {
                for(int i = currentScreen.buttonLoopIndexStart; i < currentScreen.buttonLoopIndexStart + currentScreen.buttonCount; i++) {
                    if( buttonList.at(i)->checkIfClicked(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) ) {
                        if( buttonList.at(i)->getCommand() == "OPENDUMP" ) {
                            screen_update(buttonList.at(i), currentScreen);
                            dumpBuxSpent += 10;
                            cycles = 0;
                            frame = 0;
                            clock.restart();
                        } else if( buttonList.at(i)->getCommand() == "KILL" ) {
                            window.close();
                        } else if( buttonList.at(i)->getCommand() == "SAVE" ) {
                            fileOut.open("dumpster_save.txt");
                            if( fileOut.fail() ) {
                                cerr << "Error creating/opening file. Are you out of storage?" << endl;
                                return -2;
                            }
                            fileOut << profit << endl << dumpBuxSpent << endl << dumpBuxEarned << endl
                                    << playerInventory.indexCount << endl << playerInventory.speakerCount << endl
                                    << playerInventory.dvdCount << endl << playerInventory.earbudCount << endl;
                            fileOut.close();
                            screen_update(buttonList.at(i), currentScreen);
                        } else if( buttonList.at(i)->getCommand() == "LOAD" ) {
                            fileIn.open("dumpster_save.txt");
                            if( fileIn.fail() ) {
                                cerr << "Error opening file. Did you place it in the correct directory?" << endl;
                                return -1;
                            }
                            fileIn >> profit >> dumpBuxSpent >> dumpBuxEarned >> playerInventory.indexCount
                                   >> playerInventory.speakerCount >> playerInventory.dvdCount >> playerInventory.earbudCount;
                            fileIn.close();
                            screen_update(buttonList.at(i), currentScreen);
                        } else { screen_update(buttonList.at(i), currentScreen); }
                    }
                }
            }
        }

    // ------------ frame counting start ------------
    if( currentScreen.id == 2 ) {
        if( cycles < 9 ) {
            if( clock.getElapsedTime().asSeconds() >= 0.05 ) {
                clock.restart();
                frame++;
                if( frame == 4 ) {
                    cycles++;
                    frame = 0; 
                }
            }            
        }
    }
    // ------------  frame counting end  ------------
    }

        // end of simulation loop
// -------------------------------------------------------------------
        // de-allocation

    for( size_t i = 0; i < textList.size(); i++ ) {
        delete textList.at(i);
    }
    textList.clear();
    for( size_t i = 0; i < buttonList.size(); i++ ) {
        delete buttonList.at(i);
    }
    buttonList.clear();
    for( size_t i = 0; i < numDisplayList.size(); i++ ) {
        delete numDisplayList.at(i);
    }
    numDisplayList.clear();
    return 0;
}
