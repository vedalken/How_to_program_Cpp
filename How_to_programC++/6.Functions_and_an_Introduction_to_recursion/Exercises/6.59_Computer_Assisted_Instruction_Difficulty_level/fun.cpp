// fun.cpp
// Implementating functions.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "fun.h" // function prototype
using std::cout; 		 // iostream
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision; // iomanip
using std::rand; 		 //  cstdlib
using std::srand;
using std::time; 		 // ctime

// Choose level of difficulty
int levelOfDifficulty()
{
	int level = 1; // level of difficulty; default value

	// Validation
	// Display message until correct value is entered
	do {
		cout << "Enter level of difficulty [1-5]: ";
		cin >> level;
	} while( level > 5 || level < 1 );
	
	return level;
}

// Display multiplication numbers and read user input
void displayMessage( int number1, int number2 )
{
	cout << "How much is " << number1 << " times " << number2 << "?  ";
}

// Display message for wrong answer
void displayAfterWrongAnswer()
{
	srand( time(NULL) ); 				// seed random generator
	int numberMessage;					// random number to display different messages
	numberMessage = (rand() % 4 + 1); 	// random number from 1 to 4
	
	// Display different messages based on random number generated
	switch( numberMessage )
	{
		case 1:
			cout << "No. Please try again." << endl;
			break;
		case 2:
			cout << "Wrong. Try once more." << endl;
			break;
		case 3: 
			cout << "Don't give up!" << endl;
			break;
		case 4: 
			cout << "Keep trying." << endl;
			break;
		default:
			cout << "Uknown case..." << endl;
			break;
	}
}

// Display message for correct answer
// To reduce student fatigue, display four different messages based on generated 
// random number
void displayAfterCorrectAnswer()
{
	srand( time(NULL) );
	int numberMessage;
	numberMessage = (rand() % 4 + 1); // random generate number from 1 to 4

	// Display different messages based on random number generated
	switch( numberMessage )
	{
		case 1:
			cout << "Very good!" << endl;
			break;
		case 2:
			cout << "Excellent!" << endl;
			break;
		case 3: 
			cout << "Nice work!" << endl;
			break;
		case 4: 
			cout << "Keep up the good work!" << endl;
			break;
		default:
			cout << "Uknown case..." << endl;
			break;
	}
}

// display statistics
void statistics( int countAll, int countCorrect )
{
	const int procent = 100; 	// procentage factor
	double procentCorrect;		// procenatage of correct results
	procentCorrect = procent * static_cast<double>( countCorrect ) / countAll;
	
	cout << "Correct anwsers: " << fixed << setprecision(1) << procentCorrect << " % " << endl;

	if( procentCorrect < 75 ) {
		cout << "Please ask your teacher for extra help." << endl;
	}
	else {
		cout << "Congratulations, you are ready to go to the next level!" << endl;
	}
}//end statistics function
