#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>  // Include standard input-output stream library
#include <string>    // Include the string library for string manipulation
#include "Entity.h"  // Include the header file for the Entity class

// Player class definition, inheriting from the Entity class
class Player : public Entity {
protected:
    bool dodge;  // Boolean to indicate if the player dodged an attack

public:
    // Default constructor
    Player();

    // Parameterized constructor
    Player(std::string Name, std::string info, int element, int health_point, int skill_point, int attack);

    // Setter for the dodge state
    void set_dodge(bool dodge);

    // Getter for the dodge state
    bool get_dodge();

    // Function to calculate the damage dealt by the player based on the action taken
    int damageDealt(int attack, int playerOption);
};

#endif // End of the include guard
