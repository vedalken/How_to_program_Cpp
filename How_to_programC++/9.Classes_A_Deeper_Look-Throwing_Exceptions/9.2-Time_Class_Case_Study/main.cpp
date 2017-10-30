#include <iostream>
#include <stdexcept>
#include <chrono>
#include <thread>
#include "Time.h"


int main()
{
	Time t;
		
	std::cout << "The initial universal time is: ";
	t.printUniversal(); // 00:00:00
	std::cout << "\nThe initial standard time is: ";
	t.printStandard(); // 12:00:00

	// set new time
	t.setTime(13, 57, 14);

	std::this_thread::sleep_for(std::chrono::minutes(5));

	std::cout << "\n\nThe universal time after setTime is: ";
	t.printUniversal(); // 13:57:14
	std::cout << "\nThe initial standard time after setTime is: ";
	t.printStandard(); // 01:57:14 PM

	// attempt to set the time with invalid values
	try {
		t.setTime(13, 69, 1);
	}
	catch (const std::invalid_argument &ia) {
		std::cout << "Exception: " << ia.what() << std::endl;
	}

	// output t's values after specifying invalid values
	std::cout << "\n\nAfter attempting invalid settings:"
	          << "\nUniversal time: ";
	t.printUniversal(); // 13:57:14
	std::cout << "\nThe initial standard time after setTime is: ";
	t.printStandard(); // 01:57:14 PM
	
	std::cout << '\n';
	return 0;
}
