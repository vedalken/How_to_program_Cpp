#include <iostream>
using namespace std;

int reserveSeat( int [], const int );
int checkFreeSeats( const int [], const int );

int main()
{
	const size_t totalSeats = 10;  // number of seats per flight
	int seat[ totalSeats ]  = {};  // flight seats
	
	while ( true )
	{
		int flag = reserveSeat( seat, totalSeats );
		
		if ( flag == -1 ) break;
	}

	return 0;	
}

// Reserve a seat "tmpSeat" on flight with "totalSeats" 
int reserveSeat( int seat[], const int totalSeats )
{
	enum { NEXT_FLIGHT, CURRENT_FLIGHT };
	enum { FIRST_CLASS = 1, ECONOMY_CLASS };
	
	static int startFirstClassSeat = 0;
	static int startEconomySeat    = totalSeats / 2;

	if ( checkFreeSeats( seat, totalSeats) == 0 )
	{
		cout << "No more seats available. " 
			<< "Please check next flight." << endl;	
		return -1;
	}

	// user flight flag - taking current flight
	int flightFlag = CURRENT_FLIGHT;
	int tmpSeat;
	
	cout << endl;
	cout << "Please type 1 for \"First Class\"" << '\n'
	 	<< "Please type 2 for \"Economy\"" << '\n'
		<< "Enter a number (any number to quit): ";
	cin >> tmpSeat;
	
	// reserve a seat in first class or in economy class
	// In the case where all seats in the corresponding class
	// are taken, user takes a measure
	while ( true )
	{
		if ( tmpSeat == FIRST_CLASS )
		{
			// check if seats in the first class are taken
			// if not, reserve a seat
			if ( startFirstClassSeat >= totalSeats/2 )
			{
				char economySeat;
				cout << "Sorry, no first class seat is available" << endl;
				cout << "Do you wish economy seat [y/n]? ";
				cin >> economySeat;
				
				// in the case no seat is available
				// first class user can request for a economy class seat
				if ( economySeat == 'y' || economySeat == 'Y' )
					tmpSeat = ECONOMY_CLASS;
				else
				{
					// next flight
					flightFlag = NEXT_FLIGHT;
					break;
				}
			}
			else 
			{
				cout << "Seat number: " << startFirstClassSeat+1 << '\n'
					<< "First Class" << endl;
				// seat is available
				seat[ startFirstClassSeat ] = true;
				++startFirstClassSeat;
				break;
			}
		}// end if
		else if ( tmpSeat == ECONOMY_CLASS )
		{
			// check if seats are taken
			if ( startEconomySeat >= totalSeats )
			{
				char firstClassSeat;
				cout << "Sorry, no first class seat is available" << endl;
				cout << "Do you wish first class seat [y/n]? ";
				cin >> firstClassSeat;
				
				// in the case no seat is available
				// economy class user can request for a first class seat
				if ( firstClassSeat == 'y' || firstClassSeat == 'Y' )
					tmpSeat = FIRST_CLASS;
				else
				{
					// next flight
					flightFlag = NEXT_FLIGHT;
					break; 
				}
			}
			else 
			{
				cout << "Seat number: " << startEconomySeat+1 << '\n'
					<< "Economy Class" << endl;
				// seat is available
				seat[ startEconomySeat ] = true;		
				++startEconomySeat;
				break;
			}
		}
		else {
			cout << "Exiting" << endl;
			return -1;
		}
	} // end infinite while loop

	if ( flightFlag == NEXT_FLIGHT )
	{
		cout << "Next flight leaves in 3 hours" << endl;
		return 0;
	}

	return 1;
}// end function reserveSeat

// determine number of free seats 
int checkFreeSeats( const int seat[], const int totalSeats )
{
	int freeSeats = 0;

	for ( int i = 0; i < totalSeats; ++i )
	{
		// a free seat
		if ( seat[ i ] == false )	
			++freeSeats;
	}
	
	return freeSeats;
}
