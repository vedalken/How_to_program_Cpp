#ifndef UTILITY_H_
#define UTILITY_H_
#include <cstdint>

template <typename T> int sign( T value )
{
    return ( T(0) < value ) - ( T(0) > value );
}

int digits( int64_t number )
{
    if (number == 0)
        return 1;

    int64_t value = -1;
    int digits = 0;

    for ( ; value != 0; ++digits )
    {
        value = number % 10;
        number /= 10;
    }
    
    // skip last overflowed digit index
    --digits;

    return digits;
}

#endif
