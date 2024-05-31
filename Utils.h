#ifndef UTILS_H
#define UTILS_H

#include <tuple>
#include <cmath>
#include <cstdlib>

class Utils {
public:
    static std::tuple<int, int> generateRandomPos(int gridWidth, int gridHeight) {
        int x = rand() % gridWidth;
        int y = rand() % gridHeight;
        return std::make_tuple(x, y);
    }

    static double calculateDistance(std::tuple<int, int> pos1, std::tuple<int, int> pos2) {
        int x1, y1, x2, y2;
        std::tie(x1, y1) = pos1;
        std::tie(x2, y2) = pos2;
        return std::sqrt((x2 - x1) * (x2 - y1) + (y2 - y1) * (y2 - y1));
    }
};

#endif // UTILS_H
