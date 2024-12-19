//
// Created by calebk on 12/15/24.
//

#ifndef ADVENTOFCODE2024_DAYFIVE_H
#define ADVENTOFCODE2024_DAYFIVE_H


#include <vector>
#include <cstdint>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>

class DayFive {
    std::vector<std::pair<int32_t, int32_t>> pairs;
    std::map<std::int32_t, std::set<int32_t>> ordersMap;

public:
    uint16_t numBrokenUpdates();
    DayFive();
};


#endif //ADVENTOFCODE2024_DAYFIVE_H
