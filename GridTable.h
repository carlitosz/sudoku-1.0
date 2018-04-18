#ifndef GRID_TABLE_H
#define GRID_TABLE_H

#include "Grid.h"

const string FYELLOW_BLACK = "\033[43;30m";
const string FBLACK_RED = "\033[40;30m";
const string FRED_CYAN = "\033[41;36m";
const string FGREY_PURPLE = "\033[45;37m";
const string FBLACK_WHITE = "\033[47;30m";
const string FBLACK_GREEN = "\033[30;42m";
const string BOLD = "\033[1m";
const string RST = "\033[0m";

template<class T>
class GridTable : public Grid<T> {
    public:
        GridTable() { this->numRows = 0; this->numCols = 0; }
        GridTable(const int r, const int c) : Grid<T>(r, c) { };
        void printTable();
    private:
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

#endif /* GRID_TABLE_H */
