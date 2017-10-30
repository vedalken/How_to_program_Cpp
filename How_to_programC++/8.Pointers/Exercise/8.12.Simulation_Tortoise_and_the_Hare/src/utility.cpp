#include <iostream>
#include <iomanip>
#include "utility.h"

void displayStartMessage( void )
{
	std::cout << 
		"\n*******************************"
		"\nWelcome to simulation:"
		"\nThe Tortoise and the Hare race."
		"\n*******************************"
		"\nBANG !!!!"
		"\nAND THEY'RE OFF !!!!!\n\n";		
}

void checkMove( int * position, const int trackLength )
{
	if ( *position > trackLength )
		*position = trackLength;
	
	if ( *position < 1 )
		*position = 1;
}

void showTrackLabels( const int trackLength )
{
	std::cout << std::setw( trackLength ) << std::setfill('_') << std::endl;
	std::cout << std::left << std::setw( trackLength ) 
		<< "START" << "FINISH" << std::endl;
}
