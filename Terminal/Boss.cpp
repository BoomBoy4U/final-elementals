#include <iostream>
#include <string>
#include "Enemy.h"
#include "Entity.h"
#include "Boss.h"

// Default constructor for the Boss class
Boss::Boss() : Enemy() {}

// Parameterized constructor for the Boss class
// Initializes the Boss object with the given parameters
Boss::Boss(std::string Name, std::string info, int element, int health_point, int attack) {
    this->Name = Name;               // Set the name of the Boss
    this->info = info;               // Set additional info about the Boss
    this->element = element;         // Set the element type of the Boss
    this->health_point = health_point; // Set the health points of the Boss
    this->attack = attack;           // Set the attack value of the Boss
}

// Function to calculate the damage dealt by the Boss
int Boss::damageDealt(int attack) {
    srand(time(NULL));               // Seed the random number generator with the current time
    int enemyOption = rand() % 2 + 1; // Generate a random number between 1 and 2

    if (enemyOption == 1) {
        // If the random number is 1, use the basic attack
        //std::cout << "use basic attack" << std::endl;
        return damage = attack;      // Return the basic attack damage
    } else if (enemyOption == 2) {
        // If the random number is 2, use the ultimate attack
        //std::cout << "use utimate attack" << std::endl;
        damage = attack * 3;         // Calculate the ultimate attack damage
        return damage;               // Return the ultimate attack damage
    }
}
