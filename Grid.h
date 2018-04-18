#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Grid {
    public:
        Grid() { columns = NULL; }
        Grid(const int rows, const int cols);
        void populate(const vector<vector<T> > data);
        int getNumRows() { return numRows; }
        int getNumCols() { return numCols; }
        void setNumRows(int r) { numRows = r; }
        void setNumCols(int c) { numCols = c; }

        virtual void printTable() = 0;
        virtual void printHorizontalMargin() = 0;
        virtual void printVerticalMargin() = 0;

    protected:
        T **columns;
        int numRows;
        int numCols;
};


// ============================================================================
// Grid(int).
//
// Overloaded constructor.
// ============================================================================
template<class T>
Grid<T>::Grid(const int rows, const int cols) {
    // Set rows/cols.
    numRows = rows;
    numCols = cols;

    // Create array of pointers.
    columns = new T * [rows];

    // Create rows.
    for (int i = 0; i < cols; ++i) {
        columns[i] = new T[cols];
    }
}

// ============================================================================
// Populate.
//
// Populates the 2D grid with T data.
// ============================================================================
template<class T>
void Grid<T>::populate(const vector<vector<T> > data) {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            columns[i][j] = data[i][j];
        }
    }
}

#endif /* GRID_H */
