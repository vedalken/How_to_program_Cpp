#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H
#include <string>
#include <vector>

class HugeInteger
{
public:
    static const size_t arraySize = {40};
    HugeInteger();
    void input();
    void output() const;
    const std::vector<int>& getInteger() const { return m_integers; }
    
    // mathematical operations
    HugeInteger& add(const HugeInteger& );
    HugeInteger& substract(const HugeInteger& );
    
    // predicators
    bool isEqualTo(const HugeInteger&, 
                   const HugeInteger&) const;
    bool isNotEqualTo(const HugeInteger&, 
                      const HugeInteger&) const;
    bool isZero(const HugeInteger&) const;

private:
    bool _isNumeric(const std::string&) const;
    void _fillDigits(const std::string&);
    std::vector<int> m_integers;
};
#endif
