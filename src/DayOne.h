//
// Created by calebk on 12/1/24.
//

#ifndef ADVENTOFCODE2024_DAYONE_H
#define ADVENTOFCODE2024_DAYONE_H


#include <cstdint>
#include <vector>

class DayOne {
    std::vector<uint32_t> arr1;
    std::vector<uint32_t> arr2;
    uint32_t max;

    public:
        uint64_t calculateDifference();
        uint64_t similarityScore();

        // construct a day one
        DayOne();

};


#endif //ADVENTOFCODE2024_DAYONE_H
