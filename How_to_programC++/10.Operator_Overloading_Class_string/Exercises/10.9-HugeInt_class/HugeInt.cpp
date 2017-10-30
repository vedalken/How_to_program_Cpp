#include <stdexcept> // include exception out_of_range
#include <cctype>    // include isdigit
#include <typeinfo>
#include <limits>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <map>
#include "HugeInt.h"
#include "utility.h"

// default constructor 
HugeInt::HugeInt( std::int64_t value  )
{
    _digits = digits( value );
    _integer.reserve( _digits );
    
    for (int i = 0; i < _digits; ++i)
        _integer.push_back( 0 );

    for ( int j = _digits - 1; j >= 0 && value != 0; --j )
    {
        _integer[ j ] = value % 10; // extract digit
        value /= 10;                // shift to next digit
    }
}

HugeInt::HugeInt( int spaceSize, bool reserve )
{
    _digits = spaceSize;
    
    if (reserve)
        _integer.reserve( spaceSize );

    for (int i = 0; i < _digits; ++i)
        _integer.push_back( 0 );
}

// conversion constructor that converts a character string
// representing a large integer into a HugeInt object
HugeInt::HugeInt( const std::string& number )
    : _digits { ( number.size() < std::numeric_limits<int>::max() ) ? 
        static_cast<int>( number.size() ) :
        throw std::out_of_range("String number exceeded the limits.") },
      _integer{ std::vector<short>( _digits ) }
{
    // number of digits
    // conversion is safe due to member initialization list check
    int length = static_cast<int>( number.size() );
    
    for ( auto rit = number.crbegin(); rit != number.crend(); ++rit )
    {
        for ( int j = _digits - 1, k = length - 1; k >= 0 && j >= 0; --j, --k )
        {
            // extract only digits
            if ( std::isdigit( number.at( k ) ) )
            {
                // digit extraction
                // compiler implicitly cast char (right side) to short (left side)
                _integer.at( j ) = number.at( k ) - '0';
            }
        }
    }
}

// Generate subinteger
HugeInt HugeInt::subint( int startPos, int endPos ) const
{
    if (endPos <= startPos)
        throw std::length_error("Start position higher or equal than end position.");
    
    if (endPos > _digits)
        throw std::out_of_range("End position out of range.");

    HugeInt subint;
    subint.reserve( endPos - startPos );
    
    for (int pos = startPos; pos < endPos; ++pos)
        subint.push_back( _integer.at( pos ) );

    return subint;
}

short& HugeInt::first()
{
    auto it = _integer.begin();
    
    // skip any leading zeros
    for ( ; it != _integer.end(); ++it) {
        if (*it != 0) {
            return *it;
        }
    }

    return _integer.front();
}

// conversion operator
HugeInt::operator std::string() const
{
    std::string str("");

    for (auto it = _integer.cbegin(); it != _integer.cend(); ++it)
        str += (*it + '0');

    return str;
}

void HugeInt::reserve( int reserve )
{
    _digits = reserve;
    _integer.clear();
    _integer.reserve( _digits );
    
    for (int i = 0; i < _digits; ++i)
        _integer.push_back(0);
}

// overloaded subscript operator for const objects returns rvalue
int HugeInt::operator[]( int subscript ) const
{
    if (subscript < 0 || subscript >= _digits)
        throw std::out_of_range("Subscript is out of range.");
    
    return _integer[subscript];
}

// overloaded subscript operator for non-const objects returns lvalue
short& HugeInt::operator[]( int subscript )
{
    if (subscript < 0 || subscript >= _digits)
        throw std::out_of_range("Subscript is out of range.");
    
    return _integer[subscript];
}

// overloaded assignment operator
// prevent self-assignment: (h1 = h2) = h3
const HugeInt& HugeInt::operator=( const HugeInt& right )
{
    // prevent self-assignment
    if ( &right != this )
    {
        // check size
        if ( right._digits != _digits )
            _digits = right._digits;
    
        _integer = right._integer;
    }

    return *this;
}

// overloaded assignment operator for string numbers
const HugeInt& HugeInt::operator=( const std::string& right )
{
    *this = HugeInt( right );
    return *this;
}

// addition operator: HugeInt + int
HugeInt HugeInt::operator+( std::int32_t operand2 ) const
{
    int op2Digits = digits( operand2 ); // operand2 number of digits
    int maxDigits = _digits > op2Digits ? _digits : op2Digits;
    // add additional carry digit
    maxDigits += 1;
    
    // temporary sum
    HugeInt sum( std::string(maxDigits, '0') );

    int carry = 0; // addition carry
    int digit = 0; // operand2 extracted digit

    for ( int i = _digits - 1, k = maxDigits - 1; k >= 0; --i, --k )
    {
        sum[ k ] = 0;

        if ( operand2 != 0 )
        {
            digit = operand2 % 10;
            operand2 /= 10;
        }
        else
            digit = 0;

        if ( i >= 0 )
            sum[ k ] += _integer.at( i );

        sum[ k ] += digit + carry;

        if ( sum[ k ] > 9 )
        {
            sum[ k ] %= 10; // reduce 0-9
            carry = 1; // additional carry
        }
        else
            carry = 0; // no carry
    }
    
    return sum;
}

// addition operator: HugeInt + string integer
HugeInt HugeInt::operator+( const std::string& operand2 ) const
{
    // convert operand2 to HugeInt
    // call overloaded addition operator
    return *this + HugeInt( operand2 );
}

// overloaded greater than
bool HugeInt::operator>( const HugeInt& operand2 ) const
{
    // check integer sign
    if ( std::signbit(_integer.at(0)) > std::signbit(operand2._integer.at(0)) )
        return false;

    // check size
    if ( _digits != operand2._digits )
    {
        if ( _digits > operand2._digits )
            return true;

        return false;
    }

    // compare digits
    for ( int i = 0; i < _digits; ++i )
    {
        if ( _integer.at(0) < operand2._integer.at(0) )
            return false;
    }

    return true;
}

bool HugeInt::operator>( int operand2 ) const
{
    // check sign
    if ( std::signbit( _integer.at(0) ) > std::signbit( operand2 ) )
        return false;

    int op2digits = digits( operand2 );

    // check number of digits
    if ( _digits != op2digits ) 
    {
        if ( _digits > op2digits )
            return true;

        return false;
    }
   
    // temporary operand2 digit
    int op2digit = 0;

    // extract digit from integer 
    for (int i = 0; i < _digits; ++i)
    {
        op2digit = operand2 % 10;
        operand2 /= 10;

        if ( _integer.at( i ) < op2digit )
            return false;
    }

    return true; 
}

bool HugeInt::operator>( const std::string& operand2 ) const
{
    HugeInt op2(operand2);
    return (*this > op2);
}

bool HugeInt::operator==( const HugeInt& operand2 ) const
{
    // check size
    if ( _digits != operand2._digits )
        return false;

    // check each element
    for (int i = 0; i < _digits; ++i)
    {
        if ( _integer.at(i) != operand2._integer.at(i) )
            return false;
    }

    return true;
}

bool HugeInt::operator==( int operand2 ) const
{
    if ( _digits != digits(operand2) )
        return false;

    int value = operand2;
    int digit = 0;

    for (int i = 0; i < _digits && value > 0; ++i)
    {
        digit = value % 10;
        value /= 10;
        if ( _integer.at(i) != digit )
            return false;
    }

    return true;
}

bool HugeInt::operator==( const std::string& operand2 ) const
{
    if (static_cast<size_t>(_digits) != operand2.size())
        return false;
    
    for (int i = 0; i < _digits; ++i)
    {
        // NOTE: implicit conversion char to int
        if (_integer.at(i) != operand2.at(i) )
            return false;
    }

    return true;
}

HugeInt HugeInt::operator*( const HugeInt& multiplier) const
{
    // TODO: different algorithms
    return longMultiplication(*this, multiplier);
}

// overloaded insertion operator
std::ostream& operator<<( std::ostream& output, const HugeInt& num )
{
    int i = 0;

    // skip leading zeros
    for ( i = 0; ( i < num._digits && num[ i ] == 0 ) ; ++i )
        ;

    if ( i == num._digits )
        output << 0;
    else
    {
        for ( ; i < num._digits; ++i )
            output << num[ i ];
    }

    return output;
}

std::istream& operator>>( std::istream& input, HugeInt& num )
{
    std::string str;
    char digit;

    while ( (digit = input.get()) != '\n' )
        str.push_back( digit );

    // shrink reserved space    
    str.reserve( str.size() );

    if (str.empty())
        throw std::invalid_argument("No digit read.");

    num = str;

    return input;
}

HugeInt operator+( const HugeInt& operand1, const HugeInt& operand2 )
{
    int maxDigits;
    maxDigits = getMaxDigits( operand1, operand2 );
    maxDigits += 1; // add additional digit for carry  
    
    // temporary sum
    HugeInt sum( std::string(maxDigits, '0') );
    
    // carry of digit addition
    int carry = 0;
    
    int k = maxDigits - 1; // step over sum digits array
    for ( int i = operand1._digits - 1, j = operand2._digits - 1; k >= 0 ; --i, --j, --k )
    {
        sum[ k ] = 0;
        if ( i >= 0 ) sum[ k ] += operand1[ i ];
        if ( j >= 0 ) sum[ k ] += operand2[ j ];
        
        // add carry
        sum[ k ] += carry;

        if ( sum[ k ] > 9 ) 
        {
            sum[ k ] %= 10; // reduce 0-9
            carry = 1;
        }
        else {
            carry = 0; // no carry
        }
    }
    
    return sum;

}

HugeInt operator+( const int lhs, const HugeInt& rhs )
{
    return rhs + lhs;
}

HugeInt operator+( const std::string& lhs, const HugeInt& rhs )
{
    return rhs + lhs;
}

// Substract two numbers: 
// the minuend (lhs) from the substrahend (rhs)
// Algorithm:
// compute difference from left to right using American method
// https://en.wikipedia.org/wiki/Subtraction#American_method
HugeInt operator-( const HugeInt& lhs, const HugeInt& rhs )
{
    int maxDigits;
    maxDigits = getMaxDigits( lhs, rhs );
    
    HugeInt result;
    result.reserve( maxDigits );
   
    bool changedSign = false;
    const HugeInt* minuend    = &lhs;
    const HugeInt* subtrahend = &rhs;

    // determine higher number
    if (rhs > lhs) 
    {
        // swap minuend and subtrahend, and set change sign
        changedSign = true;
        minuend     = &rhs;
        subtrahend  = &lhs;
    }
    
    short diff = 0;
    const short module = 10; // the module

    // array of borrow indices
    std::vector<int> borrowIndex( minuend->_digits, 0 );
    borrowIndex.reserve( minuend->_digits );
    
    // calculate non-trivial difference
    for ( int s = subtrahend->_digits - 1, m = minuend->_digits - 1; 
         s >= 0 && m >= 0; --s, --m )
    {
        // calculate difference and substract carries from the minuend digit
        diff  = ((*minuend)[m] - borrowIndex.at(m)) - (*subtrahend)[s];
    
        if ( diff >= module ) {
            throw std::out_of_range("Difference is bigger than module");
        }
        
        // digit borrow a module and add to difference
        if ( m > 0 && borrowIndex.at(m - 1) > 0 ) {
            diff += module;
        }
    
        if ( diff < 0 ) 
        {
            int index = ((m > 0) ? (m - 1) : 0);
            int tmpDiff = 0;

            // determine to which position carry is carried
            for ( ; index >= 0; --index ) 
            {
                // increment minuend carry index list
                ++borrowIndex.at(index);
                
                tmpDiff = (*minuend)[index] - borrowIndex.at(index);
                
                // subtract one carry digit from minuend next digit
                // this way we check if the minuend is capable of borrowing carry digit
                if ( index > 0 && borrowIndex.at(index - 1) > 0 ) {
                    tmpDiff += module;
                }
                
                if ( tmpDiff > 0 ) {
                    break;
                }
            }

            if ( index < 0 && (*minuend)[minuend->_digits - 1] < 0 ) {
                throw std::logic_error("Minuend cannot pass carry. Minuend is smaller than subtrahend!");
            }

            if ( m > 0 && borrowIndex.at(m - 1) > 0 ) {
                diff += module;
            }
        }

        result[m] = diff;
    }

    // proceede with trivial difference
    for (int m = minuend->_digits - subtrahend->_digits - 1; m > 0; --m) 
    {
        result[m] = (*minuend)[m];

        if (borrowIndex.at(m-1) > 0)
            result[m] += module - borrowIndex.at(m);
        
        if (result < 0) {
            throw std::logic_error("Sub-result is negative.");
        }
    }

    if ( (minuend->_digits - subtrahend->_digits - 1) >= 0) {
        result[0] = (*minuend)[0] - borrowIndex.at(0);
    }

    if (result[0] < 0) {
        throw std::logic_error("Last digit difference is negative.");
    }

    if (changedSign) {
        // re-flip the sign
        // Note: the sign first changed when swapped minuend and subtrahend
        result.first() *= -1;
    }

    return result;
}// end operator-

// Return maximal number of digits
int getMaxDigits( const HugeInt& lh, const HugeInt& rh)
{
    int lh_digits, rh_digits;
    
    lh_digits = lh.getDigits();
    rh_digits = rh.getDigits();
    
    return (lh_digits > rh_digits ? lh_digits : rh_digits);
}

void printSum( const HugeInt& summand1, const HugeInt& summand2, const HugeInt& sum)
{
    int maxDigits = 0;
    int offset = 1;
    // get max. width
    maxDigits = getMaxDigits( summand1, summand2 );
    
    // add one space alignment with + operator
    maxDigits += offset;

    char prev;

    std::cout.width(maxDigits);
    std::cout << std::setw(maxDigits)         << static_cast<std::string>(summand1) << '\n'
        << "+" << std::setw(maxDigits-offset) << static_cast<std::string>(summand2) << '\n';
    
    prev = std::cout.fill('-');
    std::cout.width(maxDigits + offset);
    std::cout << '\n';
    std::cout << std::setw(maxDigits) << static_cast<std::string>(sum) << std::endl;
    
    std::cout.fill(prev);
    
}

// Long multiplication algorithm for product computation
// product = lhs * rhs
// Internally product result is stored in reverse order, final result is reversed
// Complexity: O(n^2)
HugeInt longMultiplication( const HugeInt& lhs, const HugeInt& rhs )
{
    HugeInt product;
    
    // add additional digit due to one digit numbers with product operation
    // producing two digit number
    int maxDigits = 1;
   
    // calculate maximal possible digit
    maxDigits += lhs._digits * rhs._digits;

    // reserve space to accomodate maximal possible digits
    product.reserve( maxDigits );
    
    int lhsEnd   = lhs._digits - 1;
    int rhsEnd   = rhs._digits - 1;
    short tmp    = 0;
    short carry  = 0;
    int shift    = 0;
    int lhsIndex = 0;

    for (int rhsIndex = 0; rhsIndex < rhs._digits; ++rhsIndex)
    {
        shift = rhsIndex;
        carry = 0;
        lhsIndex = 0;

        for (; lhsIndex < lhs._digits; ++lhsIndex)
        {
            tmp = carry + rhs[ rhsEnd - rhsIndex ] * lhs[ lhsEnd - lhsIndex ];
            tmp += product[ shift + lhsIndex ];
            product[ shift + lhsIndex ] = tmp % 10;
            carry = tmp / 10;
        }
        
        // add carry to product
        if (carry > 0) 
            product[ shift + lhsIndex ] = carry;
    }
    
    // remove leading zeros
    while (product._integer.back() == 0) {
        product.pop_back();
    }

    // reverse product order
    std::reverse( product._integer.begin(), product._integer.end() );

    return product;
}

// Fast multiplication algorithm
// The karatsuba mulitplication algorithm ("divide and conquer")
// Complexity: O(n^(ln 3))
//
// Algorithm to compute: x * y
//
//   x = x1 * B^m + x0
//   y = y1 * B^m + y0
//
// where x,y has n digits, m < n. Then
//  
//  x * y = z2 * B^(2m) + z1 * B^m + z0
//
//  z0 = x0 * y0
//  z1 = x1 * y0 + x0 * y1 = (x0 + x1) * (y0 + y1) - z0 - z2
//  z2 = x1 * y1
//
HugeInt karatsuba( HugeInt& lhs, HugeInt& rhs )
{
    // Long multiplication
    if (lhs._digits < 10 || rhs._digits < 10)
        return longMultiplication( lhs, rhs );

    int maxDigits = 0;
    int splitDigits = 0;

    HugeInt result;
    result.reserve( lhs._digits + rhs._digits );    
    
    maxDigits = getMaxDigits( lhs, rhs );
    splitDigits = maxDigits / 2;

    // lhs splits into [lhsHigh][lhsLow] digits
    // rhs splits into [rhsHigh][rhsLow] digits
    HugeInt lhsLow, lhsHigh;
    HugeInt rhsLow, rhsHigh;
    
    // prepare devided digits
    if (lhs._digits == maxDigits) 
    {
        lhsLow  = lhs.subint( 0, splitDigits );
        lhsHigh = lhs.subint( splitDigits + 1, maxDigits );

        if (rhs._digits <= splitDigits)
            rhsLow = rhs;
        else {
            rhsLow  = rhs.subint( 0, splitDigits );
            rhsHigh = rhs.subint( splitDigits + 1, maxDigits );
        }
    } 
    else 
    {
        rhsLow  = rhs.subint( 0, splitDigits );
        rhsHigh = rhs.subint( splitDigits + 1, maxDigits );

        if (lhs._digits <= splitDigits)
            lhsLow = lhs;
        else {
            lhsLow  = lhs.subint( 0, splitDigits );
            lhsHigh = lhs.subint( splitDigits + 1, maxDigits );
        }
    }

    // karatsuba parameters
    HugeInt z0, z1, z2;
    HugeInt lhsSum( lhsLow + lhsHigh );
    HugeInt rhsSum( rhsLow + rhsHigh );

    z0 = karatsuba( lhsLow,  rhsLow );
    z2 = karatsuba( lhsHigh, rhsHigh );
    z1 = karatsuba( lhsSum, rhsSum ) - (z0 + z2);

    return result;
}
