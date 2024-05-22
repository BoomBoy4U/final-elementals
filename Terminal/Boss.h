#pragma once  // Ensure the file is included only once during compilation
#include <iostream>  // Include standard input-output stream library
#include <string>    // Include the string library for string manipulation
#include "Enemy.h"   // Include the header file for the Enemy class
#include "Entity.h"  // Include the header file for the Entity class

#ifndef BOSS_H      // Begin the include guard to prevent multiple inclusions
#define BOSS_H

// Boss class definition, inheriting from the Enemy class
class Boss : public Enemy {
public:
    // Default constructor
    Boss();

    // Parameterized constructor
    Boss(std::string Name, std::string info, int element, int health_point, int attack);

    // Function to calculate the damage dealt by the Boss
    int damageDealt(int attack);
};

#endif // End of the include guard
