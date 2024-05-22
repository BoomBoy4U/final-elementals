#include <iostream>  // Include the standard input-output stream library
#include <string>    // Include the string library for string manipulation
#include "Enemy.h"   // Include the header file for the Enemy class
#include "Entity.h"  // Include the header file for the Entity class

// Default constructor for the Enemy class
Enemy::Enemy() : Entity() {}

// Parameterized constructor for the Enemy class
// Initializes the Enemy object with the given parameters
Enemy::Enemy(std::string Name, std::string info, int element, int health_point, int attack) {
    this->Name = Name;                // Set the name of the Enemy
    this->info = info;                // Set additional info about the Enemy
    this->element = element;          // Set the element type of the Enemy
    this->health_point = health_point; // Set the health points of the Enemy
    this->attack = attack;            // Set the attack value of the Enemy
}

// Function to calculate the damage dealt by the Enemy
int Enemy::damageDealt(int attack) {
    //std::cout << "use basic attack" << std::endl;
    damage = attack;  // Assign the attack value to the damage
    return damage;    // Return the damage value
}
