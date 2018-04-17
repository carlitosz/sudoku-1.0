#ifndef GRID_H
#define GRID_H

template<class T>
class Grid {
    public:
        Grid(const int dimensions);
        void populate(const T& data);

    private:
        void build();

        int dimensions;
        T data;
};


// ============================================================================
// Grid(int).
//
// Overloaded constructor.
// ============================================================================
template<class T>
Grid<T>::Grid(const int dimensions) {

}

// ============================================================================
// Populate.
//
// Populates the grid with T data.
// ============================================================================
template<class T>
void Grid<T>::populate(const T& data) {

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
