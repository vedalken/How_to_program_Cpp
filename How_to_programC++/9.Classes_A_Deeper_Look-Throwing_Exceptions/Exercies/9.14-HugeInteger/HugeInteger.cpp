#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <vector>
#include "HugeInteger.h"

HugeInteger::HugeInteger()
    : m_integers{}
{
}

void HugeInteger::input()
{
    std::string intInput;
    std::cout << "Enter integer: ";
    std::getline( std::cin, intInput );
    
    // verify numeric input
    if (!_isNumeric(intInput))
        throw std::invalid_argument("Input is not an integer");

    // allocate memory for data member
    try {
        m_integers.resize(intInput.size());
    }
    catch (const std::length_error &le) {
        std::cerr << "Length error: " << le.what() << std::endl;
        return;
    }
    catch (const std::bad_alloc &ba) {
        std::cerr << "Bad allocation: " << ba.what() << std::endl;
        return;
    }

    // fill with digits
    _fillDigits(intInput);
}

void HugeInteger::output() const
{
    bool prefixZero = {true};
    
    for (const int &digit : m_integers) 
    {
        if (prefixZero)
        {
            if (digit == 0)
                continue;
            prefixZero = false;
        }
        std::cout << digit;
    }
}

HugeInteger& HugeInteger::add(const HugeInteger& a_hi)
{
    const int base  = {10};
    const int carry = {1};

    int sum, reminder;
    sum = reminder = {0};
    
    // append zeros before integer
    if (a_hi.getInteger().size() > m_integers.size()) 
    {
        int diff;
        diff = a_hi.getInteger().size() - m_integers.size();
        m_integers.insert(m_integers.begin(), diff, 0);
    }

    for (size_t index = a_hi.getInteger().size() - 1, maxIndex = -1; index != maxIndex; --index)
    {
        // add carry
        sum  = (sum >= base)? carry : 0;
        
        // sum two digits
        sum += m_integers.at(index) + a_hi.getInteger().at(index);

        // reminder
        reminder = sum % base;
        m_integers.at(index) = reminder;
    }
   
    // add any carrier to the sum
    if (sum >= base) {
        m_integers.insert(m_integers.begin(), carry);
    }

    return *this;
}

HugeInteger& HugeInteger::substract(const HugeInteger& a_hi)
{
    const int base = {10};

    int diff   = {0};
    bool carry = {false};
    // sign to swap
    int sign   = 1;

    // append zeros before integer
    if (a_hi.getInteger().size() > m_integers.size()) 
    {
        diff = a_hi.getInteger().size() - m_integers.size();
        m_integers.insert(m_integers.begin(), diff, 0);
        sign = -1;
    }

    for (size_t index = a_hi.getInteger().size() - 1, maxIndex = -1; 
         index != maxIndex; --index)
    {
        if (carry) {
            --m_integers.at(index);
            carry = false;
        }
        
        while (a_hi.getInteger().at(index) > m_integers.at(index)) {
            m_integers.at(index) += base;
            carry = true;
        }

        // substraction
        diff = m_integers.at(index) - a_hi.getInteger().at(index);
        m_integers.at(index) = diff;
    }

    return *this;
}

bool HugeInteger::isEqualTo(const HugeInteger &a_hi1, const HugeInteger &a_hi2) const
{
    if (a_hi1.getInteger().size() != a_hi2.getInteger().size())
        return false;

    return true;
}

bool HugeInteger::isNotEqualTo(const HugeInteger &a_hi1, const HugeInteger &a_hi2) const
{
    if (isEqualTo(a_hi1, a_hi2))
        return false;

    return true;
}

bool HugeInteger::isZero(const HugeInteger &a_hi) const
{
    for (const int element : a_hi.getInteger()) {
        if (element != 0)
            return false;
    }

    return true;
}

bool HugeInteger::_isNumeric(const std::string &a_input) const
{
   for (const char &digit : a_input) {
       if (!isdigit(digit))
           return false;
   }

   return true;
}

void HugeInteger::_fillDigits(const std::string &a_digits)
{
    size_t digit = {0};

    for (auto cit = a_digits.cbegin(); cit != a_digits.cend(); ++cit, ++digit)
        m_integers.at(digit) = *cit - '0';
}
