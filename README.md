# CS210 Project Three – Corner Grocer

This project is a C++ program that reads grocery item data from an input file and tracks how often each item appears. The program uses a map to store item names and their frequencies, then allows the user to interact with the data through a menu.

## Features
- Search for a specific item and see how many times it appears
- Print all items with their frequencies
- Display a histogram using asterisks
- Save frequency data to an output file (`frequency.dat`)

## How It Works
- The program reads from `CS210_Project_Three_Input_File.txt`
- Each item is stored in a `map<string, int>`
- A menu allows the user to choose different actions
- Input is validated to prevent crashes or invalid entries

## Files Included
- `groceryMain.cpp` – main program and user interaction
- `groceryClass.cpp` – class function implementations
- `grocery.h` – class definition
- `CS210_Project_Three_Input_File.txt` – input data file

## How to Run
1. Make sure all files are in the same directory
2. Compile the program
3. Run the executable
4. Follow the menu prompts

## Notes
- Item searches are case-sensitive (ex: "Apples" is different from "apples")
- The program creates a backup file named `frequency.dat`
