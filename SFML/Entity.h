#pragma once // Ensures the file is included only once during compilation
#include <iostream>
#include <string>

#ifndef ENTITY_H // Begin conditional inclusion to prevent multiple inclusions of the header file
#define ENTITY_H

// Entity class declaration
class Entity {
public:
    // Member variables
    std::string Name;       // Name of the entity
    std::string info;       // Information about the entity
    int health_point;       // Health points of the entity
    int skill_point;        // Skill points used to perform skills and ultimates
    int attack;             // Attack value that determines damage dealt to enemies
    int element;            // Element type of the entity
    int damage;             // Damage dealt by the entity

public:
    // Default constructor
    Entity();

    // Parameterized constructor to initialize the entity's attributes
    Entity(std::string Name, std::string info, int element, int health_point, int skill_point, int attack);

    // Getter functions
    int get_Health();          // Returns the health points of the entity
    int get_SkillPoint();      // Returns the skill points of the entity
    int get_Attack();          // Returns the attack value of the entity
    int get_Element();         // Returns the element type of the entity
    std::string get_name();    // Returns the name of the entity
    std::string get_info();    // Returns the information about the entity
    int get_damage();          // Returns the damage dealt by the entity

    // Setter functions
    void set_Name(const std::string& newName);         // Sets the name of the entity
    void set_info(const std::string& newInfo);         // Sets the information about the entity
    void set_health_point(int newHealthPoint);         // Sets the health points of the entity
    void set_skill_point(int newSkillPoint);           // Sets the skill points of the entity
    void set_attack(int newAttack);                    // Sets the attack value of the entity
    void set_element(int newElement);                  // Sets the element type of the entity

    // Virtual function to calculate damage dealt, can be overridden in derived classes
    virtual int damageDealt(int attack);
};

#endif // End conditional inclusion
