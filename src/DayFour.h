//
// Created by calebk on 12/12/24.
//

#ifndef ADVENTOFCODE2024_DAYFOUR_H
#define ADVENTOFCODE2024_DAYFOUR_H


#include <cstdint>
#include <vector>


const std::vector<std::pair<int32_t, int32_t>> check
    { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

class DayFour {
    std::vector<std::vector<char>> board;


public:
    DayFour();
    uint64_t xmasInstances();
    bool inBounds(int32_t i, int32_t j);
    bool searchThroughFoundXM(int32_t ix, int32_t jx, int32_t im, int32_t jm);
};


#endif //ADVENTOFCODE2024_DAYFOUR_H
