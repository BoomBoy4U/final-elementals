#include <iostream>
#include "Trap.h"
#include "Character.h"
#include "Utils.h"

int main() {
    Character character(0, 0);
    Trap trap(1, 0);

    std::cout << "Character initial position: (" << std::get<0>(character.getPos()) << ", " << std::get<1>(character.getPos()) << ")" << std::endl;
    std::cout << "Trap initial position: (" << std::get<0>(trap.getPos()) << ", " << std::get<1>(trap.getPos()) << ")" << std::endl;

    character.move(1, 0);
    std::cout << "Character moved to position: (" << std::get<0>(character.getPos()) << ", " << std::get<1>(character.getPos()) << ")" << std::endl;

    if (Utils::calculateDistance(character.getPos(), trap.getPos()) == 0) {
        trap.apply(character);
    }

    std::cout << "Character type after moving: " << character.getType() << std::endl;
    std::cout << "Trap active status: " << trap.isActive() << std::endl;

    return 0;
}
