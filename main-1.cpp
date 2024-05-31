#include <iostream>
#include "Cell.h"
#include "Utils.h"

int main() {
    // Test Cell class
    Cell cell(0, 0, 'E');
    std::cout << "Initial Position: (" << std::get<0>(cell.getPos()) << ", " << std::get<1>(cell.getPos()) << ")" << std::endl;
    std::cout << "Initial Type: " << cell.getType() << std::endl;

    cell.setPos(1, 2);
    cell.setType('A');
    std::cout << "Updated Position: (" << std::get<0>(cell.getPos()) << ", " << std::get<1>(cell.getPos()) << ")" << std::endl;
    std::cout << "Updated Type: " << cell.getType() << std::endl;

    // Test Utils class
    auto randomPos = Utils::generateRandomPos(10, 10);
    std::cout << "Random Position: (" << std::get<0>(randomPos) << ", " << std::get<1>(randomPos) << ")" << std::endl;

    double distance = Utils::calculateDistance(std::make_tuple(0, 0), std::make_tuple(3, 4));
    std::cout << "Distance between (0,0) and (3,4): " << distance << std::endl;

    return 0;
}
