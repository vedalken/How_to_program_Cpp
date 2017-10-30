// functions.cpp
// Definitions of functions.
#include <iostream>
#include "functions.h"
using std::cout; // iostream
using std::endl; 

// Funtion displays some basic game information
void displayMessage()
{
	cout << "I have a number between 1 and 1000." << endl
		 << "Can you guess my number?" << endl
		 << "Please type your first guess." 
		 << endl;
}

// Display information based on number of tries
// to guess correct number
void displayGuessMessage( int count )
{
	// For each count number display message
	if (count < 10) {
		cout << "Either you know the secret or you got lucky!" << endl;
	}	
	else if ( count == 10) {
		cout << "Ahah! You know the secret!" << endl;
	}
	else { // count > 10
		cout << "You should be able to do better!" << endl;
	}
}//end function displayGuessMessage
