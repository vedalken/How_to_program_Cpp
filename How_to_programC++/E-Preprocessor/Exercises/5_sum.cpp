// Macro SUM uses two arguments, x and y to
// produce output 13

#include <iostream>
#define SUM( x, y ) ( x + y )

int inline sum2( int x, int y ) { return x+y; }

using namespace std;

int main()
{
	int x = 5;
	int y = 8;
	int sum = sum2(x,y);

	cout << "The sum of x and y is " << SUM(x,y) << endl;
	cout << "The sum of x and y is " << sum << endl; 

	return 0;	
}
