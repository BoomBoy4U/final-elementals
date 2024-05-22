
# Final Elementals

## Introduction
Welcome to the game! This document will guide you through the features, functionalities, and controls of the game, providing detailed instructions to ensure an enjoyable gaming experience.

## Game Overview
In this game, you will play as a hero navigating through various stages, battling enemies and bosses to progress. Your goal is to complete all stages and emerge victorious.

## Main Features
- **Player Customization:** Enter your name and customize your hero.
- **Stages:** Three stages to challenge your skills, each with different enemies and bosses.
- **Combat System:** Engage in battles using different attack options and a dodge mechanic.
- **Progress Tracking:** Track your progress and results through the game text file.

## Getting Started

### Installation
1. Ensure you have a C++ compiler installed (e.g., g++, clang++).
2. Download the game source files and compile them using the provided commands.
3. Use Windows 11 for high compatibility.

### Compilation
Open a terminal or command prompt and navigate to the directory containing the game source files. Use the following command to compile the game:
```bash
g++ -o game GameMenu.cpp Gameplay.cpp Player.cpp Enemy.cpp Boss.cpp Entity.cpp main.cpp
```

### Running the Game
After successful compilation, run the game using the following command:
```bash
./game
```

### Makefile
A Makefile is provided for running and compiling the game efficiently. To use the Makefile, simply type in the command:
```bash
make
./game
```

## Gameplay

### Main Menu
Upon starting the game, you will be prompted to enter your name. This name will be used throughout the game to identify your character.

### Starting the Game
- **Input your name:** Type your desired name and press Enter.
- **Choose a stage:** Select a stage (1, 2, or 3) to start playing.
- **Follow on-screen prompts:** Respond to prompts to choose actions during battles.

### Combat System
During battles, you have three action options:
- **Dodge:** Attempt to dodge enemy attacks.
- **Use Elemental Skill:** Perform a skill attack (requires skill points).
- **Ultimate Attack:** Perform a powerful attack (may reduce health).

### Stages
- **Stage 1:** Initial stage with basic enemies.
- **Stage 2:** Intermediate stage with stronger enemies and bosses.
- **Stage 3:** Final stage with the toughest enemies and final boss.

### Progression
Complete stages sequentially. You must pass Stage 1 to access Stage 2 and pass Stage 2 to access Stage 3.

### Saving and Loading
- **Record Results:** After completing the game, your results are saved to \`game_result.txt\`.
- **Show Results:** View your past game results.

### Exiting the Game
To exit the game at any point, follow the on-screen prompts to choose the exit option.

## File Descriptions
- **GameMenu.h/GameMenu.cpp:** Manages the main menu, user inputs, and stage selection.
- **Gameplay.h/Gameplay.cpp:** Controls the gameplay mechanics, including player actions and enemy interactions.
- **Player.h/Player.cpp:** Defines the player character and their abilities.
- **Enemy.h/Enemy.cpp:** Defines the enemy characters and their abilities.
- **Boss.h/Boss.cpp:** Defines the boss characters and their abilities.
- **Entity.h/Entity.cpp:** Base class for all game entities (players, enemies, bosses).

## Troubleshooting
- **Compilation Errors:** Ensure all source files are present and the compiler is correctly installed.
- **Runtime Errors:** Check for logical errors or incorrect user inputs.
- **Saving/Loading Issues:** Ensure file permissions allow reading/writing to \`game_result.txt\`.

## Conclusion
Thank you for playing the game! We hope you enjoy the experience. Follow the instructions, master the stages, and defeat all enemies to become the ultimate hero. Good luck!
