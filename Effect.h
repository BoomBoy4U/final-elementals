#ifndef EFFECT_H
#define EFFECT_H

#include "Cell.h"

class Effect {
public:
    virtual void apply(Cell& cell) = 0;
};

#endif // EFFECT_H
