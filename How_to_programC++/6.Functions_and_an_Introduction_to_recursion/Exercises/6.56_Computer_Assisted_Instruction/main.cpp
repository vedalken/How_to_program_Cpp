// main.cpp
// Computer-Assisted Instruction (CAI). 
// Program help elementary school student learn multiplication.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "fun.h"
using std::cin;	 //iostream
using std::rand; //cstdlib
using std::srand;
using std::time; //ctime

// generate number from 1 to 9
inline int generateNumber() {
	return (1 + rand() % 9);
}

int main()
{
	srand( time(NULL) ); //seed random generator
	while( 1 )
	{
		int number1 = generateNumber(); // generate one number
		int number2 = generateNumber(); // generate second number

		int correctResult = -1;
		correctResult = number1 * number2; // correct multiplication result

		// display which numbers are being multiplyed
		// To exit loop, input 0
		displayMessage( number1, number2 );
		int userResult = -1; 				// user result of multiplication
		cin >> userResult;					// read input

		// exit program
		if( userResult == 0 )
			break;

		// repeat until result is correct
		while( userResult != correctResult )
		{
			displayAfterWrongAnswer();
			cin >> userResult;
		}
		
		// display message for correct result
		if( userResult == correctResult )
			displayAfterCorrectAnswer();
	}
	
	return 0;
}// end main function
