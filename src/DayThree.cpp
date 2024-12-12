//
// Created by calebk on 12/12/24.
//

#include "DayThree.h"

int64_t DayThree::parseIntoSum() {
    int64_t total = 0;
    bool toDoOrNotToDo = true;

    std::regex op(R"(mul\([0-9]{1,3},[0-9]{1,3}\)|do\(\)|don't\(\))");
    std::regex numParse(R"(\b[0-9]{1,3}\b)");

    std::ifstream inputFile("../inputs/inputDayThree.txt");
    std::stringstream buff;
    buff << inputFile.rdbuf();
    std::string message = buff.str();

    // parse the operation specifically
    auto opBegin = std::sregex_iterator(message.begin(), message.end(), op);
    auto opEnd = std::sregex_iterator();

    for (std::sregex_iterator i = opBegin; i != opEnd; i++) {
        const std::smatch& match = *i;
        std::string matchs = match.str(); // match as a string

        auto numParse2Start = std::sregex_iterator(matchs.begin(), matchs.end(), numParse);
        auto numParse2End = std::sregex_iterator();

        std::vector<int64_t> multiNumBuff;
        for (std::sregex_iterator j = numParse2Start; j != numParse2End; j++) {
            const std::smatch& num = *j;
            std::string numMatch = num.str();
            multiNumBuff.push_back(std::stoi(numMatch));
        }
        if (multiNumBuff.size() == 2 && toDoOrNotToDo) {
            total += multiNumBuff[0] * multiNumBuff[1];
        }
    }
    return total;
}

int64_t DayThree::parseIntoSumDoOrDoNot() {
    int64_t total = 0;
    bool toDoOrNotToDo = true;

    std::regex op(R"(mul\([0-9]{1,3},[0-9]{1,3}\)|do\(\)|don't\(\))");
    std::regex numParse(R"(\b[0-9]{1,3}\b)");

    std::ifstream inputFile("../inputs/inputDayThree.txt");
    std::stringstream buff;
    buff << inputFile.rdbuf();
    std::string message = buff.str();

    // parse the operation specifically
    auto opBegin = std::sregex_iterator(message.begin(), message.end(), op);
    auto opEnd = std::sregex_iterator();

    for (std::sregex_iterator i = opBegin; i != opEnd; i++) {
        const std::smatch& match = *i;
        std::string matchs = match.str(); // match as a string
        if (matchs == "do()") {
            toDoOrNotToDo = true;
            // do :)
        }
        else if (matchs == "don't()") {
            toDoOrNotToDo = false;
            // don't do
        }
        auto numParse2Start = std::sregex_iterator(matchs.begin(), matchs.end(), numParse);
        auto numParse2End = std::sregex_iterator();

        std::vector<int64_t> multiNumBuff;
        for (std::sregex_iterator j = numParse2Start; j != numParse2End; j++) {
            const std::smatch& num = *j;
            std::string numMatch = num.str();
            multiNumBuff.push_back(std::stoi(numMatch));
        }
        if (multiNumBuff.size() == 2 && toDoOrNotToDo) {
            total += multiNumBuff[0] * multiNumBuff[1];
        }
    }
    return total;
}
