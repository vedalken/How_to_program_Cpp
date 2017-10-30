// craps.cpp
// Program simulates popular game of chance, "craps".
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "crapsFunctions.h"
using std::cout;//iostream
using std::endl;
using std::cin;
using std::srand;//cstdlib
using std::rand;
using std::exit;
using std::time;// ctime

// Program execution begins with main
int main()
{
	cout << "----------- WELOME TO CRAPS ----------" << endl;
	
	// Display message if player would start game or not
	char startGame;
	cout << "Would you begin game? [y/n] ";
	cin >> startGame;
	
	// validation: determine correct input character
	if (startGame == 'n') {
		cout << "Exit games..." << endl;
		exit(0); // exit game
	}
	else if (startGame == 'y') {
		cout << "Press key to throw dice..." << endl;
		cin.get();
	}
	else {
		cout << "Unknown input! Exit." << endl;
		exit(0); // exit game
	}

	// enumeration with constants that represents game status
	enum Status { CONTINUE, WON, LOST };

	srand( time(NULL) ); // initialize every second new seed

	Status gameStatus; 			// determine current game status: won, lose, continue(or point)
	int currentPoint;			// save current point for continuation phase
	int sumOfDice = rollDice(); // current dice sum
	
	// determine result in first roll
	// main algorithm process
	switch (sumOfDice) {
		case 7:		// win with 7 on first roll
		case 11:	// win with 11 on frist roll
			gameStatus = WON;
			break;
		case 2:		// lose with 2 on first roll
		case 3:		// lose with 3 on first roll
		case 12:	// lose with 12 on first roll
			gameStatus = LOST;
			break;
		default:	// did not win or lose; remember point
			// continuation phase
			gameStatus = CONTINUE;
			currentPoint = sumOfDice;
			cout << "Point is " << currentPoint << endl;
			break;
	}

	// Continuation phase
	// You win if die sum equals "point" i.e. currentPoint
	// and lose if sum equals 7. If non of them is reached,
	// game continues.
	while (gameStatus == CONTINUE) 
	{
		cin.get(); // simulate rolling die
		sumOfDice = rollDice(); // roll die
		
		// determine game status
		if (sumOfDice == currentPoint) // player win
			gameStatus = WON; 
		else if (sumOfDice == 7) // player lose
			gameStatus = LOST; 
	}

	// Display player status: win or lose
	if (gameStatus == WON)
		cout << "Player wins." << endl;
	else
		cout << "Player lose." << endl;

	return 0;	
}
