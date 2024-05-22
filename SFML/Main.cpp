#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"
#include "Boss.h"
#include <vector>

// Entry point of the program
int main() {
    // Create a Player object dynamically
    Player* player = new Player("user", "1st_player", 3, 150, 50, 5);
    
    // Create an Enemy object dynamically
    Enemy* enemy = new Enemy();

    // Initialize random seed
    std::srand(static_cast<unsigned>(time(NULL)));

    // Initialize Game engine with the player and enemy
    Game game(player, enemy);

    // Game loop
    while (game.running() && !game.getEndGame()) {
        // Update the game state
        game.update();

        // Render the game
        game.render();
    }    

    // End of application
    // Clean up dynamically allocated memory
    delete player;
    delete enemy;

    return 0;
}
