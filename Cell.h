#ifndef CELL_H
#define CELL_H

#include <tuple>

enum CellType { GENERIC, CHARACTER, TRAP };

class Cell {
private:
    std::tuple<int, int> position;
    char type;
    CellType cellType;

public:
    Cell(int x, int y, char type, CellType cellType = GENERIC)
        : position(x, y), type(type), cellType(cellType) {}

    std::tuple<int, int> getPos() const {
        return position;
    }

    char getType() const {
        return type;
    }

    void setPos(int x, int y) {
        position = std::make_tuple(x, y);
    }

    void setType(char type) {
        this->type = type;
    }

    CellType getCellType() const {
        return cellType;
    }
};

#endif // CELL_H
