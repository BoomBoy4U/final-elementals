
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <fstream> // Include for file handling
#include <iostream> // Include for console output
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
    Class that acts as the game engine.
    Wrapper class.
*/

enum GameState {
    MAIN_MENU,
    NAME_INPUT,
    GAMEPLAY
};

class Game {
private:
    // Variables
    // Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    // Mouse positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // Resources
    sf::Font font;

    // Text
    sf::Text uiText;
    sf::Text uiText2;
    sf::Text uiText3;
    std::vector<sf::Text> uiTexts;

    // PNG icons for enemy and player
    sf::Texture textureP;
    sf::Texture textureE;
    std::vector<sf::Texture> enemyTextures;
    std::vector<sf::Texture> bossTextures;
    std::vector<sf::Sprite> enemySprites;
    std::vector<sf::Sprite> bossSprites;
    sf::Sprite spriteP;
    sf::Sprite spriteE;

    // Game state
    GameState gameState;

    // Name input
    std::string playerName;
    sf::Text playerNameText;
    sf::Text namePromptText;
    sf::Text playerNameDisplayText;

    // Game logic
    bool endGame;
    unsigned points;
    int health;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    int maxButtons;
    bool mouseHeld;
    bool mouseHeld2;
    int playerHP;
    int playerSP;
    int enemyHP;
    bool gameStarted;
    bool enemyDefeated;
    bool playerDefeated;
    int currentLevel;

    // Linking it to our C++ code
    Player* player;
    Enemy* enemy2;
    std::vector<Enemy*> enemies;

    // Start button
    sf::CircleShape button;
    std::vector<sf::CircleShape> buttons;
    sf::RectangleShape startButton;
    sf::Text startButtonText;
	sf::RectangleShape gameOverRect;
    sf::Text gameOverText;

    // Private functions
    void initVariables();
    void initWindow();
    void initFonts();
    void initText();
    void initEnemies();
    void initButton();
    void initNameInput();
    void loadLevel1();
    void loadLevel2();
    void loadLevel3();
    void loadTextures();
    void initSprites();
	void initStartButton();
	void writeGameSummary();
	void readPlayerHealthFromFile();

public:
    // Constructors / Destructors
    Game(Player* player, Enemy* enemy2);
    virtual ~Game();

    // Accessors
    const bool running() const;
    const bool getEndGame() const;

    // Functions
    void spawnButtons();
    void pollEvents();
    void updateMousePositions();
    void updateEnemies();
    void update();
    void updateButtons();
    void renderText(sf::RenderTarget& target);
    void renderEnemies(sf::RenderTarget& target);
    void renderButtons(sf::RenderTarget& target);
    void render();
    void initImages();
    void drawImages(sf::RenderTarget& window);
    void handleStartButtonClick();
    void handleTextInput(sf::Event event);
};
