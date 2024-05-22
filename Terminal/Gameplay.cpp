#include "Gameplay.h"

// Constructor for Gameplay class
// Initializes the enemies vector and the player object
Gameplay::Gameplay(std::vector<Entity*>& _enemies, Player* player) : enemies(_enemies) {
    player = new Player[1];
    player = player;
}

// Get the current stage
int Gameplay::get_stage() {
    return stage;
}

// Set the current stage
void Gameplay::set_stage(int _stage) {
    stage = _stage;
}

// Method to play the game stage
int Gameplay::play(std::vector<Entity*>& enemies, Player* player) {
    // Count the number of enemies
    int count = std::distance(enemies.begin(), enemies.end());
    std::cout << "Enemies count: " << count << std::endl;

    // Main game loop
    while (!enemies.empty() && player->get_Health() > 0) {
        if (!enemies.empty()) {
            Entity* currentEnemy = enemies.back(); // Get the current enemy
            std::cout << "Current Enemy: " << currentEnemy->get_name() << std::endl;
            std::cout << std::endl;

            std::cout << player->get_name() << ":" << std::endl;
            std::cout << player->get_Health() << " || " << player->get_SkillPoint() << std::endl;
            std::cout << std::endl;
            std::cout << currentEnemy->get_name() << ":" << std::endl;
            std::cout << currentEnemy->get_Health() << " || " << currentEnemy->get_SkillPoint() << std::endl;
            std::cout << std::endl;

            // Player actions
            int choice;
            std::cout << "1. Dodge\n2. Element Skill\n3. Ultimate Skill\n" << std::endl;
            std::cout << "Choose your action: ";
            std::cin >> choice;
            std::cout << std::endl;

            // Validate skill point for skill usage
            while (player->get_SkillPoint() <= 0 && choice == 2) {
                std::cout << "No SP! Choose your action again either 1 or 3:" << std::endl;
                std::cout << "1. Dodge\n2. Element Skill\n3. Ultimate Skill\n" << std::endl;
                std::cin >> choice;
            }

            // Validate choice input
            while (choice < 1 || choice > 3) {
                std::cout << "Invalid Option! Choose your action again:" << std::endl;
                std::cout << "1. Dodge\n2. Element Skill\n3. Ultimate Skill\n" << std::endl;
                std::cin >> choice;

                while (player->get_SkillPoint() <= 0 && choice == 2) {
                    std::cout << "No SP! Choose your action again either 1 or 3:" << std::endl;
                    std::cout << "1. Dodge\n2. Element Skill\n3. Ultimate Skill\n" << std::endl;
                    std::cin >> choice;
                }
            }

            // Perform actions based on choice
            if (choice == 2) {
                // Element-based damage calculation
                if (player->get_Element() == 1 && currentEnemy->get_Element() == 3) {
                    player->damageDealt(player->get_Attack(), choice);
                    currentEnemy->set_health_point(currentEnemy->get_Health() - 2 * player->get_damage());
                    std::cout << player->get_name() << " has used fire element" << " and dealt " << player->get_damage() << std::endl;
                } else if (player->get_Element() == 2 && currentEnemy->get_Element() == 1) {
                    player->damageDealt(player->get_Attack(), choice);
                    currentEnemy->set_health_point(currentEnemy->get_Health() - 2 * player->get_damage());
                    std::cout << player->get_name() << " has used water element" << " and dealt " << 2 * player->get_damage() << std::endl;
                } else if (player->get_Element() == 3 && currentEnemy->get_Element() == 2) {
                    player->damageDealt(player->get_Attack(), choice);
                    currentEnemy->set_health_point(currentEnemy->get_Health() - 2 * player->get_damage());
                    std::cout << player->get_name() << " has used earth element" << " and dealt " << 2 * player->get_damage() << std::endl;
                } else {
                    player->damageDealt(player->get_Attack(), choice);
                    currentEnemy->set_health_point(currentEnemy->get_Health() - player->get_damage());
                    std::cout << player->get_name() << " has used wrong element against enemy" << " and dealt " << player->get_damage() << std::endl;
                }
            } else if (choice == 1) {
                player->damageDealt(player->get_Attack(), choice);
                std::cout << player->get_name() << " Use Dodge" << std::endl;
            } else if (choice == 3) {
                player->damageDealt(player->get_Attack(), choice);
                currentEnemy->set_health_point(currentEnemy->get_Health() - player->get_damage());
                std::cout << player->get_name() << " has dealt " << player->get_damage() << std::endl;
            }

            // Check if enemy is defeated
            if (currentEnemy->get_Health() <= 0) {
                std::cout << currentEnemy->get_name() << " defeated!" << std::endl;
                std::cout << std::endl;
                enemies.pop_back(); // Remove defeated enemy from vector
            } else if (currentEnemy->get_Health() > 0 && !player->get_dodge()) {
                player->set_health_point(player->get_Health() - currentEnemy->damageDealt(currentEnemy->get_Attack()));
                std::cout << currentEnemy->get_name() << " has dealt " << currentEnemy->get_damage() << std::endl;
            } else if (currentEnemy->get_Health() > 0 && player->get_dodge()) {
                currentEnemy->damageDealt(currentEnemy->get_Attack());
                std::cout << currentEnemy->get_name() << " has dealt " << currentEnemy->get_damage() << " However, " << player->get_name() << " dodged the attack." << std::endl;
                player->set_dodge(false); // Reset dodge state
            }
        }
    }

    // Check game over condition
    if (player->get_Health() <= 0) {
        std::cout << "Game Over! You have been defeated." << std::endl;
        return stage = 0;
    }

    // Check stage pass condition
    if (player->get_Health() > 0 && enemies.empty()) {
        std::cout << "Congratulations! You have passed the stage and defeated all enemies including the boss." << std::endl;
        return stage = 1;
    }

    // Clean up memory
    for (auto entity : enemies) {
        delete entity;
    }
}
