#include <iostream>
#include <vector>
#include "Gameplay.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"

using namespace std;

// Test the constructor of the Gameplay class
void testConstructor() {
    Player player("Hero", "Main player", 1, 100, 50, 20);
    Enemy enemy1("Goblin", "Weak enemy", 2, 50, 10);
    Enemy enemy2("Orc", "Strong enemy", 2, 80, 15);
    Boss boss("Dragon", "Strong boss", 3, 200, 50);

    vector<Entity*> enemies = { &enemy1, &enemy2, &boss };

    Gameplay gameplay(enemies, &player);

    if (gameplay.get_stage() == 0) {
        cout << "testConstructor PASSED" << endl;
    } else {
        cout << "testConstructor FAILED" << endl;
    }
}

// Test the get and set stage methods of the Gameplay class
void testGetSetStage() {
    Player player("Hero", "Main player", 1, 100, 50, 20);
    vector<Entity*> enemies;
    Gameplay gameplay(enemies, &player);

    gameplay.set_stage(1);
    if (gameplay.get_stage() == 1) {
        cout << "testGetSetStage PASSED" << endl;
    } else {
        cout << "testGetSetStage FAILED" << endl;
    }
}

// Test the play method of the Gameplay class
void testPlay() {
    Player player("Hero", "Main player", 1, 100, 50, 20);
    Enemy enemy1("Goblin", "Weak enemy", 2, 50, 10);
    Enemy enemy2("Orc", "Strong enemy", 2, 80, 15);
    Boss boss("Dragon", "Strong boss", 3, 200, 50);

    vector<Entity*> enemies = { &enemy1, &enemy2, &boss };

    Gameplay gameplay(enemies, &player);

    int result = gameplay.play(enemies, &player);
    if (result == 0 || result == 1) {
        cout << "testPlay PASSED" << endl;
    } else {
        cout << "testPlay FAILED" << endl;
    }
}

int main() {
    // Run all tests for the Gameplay class
    testConstructor();
    testGetSetStage();
    testPlay();

    cout << "All tests completed." << endl;
    return 0;
}
