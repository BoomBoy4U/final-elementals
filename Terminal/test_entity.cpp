#include <iostream>
#include "Entity.h"

// Function to run all tests
void runTests();

// Test Case 1: Test the Entity constructor
void testConstructor() {
    Entity entity("Hero", "Water", 1, 100, 50, 20);

    // Check if the constructor initializes the attributes correctly
    if (entity.get_name() == "Hero" &&
        entity.get_info() == "Water" &&
        entity.get_Element() == 1 &&
        entity.get_Health() == 100 &&
        entity.get_SkillPoint() == 50 &&
        entity.get_Attack() == 20) {
        std::cout << "Entity Constructor Test passed.\n";
    } else {
        std::cout << "Entity Constructor Test failed.\n";
    }
}

// Test Case 2: Test the Entity getters and setters
void testGettersAndSetters() {
    Entity entity;

    // Test set and get for Name
    entity.set_Name("Hero");
    if (entity.get_name() == "Hero") {
        std::cout << "Entity Name Getter/Setter Test passed.\n";
    } else {
        std::cout << "Entity Name Getter/Setter Test failed.\n";
    }

    // Test set and get for info
    entity.set_info("Water Elemental");
    if (entity.get_info() == "Water Elemental") {
        std::cout << "Entity Info Getter/Setter Test passed.\n";
    } else {
        std::cout << "Entity Info Getter/Setter Test failed.\n";
    }

    // Test set and get for health_point
    entity.set_health_point(100);
    if (entity.get_Health() == 100) {
        std::cout << "Entity Health Point Getter/Setter Test passed.\n";
    } else {
        std::cout << "Entity Health Point Getter/Setter Test failed.\n";
    }

    // Test set and get for skill_point
    entity.set_skill_point(50);
    if (entity.get_SkillPoint() == 50) {
        std::cout << "Entity Skill Point Getter/Setter Test passed.\n";
    } else {
        std::cout << "Entity Skill Point Getter/Setter Test failed.\n";
    }

    // Test set and get for attack
    entity.set_attack(20);
    if (entity.get_Attack() == 20) {
        std::cout << "Entity Attack Getter/Setter Test passed.\n";
    } else {
        std::cout << "Entity Attack Getter/Setter Test failed.\n";
    }

    // Test set and get for element
    entity.set_element(1);
    if (entity.get_Element() == 1) {
        std::cout << "Entity Element Getter/Setter Test passed.\n";
    } else {
        std::cout << "Entity Element Getter/Setter Test failed.\n";
    }
}

int main() {
    runTests();
    return 0;
}

// Function to run all test cases
void runTests() {
    testConstructor();
    testGettersAndSetters();
}
