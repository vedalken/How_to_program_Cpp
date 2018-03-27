#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <memory>
#include <initializer_list>

template <typename T>
class Array
{
// overloaded output operator for class Array
friend std::ostream& operator<<( std::ostream& output,
		                 const Array<T>& array )
{
    for ( size_t i = 0; i < array.size_; ++i )
        output << std::setw( 5 ) << array.ptr_[ i ];
    
    output << std::endl;

    // enables cascading outputs: cout << x << y
    return output;
}

// overloaded input operator for class Array
friend std::istream& operator>>( std::istream& input,
		                 Array<T>& array )
{
    for ( size_t i = 0; i < array.size_; ++i )
        input >> array.ptr_[ i ];

    // enables cascading inputs: cin >> x >> y
    return input;
}
    
public:
    // default constructor (default size 10)
	explicit Array( int arraySize = 10 )
        : size_( arraySize > 0 ? arraySize :
                throw std::invalid_argument( "Array size must be non-negative!" ) ),
          ptr_( new T[ size_ ] {} )
    {
    }

    // copy constructor
    Array( const Array& arrayToCopy )
        : size_( arrayToCopy.size_ ),
          ptr_( new T [ size_ ] )
    {
        for ( size_t i = 0; i < size_; ++i )
            ptr_[ i ] = arrayToCopy.ptr_[ i ];
    }

    // list initializer, enables passing a list initializer { }
    Array( std::initializer_list<T> list )
        : size_( list.size() ),
          ptr_( new T [ size_ ] )
    {
        size_t i = 0;
        
        // range base for-loop
        for ( T item : list )
            ptr_[ ++i ] = item;
    }

    // destructor
    ~Array()
    {
    }

    // get array size
    size_t getSize() const { return size_; }
    
    // assignment operator
    // overloaded assignment operator
    // cascading enabled with one exception: (a1 = a2 ) = a3
    const Array& operator=( const Array<T>& right )
    {
        // prevent self assignment
        if ( &right != this )
        {
            if ( right.size_ != size_ )
            {
                size_ = { right.size_ };
                ptr_.reset( new T [ size_ ] );
            }
            
            // copy right array contents
            for ( size_t i = 0; i < size_; ++i )
                ptr_[ i ] = right.ptr_[ i ];
        }
    
        // enable cascading: a1 = a2 = a3 (or a1 = ( a2 = a3 ) )
        return *this;
    }

    // equality operator
    // overloaded equality operator
    bool operator==( const Array<T>& right ) const
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
    bool operator!=( const Array<T>& right ) const
    {
        return ! ( *this == right );
    }

    // overloaded subscript operator, modifiable rvalue
    T& operator[]( size_t subscript )
    {
        if ( subscript >= size_ )
            throw std::out_of_range("Subscript out of range");
    
        return ptr_[ subscript ];
    }

    // overloaded subscript operator, non-modifiable lvalue
    T operator[]( size_t subscript ) const
    {
        if ( subscript >= size_ )
            throw std::out_of_range("Subscript out of range");
    
        return ptr_[ subscript ];
    }

    // return last element
    T& back()
    {
	size_t size = 0;
	if (size_ > 1) {
	    size = size_ - 1;
	}
        return ptr_[size];
    }

private:
    size_t size_;
    std::unique_ptr< T[] > ptr_;
};

#endif
