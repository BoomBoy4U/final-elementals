#pragma once  // Ensure the file is included only once during compilation
#include <iostream>  // Include standard input-output stream library
#include <string>    // Include the string library for string manipulation

#ifndef ENTITY_H      // Begin the include guard to prevent multiple inclusions
#define ENTITY_H

// Entity class definition
class Entity {
protected:
    std::string Name;         // Name of the entity
    std::string info;         // Additional info about the entity
    int health_point;         // Health points of the entity
    int skill_point;          // Skill points to use skills and ultimate
    int attack;               // Attack value that deals damage to the enemy
    int element;              // Element type of the entity
    int damage;               // Damage value

public:
    // Default constructor
    Entity();

    // Parameterized constructor
    Entity(std::string Name, std::string info, int element, int health_point, int skill_point, int attack);

    // Getter for health points
    int get_Health();

    // Getter for skill points
    int get_SkillPoint();

    // Getter for attack value
    int get_Attack();

    // Getter for element type
    int get_Element();

    // Getter for name
    std::string get_name();

    // Getter for info
    std::string get_info();

    // Getter for damage
    int get_damage();

    // Setter for name
    void set_Name(const std::string& newName);

    // Setter for info
    void set_info(const std::string& newInfo);

    // Setter for health points
    void set_health_point(int newHealthPoint);

    // Setter for skill points
    void set_skill_point(int newSkillPoint);

    // Setter for attack value
    void set_attack(int newAttack);

    // Setter for element type
    void set_element(int newElement);

    // Virtual function to calculate the damage dealt by the entity
    virtual int damageDealt(int attack);
};

#endif // End of the include guard
