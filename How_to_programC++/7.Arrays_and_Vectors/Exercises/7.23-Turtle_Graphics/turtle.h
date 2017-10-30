// turtle.h
// Function delcaration for turtle movments.
#ifndef TURTLE_H
#define TURTLE_H
const int gFloorWidth = 20; // floor size

// display available commands
void displayCommands();

// display scpecified number of markers
void displayMarker( const int, char = '-' );

// initialize floor values
void setFloor( bool [][ gFloorWidth ], bool = false );

// display two dimensional floor
void printFloor( const bool [][ gFloorWidth ], char = '*' );

// rotate turtle left
void left( int direction[] );

// rotate turtle right
void right( int direction[] );

// move forward  
void forward( bool [][ gFloorWidth ], int position[], 
	const int direction[], const int penPosition=1, 
	int forwardNspaces=9 );

#endif
