//
// Created by calebk on 12/12/24.
//

#include <fstream>
#include <iostream>
#include "DayFour.h"


uint64_t DayFour::xmasInstances() {
   uint64_t numInstances = 0;

   for (int32_t i = 0; i < board.size(); i++) {
       for (int32_t j = 0; j < board[i].size(); i++) {
           if (board[i][j] == 'X') {
                // we have found an X now we need to search around for an M, then we can continue in the direction
                // of that m to determine if it continues off into XMAS

                // look in a square
                int32_t nextI = i;
                int32_t nextJ = j;

               for (std::pair<int32_t, int32_t> pair : check) {
                   if (inBounds(nextI - 1, nextJ - 1) && searchThroughFoundXM(i, j, nextI + check[i].first, nextJ + check[i].second)) {
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
        std::vector<int32_t> vec;
        std::istringstream ss(line);
        int32_t num;
        while (ss >> num) {
            vec.push_back(num);
        }
        levels.push_back(vec);
    }


}

bool DayFour::inBounds(int32_t i, int32_t j) {
   return (i >= 0 && i < board.size()) && (j >= 0 && j < board.size());
}

bool DayFour::searchThroughFoundXM(int32_t ix, int32_t jx, int32_t im, int32_t jm) {
    // extend the indices in sort of a line to determine.
    int8_t iModifier = im - ix;
    int8_t jModifier = jm - jx;

    // extend to check A and S
    int32_t indexI = iModifier + im;
    int32_t indexJ = jModifier + jm;

    if (inBounds(indexI, indexJ) && board[indexI][indexJ] == 'A') {
        indexI += iModifier;
        indexJ += jModifier;
        if (inBounds(indexI, indexJ) && board[indexI][indexJ] == 'S') {
            return true;
        }
    }



    return false;
}
