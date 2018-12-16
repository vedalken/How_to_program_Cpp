#ifndef HUGEINT_H_
#define HUGEINT_H_

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>

/* Class HugeInt is used to initialize long integers. Most mathematical operations are defined
 * except division, modulus (TODOs).
 */

class HugeInt
{
    friend std::ostream& operator<<( std::ostream&,      const HugeInt& );
    friend std::istream& operator>>( std::istream&,      HugeInt& );
    friend HugeInt       operator+(  const HugeInt&,     const HugeInt& );
    friend HugeInt       operator+(  const int,          const HugeInt& );
    friend HugeInt       operator+(  const std::string&, const HugeInt& );
    friend HugeInt       operator-(  const HugeInt&,     const HugeInt& );

    friend int           getMaxDigits(       const HugeInt&,    const HugeInt& );
    friend void          printSum(           const HugeInt& s1, const HugeInt& s2, const HugeInt& sum);
    friend HugeInt       longMultiplication( const HugeInt&,    const HugeInt& );
    friend HugeInt       karatsuba(          HugeInt&,          HugeInt& );

public:
    // conversion/default constructor
    explicit HugeInt( std::int64_t = 0 );
    
    // conversion constructor
    HugeInt( const std::string& );
    
    int     getDigits() const { return _digits; } 
    HugeInt subint( int startPos, int endPos ) const;
    short&  first();

    // conversion operator (cast operator)
    // prevent compiler to implicity cast
    explicit operator std::string () const;
    
    // subscript operator for const objects return rvalue
    int operator[]( int ) const;

    const HugeInt& operator=( const HugeInt& );
    const HugeInt& operator=( const std::string& );

    HugeInt operator+( std::int32_t )           const;
    HugeInt operator+( const std::string& )     const;
     
    bool operator>( const HugeInt& )            const;
    bool operator>( int )                       const;
    bool operator>( const std::string& )        const;
    
    bool operator<( const HugeInt& right )      const  { return ! ( *this > right ); }
    bool operator<( int right )                 const  { return ! ( *this > right ); }
    bool operator<( const std::string& right )  const  { return ! ( *this > right ); }
    
    bool operator>=( const HugeInt& right )     const { return ( *this > right && *this == right ); }
    bool operator>=( int right )                const { return ( *this > right && *this == right ); }
    bool operator>=( const std::string& right ) const { return ( *this > right && *this == right ); }
    
    bool operator<=( const HugeInt& right )     const { return ( *this < right && *this == right ); }
    bool operator<=( int right )                const { return ( *this < right && *this == right ); }
    bool operator<=( const std::string& right ) const { return ( *this < right && *this == right ); }
    
    bool operator==( const HugeInt& )           const;
    bool operator==( int )                      const;
    bool operator==( const std::string& )       const;

    bool operator!=( const HugeInt& right )     const { return ! ( *this == right ); }
    bool operator!=( int right )                const { return ! ( *this == right ); }
    bool operator!=( const std::string& right ) const { return ! ( *this == right ); }
    
    HugeInt operator*( const HugeInt& )         const;
    //HugeInt operator*( int ) const;
    //HugeInt operator*( const std::string& ) const;
    
private:
    int _digits;
    std::vector<short> _integer;
    
    explicit HugeInt( int, bool );

    /* --------------------------------------------------------------------------------------*/
    /* subscript operator for non-const objects return lvalue */
    short& operator[]( int );
    void   reserve( int );

    inline void pop_back() {
        _integer.pop_back();
        --_digits;
        if (_integer.size() != static_cast<size_t>(_digits)) { 
            throw std::length_error("Decrease array size differs with number of digits.");
        }
    }

    inline void push_back( short digit ) {
        _integer.push_back( digit );
        ++_digits;
        if (_integer.size() != static_cast<size_t>(_digits)) {
            throw std::length_error("Increase array size differs from number of digits");
        }
    }
}; // end class HugeInt

#endif
