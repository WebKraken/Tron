// This template creates a 2dimensional container class for variables of any type

#ifndef GRID_H
#define GRID_H

#include <stdexcept>

#define MAX_SIZE 500000000  // Maximum memory grid may allocate

template <class T>
class Grid
{
    public:
        Grid( const size_t width, const size_t height );
        Grid( const size_t width, const size_t height, const T defaultValue );
        virtual ~Grid();

        // Easy read/write access to grid elements via g(x,y)=value or value=g(x,y)
        T& operator()( const size_t x, const size_t y ) const;
        T& at( const size_t x, const size_t y) const;

        // Provides information about grid's limits
        size_t getWidth() const;
        size_t getHeight() const;

    private:
        const size_t max_x; // Grid's maximum width
        const size_t max_y; // Grid's maximum height

        // Dynamically created 2 dimensional array with elements of type T
        T **grid;
        void initGrid( T );

        // Free all memory allocated by grid
        void deleteGrid();
        // Checks if xy-tuple is in grid's borders
        bool checkRange( size_t, size_t ) const;
        // Checks if grid's size in memory exceeds MAX_SIZE
        bool checkSize() const;
};

template <class T>
Grid<T>::Grid( const size_t x, const size_t y ) : max_x( x ), max_y( y )
{
    checkSize();
    Grid<T>::grid = new T*[ max_x ];
    for( size_t i = 0; i < max_x; i++ )
    {
        Grid<T>::grid[ i ] = new T[ max_y ];
    }
}

template <class T>
Grid<T>::Grid( const size_t x, const size_t y, const T defaultValue ) : max_x( x ), max_y( y )
{
    initGrid( defaultValue );
}

template <class T>
void Grid<T>::initGrid( const T defaultValue )
{
    checkSize();
    Grid<T>::grid = new T*[ max_x ];
    for( size_t i = 0; i < max_x; i++ )
    {
        Grid<T>::grid[ i ] = new T[ max_y ];
        for( size_t j = 0; j < max_y; j++ )
            {
                Grid<T>::grid[ i ][ j ] = defaultValue;
            }
    }
}

template <class T>
bool Grid<T>::checkSize() const
{
    int elementSize = sizeof( T );
    if ( (max_x * max_y * elementSize ) > MAX_SIZE )
    {
        throw std::invalid_argument( "Grid's maximum size exceeded." );
    }
    return true;
}

template <class T>
Grid<T>::~Grid()
{
    deleteGrid();
}

template <class T>
void Grid<T>::deleteGrid()
{
    for( size_t i = 0; i < max_x; i++ )
    {
        delete[] grid[i];
    }
    delete[] grid;
}

template <class T>
T& Grid<T>::operator()( const size_t x, const size_t y ) const
{
    return at( x, y );
}

template <class T>
T& Grid<T>::at( const size_t x, const size_t y ) const
{
    checkRange( x, y );
    return grid[ x ][ y ];
}

template <class T>
bool Grid<T>::checkRange ( const size_t x, const size_t y ) const
{
    if ( x < max_x && y < max_y )
    {
        return true;
    }
    else
    {
        throw std::invalid_argument( "Grid out of bounds." );
    }
}

template <class T>
size_t Grid<T>::getWidth() const { return max_x; }

template <class T>
size_t Grid<T>::getHeight() const { return max_y; }

#endif // GRID_H
