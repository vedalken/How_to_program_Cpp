// turtle.cpp
// Turle functions implementation.
#include <iostream>
#include <iomanip>
#include <cmath>
#include "turtle.h"
using std::cout; // iostream
using std::endl;
using std::left;
using std::setw; // iomanip
using std::fabs;

// display turtle graphics commands
void displayCommands()
{
	// display 37 "-" markers
	displayMarker( 42 );
	
	// output description
	cout << left << setw(12) << "Command" << setw(30) << "Meaning" << endl;
	
	displayMarker( 42 );
	
	// print commands
	cout << left 
		<< setw(12) << 1 << setw(30) << "Pen up" << endl
		<< setw(12) << 2 << setw(30) << "Pen down" << endl
		<< setw(12) << 3 << setw(30) << "Turn right" << endl
		<< setw(12) << 4 << setw(30) << "Turn left" << endl
		<< setw(12) << 5 << setw(30) << "Move forward 10 spaces" << endl
		<< setw(12) << 6 << setw(30) << "Print array" << endl
		<< setw(12) << 9 << setw(30) << "End of data" << endl;
	
	displayMarker( 42 );
}//end displayCommands

// display N characters, where N=numberOfChars
void displayMarker( const int numberOfMarkers, char ch )
{
	for ( int i = 0; i < numberOfMarkers; ++i )
		cout << ch;

	cout << endl; // new line
}//end displayMarker function

// set floor (initialize to false, by default)
// to change setFloor values, setValue=true
void setFloor( bool abFloor[][ gFloorWidth ], bool setValue )
{
	const int width = ::gFloorWidth;

	for ( int row = 0; row < width; ++row )
		for ( int column = 0; column < width; ++column )
			abFloor[ row ][ column ] = setValue;
}//end setFloor function

// print floor with marker
// empty values are spaces, while others are specified marker types
void printFloor( const bool abFloor[][ gFloorWidth ], char marker )
{
	const int width = ::gFloorWidth;
	
	for ( int row = 0; row < width; ++row )
	{
		for ( int column = 0; column < width; ++column )
		{
			if ( abFloor[ row ][ column ] )
				cout << " " << marker;
			else
				cout << "  ";
		}
		cout << endl; // print new line
	}
}//end printFloor function

////
//// turn turtle left
//// function changes direction vector or unity vector after turning
//// Function takes direction vector and vector dimension
void left( int dir[] )
{
	// new computed direction after rotation
	// first is y, second is x
	int newDir[ 2 ] = { 0, 0 };

	// rotation is computed based on rotational matrix with 
	// rotating angle equals -90 degrees, based on coordinate
	// system 
	// old system direction is {x,y}, new system direction {x',y'}
	// is computed as:
	// { x', y' } = { y, -x }
	// definition: dir[0] = y, dir[1] = x
	newDir[ 0 ] = - dir[ 1 ]; // y'
	newDir[ 1 ] = 	dir[ 0 ]; // x'
	
	// replace old direction with new
	dir[ 0 ] = newDir[ 0 ]; 
	dir[ 1 ] = newDir[ 1 ];	
}//end turn left

////
//// turn turtle right
//// function changes direction vector or unity vector after turning
//// Function takes direction vector and vector dimension
void right( int dir[] )
{
	// new computed direction after rotation
	int newDir[ 2 ] = { 0, 0 };

	// rotation is computed based on rotational matrix with 
	// rotating angle equals +90 degrees, based on coordinate system 
	// old system direction is {x,y}, new system direction {x',y'}
	// is computed as:
	// { x', y' } = { -y, x }
	// definition: dir[0] = y, dir[1] = x
	newDir[ 0 ] =	dir[ 1 ];
	newDir[ 1 ] = - dir[ 0 ];
	
	// replace old direction with new
	dir[ 0 ] = newDir[ 0 ];
	dir[ 1 ] = newDir[ 1 ];
}//end turn right

// forward turtle
// Forward N spaces (default is set to 10)
// parameters are current position and direction,
// number of forwarding spaces and pen position ( 1(up), 2(down) )
// If pen is up nothing hapens with floor, only new position is
// calculated
void forward( bool abFloor[][ gFloorWidth ], int pos[], const int dir[], 
	const int penPosition, int fwdN )
{
	// forward "fwdN" spaces in specified direction only
	// first array element starts with zero index, and not from 1,
	// so fwdN is decreased by one!
	// e.g. array[ 9 ], start=array[0], end=array[8]
	// fwd=9; fwd--(=8) -> forward 9 steps
	// end-fwd = 0 -> goes from end position back to starting point
	fwdN--; 

	int anFwd[ 2 ] = {}; 
	anFwd[ 0 ] = ( pos[ 0 ] + dir[ 0 ] * fwdN ) * fabs( dir[ 0 ] );
	anFwd[ 1 ] = ( pos[ 1 ] + dir[ 1 ] * fwdN ) * fabs( dir[ 1 ] ) ;
	
	int rowBE[ 2 ] = {}; 	// row begining and row end
	int colBE[ 2 ] = {};	// column begining and column end
	
	// determine shifting positions and final position
	if ( dir[ 0 ] ) // direction vector (+-1, 0); column=const., row!=const. 
	{
		// column is unchanged
		// loop over rows, maximum nFwd times
		rowBE[ 0 ] = pos[ 0 ];		// starting row index
		rowBE[ 1 ] = anFwd[ 0 ];	// row position is changed after forwarding
		colBE[ 0 ] = pos[ 1 ];		// column start index
		colBE[ 1 ] = colBE[ 0 ];	// column number is unchanged
		
		// remember new position after shifting forward
		// vertial position (row) is changed while x component (column) remains
		// unchanged!
		pos[ 0 ] = rowBE[ 1 ];	// substract 1 to shift to appropriate row position!
		pos[ 1 ] = colBE[ 0 ];	// column position is unchanged!
	} 
	else // direction vector (0, +-1); row=const., column != const.
	{
		// horizontal movement: column bounds are changed
		// while row remains unchanged
		rowBE[ 0 ] = pos[ 0 ];		// row position is unchanged
		rowBE[ 1 ] = rowBE[ 0 ];	// row position is unchanged
		colBE[ 0 ] = pos[ 1 ];		// column starting position
		colBE[ 1 ] = anFwd[ 1 ];	// column ending position

		// new position after shift
		pos[ 0 ] = rowBE[ 0 ];	// row position is unchanged
		pos[ 1 ] = colBE[ 1 ];	// column position is changed
	}// end if else
	
	// do not change floor values for pen position down
	// new position values are only set (above)
	if ( penPosition == 1 )
		return;
	
	cout << "pos( " << pos[ 0 ] << ", " << pos[ 1 ] << " )" << endl;
	cout << "row: min=" << rowBE[ 0 ] << ", max=" << rowBE[ 1 ] << endl;
	cout << "col: min=" << colBE[ 0 ] << ", max=" << colBE[ 1 ] << endl;

	// Shift turtle forward
	// If turtle has pen up(=1), floor values are unchanged
	// otherwise (pen down(=2) ) values are changed and never reach this point!
	if ( colBE[ 0 ] == colBE[ 1 ] ) // constant column
	{
		int min = 0; // starting row index
		int max = 0; // ending row index

		if ( rowBE[ 1 ] > rowBE[ 0 ] )
		{	
			min = rowBE[ 0 ];
			max = rowBE[ 1 ];
		}
		else // rowBE[1] < rowBE[0]
		{
			min = rowBE[ 1 ]; 
			max = rowBE[ 0 ];
		}
		
		cout << "min:" << min << ", max:" << max << endl;

		for ( int row = min; row <= max; ++row )
		{
			// pen down(=2); change floor values to true
			if ( penPosition == 2 ) 
				abFloor[ row ][ colBE[ 0 ] ] = true;
		}
	}
	else // colBE[ 0 ] != colBE[ 1 ] -> row is constant!
	{
		int min = 0; // starting column index
		int max = 0; // starting row index
		
		if ( colBE[ 1 ] > colBE[ 0 ] )
		{
			min = colBE[ 0 ];
			max = colBE[ 1 ]; 
		}
		else
		{
			min = colBE[ 1 ];
			max = colBE[ 0 ];
		}

		for ( int column = min; column <= max; ++column )
		{
			if ( penPosition == 2 )
				abFloor[ rowBE[ 0 ] ][ column ] = true;
		}
	}// end if else
}//end forward function
