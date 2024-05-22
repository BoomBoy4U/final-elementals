#include "GameMenu.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"
#include "Boss.h"

// Constructor for GameMenu class
GameMenu::GameMenu(Player* player)
    : Gameplay(*new std::vector<Entity*>(), player), startOrExit(1), pass_stage1(0), pass_stage2(0), pass_stage3(0) {}

// Method to start the game
void GameMenu::start() {
    // Ask the player to enter their name
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << std::endl;

    // Open a file to write the player's name and game results
    std::ofstream outfile("game_result.txt");
    if (!outfile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    outfile << "Player Name: " << name << std::endl;

    // Loop to manage the game stages
    while (startOrExit != 0) {
        int stage;
        std::cout << "Choose the stage: ";
        std::cin >> stage;
        std::cout << std::endl;

        // Validate the chosen stage
        while (stage < 1 || stage > 3) {
            std::cout << "Invalid Option! Choose the stage 1, 2, or 3: ";
            std::cin >> stage;
            std::cout << std::endl;
        }

        // Play the selected stage
        playStage(stage);

        // Ask the player if they want to continue the game
        std::cout << "Do you want to continue the game? 1(Yes) or 0(No)?: ";
        std::cin >> startOrExit;

        // Validate the input for continuing the game
        while (startOrExit < 0 || startOrExit > 1) {
            std::cout << "Please click 1 or 0! 1(Yes) or 0(No)?: ";
            std::cin >> startOrExit;
        }

        // Unlock all stages once all stages are cleared
        if (pass_stage1 == 1 && pass_stage2 == 1 && pass_stage3 == 1) {
            pass_stage1 = 1;
            pass_stage2 = 1;
            pass_stage3 = 1;
        }
    }

    // Record the game results to the file
    recordResults();

    // Display the game results
    showResults();
}

// Method to play a specific stage
void GameMenu::playStage(int stage) {
    // Initialize the player with default state
    Player* player = new Player(name, "elementalless", 0, 0, 0, 0);

    // Set the player's state based on the selected stage
    if (stage == 1) {
        player->set_health_point(200);
        player->set_skill_point(40);
        player->set_attack(10);
    } else if (stage == 2) {
        player->set_health_point(800);
        player->set_skill_point(80);
        player->set_attack(20);
    } else if (stage == 3) {
        player->set_health_point(200);
        player->set_skill_point(140);
        player->set_attack(30);
    }

    // Create enemies for each stage
    Enemy* zodiak = new Enemy("Zodiak", "Fire", 1, 80, 10);
    Boss* Sage = new Boss("Sage", "Water", 2, 200, 10);
    Enemy* golem = new Enemy("Golem", "Earth", 3, 200, 10);
    Boss* dragon = new Boss("Dragon", "Fire", 1, 300, 20);

    // Vectors to store enemies for each stage
    std::vector<Entity*> Enemies1;
    std::vector<Entity*> Enemies2;
    std::vector<Entity*> Enemies3;

    // Gameplay instances for each stage
    Gameplay stage1(Enemies1, player);
    Gameplay stage2(Enemies2, player);
    Gameplay stage3(Enemies3, player);

    // Add enemies to each stage
    Enemies1.push_back(zodiak);
    Enemies2.push_back(zodiak);
    Enemies2.push_back(Sage);
    Enemies2.push_back(golem);
    Enemies3.push_back(zodiak);
    Enemies3.push_back(Sage);
    Enemies3.push_back(golem);
    Enemies3.push_back(dragon);

    // Play the selected stage and check access to locked stages
    if (stage == 1) {
        pass_stage1 = stage1.play(Enemies1, player);
    } else if (stage == 2 && pass_stage1 == 1) {
        pass_stage2 = stage2.play(Enemies2, player);
    } else if (stage == 3 && pass_stage2 == 1) {
        pass_stage3 = stage3.play(Enemies3, player);
    } else {
        std::cout << "Can't access the locked stage yet!" << std::endl;
    }

    // Clean up dynamically allocated memory
    delete player;
    delete zodiak;
    delete Sage;
    delete golem;
    delete dragon;
}

// Method to record the game results to a file
void GameMenu::recordResults() {
    std::ofstream outfile("game_result.txt", std::ios_base::app);
    if (!outfile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    outfile << "Passed Stages: ";
    if (pass_stage1 == 1) outfile << "1 ";
    if (pass_stage2 == 1) outfile << "2 ";
    if (pass_stage3 == 1) outfile << "3 ";
    outfile << std::endl;
    outfile.close();
}

// Method to display the game results from a file
void GameMenu::showResults() {
    std::ifstream infile("game_result.txt");
    if (!infile) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
    }
    infile.close();
}
