#include <iostream>
#include <cstdlib>
#include "crapsFunctions.h"
using std::cout; // iostream
using std::endl;
using std::rand; //cstdlib

// Simulates two rolling dices; return sum of die values
int rollDice() {
	// generate two random numbers
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;

	// compute sum of die values
	int sum = die1 + die2;
	
	// display sum
	cout << "Player rolled " << die1 << " + " << die2 << " = " << sum << endl;

	return sum;
}
