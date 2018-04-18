#ifndef GRID_TABLE_H
#define GRID_TABLE_H

#include "Grid.h"

template<class T>
class GridTable : public Grid<T> {
    public:
        GridTable(const int r, const int c) : Grid<T>(r, c) { };
        void printTable();
    private:

};

// ============================================================================
// printTable.
//
// Input -> nothing.
// Output -> prints the table to stdout.
// ============================================================================
template<class T>
void GridTable<T>::printTable() {

}

#endif /* GRID_TABLE_H */
