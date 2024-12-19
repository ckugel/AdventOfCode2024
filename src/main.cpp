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
#include "DayFive.h"

std::vector<int> finalPrices(std::vector<int>& prices) {
    std::vector<int> newPrices;
    newPrices.reserve(prices.size());

    for (size_t i = 0; i < prices.size(); i++) {
        bool found = false;
        for (size_t j = i + 1; j < prices.size(); j++) {
            if (prices[j] < prices[i]) {
                newPrices.push_back(prices[i] - prices[j]);
                found = true;
               break;
            }
        }
        if (!found) {
            newPrices.push_back(prices[i]);
        }
    }

    return newPrices;
}

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

    /*
    DayFour dayFour = DayFour();
    std::cout << "part 1: " << dayFour.xmasInstances() << std::endl;
    std::cout << "part 2: " << dayFour.crossMASes() << std::endl;
     */
    // std::cout << "s - m: " << 's' - 'm' << std::endl;


    DayFive dayFive = DayFive();
    std::cout << "part 1: " << std::endl;

    return 0;
}
