#include <iostream>

struct Fraction
{
	int nNumerator;
	int nDominator;
};

void Multiply( Fraction sF1, Fraction sF2 );

int main()
{
	using namespace std;
	
	// initializer lists
	Fraction sFraction1 = {43, 53};
	Fraction sFraction2 = {12, 97};

	// multiply numbers from the list
	Multiply(sFraction1, sFraction2);

	return 0;
}

void Multiply( Fraction sF1, Fraction sF2 )
{
	using namespace std;
	
	// type casting
	cout << static_cast<float>(sF1.nNumerator * sF2.nNumerator) \
				/ (sF1.nDominator * sF2.nDominator) << endl;
}
