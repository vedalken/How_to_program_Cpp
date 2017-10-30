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
	
	// declare and initialize chessboard
	int chessboard[ maxRows ][ maxCols ] = {};
	
	// accessibility number at each chessboard position
	int accessibility[ maxRows ][ maxCols ] = {};
	
	// set accessibility values into initial two 
	// dimensional array
	insertAccessibility( accessibility );
	
	// starting position
	int pos[ 2 ] = { 0, 0 };
	
	//cout << "Recursive knight tour..." << endl;
	//// solve knight move with backtracing method
	//knightTourR( chessboard, pos );
	//displayChessboard( chessboard );
	
	// Warnsdorff algorithm	(heuristic)
	cout << "Heurestic knight tour..." << endl;
	knightTourHeurestic( accessibility, chessboard, pos );
	
	displayChessboard( chessboard );
	
	return 0;	
}//end main
