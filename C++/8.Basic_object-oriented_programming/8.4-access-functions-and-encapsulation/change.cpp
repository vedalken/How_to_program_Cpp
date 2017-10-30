// change.cpp
// Change class implementation. 
// Set and get function member call.
#include <iostream>
using std::cout;
using std::endl;

class Change
{
public:
	void setValue( int value ) { m_nValue = value; }
	int getValue() { return m_nValue; }
private:
	int m_nValue;
};

int main()
{
	Change cChange;
	cChange.setValue( 5 );
	cout << cChange.getValue() << endl;

	return 0;
}
