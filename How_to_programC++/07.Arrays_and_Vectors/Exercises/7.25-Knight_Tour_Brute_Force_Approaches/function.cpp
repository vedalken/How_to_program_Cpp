// function.cpp
// Function implementations.
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include "function.h"
using std::cout; 	// iostream header
using std::endl;
using std::setw; 	// iomanip header
using std::vector; 	// vector header
using std::exit; 	// cstdlib header
using std::rand;

int checkMove( const int anBoard[][ ::gChessboardSize ], 
	const int pos[], const int moveNumber, const bool access )
{
	// check if "moveNumber" is legal:
	// 		- check bounds
	// 		- check for already occupied position
	
	// temporary new position
	int tmp[2] = { pos[0], pos[1] };
	movePosition( tmp, moveNumber );

	// bounds checking
	// check row bounds after move
	if ( !checkBoundaries( tmp ) )
		return 0;
	
	// check chessboard occupation position
	// chessboard with non zero values are occupied positions
	if ( !access ) // no accessibility set
	{
		if ( anBoard[ tmp[0] ][ tmp[1] ] != 0 )
			return 0;
	}
	else {
		if ( anBoard[ tmp[0] ][ tmp[1] ] == 0 )
			return 0;
	}
	// move is legal!
	return 1;
}// end checkMove function

///
///
void movePosition( int pos[], const int moveNumber )
{
	// knights possible moves 
	static const int dx[ 8 ] = {  2,  1, -1, -2, -2, -1, 1, 2 };
	static const int dy[ 8 ] = { -1, -2, -2, -1,  1,  2, 2, 1 };
	pos[0] += dy[ moveNumber ];
	pos[1] += dx[ moveNumber ];
}

///
///  
int checkPosition( int chessboard[][ ::gChessboardSize ], const int pos[] )
{
	// boundarise check
	bool bounds = checkBoundaries( pos );
	if ( !bounds )	
		return 0;

	// check chessboard value at same position
	// for zero value, move is legal
	int chessboardValue 
		= chessboard[ pos[0] ][ pos[1] ];
	
	// legal move
	if ( chessboardValue == 0 ) 
		return 1;
	
	// illegal move
	return 0;
}//end checkPosition

///
///
bool checkBoundaries( const int pos[] )
{
	// boundarise check
	if ( (pos[0] < 0) || (pos[0] >= ::gChessboardSize) ) {
		return 0;
	}
	
	if ( (pos[1] < 0) || (pos[1] >= ::gChessboardSize) ) {
		return 0;
	}

	// correct boundaries	
	return 1;
}// end checkBoundaries function

///
/// display chessboard
void displayChessboard( const int chessboard[][ ::gChessboardSize ] ) 
{
	for ( int i = 0; i < ::gChessboardSize; ++i )
	{
		for ( int j = 0; j < ::gChessboardSize; ++j )
			cout << setw( 4 ) << chessboard[ i ][ j ];
		
		cout << endl; // new line
	}

	cout << endl; // new line
}//end displayChessboard function

///
/// set chessboard counter at current position
void setChessboard( int chessboard[][ ::gChessboardSize ],
	const int pos[] )
{
	// count chessboard knight moves
	static int counter = 0;
	const int size = (::gChessboardSize) * (::gChessboardSize);
	
	// check if position is legal
	int legal = checkPosition( chessboard, pos );
	
	if ( legal ) {
		++counter;
		chessboard[ pos[0] ][ pos[1] ] = counter;
	}
	else {
		cout << "[setChessboard] Warrning:"
			 << " current chessboard position is not legal!\n";
		displayChessboard( chessboard );
		exit(1);
	}
	
	if (counter > size) {
		cout << "[setChessboard] Warrning: counter" 
			 << "reached maximal value\n";
		displayChessboard( chessboard );
		exit(1);
	}
}// end setChessboard function

///
/// reset chessboard 
void resetChessboard( int chessboard[][ ::gChessboardSize ] )
{
	static const int size = ::gChessboardSize;

	for ( int row = 0; row < size; ++row )
		for ( int col = 0; col < size; ++col )
			chessboard[ row ][ col ] = 0;
}

////
////
//// display array
void displayArray( vector<int> & array )
{
	for ( size_t i = 0; i < array.size(); ++i )
		cout << setw( 3 ) << array[ i ];
	
	cout << endl; // new line
}// end displayArray function


///
/// fill chessboard with accessibility
void insertAccessibility( int accessibility[][ ::gChessboardSize ] )
{
	const int size = ::gChessboardSize;
	
	// empty chessboard
	const int emptyChessboard[ size ][ size ] = {};

	for ( int row = 0; row < size; ++row ) 
	{
		for ( int col = 0; col < size; ++col ) 
		{
			int count = 0; // count legal moves
			int legal = 0; // check if move is legal
			int pos[2] = { row, col };

			for ( int move = 0; move < 8; ++move )
			{
				legal = checkMove( emptyChessboard, pos, move );
				if ( legal ) {
					++count;
				} else {
					continue;
				}
			}

			accessibility[ pos[0] ][ pos[1] ] = count;
		}
	}
}//end insertAccessibility function

///
///
/// check accessibility
bool checkAccessibility( const int accessibility[][ ::gChessboardSize ], 
	const int pos[] )
{
	if ( accessibility[ pos[0] ][ pos[1] ] == 0 ) 
		return 1;

	// no zero element found!
	return 0;
}// end checkAccessibility function

///
/// set accessibility value
/// set at current position, accessibility value to 0,
/// and others to which it can be accessed, decrement 
/// by one
void setAccessibility( int accessibility[][ ::gChessboardSize ],
	const int pos[] )
{
	static int countTour = 0;
	const int size = (::gChessboardSize) * (::gChessboardSize);

	// for zero accessibility, exit program
	if ( accessibility[ pos[0] ][ pos[1] ] == 0 ) 
	{
		cout << "[setAccessibility] Warning:" 
			<< " 0 accessibility encountered" << endl;
		displayChessboard( accessibility );
		return;
	}

	// temporary new position
	int npos[2] = {};

	// Last two legal move do not decrement accessibility, 
	// only set current accesibility to zero! 
	if ( countTour < (size-2) )
	{
		// decrement all others accessibility number to which current 
		// position is accessible
		for ( int move = 0; move < 8; ++move )
		{
			// check if move is legal (boundaries and accessibility > 0)
			int isLegal = checkMove( accessibility, pos, move, 1 );
			
			if ( isLegal ) 
			{
				npos[0] = pos[0];
				npos[1] = pos[1];
				movePosition( npos, move );

				if ( accessibility[ npos[0] ][ npos[1] ] > 0 )
					--accessibility[ npos[0] ][ npos[1] ];
			}
		}
	}

	// set current accessibility to zero
	if ( accessibility[ pos[0] ][ pos[1] ] > 0 ) 
	{
		++countTour;
		accessibility[ pos[0] ][ pos[1] ] = 0;
	}
}// end setAccessibility function

///
/// determine minimal accessibility and set new position
/// Function returns move number
void getMinAccessibility( const int accessibility[][ ::gChessboardSize ],
	const int chessboard[][ ::gChessboardSize ], int pos[] )
{
	// remember each legal move with same accessibility value
	vector<int> vecAccessValues;
	vector<int> vecAccessMove;

	// maximal accessibility number is 8 and minimal 2!
	int minAccess = 9;
	
	// determine minimal accessibility
	for ( int move = 0; move < 8; ++move ) 
	{
		// check if move is legal: bondaries and chessboard occupation
		int isLegal = checkMove( chessboard, pos, move );
		
		// legal move
		if ( isLegal ) 
		{
			// new position
			int npos[2] = { pos[0], pos[1] };
			movePosition( npos, move );

			// accessibility value
			int accessValue = accessibility[ npos[0] ][ npos[1] ];

			// accessibility current position has reached all
			// possible occupations. Try next move.
			if ( accessValue == 0 )
				continue;
			
			vecAccessValues.push_back( accessValue );
			vecAccessMove.push_back( move );
		}//end if condition
	}//end for loop
	
	// find smallest value
	for ( size_t i = 0; i < vecAccessValues.size(); ++i )
	{
		if ( minAccess > vecAccessValues.at( i ) )
			minAccess = vecAccessValues.at( i );
	}

	// delete all those bigger than minimal accessibility value
	for ( size_t i = 0; i < vecAccessValues.size(); ++i )
	{
		if ( vecAccessValues.at( i ) > minAccess ) 
		{
			vecAccessValues.erase( vecAccessValues.begin() + i );
			vecAccessMove.erase( vecAccessMove.begin() + i );
			--i;
		}
	}
	
	// now remains only those (or only one) with smallest
	// accessibility
	// In this case, case of tie, any of these moves are legal!
	// How to choose them is up to you!!!
	// I use, trivial decision, simple random pick.
	//	
	// move number with minimal accessibility
	int accessMoveNumber = -1;
	
	if ( vecAccessValues.size() > 1 ) 
	{
		// number of tied moves
		const unsigned numOfTieMoves = vecAccessValues.size();
		
		// randomly choose one element with those values
		int element = rand() % numOfTieMoves;
		accessMoveNumber = vecAccessMove.at( element );
	}
	else if ( vecAccessValues.size() == 1 ) {
		accessMoveNumber = vecAccessMove.back();
	}
	else {
		return;
	}
	
	// set new position with move number "accessMoveNumber"
	// If there is exactly one move, than this has already
	// smallest accessibility number
	movePosition( pos, accessMoveNumber );
}// end getMinAccessibility function

///
///
void knightTourHeurestic( int accessibility[][ ::gChessboardSize ],
	int chessboard[][ ::gChessboardSize ], int pos[] )
{
	// temporary position
	int tpos[2] = { pos[0], pos[1] };
	int count = 1;
	// try knight tour until zero accessibility is found: 
	// found knight tour or no knight tour. 
	// Current position accessibility set to 0,
	// decrement others accessibile position accessibility value, 
	// set chessboard counter at current position and
	// set new position
	
	while ( accessibility[ tpos[0] ][ tpos[1] ] > 0 )
	{
		//cout << setw(3) << count << ":"
		//	<< setw(7) << accessibility[ tpos[0] ][ tpos[1] ]
		//	<< setw(10) << "(" << tpos[0] << "," << tpos[1] << ")" << endl;
		
		// put knight tour counter at position "tpos"
		// on chessboard-only legal moves are allowed!
		setChessboard( chessboard, tpos );
		// decrement accessibility for legal moves at
		// position "tpos" - current position accessibility
		// value is set to 0
		setAccessibility( accessibility, tpos );
		// move to new position with smallest accessibility 
		// number
		getMinAccessibility( accessibility, chessboard, tpos );
		++count;
	}
}// end getMoveNumberMinAccessibility

///
///
void knightTourR( int chessboard[][ ::gChessboardSize ], int pos[] )
{
	// count knight tour movements
	static int countTour = 1;
	static int totalTour = (::gChessboardSize) * (::gChessboardSize);
	static const int dx[ 8 ] = {  2,  1, -1, -2, -2, -1, 1, 2 };
	static const int dy[ 8 ] = { -1, -2, -2, -1,  1,  2, 2, 1 };
	
	// end of tour
	if ( countTour == totalTour+1 ) {
		displayChessboard( chessboard );
		exit(0);
	}
	else if ( countTour < 0 ) {
		cout << "Count tour is negative!" << endl;
		exit(1);
	}
	
	// check if position is legal
	int legalPosition
		= checkPosition( chessboard, pos );

	// illegal move i.e. out of boundaries or
	// chessboard value is nonzero!
	if ( legalPosition == 0 ) {
		return;
	}
	
	// legal move
	chessboard[ pos[0] ][ pos[1] ] = countTour;
	++countTour;
	// new position
	int npos[2] = { 0, 0 };
	// move number
	int move = 0;	

	for ( move = 0; move < 8; ++move ) {
		// new position
		npos[0] = pos[0] + dy[ move ]; 
		npos[1] = pos[1] + dx[ move ];
		knightTourR( chessboard, npos );
	}
	
	// all available moves were check
	// decrement knight tour counter
	if ( move > 7 ) {
		chessboard[ pos[0] ][ pos[1] ] = 0;
		--countTour;
	}
}// end moveKnightR function

///
/// iterative knight tour
void knightTourI( int chessboard[][ ::gChessboardSize ], int pos[] )
{
	// count knight tour movements
	int countTour = 0;
	const int totalTour = (::gChessboardSize) * (::gChessboardSize);
	const int dx[ 8 ] = {  2,  1, -1, -2, -2, -1, 1, 2 };
	const int dy[ 8 ] = { -1, -2, -2, -1,  1,  2, 2, 1 };

	// check if current position is legal,
	// much likely it is!
	int legalPosition
		= checkPosition( chessboard, pos );
	// illegal move i.e. out of boundaries or
	// chessboard value is nonzero!
	if ( legalPosition == 0 ) 
		return;
	
	// legal move
	++countTour;
	chessboard[ pos[0] ][ pos[1] ] = countTour;
	
	// vector of move numbers has size 1 less than total
	// number of maximal legal moves
	vector<int> vecKnightMove;	// knight move number
	vector<int> vecKnightRow;	// knight row position
	vector<int> vecKnightCol;	// knight column position
	//
	// save starting position
	vecKnightRow.push_back( pos[0] );
	vecKnightCol.push_back( pos[1] );

	// loop until knight tour is complete
	while ( countTour < totalTour)
	{
		if ( countTour < 0 ) {
			cout << "Tour counter is negative!" << endl;
			break;
		}
		
		int move = 0;		// move position
		int npos[2] = {}; 	// new position, after move
		//
		// previous move number is used for backtracing
		// Until is move legal start from zero move, otherwise
		// start from previous move number, saved in vector
		static int prevMove = 0;

		for ( move = prevMove; move < 8; ++move ) 
		{
			// new position, legal or not
			npos[0] = pos[0] + dy[ move ];
			npos[1] = pos[1] + dx[ move ];

			legalPosition = 
				checkPosition( chessboard, npos );
			
			// check for legal move position
			if ( legalPosition ) {
				// new legal position
				pos[0] = npos[0]; 
				pos[1] = npos[1]; 
				// save position and move number
				vecKnightRow.push_back( pos[0] );
				vecKnightCol.push_back( pos[1] );
				vecKnightMove.push_back( move );
				// increment tour counter for legal move
				++countTour;
				// set chessboard counter value
				chessboard[ pos[0] ][ pos[1] ] = countTour;
				// legal moves starts with zero move
				prevMove = 0; 
				break;
			}
		}

		// try next move at new position
		if ( move >= 0 && move < 8 )
			continue;
		
		// backtracing
		// all move position are illegal 
		if ( move > 7 )
		{
			// delete last saved position, and move number
			int currentRow = vecKnightRow.back();
			int currentCol = vecKnightCol.back();
			// reset chessboard value to 0
			chessboard[ currentRow ][ currentCol ] = 0;
			// remember move number, incremented by 1
			prevMove = vecKnightMove.back()+1;
			// remove last element
			vecKnightRow.pop_back();
			vecKnightCol.pop_back();
			vecKnightMove.pop_back();
			// reset to previous position
			pos[0] = vecKnightRow.back();
			pos[1] = vecKnightCol.back();
			// decrement tour counter by one
			--countTour;
		}
	}// end while loop counting tour
}// end knightTourI function

int knightTourBruteForce( int chessboard[][ ::gChessboardSize ], int pos[] )
{
	// count knight tour movements
	int countTour = 0;
	const int totalTour = (::gChessboardSize) * (::gChessboardSize);
	
	// temporary position
	int tmppos[2] = { pos[0], pos[1] };

	// check if current position is legal,
	// much likely it is!
	int legalPosition = checkPosition( chessboard, tmppos );

	// illegal move i.e. out of boundaries or
	// chessboard value is nonzero!
	if ( legalPosition == 0 ) 
		return 0;
	
	// legal move
	++countTour;
	chessboard[ tmppos[0] ][ tmppos[1] ] = countTour;
	
	while (countTour <= totalTour)
	{
		const unsigned maxMoves = 8;
		int randMove 		= -1; 	// random move number
		int countRandMove 	= 0;	// count random move number generation 
		vector<int> vecRandMove;	// remember random number for illegal moves
		
		// random choose move number
		// loop continues until all available numbers are used
		while ( vecRandMove.size() != maxMoves )
		{
			countRandMove = 0;
			randMove = rand() % maxMoves; // 0 to 7
			
			// check if move number is legal
			int isLegal = checkMove( chessboard, tmppos, randMove );
			
			// legal move number is found; exit loop
			if ( isLegal ) 
				break;

			// check for any already generated number
			for ( size_t i = 0; i < vecRandMove.size(); ++i )
			{
				if ( vecRandMove[ i ] == randMove )
					++countRandMove;
			}

			// number was not generated yet - save into
			// vector
			if ( countRandMove == 0 )
				vecRandMove.push_back( randMove );
			
			if ( vecRandMove.size() == maxMoves )
				return countTour;
		}

		// check if there is available legal move
		// break loop is move is illegal
		if ( randMove < 0 || randMove >= static_cast<int>(maxMoves) )
			break;

		// legal move
		// increment tour counter, move to new position, 
		// set chessboard value
		++countTour;
		movePosition( tmppos, randMove );
		chessboard[ tmppos[0] ][ tmppos[1] ] = countTour;
	}// end while loop countTour
	
	return countTour;
}// end knightTourBruteForce
