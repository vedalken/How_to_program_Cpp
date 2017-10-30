// queen.cpp
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include "queen.h"
using std::cout; // iostream
using std::endl;
using std::vector;
using std::setw; // iomnaip
using std::rand; // cstdlib

// initialize 2D array to -1 (by default)
// otherwise initialize board values by setting initVal
void init( int array[][ ::boardSize ], const int initVal )
{
	for ( int i = 0; i < ::boardSize; ++i )
		for ( int j = 0; j < ::boardSize; ++j )
			array[ i ][ j ] = initVal;
}

// display 2D array with spacing "space"
void print2D( int array[][ ::boardSize ], const int space )
{
	for ( int i = 0; i < ::boardSize; ++i ) 
	{
		for ( int j = 0; j < ::boardSize; ++j )
			cout << setw( space ) << array[ i ][ j ];
		
		cout << "\n";
	}
}

// check chessboard boundaries
bool checkBounds( const int pos[] )
{
	if ( (pos[0] < 0) || (pos[0] >= ::boardSize) ) return 0;
	if ( (pos[1] < 0) || (pos[1] >= ::boardSize) ) return 0;
	return 1;
}

// check chessboard boundaries
bool checkBounds( const vector<int> & pos )
{
	if ( (pos[0] < 0) || (pos[0] >= ::boardSize) ) return 0;
	if ( (pos[1] < 0) || (pos[1] >= ::boardSize) ) return 0;
	
	return 1;
}

// calculate number of queen legal moves included
// starting position counted
// 8 possible queen moves direction but all possible queen position
// are stored into "queenLegPos"
void getQueenMoves( 
	const int access[][ ::boardSize ], const vector<int> & pos, 
	vector< vector<int> > & queenLegPos )
{
	if ( access[ pos[0] ][ pos[1] ] <= 0 )
		return;
	
	// check boundaries
	if ( ! checkBounds( pos ) ) 
	{
		cout << "getQueenMoves: Illegal position!" << endl;
		return;
	}
	
	queenLegPos.clear();

	// initial position is count as queen's legal move
	queenLegPos.push_back( pos );

	// queen position
	const int queenRow = pos[0];
	const int queenCol = pos[1];

	// direction vector: (0, 1) and (0, -1)
	// fixed row position, columns are varied
	for ( int col = 0; col < ::boardSize; ++col )
	{
		// skip starting queen position
		if ( col == queenCol )
			continue;

		// temporary position
		vector<int> tmpPos;
		tmpPos.push_back( queenRow );
		tmpPos.push_back( col );
		// check legal move: chessboard values
		if ( access[ queenRow ][ col ] > 0 ) 
			queenLegPos.push_back( tmpPos );
	}

	// direction vector: (1,0) and (-1,0)
	// fixed column, rows not fixed
	for ( int row = 0; row < ::boardSize; ++row )
	{
		// skip starting position
		if ( row == queenRow )
			continue;
		// temporary position
		vector<int> tmpPos;
		tmpPos.push_back( row );
		tmpPos.push_back( queenCol );
		// check legal move: chessboard values
		if ( access[ row ][ queenCol ] > 0 ) 
			queenLegPos.push_back( tmpPos );
	}
	
	// direction vector: (1,1) 
	// (diagonal vector with -pi/4 angle declination)
	// column and row not fixed
	for ( int row = queenRow+1, col = queenCol+1; 
		(row < ::boardSize) && (col < ::boardSize); ++row, ++col )
	{
		// temporary position
		vector<int> tmpPos;
		tmpPos.push_back( row );
		tmpPos.push_back( col );

		// check legal queen move
		if ( checkBounds( tmpPos ) && access[ row ][ col ] > 0 ) 
			queenLegPos.push_back( tmpPos );
	}
	
	// direction vector: (-1,-1) 
	// (diagonal vector with 3*pi/4 angle declination)
	// column and row not fixed
	// Note: --row, --col somewhat equivalent to direction (-1,1)
	for ( int row = queenRow-1, col = queenCol-1; 
		(row >= 0) && (col >= 0); --row, --col )
	{
		// temporary position
		vector<int> tmpPos;
		tmpPos.push_back( row );
		tmpPos.push_back( col );

		// check legal queen move
		if ( checkBounds( tmpPos ) && access[ row ][ col ] > 0 ) 
			queenLegPos.push_back( tmpPos );
	}
	
	// direction vector: (-1,1) 
	// (diagonal vector with pi/4 angle declination)
	// column and row not fixed
	for ( int row = queenRow-1, col = queenCol+1; 
		(row >=0) && (col < ::boardSize); --row, ++col )
	{
		// temporary position
		vector<int> tmpPos;
		tmpPos.push_back( row );
		tmpPos.push_back( col );

		// check legal queen move
		if ( checkBounds( tmpPos ) && access[ row ][ col ] > 0 ) 
			queenLegPos.push_back( tmpPos );
	}
	
	// direction vector: (1,-1) 
	// (diagonal vector with -3*pi/4 angle declination)
	// column and row not fixed
	for ( int row = queenRow+1, col = queenCol-1; 
		(row < ::boardSize) && (col >=0); ++row, --col )
	{
		// temporary position
		vector<int> tmpPos;
		tmpPos.push_back( row );
		tmpPos.push_back( col );

		// check legal queen move
		if ( checkBounds( tmpPos ) &&  access[ row ][ col ] > 0 ) 
			queenLegPos.push_back( tmpPos );
	}
	
	//for ( int i = 0; i < (int)queenLegPos.size(); ++i )
	//	cout << queenLegPos[i][0] << " , " << queenLegPos[i][1] << endl;
}//end getQueenMoves function

// fill chessboard with queens accessibilities at
// each position
void fillAccess( int accessibility[][ ::boardSize ] )
{
	// create temporary empty chessboard
	int emptyBoard[ ::boardSize ][ ::boardSize ];
	init( emptyBoard, 9999 );
	
	// temporary queen position
	vector<int> tmpPos;
	// 2D vector of queen's legal positions
	vector< vector<int> > queenMoves;

	for ( int row = 0; row < ::boardSize; ++row )
	{
		for ( int col = 0; col < ::boardSize; ++col )
		{
			tmpPos.clear();
			queenMoves.clear();
			rowcol2Vec( row, col, tmpPos );
			getQueenMoves( emptyBoard, tmpPos, queenMoves );
			// fill accessibility as total number of
			// legal queen moves
			accessibility[ row ][ col ] = queenMoves.size();
		}
	}
}

// re-evaluate accessibility of each position
void getAccess( int access[][ ::boardSize ] )
{
	// temporary queen position
	vector<int> tmpPos;
	// 2D vector of queen's legal positions
	vector< vector<int> > queenMoves;
	
	for ( int row = 0; row < ::boardSize; ++row )
	{
		for ( int col = 0; col < ::boardSize; ++col )
		{
			tmpPos.clear();
			queenMoves.clear();
			rowcol2Vec( row, col, tmpPos );
			getQueenMoves( access, tmpPos, queenMoves );
			if ( queenMoves.size() > 0 )
				access[ row ][ col ] = queenMoves.size();
		}
	}
}

// check accessibility values if correct
bool checkQueens( int access[][ ::boardSize ] )
{
	vector<int> tmpPos;
	vector< vector<int> > queenMoves;
	
	// create temporary accessibility board with positive numbers
	int board[ ::boardSize ][ ::boardSize ];
	init( board, 0 );
	
	for ( int row = 0; row < ::boardSize; ++row )
	{
		for ( int col = 0; col < ::boardSize; ++col )
		{
			if ( access[ row ][ col ] < 0 )
				board[ row ][ col ] = 1;
		}
	}
	
	print2D( board, 3 );
	cout << "\n\n";	

	for ( int row = 0; row < ::boardSize; ++row )
	{
		for ( int col = 0; col < ::boardSize; ++col )
		{
			//cout << row << "," << col << endl;
			// test only queens
			if ( board[ row ][ col ] == 1 )
			{
				tmpPos.clear();
				queenMoves.clear();
				rowcol2Vec( row, col, tmpPos );
				getQueenMoves( board, tmpPos, queenMoves );
				cout << queenMoves.size() << endl;
			}
		}
	}
	
	return 1;
}

// determine smallest accessibility value
int getMinAccess( const int accessibility[][ ::boardSize ] )
{
	// minimal accessibility
	int minAccess = 9999;

	for ( int row = 0; row < ::boardSize; ++row )
	{
		for ( int col = 0; col < ::boardSize; ++col )
		{
			// check only occupied positions
			if ( accessibility[ row ][ col ] > 0 &&
				accessibility[ row ][ col ] < minAccess )
			{
				minAccess = accessibility[ row ][ col ];
			}
		}
	}
	
	// return smallest accessibility
	return minAccess;
}

// get smallest accessibility positions
void getMinAccess( const int accessibility[][ ::boardSize ],
	vector< vector<int> > & minAccessPos )
{
	minAccessPos.clear();
	// minimal accessibility
	const int minAccess = getMinAccess( accessibility );
	
	// temporary vector of minimal accessibility
	vector<int> tmpMinAccessPos;

	for ( int row = 0; row < ::boardSize; ++row ) {
		for ( int col = 0; col < ::boardSize; ++col ) 
		{
			if ( accessibility[ row ][ col ] == minAccess )
			{
				tmpMinAccessPos.clear();
				rowcol2Vec( row, col, tmpMinAccessPos );
				minAccessPos.push_back( tmpMinAccessPos );
			}
		}
	}
}

// algorithm how to choose minimal accessibility if there are
// more than one
// simplest is by randomly choosing any position
void chooseMinAccess( vector< vector<int> > & minAccessPos )
{
	// only one minimal accessibility
	if ( minAccessPos.size() <= 1 )
		return;
	
	// number positions with same accessibility 
	int countSameAccess = minAccessPos.size();
	// randomly choose index position
	int indexPos = rand() % countSameAccess;
	
	vector< vector<int> > tmpPos;
	tmpPos.push_back( minAccessPos[ indexPos ] );
	minAccessPos.clear();
	minAccessPos.push_back( tmpPos[0] );
}

// make queen move
// first is choosen minimal accessibility which is at same time
// queen's legal position (getMinAccess(), chooseMinAccess() )
// determine positions where queen can access from current position
// ( getQueenMoves )
//
// queen position accessibility occupation is -1
void queenPosMove( int access[][ ::boardSize ], vector<int> & queenPos )
{
	// count root queen
	static int pass = 1;
	
	if ( queenPos.size() == 0 ) {
		cout << "No position found!" << endl;
		return;
	}
	else if ( queenPos.size() > 2 ) {
		cout << "Unknwon position!" << endl;
		return;
	} 
	
	if ( access[ queenPos[0] ][ queenPos[1] ] <= 0 ) {
		cout << "Already used position!" << endl;
		return;
	}

	// queen legal positions
	vector< vector<int> > queenLegMovePos;
	getQueenMoves( access, queenPos, queenLegMovePos );	
	
	for ( size_t i = 0; i < queenLegMovePos.size(); ++i ) 
	{
		int row = queenLegMovePos[i][0];
		int col = queenLegMovePos[i][1];
		if ( row == queenPos[0] && col == queenPos[1] )
		{
			queenLegMovePos.erase( queenLegMovePos.begin() + i );
			--i;
			break;
		}
	}
	
	//cout << "queen leg move size: " << queenLegMovePos.size() << endl;

	if ( pass == 1 ) {
		// set queen position accessibility occupation to -1
		access[ queenPos[0] ][ queenPos[1] ] = -1;	
	}
	else {
		access[ queenPos[0] ][ queenPos[1] ] = 0;	
	}

	// decrement accessibility
	for ( size_t i = 0; i < queenLegMovePos.size(); ++i ) 
	{
		if ( !checkBounds( queenLegMovePos[i] ) )
		{
			cout << "[queenMove]: Illegal move." << endl;
			break;
		}
		int row = queenLegMovePos[i][0];
		int col = queenLegMovePos[i][1];
		--access[ row ][ col ];
	}
	
	// one recursive depth
	if ( pass == 1 ) 
	{
		for ( size_t i = 0; i < queenLegMovePos.size(); ++i ) {
			++pass;
			queenPosMove( access, queenLegMovePos[ i ] );
		}
		pass = 1;
	}
}

// queen move
int queenMove( int access[][ ::boardSize ] )
{
	// queen starting position: row, column
	vector< vector<int> > queenPos;

	// determine min accessibility
	getMinAccess( access, queenPos );
	chooseMinAccess( queenPos );
	
	// reset accessibility values
	// look for any solution
	if ( queenPos.size() <= 0 )
		return -1;

	// change accessibility
	queenPosMove( access, queenPos[0] );
	//getAccess( access );

	return 0;
}
