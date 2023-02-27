#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

class Inventory {
private:
    map<string, int> itemCount;
    int highestItemLength = 0;

public:

    // file reading function
    void ReadFile(string fileName);

    // 3 print functions
    void FrequencyOfWord();
    void FrequencyOfAllWords();
    void Histogram();

    // menu
    void Menu();
};