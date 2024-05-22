#include "Game.h"
#include <fstream> // For file handling
#include <iostream> // For console output

// Private functions

// Initialize game variables
void Game::initVariables() {
    this->window = nullptr;

    // Game logic
    this->endGame = false;
    this->mouseHeld = false;
    this->mouseHeld2 = false;
    this->playerHP = 0;
    this->playerSP = 0;
    this->enemyHP = 0;
    this->currentLevel = 1; // Start at level 1

    this->maxButtons = 3;
    this->gameState = MAIN_MENU;
    this->gameStarted = false;
    this->playerName = ""; // Initialize player name 

    this->enemyDefeated = false; // Initialize the enemyDefeated flag
    this->playerDefeated = false; // Initialize the playerDefeated flag
    this->readPlayerHealthFromFile(); // Read player's health from file
}

// Initialize the game window
void Game::initWindow() {
    this->videoMode.height = 1000;
    this->videoMode.width = 1000;

    this->window = new sf::RenderWindow(this->videoMode, "Game 1", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(30);
}

// Load and initialize fonts
void Game::initFonts() {
    if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")) {
        std::cerr << "ERROR::GAME::INITFONTS::Failed to load font!" << std::endl;
    }
}

// Initialize text elements
void Game::initText() {
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(36);
    this->uiText.setFillColor(sf::Color::Green);
    this->uiText.setString("Game has not started!");

    this->uiText2.setFont(this->font);
    this->uiText2.setCharacterSize(36);
    this->uiText2.setFillColor(sf::Color::Green);
    this->uiText2.setString("Game has not started!");

    this->uiText3.setFont(this->font);
    this->uiText3.setPosition(400.f, 950.f);
    this->uiText3.setCharacterSize(20);
    this->uiText3.setFillColor(sf::Color::Green);
    this->uiText3.setString("Game is on");

    this->namePromptText.setFont(this->font);
    this->namePromptText.setCharacterSize(24);
    this->namePromptText.setFillColor(sf::Color::White);
    this->namePromptText.setString("Enter your name:");
    this->namePromptText.setPosition(this->videoMode.width / 2.f - 100.f, this->videoMode.height / 2.f - 50.f);

    this->playerNameText.setFont(this->font);
    this->playerNameText.setCharacterSize(24);
    this->playerNameText.setFillColor(sf::Color::White);
    this->playerNameText.setPosition(this->videoMode.width / 2.f - 100.f, this->videoMode.height / 2.f);

    this->playerNameDisplayText.setFont(this->font);
    this->playerNameDisplayText.setCharacterSize(24);
    this->playerNameDisplayText.setFillColor(sf::Color::White);

    // Initialize game over rectangle
    this->gameOverRect.setSize(sf::Vector2f(800.f, 200.f));
    this->gameOverRect.setFillColor(sf::Color::Red);
    this->gameOverRect.setPosition(this->videoMode.width / 2.f - this->gameOverRect.getSize().x / 2.f, this->videoMode.height / 2.f - this->gameOverRect.getSize().y / 2.f);

    // Initialize game over text
    this->gameOverText.setFont(this->font);
    this->gameOverText.setCharacterSize(50);
    this->gameOverText.setFillColor(sf::Color::White);
    this->gameOverText.setString("The game is finished.");
    this->gameOverText.setPosition(this->videoMode.width / 2.f - this->gameOverText.getGlobalBounds().width / 2.f, this->videoMode.height / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);
}

// Load and initialize images
void Game::initImages() {
    if (!textureP.loadFromFile("PNGS/player.png")) {
        std::cerr << "ERROR::GAME::INITIMAGES::Failed to load player image!" << std::endl;
    }

    spriteP.setTexture(textureP);
    spriteP.setPosition(100.f, 200.f);
    spriteP.scale(1.5f, 1.5f);

    std::cout << "Images loaded successfully!" << std::endl;
}

// Load textures for enemies and bosses
void Game::loadTextures() {
    sf::Texture texture;

    // Load textures for enemies
    if (!texture.loadFromFile("PNGS/enemy1.png")) {
        std::cerr << "ERROR::GAME::LOADTEXTURES::Failed to load enemy1.png" << std::endl;
    }
    enemyTextures.push_back(texture);

    if (!texture.loadFromFile("PNGS/enemy2.png")) {
        std::cerr << "ERROR::GAME::LOADTEXTURES::Failed to load enemy2.png" << std::endl;
    }
    enemyTextures.push_back(texture);

    if (!texture.loadFromFile("PNGS/enemy3.png")) {
        std::cerr << "ERROR::GAME::LOADTEXTURES::Failed to load enemy3.png" << std::endl;
    }
    enemyTextures.push_back(texture);

    // Load textures for bosses
    if (!texture.loadFromFile("PNGS/boss1.png")) {
        std::cerr << "ERROR::GAME::LOADTEXTURES::Failed to load boss1.png" << std::endl;
    }
    bossTextures.push_back(texture);

    if (!texture.loadFromFile("PNGS/boss2.png")) {
        std::cerr << "ERROR::GAME::LOADTEXTURES::Failed to load boss2.png" << std::endl;
    }
    bossTextures.push_back(texture);

    if (!texture.loadFromFile("PNGS/boss3.png")) {
        std::cerr << "ERROR::GAME::LOADTEXTURES::Failed to load boss3.png" << std::endl;
    }
    bossTextures.push_back(texture);

    if (!texture.loadFromFile("PNGS/boss4.png")) {
        std::cerr << "ERROR::GAME::LOADTEXTURES::Failed to load boss4.png" << std::endl;
    }
    bossTextures.push_back(texture);
}

// Initialize the button
void Game::initButton() {
    this->button.setPosition(150.f, 150.f);
    this->button.setRadius(10.f);
    this->button.setFillColor(sf::Color::Yellow);
    this->button.setOutlineColor(sf::Color::Red);
    this->button.setOutlineThickness(5.f);
}

// Initialize the start button
void Game::initStartButton() {
    this->startButton.setSize(sf::Vector2f(600.f, 300.f));
    this->startButton.setFillColor(sf::Color::Green);
    this->startButton.setPosition(this->videoMode.width / 2.f - this->startButton.getSize().x / 2.f, this->videoMode.height / 2.f);

    this->startButtonText.setFont(this->font);
    this->startButtonText.setCharacterSize(50);
    this->startButtonText.setFillColor(sf::Color::Black);
    this->startButtonText.setString("Press the green box \n to start game");
    this->startButtonText.setPosition(this->startButton.getPosition().x + 20.f, this->startButton.getPosition().y + 10.f);
}

// Initialize enemies (currently empty, to be implemented)
void Game::initEnemies() {
}

// Initialize sprites for enemies and bosses
void Game::initSprites() {
    sf::Sprite sprite;

    // Initialize enemy sprites
    for (const auto& texture : enemyTextures) {
        sprite.setTexture(texture);
        sprite.setPosition(800.f, 100.f * enemySprites.size()); // Position along the y-axis
        enemySprites.push_back(sprite);
    }

    // Initialize boss sprites
    for (const auto& texture : bossTextures) {
        sprite.setTexture(texture);
        sprite.setPosition(800.f, 400.f + 100.f * bossSprites.size()); // Position along the y-axis
        bossSprites.push_back(sprite);
    }
}

// Constructor
Game::Game(Player* player, Enemy* enemy2) {
    this->player = player;
    this->enemy2 = enemy2;
    this->initVariables();
    this->initWindow();
    this->initFonts();
    this->initText();
    this->initEnemies();
    this->initButton();
    this->initImages();
    this->loadTextures();
    this->initSprites();
    this->initStartButton();

    std::cout << "Current Enemy: " << enemy2->get_name() << std::endl;
    std::cout << std::endl;

    std::cout << player->get_name() << ":" << std::endl;
    std::cout << player->get_Health() << " || " << player->get_SkillPoint() << std::endl;
    std::cout << std::endl;
    std::cout << enemy2->get_name() << ":" << std::endl;
    std::cout << enemy2->get_Health() << " || " << enemy2->get_SkillPoint() << std::endl;
    std::cout << std::endl;
}

// Destructor
Game::~Game() {
    delete this->window;
    for (auto& enemy : this->enemies) {
        delete enemy;
    }
}

// Check if the game is running
const bool Game::running() const {
    return this->window->isOpen();
}

// Check if the game has ended
const bool Game::getEndGame() const {
    return this->endGame;
}

// Functions

// Spawn buttons on the screen
void Game::spawnButtons() {
    for (int i = 0; i < maxButtons; i++) {
        this->button.setRadius(70.f);
        this->button.setFillColor(sf::Color::Green);
        this->button.setPosition(sf::Vector2f(static_cast<float>(200 * i + 100), 700.f));
        this->buttons.push_back(this->button);

        switch (i) {
        case 0:
            this->uiText.setString("DODGE");
            this->uiText.setPosition(static_cast<float>(200 * i + 120), 850.f);
            this->uiTexts.push_back(uiText);
            break;

        case 1:
            this->uiText.setString("ELEMENT");
            this->uiText.setPosition(static_cast<float>(200 * i + 120), 850.f);
            this->uiTexts.push_back(uiText);
            break;

        case 2:
            this->uiText.setString("ULTIMATE");
            this->uiText.setPosition(static_cast<float>(200 * i + 120), 850.f);
            this->uiTexts.push_back(uiText);
            break;

        default:
            std::cerr << "ERROR::GAME::SPAWNBUTTONS::Invalid button index" << std::endl;
            break;
        }
    }
}

// Handle poll events
void Game::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
        case sf::Event::Closed:
            this->window->close();
            break;

        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;

        case sf::Event::MouseButtonPressed:
            if (this->ev.mouseButton.button == sf::Mouse::Left) {
                if (this->gameState == MAIN_MENU) {
                    if (this->startButton.getGlobalBounds().contains(this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)))) {
                        this->handleStartButtonClick();
                    }
                }
            }
            break;

        case sf::Event::TextEntered:
            if (this->gameState == NAME_INPUT) {
                this->handleTextInput(this->ev);
            }
            break;
        }
    }
}

// Handle start button click
void Game::handleStartButtonClick() {
    this->gameState = NAME_INPUT;
}

// Handle text input for player's name
void Game::handleTextInput(sf::Event event) {
    if (event.text.unicode == '\b') {
        // Handle backspace
        if (!this->playerName.empty()) {
            this->playerName.pop_back();
        }
    } else if (event.text.unicode == '\r') {
        // Handle enter key
        this->gameState = GAMEPLAY;
        this->uiText.setPosition(1.f, 950.f);
        this->uiText.setCharacterSize(20);
        this->uiText.setFillColor(sf::Color::White);
        this->uiText.setString("OOP20024 GROUP4");
        this->player->set_Name(this->playerName); // Set the player name
        this->playerNameDisplayText.setString("PLAYER: " + this->playerName); // Set the display text with "PLAYER:"

        // Center the player name at the top of the screen
        sf::FloatRect textRect = this->playerNameDisplayText.getLocalBounds();
        this->playerNameDisplayText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        this->playerNameDisplayText.setPosition(sf::Vector2f(this->videoMode.width / 2.0f, textRect.height));

        // Load the first level
        this->loadLevel1();
    } else {
        // Handle regular text input
        this->playerName += static_cast<char>(event.text.unicode);
    }
    this->playerNameText.setString(this->playerName);
}

// Update mouse positions
void Game::updateMousePositions() {
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

// Update enemies
void Game::updateEnemies() {
    // Remove defeated enemies from the list
    for (size_t i = 0; i < enemies.size();) {
        if (enemies[i]->get_Health() <= 0) {
            std::cout << "Enemy no:" << i + 1 << " defeated: " << enemies[i]->get_name() << std::endl;
            delete enemies[i];
            enemies.erase(enemies.begin() + i);
        } else {
            ++i;
        }
    }

    // Check for level completion
    if (currentLevel == 1 && enemies.empty() && this->gameState == GAMEPLAY) {
        std::cout << "Level 1 complete" << std::endl;
        std::stringstream ss;
        ss << "Last result update: Congratulations! You have passed the current stage\n"
           << "and defeated all enemies!\n";

        this->uiText3.setString(ss.str());
        this->uiText3.setPosition(400.f, 950.f);
        this->uiText3.setCharacterSize(20);

        this->currentLevel = 2; // Move to the next level
        this->loadLevel2();
    } else if (currentLevel == 2 && enemies.empty() && this->gameState == GAMEPLAY) {
        std::cout << "Level 2 complete" << std::endl;
        std::stringstream ss;
        ss << "Last result update: Congratulations! You have passed the current stage\n"
           << "and defeated all enemies!\n";

        this->uiText3.setString(ss.str());
        this->uiText3.setPosition(400.f, 950.f);
        this->uiText3.setCharacterSize(20);

        this->currentLevel = 3; // Move to the next level
        this->loadLevel3();
    } else if (currentLevel == 3 && enemies.empty() && this->gameState == GAMEPLAY) {
        std::cout << "Level 3 complete" << std::endl;
        std::stringstream ss;
        ss << "Last result update: Congratulations! You have passed all levels\n"
           << "and defeated all enemies!\n";

        this->uiText3.setString(ss.str());
        this->uiText3.setPosition(400.f, 950.f);
        this->uiText3.setCharacterSize(20);

        // Set end game flag
        this->endGame = true;
        this->writeGameSummary(); // Write game summary when game ends
    }
}

// Update buttons
void Game::updateButtons() {
    // Updating the timer for enemy spawning
    if (this->buttons.size() < this->maxButtons) {
        // Spawn the enemy and reset the timer
        this->spawnButtons();
    }

    // Check if clicked upon
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->mouseHeld2 == false) {
            this->mouseHeld2 = true;
            for (size_t i = 0; i < this->buttons.size(); i++) {
                if (this->buttons[i].getGlobalBounds().contains(this->mousePosView)) {
                    if (!enemies.empty() && enemies[0]->get_Health() > 0 && player->get_Health() > 0) {
                        auto currentEnemy = enemies[0];

                        // Handle button actions
                        switch (i) {
                        case 0: // Dodge button
                            if (currentLevel == 1) {
                                std::cout << "Dodge not permitted in level 1" << std::endl;
                                std::stringstream ss;
                                ss << "Dodge not available in level 1\n";
                                this->uiText2.setString(ss.str());
                            } else {
                                player->damageDealt(player->get_Attack(), 1);
                                std::cout << player->get_name() << " uses dodge." << std::endl;
                                if (currentEnemy->get_Health() > 0 && !player->get_dodge()) {
                                    player->set_health_point(player->get_Health() - currentEnemy->damageDealt(currentEnemy->get_Attack()));
                                    std::cout << currentEnemy->get_name() << " deals " << currentEnemy->get_damage() << std::endl;
                                }
                                if (currentEnemy->get_Health() > 0 && player->get_dodge()) {
                                    currentEnemy->damageDealt(currentEnemy->get_Attack());
                                    std::cout << currentEnemy->get_name() << " deals " << currentEnemy->get_damage() << " However, " << player->get_name() << " dodges the attack." << std::endl;
                                    player->set_dodge(false); // Revert dodge state
                                }
                                std::stringstream ss;
                                ss << "Current Level: " << currentLevel << "\n"
                                   << "Player HP: " << player->get_Health() << "\n"
                                   << "Player SP: " << player->get_SkillPoint() << "\n"
                                   << "Enemy HP: " << currentEnemy->get_Health() << "\n";
                                this->uiText2.setString(ss.str());
                            }
                            break;

                        case 1: // Element button
                            if (player->get_SkillPoint() <= 0) {
                                break;
                            } else {
                                int damageMultiplier = 1;
                                if ((player->get_Element() == 1 && currentEnemy->get_Element() == 3) ||
                                    (player->get_Element() == 2 && currentEnemy->get_Element() == 1) ||
                                    (player->get_Element() == 3 && currentEnemy->get_Element() == 2)) {
                                    damageMultiplier = 2;
                                }
                                player->damageDealt(player->get_Attack(), 2);
                                currentEnemy->set_health_point(currentEnemy->get_Health() - damageMultiplier * player->get_damage());
                                std::cout << player->get_name() << " uses element and deals " << damageMultiplier * player->get_damage() << std::endl;

                                std::stringstream ss;
                                ss << "Current Level: " << currentLevel << "\n"
                                   << "Player HP: " << player->get_Health() << "\n"
                                   << "Player SP: " << player->get_SkillPoint() << "\n"
                                   << "Enemy HP: " << currentEnemy->get_Health() << "\n";
                                this->uiText2.setString(ss.str());
                            }
                            break;

                        case 2: // Ultimate button
                            this->points += 0;
                            player->damageDealt(player->get_Attack(), 3);
                            currentEnemy->set_health_point(currentEnemy->get_Health() - player->get_damage());
                            std::cout << player->get_name() << " deals " << player->get_damage() << std::endl;

                            std::stringstream ss;
                            ss << "Current Level: " << currentLevel << "\n"
                               << "Player HP: " << player->get_Health() << "\n"
                               << "Player SP: " << player->get_SkillPoint() << "\n"
                               << "Enemy HP: " << currentEnemy->get_Health() << "\n";
                            this->uiText2.setString(ss.str());
                            break;

                        default:
                            std::cerr << "ERROR::GAME::UPDATEBUTTONS::Invalid button index" << std::endl;
                            break;
                        }

                        // Check if the enemy is defeated
                        if (currentEnemy->get_Health() <= 0) {
                            std::cout << currentEnemy->get_name() << " defeated!" << std::endl;
                            std::stringstream ss;
                            ss << "Last result update: ENEMY IS DEAD! WELL DONE!\n";
                            this->uiText3.setString(ss.str());
                            this->uiText3.setPosition(400.f, 950.f);
                            this->uiText3.setCharacterSize(20);

                            this->enemyDefeated = true; // Set the enemyDefeated flag
                        }

                        // Check if the player is defeated
                        if (player->get_Health() <= 0) {
                            std::cout << "Game Over! You have been defeated." << std::endl;
                            std::stringstream ss;
                            ss << "Last result update: Game Over! You have been defeated.\n";
                            this->uiText3.setString(ss.str());
                            this->uiText3.setPosition(400.f, 950.f);
                            this->uiText3.setCharacterSize(20);

                            this->playerDefeated = true; // Set the playerDefeated flag
                        }
                    }
                }
            }
        } else {
            this->mouseHeld2 = false;
        }
    }
}

// Update game logic
void Game::update() {
    this->pollEvents();

    if (!this->endGame) {
        this->updateMousePositions();
        this->updateEnemies(); // Ensure enemies are updated and checked for defeat
        this->updateButtons();
    }

    // Check if the player's health is 0 or less to end the game
    if (this->player->get_Health() <= 0) {
        std::cout << "Game Over! You have been defeated." << std::endl;
        std::stringstream ss;
        ss << "Last result update: Game Over! You have been defeated.\n";
        this->uiText3.setString(ss.str());
        this->uiText3.setPosition(400.f, 950.f);
        this->uiText3.setCharacterSize(20);

        this->playerDefeated = true; // Set player defeated flag
        this->endGame = true;
        this->writeGameSummary(); // Write game summary when game ends
    }
}

// Render text on the screen
void Game::renderText(sf::RenderTarget& target) {
    target.draw(this->uiText);
    for (const auto& text : this->uiTexts) {
        target.draw(text);
    }
    target.draw(this->uiText3);
    target.draw(this->uiText2);
}

// Draw images (sprites) on the screen
void Game::drawImages(sf::RenderTarget& target) {
    if (!playerDefeated) { // Draw player only if not defeated
        target.draw(spriteP);
    }
    this->renderEnemies(target);
}

// Render enemies on the screen
void Game::renderEnemies(sf::RenderTarget& target) {
    for (size_t i = 0; i < this->enemies.size(); ++i) {
        if (this->enemies[i]->get_Health() > 0) {
            if (dynamic_cast<Boss*>(this->enemies[i])) {
                target.draw(this->bossSprites[i]);
            } else {
                target.draw(this->enemySprites[i]);
            }
        }
    }
}

// Render buttons on the screen
void Game::renderButtons(sf::RenderTarget& target) {
    for (const auto& button : this->buttons) {
        target.draw(button);
    }
}

// Render the game
void Game::render() {
    this->window->clear();

    if (this->gameState == MAIN_MENU) {
        this->window->draw(this->startButton);
        this->window->draw(this->startButtonText);
    } else if (this->gameState == NAME_INPUT) {
        this->window->draw(this->namePromptText);
        this->window->draw(this->playerNameText);
    } else if (this->gameState == GAMEPLAY) {
        this->window->draw(this->playerNameDisplayText); // Render the player's name at the top center
        this->drawImages(*this->window);
        this->renderText(*this->window);
        this->renderButtons(*this->window);
    }

    if (this->endGame) {
        this->window->draw(this->gameOverText);
    }

    this->window->display();
}

// Load level 1 enemies
void Game::loadLevel1() {
    // Clear existing enemies
    for (auto& enemy : this->enemies) {
        delete enemy;
    }
    this->enemies.clear();
    this->enemySprites.clear();
    this->bossSprites.clear();

    // Add enemies for level 1
    Enemy* enemy = new Enemy("enemy1", "element", 3, 100, 10);
    enemy->setTexture(enemyTextures[0]);
    this->enemies.push_back(enemy);
    this->enemySprites.push_back(enemySprites[0]);
}

// Load level 2 enemies
void Game::loadLevel2() {
    // Clear existing enemies
    for (auto& enemy : this->enemies) {
        delete enemy;
    }
    this->enemies.clear();
    this->enemySprites.clear();
    this->bossSprites.clear();

    // Add enemies for level 2
    Enemy* enemy = new Enemy("enemy2", "element", 4, 150, 15);
    enemy->setTexture(enemyTextures[1]);
    Boss* boss = new Boss("boss2", "ice", 6, 300, 30);
    boss->setTexture(bossTextures[1]);
    this->enemies.push_back(enemy);
    this->enemies.push_back(boss);
    this->enemySprites.push_back(enemySprites[1]);
    this->bossSprites.push_back(bossSprites[0]);
}

// Load level 3 enemies
void Game::loadLevel3() {
    // Clear existing enemies
    for (auto& enemy : this->enemies) {
        delete enemy;
    }
    this->enemies.clear();
    this->enemySprites.clear();
    this->bossSprites.clear();

    // Add enemies for level 3
    Enemy* enemy = new Enemy("enemy3", "element", 5, 200, 20);
    enemy->setTexture(enemyTextures[2]);
    Boss* boss1 = new Boss("boss3", "earth", 7, 400, 40);
    boss1->setTexture(bossTextures[2]);
    Boss* boss2 = new Boss("boss4", "lightning", 8, 500, 50);
    boss2->setTexture(bossTextures[3]);
    this->enemies.push_back(enemy);
    this->enemies.push_back(boss1);
    this->enemies.push_back(boss2);
    this->enemySprites.push_back(enemySprites[2]);
    this->bossSprites.push_back(bossSprites[1]);
    this->bossSprites.push_back(bossSprites[2]);
}

// Read player's health from file
void Game::readPlayerHealthFromFile() {
    std::ifstream file("player_health.txt"); // Open the file for reading
    if (file.is_open()) {
        std::string line;
        int lineNumber = 0;
        while (getline(file, line)) {
            lineNumber++;
            if (lineNumber == 2) { // Read the second line
                int playerHealth = std::stoi(line); // Convert the string to an integer
                this->player->set_health_point(playerHealth); // Set the player's health points
                break;
            }
        }
        file.close();
    } else {
        std::cerr << "ERROR::GAME::READPLAYERHEALTHFROMFILE::Failed to open file!" << std::endl;
    }
}

// Write game summary to file
void Game::writeGameSummary() {
    std::ofstream file("game_summary.txt", std::ios::app); // Open in append mode
    if (file.is_open()) {
        file << "Player Name: " << this->playerName << "\n";
        file << "Levels Accomplished: " << this->currentLevel << "\n";
        file << "-------------------------\n";
        file.close();
    } else {
        std::cerr << "ERROR::GAME::WRITEGAMESUMMARY::Failed to open file!" << std::endl;
    }
}
