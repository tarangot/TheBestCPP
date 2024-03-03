#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map> // used to sort through text file data
#include <string>
#include <memory>    // used to import smart pointers

using namespace std;

class GroceryCounter {
private:
    map<string, int> freqMap; //stores item occurences
    unique_ptr<vector<string>> items; //smart pointer handles memory allocation and deallocation
public:
    GroceryCounter(const string& fileName);
    void readFile(const string& fileName, unique_ptr<vector<string>>& items);
    void countFrequencies(const vector<string>& items, map<string, int>& freqMap);
    void printItemsWithCounts() const;
    void printItemWithCount();
    void printHistogram() const;
    void backupToFile(const string& fileName) const;
    bool validateInput(int input);
};