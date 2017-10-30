// 2_19_average_small_large_int.cpp
// Program input are three integers, and print the
// sum, average, product, smallest and largest of
// these numbers.
#include <iostream>

using namespace std; // use standard library for iostream functions

int main()
{
	int number1;
	int number2;
	int number3;

	cout << "Please enter three integers: "; // user input
	cin >> number1 >> number2 >> number3;
	
	int sum;
	sum = number1 + number2 + number3;
	
	int average;
	average = ( number1 + number2 + number3 ) / 3;
	
	int product;
	product = number1 * number2 * number3;

	cout << "Sum is " 		<< sum 		<< endl;
	cout << "Average is " 	<< average 	<< endl;
	cout << "Product is "	<< product	<< endl;

	// find the smallest and the largest number
	if ( number1 > number2 )
	{
		// find the smallest number
		if ( number2 < number3 )
			cout << "Smallest is " << number2 << endl;

		if ( number2 > number3 )
			cout << "Smallest is " << number3 << endl;

		// find the largerst number
		if ( number1 > number3 )
			cout << "Largest is " << number1 << endl;
		
		if ( number1 < number3 )
			cout << "Largest is " << number3 << endl; 
	}

	if ( number1 < number2 )
	{
		// find the smallest number
		if ( number1 < number3 )
			cout << "Smallest is " << number1 << endl;

		if ( number1 > number3 )
			cout << "Smallest is " << number3 << endl;

		// find the largest number
		if ( number2 > number3 )
			cout << "Largest is " << number2 << endl;
		
		if ( number2 < number3 )
			cout << "Largest is " << number3 << endl;
	}

	return 0;
} // end main function
