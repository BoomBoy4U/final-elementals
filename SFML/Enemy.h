#pragma once // Ensures the file is included only once during compilation
#include <iostream>
#include <string>
#include "Entity.h"
#include <SFML/Graphics.hpp> // Include SFML graphics library for texture and sprite handling

#ifndef ENEMY_H // Begin conditional inclusion to prevent multiple inclusions of the header file
#define ENEMY_H

// Enemy class declaration inheriting from Entity class
class Enemy : public Entity {
public:
    // Default constructor
    Enemy();

    // Parameterized constructor to initialize the enemy's attributes
    Enemy(std::string Name, std::string info, int element, int health_point, int attack);

    // Function to calculate the damage dealt by the enemy
    int damageDealt(int attack);

    // Function to set the texture for the enemy's sprite
    void setTexture(const sf::Texture& texture);

    // Function to get the sprite of the enemy
    const sf::Sprite& getSprite() const;

    // Function to get the health points of the enemy
    int get_Health();
    
private:
    sf::Texture texture; // Texture for the enemy's sprite
    sf::Sprite sprite;   // Sprite representing the enemy
};

#endif // End conditional inclusion
