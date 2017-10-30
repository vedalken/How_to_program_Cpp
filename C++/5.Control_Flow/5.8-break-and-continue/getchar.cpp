// getchar.cpp
// Count number of spaces entered. Terminate if new line is pressed.
#include <iostream>
#include <cstdio>	// function getchar()
// iostream header
using std::cout;
using std::endl;
// cstdio header
using std::getchar;

int main()
{
	int countSpaces = 0; // count number of spaces
	
	cout << "Enter characters with spaces (press Enter to exit):" << endl;

	for (int count = 0; count < 80; ++count) 
	{	// read character from user
		char spaces = getchar();
		
		if (spaces == ' ') { // count spaces
			++countSpaces;
		}

		if (spaces == '\n') { // terminate loop if new line is pressed
			break;
		}
	}
	
	cout << "Number of spaces entered: " << countSpaces << endl;

	return 0;
}
