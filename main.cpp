#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <fstream>
#include <vector>
using namespace std;

// ============================================================================
// User defined classes.
// ============================================================================
#include "GridTable.h"

// ============================================================================
// Function prototypes.
// ============================================================================
vector<int> loadPuzzle(char);
char printMenu();
bool validateLevel(string);
void printErrorAndExit(string);

// ============================================================================
// Main.
// ============================================================================
int main(void) {

    // ========================================================================
    // Welcome menu.
    // ========================================================================
    cout << "\n\n";
    cout << " * * * * * * * * * Welcome to Sudoku! * * * * * * * * * " << endl;
    char c = printMenu();

    // ========================================================================
    // Load puzzle from file based on difficulty level.
    // ========================================================================
    vector<int> puzzle = loadPuzzle(c);

    // ========================================================================
    // Create the table and load the puzzle.
    // ========================================================================
    GridTable<int> table(9);

    return 0;
}



// ============================================================================
// loadPuzzle.
//
// Input -> the difficulty level.
// Output -> An array of ints containing the puzzle.
// ============================================================================
vector<int> loadPuzzle(char difficulty) {
    ifstream readFromFile;
    vector<int> puzzle;
    int number;

    switch (difficulty) {
        case 'e':
            readFromFile.open("easy.txt");
            break;
        case 'i':
            readFromFile.open("intermediate.txt");
            break;
        case 'd':
            readFromFile.open("difficult.txt");
            break;
        case 'r':
            readFromFile.open("really_hard.txt");
            break;
        default:
            printErrorAndExit(
                "Something went totally wrong, please restart the game."
            );
    }

    return puzzle;
}


// ============================================================================
// printMenu.
//
// Input -> nothing
// Output -> returns the user input as a character i.e. 'e', 'i' etc...
// ============================================================================
char printMenu() {
    bool isValid = false;
    string userInput = "";

    while (validateLevel(userInput) == false) {
        cout << "e)asy\n";
        cout << "i)ntermediate\n";
        cout << "d)ifficultn\n";
        cout << "r)eally hard\n\n";
        cout << "Please enter your level (e, i, d, r): ";
        cin >> userInput;
    }

    return userInput.at(0);
}


// ============================================================================
// validateLevel.
//
// Input -> The user selection.
// Output -> true if the selection is valid, otherwise false.
// ============================================================================
bool validateLevel(string input) {
    // Beginning of program, don't need to validate.
    if (input == "") return false;

    // Valid input.
    char c = input.at(0);
    if (c == 'e' || c == 'i' || c == 'd' || c == 'r') return true;

    // Invalid input.
    cout << "\n\nInvalid input, please try again...\n\n" << endl;
    return false;
}


// ============================================================================
// printErrorAndExit.
// 
// Input -> the message to be printed.
// Output -> nothing.
// ============================================================================
void printErrorAndExit(string message = "") {
    cout << message << endl;
    exit(0);
}
