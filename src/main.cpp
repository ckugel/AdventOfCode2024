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

int main() {
    DayOne dayOne;
    std::cout << "difference: " << dayOne.calculateDifference() << std::endl;
    std::cout << "similarity score: " << dayOne.similarityScore() << std::endl;

    return 0;
}
