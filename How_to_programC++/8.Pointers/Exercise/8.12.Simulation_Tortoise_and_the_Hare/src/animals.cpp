#include "utility.h"

/// Hare: type of moves
int typeOfMoveHare( const int typeOfMove )
{
	int move = 0;

	switch ( typeOfMove )
	{
		// sleep (20% of time)
		case 1:
		case 2:
			// move = 0
			break;
		
		// big hop (20% of time)
		case 3:
		case 4: 
			move = 9; break;

		// big slip (10% of time)
		case 5: 
			move = -12; break;

		// small hop (30% of time)
		case 6:
		case 7:
		case 8: 
			move = 1; break;

		// small slip (20% of time)
		case 9:
		case 10: 
			move = -2; break;

		default:
			break;
	}// end switch
	
	return move;
}


/// Turtle: type of moves
int typeOfMoveTurtle( const int typeOfMove )
{
	int move = {0};
	
	// fast plod, slip, slow plod
	if ( typeOfMove >= 1 && typeOfMove <= 5 ) 
		move = 3;
	else if ( typeOfMove >= 6 && typeOfMove <= 7 )
		move = -6;
	else if ( typeOfMove >= 8 )
		move = 1;
	else
		;

	return move;
}


/// Hare makes a move with specified action i.e. typeOfMove (slip, big hop etc.)
/// from current position `position'
void moveHare( int * position, const int typeOfMove, const int trackLength )
{
	int move;
	move = typeOfMoveHare( typeOfMove );
	*position += move;
	checkMove( position, trackLength );
}


/// Move turtle from position `position' with 
/// specified type of move `typeOfMove'
void moveTurtle( int * position, const int typeOfMove, const int trackLength )
{
	int move;
	move = typeOfMoveTurtle( typeOfMove );
	*position += move;
	checkMove( position, trackLength );
}// end moveTurtle

