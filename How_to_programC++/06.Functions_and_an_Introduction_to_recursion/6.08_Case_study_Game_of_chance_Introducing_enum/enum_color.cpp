// enum_color.cpp
// Enumerator for different colors.
#include <iostream>

// define colors with enumerator
enum Color {
	COLOR_BLACK, 	// assigned 0
	COLOR_WHITE, 	// assigned 1
	COLOR_RED,		// assigned 2
	COLOR_GREEN,	// assigned 3
	COLOR_BLUE,		// assigned 4
	COLOR_YELLOW = 4// explicit assignment to 4
};

int main()
{
	Color myColor; 			// allocate memory for myColor
	myColor = COLOR_YELLOW; // asigned 4 to myColor

	// display color
	std::cout << myColor << std::endl;

	return 0;	
}
