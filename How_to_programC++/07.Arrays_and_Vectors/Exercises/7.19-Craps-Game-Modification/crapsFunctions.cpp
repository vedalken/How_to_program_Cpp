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
	
	return die1 + die2;
}
