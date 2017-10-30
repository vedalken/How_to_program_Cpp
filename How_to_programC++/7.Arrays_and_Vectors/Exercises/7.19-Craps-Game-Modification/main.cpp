// craps.cpp
// Program simulates popular game of chance, "craps".
// Program simulates craps N times, while counting
// wins, loses and number of rolls.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "crapsFunctions.h"
using std::cout; //iostream header
using std::endl;
using std::left;
using std::right;
using std::fixed;
using std::setw; // iomanip header
using std::setprecision;
using std::srand; //cstdlib header
using std::rand;
using std::time; // ctime header

// function prototype
int sumElements( const int [], const int );
void displayMarker( const int, char ='-' );

// Program execution begins with main
int main()
{
	const int nNumOfPlays = 30000; 			// number of playes
	int anCountRolls[ nNumOfPlays ] = {};	// count number of die roll
	int anCountWon[ nNumOfPlays ] = {};		// count number of wins in each play
	int anCountLose[ nNumOfPlays ] = {};	// count number of loses in each play

	// enumeration with constants that represents game status
	enum Status { CONTINUE, WON, LOST };

	srand( time(NULL) ); // initialize every second new seed
	
	// simulate craps N times, where N equals nNumOfPlays
	for ( int nGame = 0; nGame < nNumOfPlays; ++nGame )
	{
		Status gameStatus; 			// determine current game status: won, lose, continue(or point)
		int currentPoint = -1;		// save current point for continuation phase
		int sumOfDice = rollDice(); // current dice sum
		++anCountRolls[ nGame ];	// count dice roll
		
		// determine result in first roll
		// main algorithm process
		switch (sumOfDice) {
			case 7:		// win with 7 on first roll
			case 11:	// win with 11 on frist roll
				gameStatus = WON;
				++anCountWon[ nGame ];
				break;
			case 2:		// lose with 2 on first roll
			case 3:		// lose with 3 on first roll
			case 12:	// lose with 12 on first roll
				gameStatus = LOST;
				++anCountLose[ nGame ];
				break;
			default: // did not win or lose; remember point
				// continuation phase
				gameStatus = CONTINUE;
				currentPoint = sumOfDice;
				break;
		}

		// Continuation phase
		// You win if die sum equals "point" i.e. currentPoint
		// and lose if sum equals 7. If non of them is reached,
		// game continues.
		while (gameStatus == CONTINUE) 
		{
			sumOfDice = rollDice(); // roll die
			++anCountRolls[ nGame ];

			// determine game status
			if (sumOfDice == currentPoint) // player win
			{
				gameStatus = WON; 
				++anCountWon[ nGame ];
			}
			else if (sumOfDice == 7) // player lose
			{	
				gameStatus = LOST; 
				++anCountLose[ nGame ];
			}
		}
	}// end for loop
	
	// determine total number of wins, loses, rolls and average
	// game length
	const int nTotalWins  = sumElements( anCountWon, nNumOfPlays );
	const int nTotalLoses = sumElements( anCountLose, nNumOfPlays ); 
	const int nTotalRolls = sumElements( anCountRolls, nNumOfPlays ); 
	const double dAvgGameLength = 
		static_cast<double>(nTotalRolls) / nNumOfPlays;

	// display game info
	cout << "game info" << endl; 
	displayMarker( 42 ); // display 42 markers type "-"
	cout << setw(30) << left << "Total wins:" << setw(12) 
		<< right << nTotalWins << endl; 
	cout << setw(30) << left << "Total loses:" << setw(12) 
		<< right << nTotalLoses<< endl;
	cout << setw(30) << left << "Number of rolls:" << setw(12) 
		<< right << nTotalRolls << endl;
	cout << setw(30) << left << "Average game length:" << setw(12) 
		<< right << fixed << static_cast<int>(dAvgGameLength) << endl;

	return 0;	
}// end main function

////
////
//// sum elements in array
int sumElements( const int array[], const int arraySize )
{
	int sum = 0; // sum elements in array

	for ( int i = 0; i < arraySize; ++i )
		sum += array[ i ];
	
	return sum;
}//end sumElements function

////
////
//// display markers (default: '-') in length numOfMark
void displayMarker( const int numOfMark, char chMarkType )
{
	for ( int i = 0; i < numOfMark; ++i )
		cout << chMarkType;

	cout << endl; // new line
}// end displayMarker function
