#pragma once

#include <string>      // For string data type
#include <map>         // For map container
#include <limits>   // For numeric_limits

using namespace std;

const int MAX_INTEGER = numeric_limits<int>::max();

/*
 * Class Name: Grocery
 * Description:
 * This class handles all functionality related to tracking grocery items.
 * It reads item data from an input file, stores item frequencies using a map,
 * and provides functions to retrieve and display this data in various formats.
 */
class Grocery {
public:
	// Constructor that initializes the grocery object
	Grocery();

	// reads grocery items from the input file and stores the frequencies
	void LoadData();
	
	// Writes item frequencies to the frequency.dat file
	void CreateBackupFile();

	// Returns the frequency of a certain item
	int GetItemFrequency(string item);

	// Displays all items with their frequencies
	void PrintAllItems();

	// Displays a histogram of item fequencies using asterisks
	void PrintHistogram();

private:
	// Stores grocery tiems as keys and their frequencies as values
	map<string, int> grocList;
};