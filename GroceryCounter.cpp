#include "GroceryCounter.h" //include the separate header file for GroceryCounter class

//Constructor for GroceryCounter class using maps and vectors to store data read from input file
GroceryCounter::GroceryCounter(const string& fileName) : items(make_unique<vector<string>>()) { 
    readFile(fileName, items);
    countFrequencies(*items, freqMap);
}

//Method to parse and store input file contents by line
void GroceryCounter::readFile(const string& fileName, unique_ptr<vector<string>>& items) {
    ifstream file(fileName); // Open the file!
    string line;

    while (getline(file, line)) {
        items->push_back(line); // read lines
    }
}

//Method to count occurences of items found in the parsed data
void GroceryCounter::countFrequencies(const vector<string>& items, map<string, int>& freqMap) {
    for (const auto& item : items) {
        ++freqMap[item]; // Increase item counts
    }
}

//Method to print all items and occurences
void GroceryCounter::printItemsWithCounts() const {
    for (const auto& pair : freqMap) {
        cout << pair.first << " " << pair.second << endl;
    }
}

//Method to print count of a specific item
void GroceryCounter::printItemWithCount() {
    cout << "Enter item: ";
    string item;
    cin >> item;
    auto iter = freqMap.find(item);
    if (iter != freqMap.end()) {
        cout << iter->second << endl; // Prints item count if in list
    }
    else {
        cout << "Item '" << item << "' not found." << endl;
    }
}

//Method to print a histogram of items and their occurences, similar to printItemsWithCounts() but with asterisks instead of ints
void GroceryCounter::printHistogram() const {
    for (const auto& pair : freqMap) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*"; // Prints a star for each occurence
        }
        cout << endl;
    }
}

//Method to backup data
void GroceryCounter::backupToFile(const string& fileName) const {
    ofstream file(fileName);

    for (const auto& pair : freqMap) {
        file << pair.first << ": " << pair.second << endl;
    }
}

//Method to validate user input for menu
bool GroceryCounter::validateInput(int input) {
    if (input < 1 || input > 4) { // Checking whether the input is a valid menu choice between 1 and 4 (inclusive)
        return false;
    }
    return true;
}