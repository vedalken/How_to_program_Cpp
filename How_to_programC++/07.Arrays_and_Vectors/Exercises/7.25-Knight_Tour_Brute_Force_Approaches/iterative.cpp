// main.cpp
// Program computes Knight's Tour problem on
// empty chessboard (8x8).
#include <iostream>
#include "function.h" // functions declaration
using std::cout;
using std::endl;

int main()
{
	// declare chessboard horizontal and vertical length
	const int maxRows = ::gChessboardSize;	// chessboard size in horizontal (x) direction
	const int maxCols = ::gChessboardSize;	// chessboard size in vertical (y) direction
	int chessboard[ maxRows ][ maxCols ] = {};
	
	// starting position
	int pos[2] = { 0, 0 };	

	cout << "\nIterative knight tour..." << endl;
	// iterative knight tour
	knightTourI( chessboard, pos );
	displayChessboard( chessboard );

	return 0;
}//end main
