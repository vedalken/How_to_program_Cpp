// function.h
// Function declaration.
#include <vector>

#ifndef FUNCTION_H
#define FUNCTION_H
// define size of squared chessboard
const int gChessboardSize = 7;

// check knights legal move on chessboard with "move"
// at current row and column position
// Also bounderies are checked!
// default, chessboard has no accessibility set, if not
// set access=1, so that move position is checked based on 
// accessibility value
int checkMove( 
	const int chessboard[][ ::gChessboardSize ], const int position[], 
	const int moveNumber, const bool access=0 );

// move to new position with known move number
void movePosition( int position[], const int moveNumber );

// check if position is legal, based on chessboard value
// and chessboard bounderies
int checkPosition( 
	int chessboard[][ ::gChessboardSize ], const int position[] );

// check chessboard boundaries
bool checkBoundaries( const int pos[] );

// display chessboard
void displayChessboard( const int chessboard[][ ::gChessboardSize ] );

// set current chessboard counter
void setChessboard( int chessboard[][ ::gChessboardSize ],
	const int position[] );

// reset chessboard values to 0
void resetChessboard( int [][ ::gChessboardSize ] );

// display array
void displayArray( std::vector<int> & );


// fill chessboard with accessibility for each square
void insertAccessibility( int accessibility[][ ::gChessboardSize ] );

// check for zero accessibility at position
bool checkAccessibility( const int accessibility[][ ::gChessboardSize ],
	const int position[] );

// set accessibility at current position
void setAccessibility( int accessibility[][ ::gChessboardSize ], 
	const int position[] );

// determine smallest accessibility at current position and set new
// position
void getMinAccessibility( const int accessibility[][ ::gChessboardSize ], 
	const int chessboard[][ ::gChessboardSize ], int position[] );

// recursive knight tour (with backtracing algorithm)
void knightTourR( int chessboard[][ ::gChessboardSize ], int position[] );

// iterative knight tour (with backtracing algorithm)
void knightTourI( int chessboard[][ ::gChessboardSize ], int position[] );

// recursive knight tour with accessibility counting
// Warnsdorff algorithm
void knightTourHeurestic( int accessibility[][ ::gChessboardSize ], 
	int chessboard[][ ::gChessboardSize ], int position[] );

// brute force calculatation of knight tour using random number
// to choose which path to take!
// function returns number of steps in a tour
int knightTourBruteForce( int chessboard[][ ::gChessboardSize ], int pos[] );
#endif
