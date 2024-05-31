#ifndef CHARACTER_H
#define CHARACTER_H

#include "Cell.h"

class Character : public Cell {
public:
    Character(int x, int y) : Cell(x, y, 'C', CHARACTER) {}

    void move(int dx, int dy) {
        int x, y;
        std::tie(x, y) = getPos();
        setPos(x + dx, y + dy);
    }
};

#endif // CHARACTER_H
