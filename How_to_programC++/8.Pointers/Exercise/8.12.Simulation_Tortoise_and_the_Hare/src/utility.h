#include <iostream>
#include <array>
#include <vector>
#include <stdexcept>
#include <string>
#include <cstring>

#ifndef UTILITY_H
#define UTILITY_H
void displayStartMessage( void );
void checkMove( int * position, const int trackLength );

template <size_t _trackLength>
void showContendersOnTrack( const std::array<char, _trackLength> &track )
{
	std::string str( std::begin( track ), std::end( track) );
	std::cout << '\r' << str << std::flush;
}

template <size_t _trackLength>
void putOnTrack( std::array<char, _trackLength> &track, const int position, const char val )
{
	static const std::string messg = "OUCH!!!";

	try {
		if (track.at( position ) == ' ' || track.at( position ) == '|')
			track.at( position ) = val;
		else
		{
			int pos = position;
			for (const char & c : messg)
			{
				track.at( pos ) = c;
				++pos;
			}
		}
	}
	catch (const std::out_of_range &oor) {
		std::cerr << "Out of range error: " << oor.what() << '\n';
	}
}

void showTrackLabels( const int trackLength );
#endif
