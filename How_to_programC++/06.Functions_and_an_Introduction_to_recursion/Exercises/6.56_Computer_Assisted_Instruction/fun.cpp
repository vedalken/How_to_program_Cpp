// fun.cpp
// Implementating functions.
#include <iostream>
#include "fun.h" // function prototype
using std::cout; // iostream
using std::endl;
using std::cin;

// Display multiplication numbers and read user input
void displayMessage( int number1, int number2 )
{
	cout << "How much is " << number1 << " times " << number2 << "?  ";
}

// Display message for wrong answer
void displayAfterWrongAnswer()
{
	cout << "No. Please try again.";
}

// Display message for correct answer
void displayAfterCorrectAnswer()
{
	cout << "Very good!" << endl;
}
