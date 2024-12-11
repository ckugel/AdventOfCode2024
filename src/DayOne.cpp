//
// Created by calebk on 12/1/24.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include "DayOne.h"


uint64_t DayOne::calculateDifference() {
    uint64_t total = 0;
    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());

    // sizes should be the same
    for (size_t i = 0; i < arr1.size(); i++) {
        total += std::abs(((int32_t) arr1[i]) - (int32_t)(arr2[i]));
    }
    return total;
}

uint64_t DayOne::similarityScore() {
    uint64_t similarity = 0;
    std::vector<uint64_t> timesOccured(max + 1, 0);

    for (size_t i = 0; i < arr2.size(); i++) {
        timesOccured[arr2[i]]++;
    }

    for (size_t i = 0; i < arr1.size(); i++) {
        similarity += arr1[i] * timesOccured[arr1[i]];
    }

    return similarity;

}

DayOne::DayOne() {
    std::ifstream inputFile("../inputs/inputDayOne.txt");
    arr1 = std::vector<uint32_t>(1000);
    arr2 = std::vector<uint32_t>(1000);

    // file is formatted as
    // 80784   47731
    //81682   36089
    //22289   41038
    //79525   17481
    //62156   70590

    if (!inputFile.is_open()) {
        std::cout << "Failed to open file: inputDayOne.txt" << std::endl;
        return;
    }

    while (!inputFile.eof()) {
        uint32_t num1, num2;
        inputFile >> num1 >> num2;
        arr1.push_back(num1);
        arr2.push_back(num2);
        max = std::max(max, std::max(num1, num2));
    }
}

