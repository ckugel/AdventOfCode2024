//
// Created by calebk on 12/1/24.
//

#include <cstddef>
#include <vector>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <DayFour.h>

#include "DayOne.h"
#include "DayTwo.h"
#include "DayThree.h"

int main() {
    /*
    DayOne dayOne;
    std::cout << "difference: " << dayOne.calculateDifference() << std::endl;
    std::cout << "similarity score: " << dayOne.similarityScore() << std::endl;
     */

    /*
    DayTwo dayTwo;
    std::cout << "number of safe levels: " << dayTwo.getNumberOfSafeLevels() << std::endl;
    std::cout << "number of safe levels with remove: " << dayTwo.getNumberSafeLevelsWithRemoval() << std::endl;
     */

    /*
    DayThree dayThree;
    std::cout << "result part 1: " << DayThree::parseIntoSum() << std::endl;
    std::cout << "result part 2: " << DayThree::parseIntoSumDoOrDoNot() << std::endl;
    */

    DayFour dayFour = DayFour();
    std::cout << "part 1: " << dayFour.xmasInstances() << std::endl;
    std::cout << "part 2: " << dayFour.crossMASes() << std::endl;
    // std::cout << "s - m: " << 's' - 'm' << std::endl;
    return 0;
}
