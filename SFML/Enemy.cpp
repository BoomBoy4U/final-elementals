#include <iostream>
#include <string>
#include "Enemy.h"
#include "Entity.h"

// Default constructor for Enemy class, calling the base class Entity constructor
Enemy::Enemy() : Entity() {}

// Parameterized constructor for Enemy class
Enemy::Enemy(std::string Name, std::string info, int element, int health_point, int attack) {
    this->Name = Name;             // Initialize the enemy's name
    this->info = info;             // Initialize the enemy's information
    this->element = element;       // Initialize the enemy's element type
    this->health_point = health_point; // Initialize the enemy's health points
    this->attack = attack;         // Initialize the enemy's attack points
}

// Function to calculate damage dealt by the enemy
int Enemy::damageDealt(int attack) {
    damage = attack;               // Set damage to the given attack value
    return damage;                 // Return the calculated damage
}

// Function to set the texture for the enemy's sprite
void Enemy::setTexture(const sf::Texture& texture) {
    this->texture = texture;       // Assign the given texture to the enemy's texture
    this->sprite.setTexture(this->texture); // Set the texture to the enemy's sprite
}

// Function to get the sprite of the enemy
const sf::Sprite& Enemy::getSprite() const {
    return this->sprite;           // Return the enemy's sprite
}

// Function to get the health points of the enemy
int Enemy::get_Health() {
    return this->health_point;     // Return the enemy's health points
}
