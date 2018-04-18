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
// Globals
// ============================================================================
const int ROWS = 9;
const int COLS = 9;
const int TOTAL = ROWS * COLS;
const string ERROR = "Something went totally wrong, please restart the game.";

// ============================================================================
// Function prototypes.
// ============================================================================
vector<vector<char> > getPuzzleFromFile(char);
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

    if (c == 'q') {
        cout << endl << endl;
        cout << "* * * * Thanks for playing Sudoku! * * * * " << endl;
        exit(1);
    }

    // ========================================================================
    // Create the table and load the puzzle.
    // ========================================================================
    GridTable<char> table(ROWS, COLS);

    // ========================================================================
    // Load puzzle from file based on difficulty level.
    // ========================================================================
    vector<vector<char> > puzzle = getPuzzleFromFile(c);
    table.populate(puzzle);

    // ========================================================================
    // Print table.
    // ========================================================================
    table.printTable();

    return 0;
}

// ============================================================================
// getPuzzleFromFile.
//
// Input -> the difficulty level.
// Output -> An array of ints containing the puzzle.
// ============================================================================
vector<vector<char> > getPuzzleFromFile(char difficulty) {
    static vector<vector<char> > puzzle(ROWS, vector<char>(COLS));
    ifstream readFromFile;
    string line;
    char c;

    // Open the correct puzzle.
    switch (difficulty) {
        case 'e':
            readFromFile.open("puzzles/easy.txt");
            break;
        case 'i':
            readFromFile.open("puzzles/intermediate.txt");
            break;
        case 'd':
            readFromFile.open("puzzles/difficult.txt");
            break;
        case 'r':
            readFromFile.open("puzzles/expert.txt");
            break;
        default:
            printErrorAndExit(ERROR);
    }

    // Check successful open.
    if (!readFromFile.is_open()) {
        cout << "Could not read from file.\n\n\n" << endl;
        printErrorAndExit(ERROR);
    }

    int row = 0;
    while (!readFromFile.eof()) {
        getline(readFromFile, line);

        for (int col = 0; col < line.size(); ++col) {
            c = line.at(col);
            if (c == 'x') c = ' ';
            puzzle[row][col] = c;
        }

        row++;
    }

    // Close the file stream.
    readFromFile.close();

    return puzzle;
}


// ============================================================================
// printMenu.
//
// Input -> nothing
// Output -> returns the user input as a character i.e. 'e', 'i' etc...
// ============================================================================
char printMenu() {
    string userInput = "";

    while (validateLevel(userInput) == false) {
        cout << "e)asy\n";
        cout << "i)ntermediate\n";
        cout << "d)ifficultn\n";
        cout << "r)eally hard\n";
        cout << "q)uit\n\n";
        cout << "Please enter your level (e, i, d, r, q): ";
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
    if (c == 'e' || c == 'i' || c == 'd' || c == 'r' || c == 'q') return true;

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
