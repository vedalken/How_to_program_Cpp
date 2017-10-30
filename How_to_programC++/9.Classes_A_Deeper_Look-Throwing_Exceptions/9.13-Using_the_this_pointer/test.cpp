#include <iostream>

class Test
{
public:
    explicit Test(int = 0);
    void print() const;
private:
    int m_x;
};

Test::Test(int value)
    : m_x( value )
{
    // empty
}

void Test::print() const
{
    // implicity use the this pointer to access the member m_x
    // explicity with this pointer and the arrow operator and
    // explicity with dereferenced this pointer and the dot operator
    std::cout << "        m_x = " << m_x << '\n'
              << "  this->m_x = " << this->m_x << '\n'
              << "(*this).m_x = " << (*this).m_x << std::endl;
    std::cout << "this = " << this << std::endl;
}

int main()
{
    Test testObject(2);
    
    testObject.print();
	return 0;
}
