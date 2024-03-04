# Grocery Counter Program

The Grocery Counter program reads data from a text file containing a list of different fruits, counts the occurences of each item in the list of fruits, and outputs options for displaying different visualizations of the data.

## Program Files

`GroceryCounter.cpp`: Contains the implementation of the `GroceryCounter` class and its methods.
`GroceryCounter.h`: Header file for the `GroceryCounter` class and the required includes.
`CS210_Project_Three_Input_File.txt`: Input file containing the list of grocery items to parse.
`main.cpp`: Entry point for the Grocery Counter program.

### `GroceryCounter` Class

The `GroceryCounter` class reads the specified input file, counts the occurence of each grocery item, and provides methods to display visualizations of the parsed data.

### Constructor

`GroceryCounter`

Constructs a `GroceryCounter` object and initializes it with the data from the specified input file.

### Member Methods

`readFile`: Reads each line from the input file containing a list of fruit and stores the unique items in a vector.
`countFrequencies`: Counts the occurrences of each item and stores the different counts in a map.
`printItemsWithCounts`: Outputs all unique items and item counts.
`printItemWithCount`: Outputs a single specified item and its count given user input.
`printHistogram`: Outputs a histogram of all fruits in the list where asterisks represent unique occurrences.
`backupToFile`: Writes the unique item and item counts to a `.data` file
`validateInput`: Validates the user's input. Displays error message if given invalid input. Selects specified menu option if input is valid.

## The Main Function

The `main` function is the entry point to the program, and completes the following steps.

Instantiates a `GroceryCounter` object, where the input file name is the argument.
Invokes the `backupToFile` method to create a backup file containing the unique item and item counts.
Displays a menu with options for different visualizations such as displaying the count for a unique fruit, displaying a histogram of all items in the list or to exit the program.
Prompts the user to enter a menu option, validating the input using the `validateInput` method from the `GroceryCounter` class.
Executes the menu option inputted by the user.
Loops indefinitely until the user exits the program.
