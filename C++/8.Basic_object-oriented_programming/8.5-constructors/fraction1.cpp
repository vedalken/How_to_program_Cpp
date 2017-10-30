// fraction.cpp
// Fraction class calls default constructor
// when object of the same type is called or
// constructor with parameters!
#include <iostream>
#include <cassert>
using std::cout; // iostream
using std::endl;

class Fraction
{
public:
	// default constructor initialize default values
	// to member variables
	Fraction()
	{
		m_nNumerator = 0;
		m_nDominator = 1;
	}
	
	//  constructor with parameters
	Fraction( int numerator, int dominator )
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
	Fraction cDefault; // default Fraction() constructor is called!
	cout << cDefault.getFraction() << endl;

	Fraction cFiveThirds( 5, 3 ); 
	cout << cFiveThirds.getFraction() << endl;

	return 0;	
}
