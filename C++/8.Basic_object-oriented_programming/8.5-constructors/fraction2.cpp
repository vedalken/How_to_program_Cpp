// fraction2.cpp
// Use constructor with default parameters
// as default constructor or as constructor
// with parameters!
#include <iostream>
#include <cassert>
using std::cout; // iostream
using std::endl;

class Fraction
{
public:
	//  constructor with parameters with default parameters
	//  (act as default constructor!)
	Fraction( int numerator = 0, int dominator = 1 )
	{
		assert( dominator != 0 ); // assertion dominator not equal 0, otherwise print error!
		m_nNumerator = numerator;
		m_nDominator = dominator;
	}

	// member functions returns numberator, 
	// dominator, and returns fraction ob both
	// integer values
	int getNumerator() { return m_nNumerator; }
	int getDominator() { return m_nDominator; }
	double getFraction() { return static_cast<double>( m_nNumerator ) / m_nDominator; }
private:
	int m_nNumerator;
	int m_nDominator;
};

int main()
{
	Fraction cDefault; // constructor with default parameter is called (default constructor)!
	cout << cDefault.getFraction() << endl;

	Fraction cFiveThirds( 5, 3 ); // constructor with parameters
	cout << cFiveThirds.getFraction() << endl;

	return 0;	
}
