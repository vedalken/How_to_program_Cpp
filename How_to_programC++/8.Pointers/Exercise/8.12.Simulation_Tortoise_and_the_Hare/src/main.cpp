#include <iostream>
#include <array>
#include <chrono>
#include <ctime>
#include <random>
#include <vector>
#include <thread>
#include "utility.h"
#include "animals.h"

#define PAUSE 1000

int main()
{
	const char finishLineMark = '|';
	const int trackLength = {71};
	std::array< char, trackLength > track;

	displayStartMessage();
	showTrackLabels( trackLength-1 );

	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine gen_engine( seed );
	std::uniform_int_distribution<size_t> moveType(1, 10);

	// starting point position
	int turtlePosition = {1};
	int harePosition = {1};
	unsigned int move_type = {0};

	while (true)
	{
		if (turtlePosition == trackLength-1)    break;
		else if (harePosition == trackLength-1) break;

        track.fill(' ');
		track.back() = finishLineMark;

		// pause thread
		std::this_thread::sleep_for( std::chrono::milliseconds( PAUSE ) );

		move_type = moveType( gen_engine );
		moveTurtle( &turtlePosition, move_type, trackLength-1 );

		move_type = moveType( gen_engine );
		moveHare( &harePosition, move_type, trackLength-1 );

		// put hare and turtle on track position
		putOnTrack( track, turtlePosition, 'T' );
		putOnTrack( track, harePosition,   'H' );
		showContendersOnTrack( track );
	}

	std::cout << std::endl;

	if ( harePosition == turtlePosition )
		std::cout << "\nIt's a tie." << std::endl;
	else if ( turtlePosition == (trackLength - 1) )
		std::cout << "\nTORTOISE WINS!!!" << std::endl;
	else if ( harePosition == (trackLength - 1) )
		std::cout << "\nHare wins." << std::endl;

	return 0;
}

