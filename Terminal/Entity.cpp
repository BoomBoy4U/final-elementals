#include <iostream>  // Include the standard input-output stream library
#include <string>    // Include the string library for string manipulation
#include "Entity.h"  // Include the header file for the Entity class

// Default constructor for the Entity class
Entity::Entity() : Name("NA"), info("NA"), element(0), health_point(0), skill_point(0), attack(0) {}

// Parameterized constructor for the Entity class
// Initializes the Entity object with the given parameters
Entity::Entity(std::string Name, std::string info, int element, int health_point, int skill_point, int attack) {
    this->Name = Name;                // Set the name of the Entity
    this->info = info;                // Set additional info about the Entity
    this->element = element;          // Set the element type of the Entity
    this->health_point = health_point; // Set the health points of the Entity
    this->skill_point = skill_point;  // Set the skill points of the Entity
    this->attack = attack;            // Set the attack value of the Entity
}

// Getter for health points
int Entity::get_Health() { 
    return health_point;  // Return the health points of the Entity
}

// Getter for skill points
int Entity::get_SkillPoint() { 
    return skill_point;  // Return the skill points of the Entity
}

// Getter for attack value
int Entity::get_Attack() { 
    return attack;  // Return the attack value of the Entity
}

// Getter for element type
int Entity::get_Element() { 
    return element;  // Return the element type of the Entity
}

// Getter for name
std::string Entity::get_name() { 
    return Name;  // Return the name of the Entity
}

// Getter for info
std::string Entity::get_info() { 
    return info;  // Return the additional info of the Entity
}

// Getter for damage
int Entity::get_damage() { 
    return damage;  // Return the damage value of the Entity
}

// Setter for name
void Entity::set_Name(const std::string& newName) {
    Name = newName;  // Set a new name for the Entity
}

// Setter for info
void Entity::set_info(const std::string& newInfo) {
    info = newInfo;  // Set new additional info for the Entity
}

// Setter for health points
void Entity::set_health_point(int newHealthPoint) {
    health_point = newHealthPoint;  // Set new health points for the Entity
}

// Setter for skill points
void Entity::set_skill_point(int newSkillPoint) {
    skill_point = newSkillPoint;  // Set new skill points for the Entity
}

// Setter for attack value
void Entity::set_attack(int newAttack) {
    attack = newAttack;  // Set a new attack value for the Entity
}

// Setter for element type
void Entity::set_element(int newElement) {
    element = newElement;  // Set a new element type for the Entity
}

// Virtual function to calculate the damage dealt by the Entity
// This function can be overridden by derived classes
int Entity::damageDealt(int attack) {
    return 0;  // Return a default value of 0 for the damage dealt
}
