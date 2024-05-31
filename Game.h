#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Cell.h"
#include "Trap.h"
#include "Character.h"
#include "Utils.h"

class Game {
private:
    std::vector<Cell*> grid;

public:
    Game() {
        std::srand(std::time(nullptr)); 
    }

    std::vector<Cell*>& getGrid() {
        return grid;
    }

    void initGame(int numCharacters, int numTraps, int gridWidth, int gridHeight) {
        for (int i = 0; i < numCharacters; ++i) {
            auto pos = Utils::generateRandomPos(gridWidth, gridHeight);
            grid.push_back(new Character(std::get<0>(pos), std::get<1>(pos)));
        }
        for (int i = 0; i < numTraps; ++i) {
            auto pos = Utils::generateRandomPos(gridWidth, gridHeight);
            grid.push_back(new Trap(std::get<0>(pos), std::get<1>(pos)));
        }
    }

    void gameLoop(int maxIterations, double trapActivationDistance) {
        int gridWidth = 10;  
        int gridHeight = 10; 

        for (int iteration = 0; iteration < maxIterations; ++iteration) {
            for (auto& cell : grid) {
                if (cell->getCellType() == CHARACTER) {
                    Character* character = static_cast<Character*>(cell);
                    character->move(1, 0); 

                    int x, y;
                    std::tie(x, y) = character->getPos();
                    if (x < 0 || y < 0 || x >= gridWidth || y >= gridHeight) {
                        std::cout << "Character has won the game!" << std::endl;
                        return;
                    }

                    for (auto& otherCell : grid) {
                        if (otherCell->getCellType() == TRAP) {
                            Trap* trap = static_cast<Trap*>(otherCell);
                            if (Utils::calculateDistance(character->getPos(), trap->getPos()) <= trapActivationDistance) {
                                trap->apply(*character);
                            }
                        }
                    }
                }
            }
        }
        std::cout << "Maximum number of iterations reached. Game over." << std::endl;
    }

    ~Game() {
        for (auto cell : grid) {
            delete cell;
        }
    }
};

#endif // GAME_H
