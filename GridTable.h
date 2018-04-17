#ifndef GRID_TABLE_H
#define GRID_TABLE_H

#include <iostream>
using namespace std;

#include "Grid.h"

template<class T>
class GridTable : public Grid<T> {
    public:
        GridTable(int dimensions) : Grid(dimensions);
    private:

};

#endif /* GRID_TABLE_H */