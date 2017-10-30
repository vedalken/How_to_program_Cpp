#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "DoubleSubscriptedArray.h"

DoubleSubscriptedArray::DoubleSubscriptedArray( int rows, int columns )
    : _rows{ rows > 0 ? rows : 
            throw std::invalid_argument("DoubleSubscriptedArray rows must be positive!") },
      _columns{ columns > 0 ? columns :
            throw std::invalid_argument("DoubleSubscriptedArray columns must be positive!") },
      _size{ static_cast<size_t>( _rows * _columns ) },
      _ptr{ new int [ _size ] }
{
    // No set value to two-dimensional array
}

DoubleSubscriptedArray::DoubleSubscriptedArray( const DoubleSubscriptedArray& doubleArray )
    : _rows{ doubleArray._rows },
      _columns{ doubleArray._columns },
      _size{ static_cast<size_t>( _rows * _columns ) },
      _ptr{ new int [ _size ] }
{
    for ( size_t i = 0; i < _size; ++i )
        _ptr[ i ] = doubleArray._ptr[ i ];
}

DoubleSubscriptedArray::~DoubleSubscriptedArray()
{
    // memory management is automatically managed
}

// overloaded the parenthesis operator for const two-dimensional array
// const creates an rvalue
int DoubleSubscriptedArray::operator()( int row, int column ) const
{
    if ( row < 0 || row >= _rows )
        throw std::out_of_range( "Row out of range" );

    if ( column < 0 || column >= _columns )
        throw std::out_of_range( "Column out of range" );

    return _ptr[ column + _columns * row ];
}

// overloaded the parenthesis operator for non-const two-dimensional array
// returns reference to create an rvalue
int& DoubleSubscriptedArray::operator()( int row, int column )
{
    if ( row < 0 || row >= _rows )
        throw std::out_of_range( "Row out of range" );

    if ( column < 0 || column >= _columns )
        throw std::out_of_range( "Column out of range" );
    
    return _ptr[ column + _columns * row ];
}

// overloaded assignment operator
// const return avodis: ( v1 = v2 ) = v3
const DoubleSubscriptedArray& DoubleSubscriptedArray::operator=( const DoubleSubscriptedArray& doubleArray )
{
    // prevent self-assignment
    if ( this != &doubleArray )
    {
        if ( _rows != doubleArray._rows || _columns != doubleArray._columns )
        {
            _rows    = { doubleArray._rows };
            _columns = { doubleArray._columns };
            _size    = { static_cast<size_t>( _rows * _columns ) }; 
            _ptr.reset( new int [ _size ] );
        }

        for ( size_t i = 0; i < _size; ++i )
            _ptr[ i ] = doubleArray._ptr[ i ];
    }

    return *this;
}

// overloaded equality operator
bool DoubleSubscriptedArray::operator==( const DoubleSubscriptedArray& doubleArray ) const
{
    // check array size
    if ( _rows != doubleArray._rows || _columns != doubleArray._columns )
        return false;

    for ( size_t i = 0; i < _size; ++i )
    {
        if ( _ptr[ i ] != doubleArray._ptr[ i ] )
            return false;
    }

    return true; 
}

// reset double array values
void DoubleSubscriptedArray::reset( int value )
{
    for ( size_t i = 0; i < _size; ++i )
        _ptr[ i ] = { value };
}

// overloaded output operator
std::ostream& operator<<( std::ostream& output, const DoubleSubscriptedArray& doubleArray )
{
    for ( size_t i = 0; i < doubleArray._size; ++i )
    {
        output << std::setw( 5 ) << doubleArray._ptr[ i ];
         
        if ( ( i + 1 ) % doubleArray._columns == 0 )
            output << '\n';
    }
   
    // display additional new line
    if ( doubleArray._size % doubleArray._columns != 0 )
        output << '\n';

    return output;
}

// overloaded input operator
std::istream& operator>>( std::istream& input, const DoubleSubscriptedArray& doubleArray )
{
    for ( size_t i = 0; i < doubleArray._size; ++i )
        input >> doubleArray._ptr[ i ];

    return input;
}
