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
// Choose arithmetics
void displayMessage( int number1, int number2, int type )
{
	char op = '\0';
	switch( type )
	{
		case 1: op = '+'; 
				break;
		case 2: op = '-'; 
				break;
		case 3: op = '*'; 
				break;
		case 4: op = '/'; 
				break;
		default: 
			break;
	}

	cout << "How much is " << number1 << op << number2 << "?  ";
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

// Display message on arithmetic options
int readArithmetic()
{
	cout << "Type of arithmetics:" << endl;
	cout << "(1) + \n"
		 << "(2) - \n"
		 << "(3) * \n"
		 << "(4) / \n"
		 << "(5) random mixure of all those types\n";
	
	int type = -1; // type of arithmetics
	do{
		cout << "Choose type of arithmetics: ";
		cin >> type;
	}while( type<1 || type>5 );

	return type;
}

// Function return one of four arithmetic types, depeneding on parameter type
// If type=5, then random operator is choosen
int typeOfArithmetic( int type )
{
	srand( time(NULL) ); // seed random generator

	switch( type ) {
		case 1: 
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		case 4:
			return 4;
		case 5:
			return rand()%4 + 1;
		default: 
			return 0;
	}

}// end typeOfArithmetic function

long long resultOfArithmetic( long long number1, long long number2, int type )
{
	if( number2 == 0 && type == 4 ) 
	{
		cout << "Division with zero!" << endl;
		return 1;
	}
	

	switch( type ) 
	{
		case 1:	return number1 + number2;
		case 2: return number1 - number2;
		case 3: return number1 * number2;
		case 4: return number1 / number2;
		default:
			return 0;
	}
}
