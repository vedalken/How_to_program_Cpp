// heuristic.cpp
// Warnsdorff algorithm is used!
// Heuristic approach to solve knight tour problem.
// Each square is rated by the number of accessibilities
// from other squares. Each corner has accessibility 2, 
// next to it, 3, 4, 6 and 8 (in the center of chessboard).
#include "function.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout; // iostream
using std::endl;
using std::srand; // cstdlib
using std::time; // ctime

int main()
{
	// initialize seed
	srand( time(0) );

	// chessboard dimensions
	const int maxRows = ::gChessboardSize;
	const int maxCols = ::gChessboardSize;
	const int maxTours = maxRows * maxCols;

	// declare and initialize chessboard
	int chessboard[ maxRows ][ maxCols ] = {};

	// starting position
	int pos[ 2 ] = { 0, 0 };
	int countTours = 0;
	unsigned long long totalTours = 0L; // total number of tours
	unsigned long long totalMoves = 0L; // total number of moves

	cout << "\nBrute force knight tour..." << endl;
	while ( countTours != maxTours )
	{
		++totalTours;
		resetChessboard( chessboard );
		countTours = knightTourBruteForce( chessboard, pos ); 
		totalMoves += countTours;
	}

	cout << "Total number of tours: " << totalTours << endl;
	cout << "Total number of moves: " << totalMoves << endl;

	cout << "\n";
	displayChessboard( chessboard );
	
	return 0;	
}//end main
