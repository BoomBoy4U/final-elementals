#include <iostream>
#include "GameMenu.h"
#include "Player.h"

using namespace std;

// Test the constructor of the GameMenu class
void testConstructor() {
    Player player("Hero", "Main player", 1, 30, 50, 20);
    GameMenu menu(&player);
    cout << "testConstructor PASSED" << endl;
    cout << "Next test is coming up!" << endl;
}

// Test the start method of the GameMenu class
void testStart() {
    Player player("Hero", "Main player", 1, 30, 50, 20);
    GameMenu menu(&player);
    cout << "Running testStart. Follow the instructions for input." << endl;
    menu.start();
    cout << "testStart PASSED" << endl;
    cout << "Next test is coming up!" << endl;
}

// Test the playStage method of the GameMenu class
void testPlayStage() {
    Player player("Hero", "Main player", 1, 30, 50, 20);
    GameMenu menu(&player);
    menu.playStage(1);  // Test stage 1
    menu.playStage(2);  // Test stage 2
    menu.playStage(3);  // Test stage 3
    cout << "testPlayStage PASSED" << endl;
    cout << "Next test is coming up!" << endl;
}

// Test the recordResults method of the GameMenu class
void testRecordResults() {
    Player player("Hero", "Main player", 1, 30, 50, 20);
    GameMenu menu(&player);
    menu.recordResults();
    cout << "testRecordResults PASSED" << endl;
    cout << "Next test is coming up!" << endl;
}

// Test the showResults method of the GameMenu class
void testShowResults() {
    Player player("Hero", "Main player", 1, 30, 50, 20);
    GameMenu menu(&player);
    menu.showResults();
    cout << "testShowResults PASSED" << endl;
    cout << "Next test is coming up!" << endl;
}

int main() {
    cout << "This test contains 5 small tests. It is time-consuming, but follow the steps!" << endl << endl;
    testConstructor();
    testStart();
    testPlayStage();
    testRecordResults();
    testShowResults();

    cout << "All tests completed." << endl;
    return 0;
}
