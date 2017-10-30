#ifndef DOUBLE_SUBSCRIPTED_ARRAY_H_
#define DOUBLE_SUBSCRIPTED_ARRAY_H_
#include <iostream>
#include <memory>

class DoubleSubscriptedArray
{
friend std::ostream& operator<<( std::ostream& , const DoubleSubscriptedArray& );
friend std::istream& operator>>( std::istream& , const DoubleSubscriptedArray& );

public:
    DoubleSubscriptedArray( int rows, int columns);
    
    // prevent calling default copy constructor
    DoubleSubscriptedArray( const DoubleSubscriptedArray& );
    
    ~DoubleSubscriptedArray();

    // overloaded the parentheses operator for const objects returns rvalue
    int operator()( int row, int column ) const;
    
    // overloaded the parentheses operator for const objects returns modifiable lvalue
    int& operator()( int row, int column );

    // overloaded assignment operator
    const DoubleSubscriptedArray& operator=( const DoubleSubscriptedArray& );

    // overloaded equality operator
    bool operator==( const DoubleSubscriptedArray& ) const;

    // overloaded inequality operator
    inline bool operator!=( const DoubleSubscriptedArray& right ) const 
    { 
        return !( *this == right ); // invokes overloaded == operator 
    }
    
    inline size_t getSize() const { return _size; }
    
    // reset values to 0
    void reset( int = 0 );

private:
    int _rows;
    int _columns;
    size_t _size;
    std::unique_ptr<int[]> _ptr;
};

#endif
