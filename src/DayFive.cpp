//
// Created by calebk on 12/15/24.
//

#include "DayFive.h"

DayFive::DayFive() {
    std::ifstream file("../inputs/inputDayFive.txt");
    if (!file.is_open()) {
        std::cout << "could not open file: inputDayFive.txt" << std::endl;
    }
    std::stringstream line;
}

uint16_t DayFive::numBrokenUpdates() {
    return 0;
}
