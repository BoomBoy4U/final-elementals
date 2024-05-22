#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Entity.h"
#include <vector>

// Gameplay class definition
class Gameplay {
private:
    Player* player;                    // Pointer to the Player object
    std::vector<Entity*>& enemies;     // Reference to a vector of Entity pointers
    int stage = 0;                     // Current stage number

public:
    // Constructor to initialize the Gameplay with a list of enemies and a player
    Gameplay(std::vector<Entity*>& _enemies, Player* _player);

    // Method to play the game stage
    int play(std::vector<Entity*>& enemies, Player* player);

    // Getter for the current stage
    int get_stage();

    // Setter for the current stage
    void set_stage(int _stage);
};

#endif // End of the include guard
