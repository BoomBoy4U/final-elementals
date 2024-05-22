#ifndef GAMEMENU_H
#define GAMEMENU_H

#include "Gameplay.h"
#include <iostream>
#include <fstream>
#include <vector>

// GameMenu class inherits from Gameplay
class GameMenu : public Gameplay {
public:
    // Constructor that initializes the GameMenu with a Player object
    GameMenu(Player* player);

    // Method to start the game
    void start();

    // Method to display the game results
    void showResults();

    // Variables to manage game state
    int startOrExit;    // Determines whether to start or exit the game
    int pass_stage1;    // Flag to indicate if stage 1 is passed
    int pass_stage2;    // Flag to indicate if stage 2 is passed
    int pass_stage3;    // Flag to indicate if stage 3 is passed
    std::string name;   // Player's name

    // Method to play a specific stage
    void playStage(int stage);

    // Method to record game results to a file
    void recordResults();
};

#endif // GAMEMENU_H
