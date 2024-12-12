//
// Created by calebk on 12/12/24.
//

#ifndef ADVENTOFCODE2024_DAYFOUR_H
#define ADVENTOFCODE2024_DAYFOUR_H


#include <cstdint>
#include <vector>

class DayFour {
    std::vector<std::vector<char>> board;

public:
    DayFour();
    uint64_t xmasInstances();
    bool inBounds(int32_t i, int32_t j);
    bool searchThroughFoundXM(int32_t ix, int32_t jx, int32_t im, int32_t jm);
};


#endif //ADVENTOFCODE2024_DAYFOUR_H
