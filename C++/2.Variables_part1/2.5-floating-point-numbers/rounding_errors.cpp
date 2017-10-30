#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	cout << setprecision(17);	// print 17 decimal places
	double dValue;
	dValue = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 \
			+ 0.1 + 0.1 + 0.1;
	cout << dValue << endl;
	
	return 0;
}
