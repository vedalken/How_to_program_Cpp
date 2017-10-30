// main.cpp
// Simulate turtle walk. At the beginning display
// all commands.
#include <iostream>
#include "turtle.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	// display commands
	displayCommands(); 
	// available commands
	enum eCommand 
	{
		PENUP=1,	// pen up
		PENDOWN,	// pen down
		TURNRIGHT,	// turn right
		TURNLEFT,	// turn left
		MOVEFWD,	// move forward
		PRINTFLOOR, // print array
		ENDDATA=9	// end of data
	};	

	// declare (square) floor size,
	const int floorSize = ::gFloorWidth;
	bool abFloor[ floorSize ][ floorSize ];
	// initialize 2D array to false (deafult)
	setFloor( abFloor );

	// display floor with characters
	// true is replaced by '*', and false by blank " "
	//printFloor( abFloor );
	
	// turtle walks around until sentinel value is entered
	// sentinel value is 9!
	// user enters available command
	int nCommand = 0;
	// default initial direction; unity vector
	// next iteration, direction is remembered
	// { y, x } = { 0, 1 } vector direction,
	// where x=1, y = 0; so direction on x-axis
	int currentDirection[ 2 ] = { 0, 1 };
	// current turtle position; turtle start at (0,0)
	// next iteration position is remembered, but not
	// initialized (initialization is only once!)
	int currentPosition[ 2 ]= { 0, 0 };
	
	// pen position
	int penPosition = 1;
	
	while ( nCommand != ENDDATA )
	{
		// user enters available command
		cout << "Command:";
		cin >> nCommand;
		
		cout << "main:" << endl
			<< "dir( " << currentDirection[ 0 ] << ", " << currentDirection[ 1 ] << " )\n"
			<< "pos( " << currentPosition[ 0 ]	<< ", " << currentPosition[ 1 ]	<< " )\n"; 

		switch ( nCommand )
		{
			case 1: // pen up
				penPosition = 1;
				break;

			case 2: // pen down
				penPosition = 2;
				break;

			case 3: // turn right
				right( currentDirection ); // change direction vector
				break;

			case 4: // turn left
				left( currentDirection ); // change direction vector
				break;

			case 5: // forward N spaces
				// forward 10 spaces, and change floor values
				// if pen is down (=2), otherwise floor is unchanged
				// only new position is calculated
				forward( abFloor, currentPosition, currentDirection,
					penPosition );
				break;

			case 6: // print floor
				printFloor( abFloor );
				break;
			
			case 9: // end of data 
				// after breaking switch statement loop
				// is breaked - sentinel value is entered!
				break;

			default: // unknown command
				cout << "Unknown command.";
				break;
		}
	}// end infinite loop of turtles walk on the floor

	return 0;
}//end main
