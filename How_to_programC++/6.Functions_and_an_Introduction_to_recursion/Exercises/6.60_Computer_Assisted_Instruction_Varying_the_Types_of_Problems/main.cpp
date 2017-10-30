// main.cpp
// Computer-Assisted Instruction (CAI). 
// Program help elementary school student learn multiplication.
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "fun.h"
using std::cout; // iostream
using std::endl;
using std::cin;	
using std::pow;  // cmath
using std::rand; //cstdlib
using std::srand;
using std::time; //ctime

// generate number from 1 to factor-1
inline int generateNumber( int factor=1 ) {
	int power;
	power = pow( 10, factor); 

	// generate number from 1 to power-1 e.g. 1 to 9; 1 to 99
	return (1 + rand() % (power-1));
}

int main()
{
	srand( time(NULL) ); // seed random generator

	int maxCount     = 10; 	// maximal number of answer counts
	int count        = 0;	// count anwsers
	int countCorrect = 0;	// count correct answers
	int countWrong   = 0;	// count wrong anwsers
	
	// level of difficulty: 1 (default) to 5
	int difficulty = levelOfDifficulty();  
	int arithmeticType = readArithmetic(); // choose type of arithmetics;

	while( count < maxCount )
	{
		// Generate numbers depending on level of difficulty
		// Level of difficulty goes from 1 (default) to 5
		// difficulty=1 than generate numbers from 1 to 9
		// difficulty=2 than generate numbers from 1 to 99
		// difficulty=3 than generate numbers from 1 to 999
		// difficulty=4 than generate numbers from 1 to 9999
		// difficulty=5 than generate numbers from 1 to 99999
		long long number1;
		long long number2;
		number1 = generateNumber( difficulty ); // generate one number depending on difficulty
		number2 = generateNumber( difficulty ); // generate second number depending on difficulty

		int op = arithmeticType;
		// every time generate new operator
		if( arithmeticType == 5 ) {
			op = typeOfArithmetic( arithmeticType );
		}
		
		long long correctResult = -1;
		correctResult = resultOfArithmetic( number1, number2, op );
		
		displayMessage( number1, number2, op );			// display message on arithmetic of two numbers
		long long userResult = -1; 						// user result of multiplication
		cin >> userResult;								// read input
		
		// repeat until result is correct
		while(userResult != correctResult )
		{
			++countWrong; 	// count wrong anwsers
			++count;		// count anwsers	
			if( count >= maxCount ) {
				break;
			}
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
