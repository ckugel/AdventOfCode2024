//
// Created by calebk on 12/12/24.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "DayFour.h"


uint64_t DayFour::xmasInstances() {
   uint64_t numInstances = 0;

   for (int32_t i = 0; i < board.size(); i++) {
       for (int32_t j = 0; j < board[i].size(); j++) {
           if (board[i][j] == 'X') {
                // we have found an X now we need to search around for an M, then we can continue in the direction
                // of that m to determine if it continues off into XMAS

               for (std::pair<int32_t, int32_t> pair : check) {
                   if (inBounds(i + pair.first, j + pair.second) && searchThroughFoundXM(i, j, pair.first, pair.second)) {
                       numInstances++;
                   }
               }
           }
       }
   }
   return numInstances;
}

DayFour::DayFour() {
    std::fstream inputFile("../inputs/inputDayFour.txt");
    if (!inputFile.is_open()) {
        std::cout << "Failed to open file: inputDayFour.txt" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<char> vec;
        std::istringstream ss(line);
        char msg;
        while (ss >> msg) {
            if (msg != ' ') {
                vec.push_back(msg);
            }
        }
        board.push_back(vec);
    }

    // std::cout << board.size() << std::endl;
}

bool DayFour::inBounds(int32_t i, int32_t j) {
   return (i >= 0 && i < board.size()) && (j >= 0 && j < board[i].size());
}

bool DayFour::searchThroughFoundXM(int32_t ix, int32_t jx, int32_t im, int32_t jm) {
    // extend to check A and S
    int32_t indexI = ix + im;
    int32_t indexJ = jx + jm;

    if (inBounds(indexI, indexJ) && board[indexI][indexJ] == 'M') {
        indexI += im;
        indexJ += jm;
        if (inBounds(indexI, indexJ) && board[indexI][indexJ] == 'A') {
            indexI += im;
            indexJ += jm;
            if (inBounds(indexI, indexJ) && board[indexI][indexJ] == 'S') {
                return true;
            }
        }
    }
    return false;
}

uint64_t DayFour::crossMASes() {
    uint64_t sum = 0;

    for (int32_t i = 0; i < board.size(); i++) {
        for (int32_t j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'A') {
                // we found our pivot
                if (searchCross(i, j)) {
                    sum++;
                }
            }
        }
    }

    return sum;
}

bool DayFour::searchCross(int32_t pivotI, int32_t pivotJ) {
    uint8_t sOccurences = 0;
    uint8_t mOccurences = 0;

    for (std::pair<int32_t, int32_t> pair : checkCross) {
        if (!inBounds(pair.first + pivotI, pair.second + pivotJ)) {
            return false;
        }
        if (board[pair.first + pivotI][pair.second + pivotJ] == 'S') {
            sOccurences++;
        }
        if (board[pair.first + pivotI][pair.second + pivotJ] == 'M') {
            mOccurences++;
        }
    }

    return sOccurences == 2 && mOccurences == 2 && board[pivotI + 1][pivotJ + 1] != board[pivotI - 1][pivotJ - 1];
}
