#ifndef GRID_H
#define GRID_H

#include <iostream>
using namespace std;

template<class T>
class Grid {
    public:
        Grid();
        Grid(const int dimensions);
        void populate(const T& data);

    private:
        void build();

        int dimensions;
        T data;
};


// ============================================================================
// Grid.
//
// Default constructor.
// ============================================================================
template<class T>
Grid::Grid() {

}

// ============================================================================
// Grid(int).
//
// Overloaded constructor.
// ============================================================================
template<class T>
Grid::Grid(const int dimensions) {

}

// ============================================================================
// Populate.
//
// Populates the grid with T data.
// ============================================================================
void Grid::populate(const T& data) {

}

// ============================================================================
// Build.
//
// Builds the grid of dimensions.
// ============================================================================
void Grid::build() {

}

#endif /* GRID_H */