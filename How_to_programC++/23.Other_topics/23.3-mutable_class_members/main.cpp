#include <iostream>

class TestMutable
{
public:
	TestMutable( int value = 0 )
		: m_value( value )
	{
	}

	int getValue() const
	{
		return m_value++;
	}
private:
	mutable int m_value;
};

int main()
{
	const TestMutable test(99);

	std::cout << "Initial value: " << test.getValue()
		<< "\nmodified value: " << test.getValue() << std::endl;
	return 0;
}
