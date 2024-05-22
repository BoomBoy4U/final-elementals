#include <iostream>
#include "Enemy.h"

using namespace std;

// Test the default constructor of the Enemy class
void testDefaultConstructor() {
    Enemy enemy;
    if (enemy.get_name() == "NA" &&
        enemy.get_info() == "NA" &&
        enemy.get_Element() == 0 &&
        enemy.get_Health() == 0 &&
        enemy.get_Attack() == 0) {
        cout << "testDefaultConstructor PASSED" << endl;
    } else {
        cout << "testDefaultConstructor FAILED" << endl;
    }
}

// Test the parameterized constructor of the Enemy class
void testParameterizedConstructor() {
    Enemy enemy("Goblin", "Weak enemy", 2, 50, 10);
    if (enemy.get_name() == "Goblin" &&
        enemy.get_info() == "Weak enemy" &&
        enemy.get_Element() == 2 &&
        enemy.get_Health() == 50 &&
        enemy.get_Attack() == 10) {
        cout << "testParameterizedConstructor PASSED" << endl;
    } else {
        cout << "testParameterizedConstructor FAILED" << endl;
    }
}

// Test the damageDealt method of the Enemy class
void testDamageDealt() {
    Enemy enemy("Goblin", "Weak enemy", 2, 50, 10);
    int damage = enemy.damageDealt(10);
    if (damage == 10) {
        cout << "testDamageDealt PASSED" << endl;
    } else {
        cout << "testDamageDealt FAILED" << endl;
    }
}

int main() {
    // Run all tests for the Enemy class
    testDefaultConstructor();
    testParameterizedConstructor();
    testDamageDealt();

    cout << "All tests completed." << endl;
    return 0;
}
