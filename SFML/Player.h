#ifndef PLAYER_H // Begin conditional inclusion to prevent multiple inclusions of the header file
#define PLAYER_H

#include <iostream>
#include <string>
#include "Entity.h"

// Player class declaration, inheriting from Entity
class Player : public Entity {
protected:
    bool dodge; // Attribute to indicate if the player is dodging

public:
    // Default constructor for Player class
    Player();

    // Parameterized constructor to initialize the player's attributes
    Player(std::string Name, std::string info, int element, int health_point, int skill_point, int attack);

    // Setter for the dodge attribute
    void set_dodge(bool dodge); // Sets the dodge attribute to the provided value

    // Getter for the dodge attribute
    bool get_dodge(); // Returns the current value of the dodge attribute

    // Function to calculate damage dealt by the player based on the chosen option
    int damageDealt(int attack, int playerOption);
};

#endif // End conditional inclusion
