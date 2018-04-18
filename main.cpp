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
char printOptions();
void printMsgAndExit();
bool validateOption(string);
bool validateLevel(string);
void printErrorAndExit(string);
void clearStream();

// ============================================================================
// Main.
// ============================================================================
int main(void) {

    // ========================================================================
    // Welcome menu.
    // ========================================================================
    cout << "\n\n";
    cout << FGREY_PURPLE;
    cout << " * * * * * * * * * ";
    cout << " Welcome to Sudoku ";
    cout << " * * * * * * * * * " << RST << endl << endl;
    cout << endl;
    cout << FBLACK_GREEN;
    cout << "Choose your level of difficulty from the following menu";
    cout << RST;
    cout << endl << endl;
    cout << RST;
    char c = printMenu();

    if (c == 'q') printMsgAndExit();

    // ========================================================================
    // Create the table and load the puzzle.
    // Load puzzle from file based on difficulty level.
    // ========================================================================
    GridTable<char> table(ROWS, COLS);
    vector<vector<char> > puzzle = getPuzzleFromFile(c);
    table.populate(puzzle);

    // ========================================================================
    // Print table.
    // ========================================================================
    table.printTable();

    // ========================================================================
    // Loop the game.
    // ========================================================================
    char input = 'a';
    int x;
    int y;

    clearStream();
    while (input != 'q') {
        input = printOptions();

        switch (input) {
            case 'q':
                printMsgAndExit();
                break;
            case 'e':
                // get values.
                break;
            case 'p':
                table.printTable();
                break;
            default:
                printErrorAndExit(ERROR);
        }
    }

    return 0;
}


// ============================================================================
// printMsgAndExit.
//
// Input -> nothing.
// Output -> goodbye message.
// ============================================================================
void printMsgAndExit() {
    cout << endl << endl;
    cout << FGREY_PURPLE << "* Thanks for playing Sudoku! * " << RST << endl;
    exit(1);
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
// printOptions.
//
// Input -> nothing.
// Output -> the options the user has during the game.
// ============================================================================
char printOptions() {
    string userInput = "";

    cout << endl << endl;
    while(validateOption(userInput) == false) {
        cout << FBLACK_GREEN << "p)rint the table" << RST << endl;
        cout << FBLACK_GREEN << "e)nter value" << RST << endl;
        cout << FBLACK_GREEN << "q)uit game" << RST << endl << endl;
        cout << FBLACK_GREEN << "Enter choice (p, e, q): " << RST;
        cin >> userInput;
    }

    return userInput.at(0);
}

// ============================================================================
// validateOption.
//
// Input -> Option chosen as char.
// Output -> true if valid, else false.
// ============================================================================
bool validateOption(string input) {
    if (input == "") return false;

    char c = input.at(0);
    if (c == 'p' || c == 'e' || c == 'q') return true;

    cout << endl << endl << "Invalid input, please try again..." << endl << endl;
    return false;
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
        cout << FBLACK_GREEN << "e)asy" << RST << endl;
        cout << FBLACK_GREEN << "i)ntermediate" << RST << endl;
        cout << FBLACK_GREEN << "d)ifficultn" << RST << endl;
        cout << FBLACK_GREEN << "r)eally hard" << RST << endl;
        cout << FBLACK_GREEN << "q)uit" << RST << endl << endl;
        cout << FBLACK_GREEN << "Please enter your level (e, i, d, r, q): " << RST;
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


// ============================================================================
// clearStream.
//
// Input -> nothing.
// Output -> nothing.
// ============================================================================
void clearStream() {
    fflush(stdin);
}