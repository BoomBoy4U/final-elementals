#include <iostream>
#include <string>
#include "Entity.h"

// Default constructor for Entity class
Entity::Entity() 
    : Name("NA"), info("NA"), element(0), health_point(0), skill_point(0), attack(0) {}

// Parameterized constructor for Entity class
Entity::Entity(std::string Name, std::string info, int element, int health_point, int skill_point, int attack) {
    this->Name = Name;                 // Initialize the entity's name
    this->info = info;                 // Initialize the entity's information
    this->element = element;           // Initialize the entity's element type
    this->health_point = health_point; // Initialize the entity's health points
    this->skill_point = skill_point;   // Initialize the entity's skill points
    this->attack = attack;             // Initialize the entity's attack points
}

// Function to get the health points of the entity
int Entity::get_Health() {
    return this->health_point; // Return health value
}

// Function to get the skill points of the entity
int Entity::get_SkillPoint() {
    return this->skill_point; // Return skill point value
}

// Function to get the attack points of the entity
int Entity::get_Attack() {
    return this->attack; // Return attack value
}

// Function to get the element type of the entity
int Entity::get_Element() {
    return this->element; // Return element type
}

// Function to get the name of the entity
std::string Entity::get_name() {
    return this->Name; // Return name of the entity
}

// Function to get the information of the entity
std::string Entity::get_info() {
    return this->info; // Return information of the entity
}

// Function to get the damage value of the entity
int Entity::get_damage() {
    return this->damage; // Return damage value
}

// Function to set the name of the entity
void Entity::set_Name(const std::string& newName) {
    Name = newName; // Set new name
}

// Function to set the information of the entity
void Entity::set_info(const std::string& newInfo) {
    info = newInfo; // Set new information
}

// Function to set the health points of the entity
void Entity::set_health_point(int newHealthPoint) {
    health_point = newHealthPoint; // Set new health points
}

// Function to set the skill points of the entity
void Entity::set_skill_point(int newSkillPoint) {
    skill_point = newSkillPoint; // Set new skill points
}

// Function to set the attack points of the entity
void Entity::set_attack(int newAttack) {
    attack = newAttack; // Set new attack points
}

// Function to set the element type of the entity
void Entity::set_element(int newElement) {
    element = newElement; // Set new element type
}

// Virtual function to calculate damage dealt, can be overridden in derived classes
int Entity::damageDealt(int attack) {
    return 0; // Default implementation returns 0
}
