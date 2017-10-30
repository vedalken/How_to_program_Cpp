// goto.cpp
// Using goto statement - in practice used only for performance optimization
#include <iostream>
using std::cout;

int main()
{
	short count = 1;

	start: // define label start for goto statement
		if (count > 10) // skip looping; go to end label
			goto end;
		
		cout << count << " ";
		count++;

		goto start; // go back to start label

	end: // define label for goto statement
		cout << "\n";

	return 0;	
}
