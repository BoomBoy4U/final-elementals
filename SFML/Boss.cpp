#include <iostream>
#include <string>
#include <cstdlib> // Include for rand() and srand()
#include <ctime>   // Include for time()

// Include necessary header files
#include "Enemy.h"
#include "Entity.h"
#include "Boss.h"

// Default constructor for Boss class, calling the base class Enemy constructor
Boss::Boss() : Enemy() {}

// Parameterized constructor for Boss class
Boss::Boss(std::string Name, std::string info, int element, int health_point, int attack) {
    this->Name = Name;             // Initialize the boss's name
    this->info = info;             // Initialize the boss's information
    this->element = element;       // Initialize the boss's element type
    this->health_point = health_point; // Initialize the boss's health points
    this->attack = attack;         // Initialize the boss's attack points
}

// Function to calculate damage dealt by the boss
int Boss::damageDealt(int attack) {
    srand(time(NULL));             // Seed the random number generator with the current time
    int enemyOption = rand() % 2 + 1; // Generate a random number between 1 and 2

    // Determine the type of attack based on the random number
    if (enemyOption == 1) {
        // Use basic attack
        damage = attack;
    } else if (enemyOption == 2) {
        // Use ultimate attack
        damage = attack * 3;
    }

    return damage;                 // Return the calculated damage
}
