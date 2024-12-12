//
// Created by calebk on 12/11/24.
//

#ifndef ADVENTOFCODE2024_DAYTWO_H
#define ADVENTOFCODE2024_DAYTWO_H


#include <vector>
#include <cstdint>

class DayTwo {
    std::vector<std::vector<int32_t>> levels;
    static bool isSafeFloor(std::vector<int32_t>& floor);
    static uint8_t calculateNewChanging(int32_t diff);

public:
    DayTwo();
    uint32_t getNumberOfSafeLevels();
    uint32_t getNumberSafeLevelsWithRemoval();

};


#endif //ADVENTOFCODE2024_DAYTWO_H
