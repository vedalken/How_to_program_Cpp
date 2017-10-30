// Define macro PRINT to print string value
#include <iostream>
#include <string>
#define PRINT(str) #str // print string (in quotes)
using namespace std;

void inline print( string str ) { cout << str;}

int main()
{	
	cout << "Hi, my name is " << PRINT(Milos) << " and \n"
		 << "yours is " << PRINT(unknown) << "." << endl;

	cout << "Inline function call.\n"
	     << "Hi, my name is "; 
	print( "Milos" ); 
	cout << " and \nyours is ";
	print( "unknown" );
	cout << ". " << endl;
		
	return 0;
}

