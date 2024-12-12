//
// Created by calebk on 12/11/24.
//

#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>
#include "DayTwo.h"


DayTwo::DayTwo() {
    std::ifstream inputFile("../inputs/inputDayTwo.txt");
   // levels = std::vector<uint32_t>(1000);

    if (!inputFile.is_open()) {
        std::cout << "Failed to open file: inputDayTwo.txt" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<int32_t> vec;
        std::istringstream ss(line);
        int32_t num;
        while (ss >> num) {
            vec.push_back(num);
        }
        levels.push_back(vec);
    }
}

uint32_t DayTwo::getNumberOfSafeLevels() {
    uint32_t runningCounter = 0;

    for (auto & level : levels) {
        if (isSafeFloor(level)) {
            runningCounter++;
        }
    }

    return runningCounter;
}

bool DayTwo::isSafeFloor(std::vector<int32_t>& floor) {
    int32_t prevDiff = floor[1] - floor[0];
    uint8_t changing = calculateNewChanging(prevDiff);
    if (changing == 0) {
        return false;
    }
    if (std::abs(prevDiff) > 3) {
        return false;
    }

    for (size_t i = 2; i < floor.size(); i++) {
        int32_t diff = floor[i] - floor[i - 1];
        if (std::abs(diff) > 3) {
            return false;
        }
        uint8_t newChanging = calculateNewChanging(diff);
        if (newChanging == 0) {
            // still looking for trend
            return false;
        }
        else {
            if (newChanging != changing && newChanging > 0) {
                return false;
            }
        }
    }
    return true;
}

uint8_t DayTwo::calculateNewChanging(int32_t diff) {
    if (diff == 0) {
        return 0;
    }
    else if (std::signbit(diff)) {
        return 1;
    }
    else {
        return 2;
    }
}

uint32_t DayTwo::getNumberSafeLevelsWithRemoval() {
    uint32_t runningCounter = 0;

    for (auto & level : levels) {
        if (isSafeFloor(level)) {
            runningCounter++;
        }
        else {
            for (uint32_t ignore = 0; ignore < level.size(); ignore++) {
                std::vector<int32_t> vec;
                for (uint32_t i = 0; i < level.size(); i++) {
                    if (i != ignore) {
                        vec.push_back(level[i]);
                    }
                }
                if (isSafeFloor(vec)) {
                    runningCounter++;
                    break;
                }
            }
        }
    }

    return runningCounter;
}

