#include <iostream>  // Include the standard input-output stream library
#include <string>    // Include the string library for string manipulation
#include "Player.h"  // Include the header file for the Player class
#include "Entity.h"  // Include the header file for the Entity class

using namespace std;

// Default constructor for the Player class
Player::Player() : Entity() {}

// Parameterized constructor for the Player class
// Initializes the Player object with the given parameters
Player::Player(std::string Name, std::string info, int element, int health_point, int skill_point, int attack) {
    this->Name = Name;               // Set the name of the Player
    this->info = info;               // Set additional info about the Player
    this->element = element;         // Set the element type of the Player
    this->health_point = health_point; // Set the health points of the Player
    this->skill_point = skill_point; // Set the skill points of the Player
    this->attack = attack;           // Set the attack value of the Player
    this->dodge = false;             // Initialize dodge to false
}

// Setter for the dodge state
void Player::set_dodge(bool newdodge) {
    dodge = newdodge;
}

// Getter for the dodge state
bool Player::get_dodge() {
    return dodge;
}

// Function to calculate the damage dealt by the Player based on the player's action
int Player::damageDealt(int attack, int playerOption) {
    if (playerOption == 1) {
        // If the player chooses to dodge
        srand(time(NULL));           // Seed the random number generator
        int chance = rand() % 2 + 1; // Generate a random number between 1 and 2
        if (chance == 1) {
            dodge = true;            // Player successfully dodges
        } else {
            dodge = false;           // Player fails to dodge
        }
        return 0;                    // Dodging does not deal damage
    } else if (playerOption == 2) {
        // If the player chooses to use an elemental attack
        skill_point -= 10;           // Reduce skill points
        srand(time(NULL));           // Seed the random number generator
        element = rand() % 3 + 1;    // Randomly assign an element type (1 to 3)
        return damage = attack;      // Return the attack damage
    } else if (playerOption == 3) {
        // If the player chooses to use an ultimate attack
        health_point -= 20;          // Reduce health points
        return damage = attack * 5;  // Return the ultimate attack damage
    }
    return 0;                        // Default return value
}
