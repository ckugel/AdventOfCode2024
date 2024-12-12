//
// Created by calebk on 12/1/24.
//

#include <cstddef>
#include <vector>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "DayOne.h"
#include "DayTwo.h"

int main() {
    DayOne dayOne;
    /*
    std::cout << "difference: " << dayOne.calculateDifference() << std::endl;
    std::cout << "similarity score: " << dayOne.similarityScore() << std::endl;
     */

    DayTwo dayTwo;
    std::cout << "number of safe levels: " << dayTwo.getNumberOfSafeLevels() << std::endl;
    std::cout << "number of safe levels with remove: " << dayTwo.getNumberSafeLevelsWithRemoval() << std::endl;

    return 0;
}
