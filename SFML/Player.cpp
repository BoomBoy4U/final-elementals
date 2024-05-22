#include <iostream>
#include <string>
#include "Player.h"
#include "Entity.h"
using namespace std;

// Default constructor for Player class
Player::Player() : Entity() {}

// Parameterized constructor for Player class
Player::Player(std::string Name, std::string info, int element, int health_point, int skill_point, int attack) {
    this->Name = Name;                 // Initialize the player's name
    this->info = info;                 // Initialize the player's information
    this->element = element;           // Initialize the player's element type
    this->health_point = health_point; // Initialize the player's health points
    this->skill_point = skill_point;   // Initialize the player's skill points
    this->attack = attack;             // Initialize the player's attack points
    this->dodge = false;               // Initialize the player's dodge ability to false
}

// Setter for the dodge attribute
void Player::set_dodge(bool newdodge) { 
    dodge = newdodge; // Set the dodge attribute to the new value
}

// Getter for the dodge attribute
bool Player::get_dodge() { 
    return dodge; // Return the dodge attribute
}

// Function to calculate damage dealt by the player based on the chosen option
int Player::damageDealt(int attack, int playerOption) {
    if (playerOption == 1) { // Option 1: Dodge
        // Use dodge
        srand(time(NULL));
        int chance = rand() % 2 + 1; // Generate a random number between 1 and 2
        if (chance == 1) {
            dodge = true; // Successful dodge
        } else if (chance == 2) {
            dodge = false; // Unsuccessful dodge
        }
        damage = 0; // No damage dealt when dodging
    } else if (playerOption == 2) { // Option 2: Elemental attack
        // Use elemental attack
        skill_point -= 10; // Reduce skill points by 10
        srand(time(NULL));
        element = rand() % 3 + 1; // Randomly select an element
        damage = attack; // Set damage to the attack value
    } else if (playerOption == 3) { // Option 3: Ultimate attack
        // Use ultimate attack
        this->health_point -= 20; // Reduce health points by 20
        damage = attack * 5; // Set damage to five times the attack value
    }
    return damage; // Return the calculated damage
}
