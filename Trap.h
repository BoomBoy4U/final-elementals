#ifndef TRAP_H
#define TRAP_H

#include "Cell.h"
#include "Effect.h"

class Trap : public Cell, public Effect {
private:
    bool active;

public:
    Trap(int x, int y) : Cell(x, y, 'T', TRAP), active(true) {}

    bool isActive() const {
        return active;
    }

    void apply(Cell& cell) override {
        if (active) {
            cell.setType('T');
            active = false;
        }
    }
};

#endif // TRAP_H
