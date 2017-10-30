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
