/*
 * Name: Josh Dorsey
 * Course: CS 210
 * Project: Project Three - Corner Grocer
 * Description:
 * This program reads grocery item data from an input file, stores the
 * frequency of each item using a map, creates a backup file, and allows
 * the user to search item frequencies, print all items, and display a
 * histogram through a menu-driven interface.
 */

#include <iostream>   // For input and output
#include <string>     // For string data type
#include "grocery.h" // Includes Grocery class

using namespace std;

/*
 * Function Name: printStars
 * Description:
 * Returns a string of asterisks (*) equal to the number passed in.
 * Used for displaying histogram values.
 */
string printStars(int numStars) {
    return string(numStars, '*');
}

/*
 * Function Name: getInteger
 * Description:
 * Prompts the user to enter a valid integer within a specified range.
 * This function uses cin to read input and checks for invalid input
 * such as letters or out-of-range values. It will repeatedly prompt
 * the user until a valid number between the given bounds is entered.
 */
int getInteger(int lowest, int highest, string prompt)
{
    int number = 0;        // Stores the user’s numeric input
    bool needNumber = true; // Controls loop for valid input

    // Append range to prompt
    prompt = prompt + to_string(lowest) + " - " + to_string(highest) + " ";

    do {
        // Prompt user
        cout << prompt;

        // Attempt to read integer
        cin >> number;

        // Check if input failed (user entered text instead of number)
        if (cin.fail()) {
            cout << "Please enter a number." << endl;

            cin.clear(); // Reset fail state
            cin.ignore(MAX_INTEGER, '\n'); // Remove bad input
            continue;
        }

        // Clear leftover input from buffer
        cin.ignore(MAX_INTEGER, '\n');

        // Check if number is within valid range
        needNumber = (number < lowest || number > highest);

        if (needNumber) {
            cout << "Invalid number. Please select menu option 1 - 4 " << endl;
        }

    } while (needNumber);

    return number;
}

/*
 * Function Name: DisplayMenu
 * Description:
 * Displays the menu options for the user.
 */
void DisplayMenu() {
    cout << endl;
    cout << "Corner Grocer Menu" << endl;
    cout << "1. Search for item frequency" << endl;
    cout << "2. Print all item frequencies" << endl;
    cout << "3. Print histogram" << endl;
    cout << "4. Exit" << endl;
    cout << endl;
}

/*
 * Function Name: RunMenu
 * Description:
 * Handles the menu loop, processes user input, and calls the
 * appropriate Grocery class functions based on user selection.
 * Uses professor-recommended getInteger function for input validation.
 */
void RunMenu(Grocery& grocery) {

    int selection = 0;   // Stores user's menu choice
    string item = "";    // Stores item entered by user

    // Continue displaying menu until user selects option 4
    while (selection != 4) {

        // Display menu options
        DisplayMenu();

        // Get valid menu selection using professor's input validation
        selection = getInteger(1, 4, "Please select menu option ");

        // Option 1: Search for item frequency
        if (selection == 1) {
            cout << "Enter item name: ";
            cin >> item;  // Matches professor's input style

            cout << item << " "
                << grocery.GetItemFrequency(item) << endl;
        }

        // Option 2: Print all items
        else if (selection == 2) {
            grocery.PrintAllItems();
        }

        // Option 3: Print histogram
        else if (selection == 3) {
            grocery.PrintHistogram();
        }

        // Option 4: Exit
        else if (selection == 4) {
            cout << "Exiting program." << endl;
        }
    }
}

/*
 * Function Name: main
 * Description:
 * Initializes the Grocery object, loads item data from the input file,
 * creates the backup frequency file, and calls the RunMenu function
 * to handle all user interaction and menu processing.
 */
int main() {

    Grocery grocery;   // Creates Grocery object

    // Load data from file
    grocery.LoadData();

    // Create backup file
    grocery.CreateBackupFile();

    // Run the menu function
    RunMenu(grocery);

    return 0;
}

