// main.cpp
// Computer-Assisted Instruction (CAI). 
// Program help elementary school student learn multiplication.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "fun.h"
using std::cout; // iostream
using std::endl;
using std::cin;	 
using std::rand; //cstdlib
using std::srand;
using std::time; //ctime

// generate number from 1 to 9
inline int generateNumber() {
	return (1 + rand() % 9);
}

int main()
{
	srand( time(NULL) ); // seed random generator
	cout << "Enter 0 to exit!" << endl;
	
	int number1 = generateNumber(); 	// generate one number
	int number2 = generateNumber(); 	// generate second number
	int correctResult = -1;
	correctResult = number1 * number2;	// correct multiplication result

	// display which numbers are being multiplyed
	// To exit loop, input 0
	displayMessage( number1, number2 );
	int userResult = -1; 				// user result of multiplication
	cin >> userResult;					// read input

	while( userResult != 0 )
	{
		// repeat until result is correct
		while( userResult != correctResult )
		{
			displayAfterWrongAnswer();
			cin >> userResult;

			if( userResult == 0 ) // exit program
				return 0;
		}
		
		// display message for correct result
		if( userResult == correctResult )
			displayAfterCorrectAnswer();
		
		number1 = generateNumber(); 		// generate one number
		number2 = generateNumber(); 		// generate second number

		correctResult = number1 * number2;	// correct multiplication result

		// display which numbers are being multiplyed
		// To exit loop, input 0
		displayMessage( number1, number2 );
		cin >> userResult;	
	}
	
	return 0;
}// end main function
