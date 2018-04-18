#ifndef GRID_TABLE_H
#define GRID_TABLE_H

#include "Colors.h"
#include "Grid.h"

const int EMPTY = -1;
const int POPULATED = -2;

template<class T>
class GridTable : public Grid<T> {
    public:
        GridTable() { this->numRows = 0; this->numCols = 0; }
        GridTable(const int r, const int c) : Grid<T>(r, c) { };
        void printTable();
        int getTotalEmpty();
        int getTotalPopulated();
        void insert(const char value, stack<char> coordinates);

    private:
        int getTotalOfType(int);
        void printHorizontalMargin();
        void printVerticalMargin();
};

// ============================================================================
// printTable.
//
// Input -> nothing.
// Output -> prints the table to stdout.
// ============================================================================
template<class T>
void GridTable<T>::printTable() {
    if (this->columns == NULL) {
        cout << "No data!" << endl;
        return;
    }

    cout << endl << endl;
    cout << FBLACK_GREEN << "                               ";
    cout << "Y";
    cout << "                               " << RST << endl;
    cout << FBLACK_GREEN << "  " << RST;
    cout << FRED_CYAN << "      0     1     2";
    cout << "      3     4     5";
    cout << "      6     7     8    " << RST << endl;
    for (int i = 0; i < this->numCols; ++i) {
        if (i % 3 == 0 && i != 0) printHorizontalMargin();
        if (i == 4) {
            cout << FBLACK_GREEN << "X " << RST;
        } else {
            cout << FBLACK_GREEN << "  " << RST;
        }
        cout << FRED_CYAN << " " << i << " " << RST;
        for (int j = 0; j < this->numRows; j++) {
            if (j % 3 == 0) printVerticalMargin();
            cout << FYELLOW_BLACK << "  " << this->columns[i][j] << "  |" << RST;
        }
        printVerticalMargin();
        cout << endl;
    }

    printHorizontalMargin();
}

// ============================================================================
// printHorizontalMargin.
//
// prints a new horizontal margin.
// ============================================================================
template<class T>
void GridTable<T>::printHorizontalMargin() {
    string margin = "-------------------------------------------------------- ";
    cout << FBLACK_GREEN << "  " << RST;
    cout << FRED_CYAN << "    " << margin << RST << endl;
}

// ============================================================================
// printHorizontalMargin.
//
// prints a new horizontal margin.
// ============================================================================
template<class T>
void GridTable<T>::printVerticalMargin() {
    string margin = "|";
    cout << FRED_CYAN << margin << RST;
}

// ============================================================================
// getTotalEmpty.
//
// Input -> nothing.
// Output -> the number of empty cells in the table.
// ============================================================================
template<class T>
int GridTable<T>::getTotalEmpty() {
    return getTotalOfType(EMPTY);
}

// ============================================================================
// getTotalPopulated.
//
// Input -> nothing.
// Output -> the number of populated cells in the table.
// ============================================================================
template<class T>
int GridTable<T>::getTotalPopulated() {
    return getTotalOfType(POPULATED);
}

// ============================================================================
// getTotalOfType.
//
// Input -> the type to search for.
// Output -> the total of the type.
// ============================================================================
template<class T>
int GridTable<T>::getTotalOfType(const int type) {
    int counter = 0;

    // Count all empty cells.
    for (int i = 0; i < this->numRows; ++i) {
        for (int j = 0; j < this->numCols; ++j) {
            if (this->columns[i][j] == 32) counter++;
        }
    }

    // Check which type and return that number.
    switch (type) {
        case EMPTY:
            return counter;
        case POPULATED:
            return (this->numRows * this->numCols) - counter;
        default:
            break;
    }

    return counter;
}

#endif /* GRID_TABLE_H */
