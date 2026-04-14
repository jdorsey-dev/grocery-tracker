#include "grocery.h"
#include <fstream>
#include <iostream>

using namespace std;

/*
 * Function Name: printStars
 * Description:
 * Returns a string of asterisks (*) based on the number passed in.
 * Used to display histogram output without using a loop.
 */
string printStars(int numStars);  // numStars = frequency of item

// Constructor (doesn't initialize anything right now)
Grocery::Grocery() {
}

/*
 * Function Name: LoadData
 * Description:
 * Opens the input file containing grocery items, reads each item line by line,
 * and stores the frequency of each item in the grocList map.
 * If the file fails to open, the program exits with an error.
 */
void Grocery::LoadData() {
	ifstream inputFile; // input file stream
	string item = ""; // this stores each line (grocery item)
	inputFile.open("CS210_Project_Three_Input_File.txt"); // opens the file

	// check if file opened correctly
	if (!inputFile) {
		exit(EXIT_FAILURE);
	}

	// Read the file line by line and increment frequency of the item in the map
	// if item doesn't exist it it is automatically created with value 0
	while (getline(inputFile, item)) {
		grocList[item]++;
	}

	// close input file after it is read
	inputFile.close();
}

/*
 * Function Name: CreateBackupFile
 * Description:
 * Creates an output file named "frequency.dat" and writes each grocery item
 * along with its frequency from the grocList map.
 */
void Grocery::CreateBackupFile() {
	ofstream outputFile; // output the file stream for writing frequency info
	outputFile.open("frequency.dat"); // opens the file

	// loop checks if the file is open
	if (!outputFile) {
		exit(EXIT_FAILURE);
	}

	// loop through the map and write each item and its frequency to the file
	for (const auto& pair : grocList) {
		// pair.first = item name
		// pair.second = frequency count
		outputFile << pair.first << " " << pair.second << endl;
	}
	// close the output file
	outputFile.close();
}

/*
 * Function Name: GetItemFrequency
 * Description:
 * Searches the grocList map for a specific grocery item and returns
 * the number of times that item appears in the input data.
 * If the item is not found, the function returns 0.
 */
int Grocery::GetItemFrequency(string item) {
	// check if the item that was input exists in the map
	if (grocList.count(item) > 0) {
		// Returns the frequency stored for that item
		return grocList[item];
	}
	else {
		// Return 0 if the item is not in the map
		return 0;
	}

}

/*
 * Function Name: PrintAllItems
 * Description:
 * Displays all grocery items along with their frequency counts
 * from the grocList map.
 */
void Grocery::PrintAllItems() {
	// Loop through each item and its frequency in the map
	for (const auto& pair : grocList) {
		// pair.first = item name
		// pair.second = frequency count
		cout << pair.first << " " << pair.second << endl;
	}
}

/*
 * Function Name: PrintHistogram
 * Description:
 * Displays a histogram of grocery item frequencies using asterisks.
 * Each item is printed followed by a number of asterisks equal
 * to its frequency in the grocList map.
 */
void Grocery::PrintHistogram() {

	// Loop through each item and its frequency in the map
	for (const auto& pair : grocList) {

		// Print item name followed by stars
		cout << pair.first << " " << printStars(pair.second) << endl;
	}
}