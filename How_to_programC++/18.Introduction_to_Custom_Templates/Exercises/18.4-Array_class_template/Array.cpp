#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <memory>
#include <initializer_list>
#include "Array.h"

int* val=NULL;
// default constructor for class Array (default size 10)
Array::Array( int arraySize )
    : size_( arraySize > 0 ? arraySize :
            throw std::invalid_argument( "Array size must be non-negative!" ) ),
      ptr_( new int[ size_ ] {} )
{
}

// copy constructor for class Array
Array::Array( const Array& arrayToCopy )
    : size_( arrayToCopy.size_ ),
      ptr_( new int [ size_ ] )
{
    for ( size_t i = 0; i < size_; ++i )
        ptr_[ i ] = arrayToCopy.ptr_[ i ];
}

// list initializer, enables passing a list initializer { }
Array::Array( std::initializer_list<int> list )
    : size_( list.size() ),
      ptr_( new int [ size_ ] )
{
    size_t i = 0;
    
    // range base for-loop
    for ( int item : list )
        ptr_[ ++i ] = item;
}


// destructor for class Array
Array::~Array()
{
}

// overloaded assignment operator
// cascading enabled with one exception: (a1 = a2 ) = a3
const Array& Array::operator=( const Array& right )
{
    // prevent self assignment
    if ( &right != this )
    {
        if ( right.size_ != size_ )
        {
            size_ = { right.size_ };
            ptr_.reset( new int [ size_ ] );
        }
        
        // copy right array contents
        for ( size_t i = 0; i < size_; ++i )
            ptr_[ i ] = right.ptr_[ i ];
    }

    // enable cascading: a1 = a2 = a3 (or a1 = ( a2 = a3 ) )
    return *this;
}

// overloaded equality operator
bool Array::operator==( const Array& right ) const
{
    if ( right.size_ != size_ )
        return false;

    // compare each array elements
    for ( size_t i = 0; i < size_ ; ++i )
    {
        if ( right.ptr_[ i ] != ptr_[ i ] )
            return false;
    }

    return true;
}

// overloaded inequality operator
bool Array::operator!=( const Array& right ) const
{
    return ! ( *this == right );
}

// overloaded subscript operator, modifiable rvalue
int& Array::operator[]( size_t subscript )
{
    if ( subscript >= size_ )
        throw std::out_of_range("Subscript out of range");

    return ptr_[ subscript ];
}

// overloaded subscript operator, non-modifiable lvalue
int Array::operator[]( size_t subscript ) const
{
    if ( subscript >= size_ )
        throw std::out_of_range("Subscript out of range");

    return ptr_[ subscript ];
}

// overloaded output operator for class Array
std::ostream& operator<<( std::ostream& output, const Array& array )
{
    for ( size_t i = 0; i < array.size_; ++i )
    {
        output << std::setw( 5 ) << array.ptr_[ i ];

        if ( ( i + 1 ) % 4 == 0 )
            output << std::endl;
    }
    
    // end last line output
    if ( array.size_ % 4 != 0 )
        output << std::endl;

    // enables cascading outputs: cout << x << y
    return output;
}

// overloaded input operator for class Array
std::istream& operator>>( std::istream& input, Array& array )
{
    for ( size_t i = 0; i < array.size_; ++i )
        input >> array.ptr_[ i ];

    // enables cascading inputs: cin >> x >> y
    return input;
}
