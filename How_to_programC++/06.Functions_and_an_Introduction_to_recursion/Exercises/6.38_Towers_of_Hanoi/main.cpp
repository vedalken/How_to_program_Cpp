// main.cpp
// Recursive solve Towers of Hanoi (or Towers of Brahmin) problem.
#include <iostream>
#include <iomanip>
#include <cstdlib>
using std::cout; // iostream
using std::endl;
using std::cin;
using std::setw; // iomanip
using std::exit; // cstdlib

// function prototype
void hanoi( int nDisk, char source='A', char destination='B', char temp='C' );

int main()
{
	// display some basic information
	cout << "Welcome to Towers of Hanoi!" << endl;
	cout << "Info on output: \n"
		 << "         n source --> destination\n"
		 << "n is disk number, source is a place where n-th disk is located,\n"
		 << "and destination is a place where n-th disk will be placed.\n\n";

	int disks = -1;
	// Test if user has entered positive number
	do {
		cout << "Enter number of disks: ";
		cin >> disks;
	}while( disks <= 0 );
	
	cout << "Moves:" << endl;
	cout << "----------------" << endl;
	// default setting are used: source='A', destination='B', temp='C'
	hanoi( disks ); 
	cout << "----------------" << endl;
	
	return 0;	
}

// Recursive function call
// nDisk: number of disk on stack
// source: starting peg
// destination: final peg
// temp: temporary peg
void hanoi( int nDisk, char source, char destination, char temp )
{
	static int count = 0; // count hanoi moves

	if (nDisk == 1) {
		count++;
		cout << setw(3) << count << ":" << setw(3) << nDisk << setw(2) << source 
			 << setw(4)<< "-->"	 << setw(2) << destination 
			 << endl;
	}
	else {
		// Solve for nDisk-1 moving from source to temporary peg as
		// temporary desination, and used actual destnation as temporary peg
		hanoi( nDisk-1, source, temp, destination );
		
		count++;
		// Move last disk from source to destnation using temporary peg
		cout << setw(3) << count << ":" << setw(3) << nDisk << setw(2) << source 
			 << setw(4)<< "-->"	 << setw(2) << destination 
			 << endl;
		
		// Those n-1 disks on temporary peg must be moved to destination peg
		// using source as temporary peg
		hanoi( nDisk-1, temp, destination, source );
	}
}//end hanoi function
