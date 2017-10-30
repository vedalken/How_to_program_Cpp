// main.cpp
// Program plays game "guess the number".
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.h"
using std::cout; 	//iostream
using std::endl;
using std::cin;
using std::srand;	//cstdlib
using std::time;	//ctime

// generate random number between 1 and 1000
int inline genNumber() { 
	return (1 + rand() % 1000); 
}

// begin program execution with main function
int main()
{
	// Every time program runs, different seed is used, based
	// on computer time (current time)
	srand( time(NULL) );
	
	int number = 0; 
	int guess = 0;			// guessed number
	int count = 0;			// count number of guess
	number = genNumber();	// generated random number
	displayMessage();		// display information	

	do{
		cin >> guess; 	// read input number
		++count;		// count number of guesses

		if (guess > number) {
			cout << "To high. Try again." << endl;
		}
		else if (guess < number) {
			cout << "To low. Try again." << endl;
		}
		else {
			displayGuessMessage( count ); // display message based on count number
			cout << "Excellent! You guessed the number!" << endl
				 << "Would you like to play again (y or n)? ";
			char answer;
			cin >> answer;

			if (answer == 'y') // play again
			{
				number = genNumber();
				displayMessage();
			}
		}
	} while( guess != number );

	return 0;	
}// end main function
