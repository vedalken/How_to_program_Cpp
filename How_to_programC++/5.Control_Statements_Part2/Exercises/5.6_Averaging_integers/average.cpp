// average.cpp
// Average input integer numbers with for loop. Use sentinel value
// 9999 to break loop.
#include <iostream>
#include <iomanip>
// iostream header
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
// iomanip header
using std::setprecision;

int main()
{
	int sum = 0;
	int count;

	cout << "To exit enter: 9999 \n";
	
	{
		int number;
		cin >> number; // read number from user

		// Use sentinel repetition (9999 to exit loop!)
		for (count = 1; number != 9999; ++count)
		{
			sum += number;
			cin >> number; // read number from user
		}
		--count; // 
	} // destroy number

	cout << "Sum: " 		<< sum;
	cout << "\nCounts: " 	<< count;
	// Display average with 2 decimal digits
	cout << "\nAverage: " 	<< fixed << setprecision(2) <<
		static_cast<float>( sum ) / count << endl;

	return 0;	
}
