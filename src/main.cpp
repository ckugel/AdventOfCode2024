//
// Created by calebk on 12/1/24.
//

#include <cstddef>
#include <vector>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <algorithm>

uint64_t calculateDifference(std::vector<uint32_t>& arr1, std::vector<uint32_t>& arr2) {
    uint64_t total = 0;
    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());

    // sizes should be the same
    for (size_t i = 0; i < arr1.size(); i++) {
        total += std::abs(((int32_t) arr1[i]) - (int32_t)(arr2[i]));
    }
    return total;
}

uint64_t similarityScore(std::vector<uint32_t>& arr1, std::vector<uint32_t>& arr2, uint32_t max) {
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

int main() {
    std::ifstream inputFile("../input.txt");
    std::vector<uint32_t> arr1;
    std::vector<uint32_t> arr2;

    // file is formatted as
    // 80784   47731
    //81682   36089
    //22289   41038
    //79525   17481
    //62156   70590

    if (!inputFile.is_open()) {
        std::cout << "Failed to open file: input.txt" << std::endl;
        return 1;
    }

    uint32_t max = 0;
    while (!inputFile.eof()) {
        uint32_t num1, num2;
        inputFile >> num1 >> num2;
        arr1.push_back(num1);
        arr2.push_back(num2);
        max = std::max(max, std::max(num1, num2));
    }

    // std::cout << "arr1 index 0: " << arr1[0] << std::endl;
    // std::cout << "arr2 index 0: " << arr2[0] << std::endl;
    std::cout << "difference: " << calculateDifference(arr1, arr2) << std::endl;
    std::cout << "similarity score: " << similarityScore(arr1, arr2, max) << std::endl;

    return 0;
}
