// automaticDuration.cpp
// Test local variable block scope with automatic (default)
// duration.
#include <iostream>

void incrementAndPrint() {
	int value = 1; // local variable duration is by default automatic
	++value; 			// increment by one

	std::cout << value << std::endl;
}

int main() { 
	// function call several times
	incrementAndPrint();
	incrementAndPrint();
	incrementAndPrint();
	
	return 0;
}
