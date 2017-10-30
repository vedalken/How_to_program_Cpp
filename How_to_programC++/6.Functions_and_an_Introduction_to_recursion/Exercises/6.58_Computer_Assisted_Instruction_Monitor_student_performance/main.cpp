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
	
	int maxCount     = 10; 	// maximal number of answer counts
	int count        = 0;	// count anwsers
	int countCorrect = 0;	// count correct answers
	int countWrong   = 0;	// count wrong anwsers
	
	while( count < maxCount )
	{
		int number1 = generateNumber(); 	// generate one number
		int number2 = generateNumber(); 	// generate second number

		int correctResult = -1;
		correctResult = number1 * number2;	// correct multiplication result

		// display which numbers are being multiplyed
		// To exit loop, input 0
		displayMessage( number1, number2 );
		int userResult = -1; 				// user result of multiplication
		cin >> userResult;					// read input
		
		// repeat until result is correct
		while( userResult != correctResult )
		{
			++countWrong; 	// count wrong anwsers
			++count;		// count anwsers	
			displayAfterWrongAnswer();
			cin >> userResult;
		}
		
		// display message for correct result
		if( userResult == correctResult ) {
			++count;
			++countCorrect;
			displayAfterCorrectAnswer();
		}
	}

	if( count != maxCount )
		cout << "Not correct counting!" << endl;
	
	// display statistics 
	statistics( count, countCorrect );

	return 0;
}// end main function
