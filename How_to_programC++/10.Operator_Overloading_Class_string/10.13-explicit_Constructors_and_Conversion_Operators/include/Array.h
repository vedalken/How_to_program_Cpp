#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>
#include <memory>
#include <initializer_list>

class Array
{
    // insertion and extraction operators
    friend std::ostream& operator<<( std::ostream& , const Array& );
    friend std::istream& operator>>( std::istream&, Array& );
    
    public:
        explicit Array( int = 10 );
        // copy constructor
        Array( const Array& );
        // support list initialization
        Array( std::initializer_list< int > );
        
        // destructor
        ~Array();

        // get array size
        size_t getSize() const { return size_; }
        
        // assignment operator
        const Array& operator=( const Array& );

        // equality operator
        bool operator==( const Array& ) const;

        // inequality operator
        bool operator!=( const Array& ) const;

        // subscript operator for non-const objects, modifiable lvalue
        int& operator[]( size_t );

        // subscript operator for const objects, non-modifiable rvalue
        int operator[]( size_t ) const;
    private:
        size_t size_;
        std::unique_ptr< int[] > ptr_;
};

#endif
