/* CS 210 Project 3
   Author: Thomas Tarango
   Date: February 22nd, 2024 */


#include "GroceryCounter.h"

int main() {
    GroceryCounter counter("CS210_Project_Three_Input_File.txt"); //instantiate counter GroceryCounter object using text data
    counter.backupToFile("frequency.dat"); //backup data 

    int option = 0;
    while (option != 4) {
        cout << "Menu:" << endl
            << "1: Print single item count" << endl
            << "2: Print all items counts" << endl
            << "3: Print histogram" << endl
            << "4: Exit" << endl;;

        if (!(cin >> option) || (!counter.validateInput(option))) { // validate user input, display message if not valid
            cerr << "Invalid input. Please enter a valid number." << endl;
            cin.clear(); // Clear the error for input stream
            cin.ignore(123, '\n'); // Ignore last input from stream
        }
        else {
            switch (option) {
            case 1:
                counter.printItemWithCount();
                break;
            case 2: 
                counter.printItemsWithCounts(); 
                break;
            case 3: 
                counter.printHistogram(); 
                break;
            }
        }
    }

    return 0;
}
