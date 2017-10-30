// queen.h
#ifndef QUEEN_H
#define QUEEN_H
#include <vector>
using std::vector;

// chessboard size
const int boardSize = 8;

// convert row and col into vector (as vector of position)
inline void rowcol2Vec( 
	const int row, const int col, vector<int> & pos ) {
	pos.push_back( row );
	pos.push_back( col );
}

void init( int [][ ::boardSize ], const int = 0 );
void print2D( int [][ ::boardSize ], const int );
bool checkBounds( const int [] );
bool checkBounds( const vector<int> & );

void getQueenMoves( 
	const int [][ ::boardSize ], const vector<int> &, 
	vector< vector<int> > & );

// fill with accessibility
void fillAccess( int [][ ::boardSize ] );
void getAccess( int [][ ::boardSize ] );
bool checkQueens( int [][ ::boardSize] );

// determine smallest accessibility value
int getMinAccess( const int [][ ::boardSize ] );

// get positions with smallest accessibility
void getMinAccess( 
	const int [][ ::boardSize ], vector< vector<int> > & );

void chooseMinAccess( vector< vector<int> > & );

void queenPosMove( int [][ ::boardSize ], vector<int> & );
int queenMove( int [][ ::boardSize ] );
#endif
