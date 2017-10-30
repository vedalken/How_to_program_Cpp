// main.cpp
// Implement n-queen problem.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "queen.h"
using std::cout; // iostream
using std::endl;
using std::vector; // vector
using std::srand; // cstdlib
using std::time; // ctime

int main()
{
	// initialize seed 
	srand( time(0) );

	// chessboard
	int board[ ::boardSize ][ ::boardSize ];
	init( board );
	
	// set accessibility board
	int access[ ::boardSize ][ ::boardSize ];
	init( board );
	fillAccess( access );
	
	// print accessibility 2D array with
	// 5 char spacing
	//print2D( access, 5 );
	//cout << "\n";
	
	for ( int queen = 0; queen < ::boardSize; ++queen )
	{
		int legal = queenMove( access );
		// look for any solution
		if ( legal < 0 )
		{
			fillAccess( access );
			// reset counter
			queen = -1;
		}
	}
	
	print2D( access, 2 );


	return 0;
}
