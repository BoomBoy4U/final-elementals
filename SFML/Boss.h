#pragma once // Ensures the file is included only once during compilation
#include <iostream>
#include <string>
#include "Enemy.h"
#include "Entity.h" // Include the necessary header files

#ifndef BOSS_H // Begin conditional inclusion to prevent multiple inclusions of the header file
#define BOSS_H

// Boss class declaration inheriting from Enemy class
class Boss : public Enemy {
public:
    // Default constructor
    Boss();

    // Parameterized constructor to initialize the boss's attributes
    Boss(std::string Name, std::string info, int element, int health_point, int attack);

    // Function to calculate the damage dealt by the boss
    int damageDealt(int attack);
};

#endif // End conditional inclusion
