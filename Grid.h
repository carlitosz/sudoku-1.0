#ifndef GRID_H
#define GRID_H

// ============================================================================
// Colors to decorate the grid.
// ============================================================================
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Grid {
    public:
        Grid(const int rows, const int cols);
        void populate(const vector<T> data);

    private:
        void build();

        int numRows;
        int numCols;
        T **columns;
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
    columns = new int * [rows];

    // Create rows.
    for (int i = 0; i < cols; ++i) {
        columns[i] = new int[cols];
    }
}

// ============================================================================
// Populate.
//
// Populates the grid with T data.
// ============================================================================
template<class T>
void Grid<T>::populate(const vector<T> data) {
}

// ============================================================================
// Build.
//
// Builds the grid of dimensions.
// ============================================================================
template<class T>
void Grid<T>::build() {

}

#endif /* GRID_H */
