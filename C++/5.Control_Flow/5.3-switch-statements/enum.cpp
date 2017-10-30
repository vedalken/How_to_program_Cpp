// enum.cpp
// Program test for switch statement.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// Enumerate colors
enum Colors { 
	COLOR_BLACK,
	COLOR_GREEN,
	COLOR_RED,
	COLOR_YELLOW,
	COLOR_BLUE,
};

void printColor(Colors color)
{
	if		(color == COLOR_BLACK) 	{ cout << "Black."; }
	else if (color == COLOR_GREEN)	{ cout << "Green."; }
	else if (color == COLOR_RED)	{ cout << "Red.";	}
	else if (color == COLOR_YELLOW) { cout << "Yellow.";}
	else if (color == COLOR_BLUE)	{ cout << "Blue.";	}
	else { cout << "Unkown!"; }
}

int main()
{
	Colors col;			// declare variable
	col = COLOR_BLACK; 	// initialize
	
	printColor(col);	// print color
	cout << endl; // new line
	
	int grade;
	// using switch statement
	// Read character from keyboard
	switch ( grade = cin.get() )
	{
		case 'A':
			cout << " A";
			break;

		case 'B':
			cout << "B";
			break;

		case 'C':
			cout << "C";
			break;

		case 'D':
			cout << "D";
			 break;

		case 'F':
			cout << "F";
			break;

		default:
			cout << "Unknown.";
			break;
	}

	cout << endl; // new line

	return 0;
}
