// main.cpp
// Airline reservation system.
// Program reservates seats on airplane for 
// each passenger in I. class or II. class.
#include <iostream>
using std::cout; // iostream
using std::cin;
using std::endl;

void displayClassType();
bool reserveSeat( bool [], const int, int );
bool checkFreeSeat( bool [], const int, int, const int =0 );
int totalFreeSeats( const bool [], const int );

int main()
{
	const int nNumOfSeats = 10; 			// number of seats on airplane
	int countFreeSeats = nNumOfSeats;		// count free seats
	bool abSeat[ nNumOfSeats ] = {};		// initialize all empty seats
	int anClassType[ nNumOfSeats ] = {};	// class type for each passenger
	
	for ( int passenger = 0; passenger < nNumOfSeats; ++passenger )
	{ 
		// test for available seets
		if ( countFreeSeats < 1 )
		{
			cout << "No free seat left!" 
				<< "Please go next flight at 5:00 pm." << endl;
			break;
		}

		displayClassType();
		// read class type: first class or economy
		cin >> anClassType[ passenger ]; 
		
		// reserve seat-function first checks if seat is free!
		bool isSeatReserved = 
			reserveSeat( abSeat, nNumOfSeats, anClassType[ passenger ] );

		// display message to user
		if ( isSeatReserved == 0 )
		{
			// user anwser to change class type
			char userAnwser = 'y';

			if ( anClassType[ passenger ] == 1 ) // I. class is full
			{
				cout << "\nSorry, I.class is full. "
					<< "Is acceptable economy class? [y/n]";
				cin >> userAnwser;
				
				// change class type or display message to user
				if ( userAnwser == 'y' )
				{
					anClassType[ passenger ] = 2;
					isSeatReserved = 
						reserveSeat( abSeat, nNumOfSeats, anClassType[ passenger ] );
				}
				else if ( userAnwser == 'n' )
				{
					--passenger; // skip this passenger
					cout << "\nNext flight leaves in 3 hours." << endl;
				}
			}
			else // economy class is full
			{
				cout << "\nSorry, economy class is full. "
					<< "Is acceptable I.class ?[y/n]";
				cin >> userAnwser;
				
				// change class type or display message to user
				if ( userAnwser == 'y' )
				{
					anClassType[ passenger ] = 1;
					isSeatReserved =
						reserveSeat( abSeat, nNumOfSeats, anClassType[ passenger ] );
				}
				else if ( userAnwser == 'n' )
				{
					--passenger; // skip passenger
					cout << "\nNext flight leaves in 3 hours." << endl;
				}
			}
		}//end if isSeatReserved==0

		if ( isSeatReserved )
			--countFreeSeats;

	}// end loop over passengers

	return 0;	
}// end main

////
////
//// display passengers class type
void displayClassType()
{
	cout << "\nPlease type 1 for \"First Class\"" << endl
		<< "Please type 2 for \"Economy\":";
}// end displayTypeClass

////
////
//// Reserve seat on a airplane
//// class type user choose between I.class or economy class
//// Automaticaly reserve only first seats of a class, and last
//// those at the end
bool reserveSeat( bool abSeats[], const int nTotalSeats, int classType )
{
	// first check for free seat, if any
	// reserve free seat
	bool checkSeat = false;
	checkSeat = checkFreeSeat( abSeats, nTotalSeats, classType, 1 );
	
	// no free seat
	if ( !checkSeat )
		return false;
	
	return true;
}//end reserveSeat function

////
////
//// check for free seat left, if any, for specified class type
//// First half are I. class seats, second half are economy seats, respectively.
//// If there are none seats left free for specified class type, than function 
//// returns false(=0), otherwise, if are seats left free, returns true(=1).
//// Optional, function can reserve seat (fill unocupied seat) for specified
//// class type
bool checkFreeSeat( bool abSeats[], const int nTotalSeats, 
	int classType, const int fillSeat )
{
	int beginClassSeat = 0; 				// first seat number for I. class
	int lastClassSeat  = nTotalSeats / 2; 	// last seat number for I. class

	// economy class first and last seat number
	if ( classType == 2 )
	{
		beginClassSeat = lastClassSeat;
		lastClassSeat = nTotalSeats;
	}
	
	// determine if seat is empty(free) for specified class type
	bool isSeatFree = false; 

	for ( int seat = beginClassSeat; seat < lastClassSeat; ++seat )
	{
		// check for empty seat
		if ( abSeats[ seat ] == false )
		{
			// one free seat
			isSeatFree = true;

			// fill seat
			if ( fillSeat == 1 )
				abSeats[ seat ] = true;
			
			break;
		}
	}

	return isSeatFree;
}//end checkFreeSeat function

////
////
//// return total number of free seats
int totalFreeSeats( const bool abSeats[], const int nTotalSeats )
{
	int countFreeSeats = 0; // total number of free seats

	for ( int i = 0; i < nTotalSeats; ++i )
	{
		if ( abSeats[ i ] == false )
			++countFreeSeats;
	}

	// return total number of free seats
	return countFreeSeats; 
}//end totalFreeSeats function

