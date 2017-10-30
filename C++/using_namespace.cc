#include <iostream>

using namespace std ;

namespace first
{
	int x = 5;
	int y = 154;
}

namespace second 
{
	double x = 6.4234;
	double y = 0.435;
}

int main () {
	
	using namespace first ;
	cout << x << endl ;
	cout << y << endl ;
	cout << second::x << endl ;
	cout << second::y << endl ;

	return 0 ;
}
