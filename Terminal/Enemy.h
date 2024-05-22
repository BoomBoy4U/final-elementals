#pragma once  // Ensure the file is included only once during compilation
#include <iostream>  // Include standard input-output stream library
#include <string>    // Include the string library for string manipulation
#include "Entity.h"  // Include the header file for the Entity class

#ifndef ENEMY_H      // Begin the include guard to prevent multiple inclusions
#define ENEMY_H

// Enemy class definition, inheriting from the Entity class
class Enemy : public Entity {
public:
    // Default constructor
    Enemy();

    // Parameterized constructor
    Enemy(std::string Name, std::string info, int element, int health_point, int attack);

    // Function to calculate the damage dealt by the Enemy
    int damageDealt(int attack);
};

#endif // End of the include guard
