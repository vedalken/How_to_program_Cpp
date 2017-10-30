#include <iostream>

class Test
{
public:
    Test() 
    {
        Init();
    }

    Test(int value)
    {
        Init();
        m_value = {value};
    }
    
    void Init()
    {
        m_test  = {0}; 
        m_value = {0};
    }

    int getValue() { return m_value; }
    int getTest() { return m_test; }
private:
    int m_test;
    int m_value;
};

int main()
{
    Test myTest(1);

    std::cout << "value: " << myTest.getValue()
        << "\ntest: " << myTest.getTest() << std::endl;
    return 0;
}
