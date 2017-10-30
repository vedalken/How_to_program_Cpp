#include <iostream>
#include <stdexcept>
#include "Time.h"

int main()
{
	Time t1;
	Time t2{2};
	Time t3{21, 35};
	Time t4{12, 25, 56};
	
	std::cout << "Constructed with:\n\nt1: all arguments defaulted\n";
	t1.printUniversal(); // 00:00:00
	t1.printStandard(); // 12:00:00

	std::cout << "\n\nt2: hour specified; minute and second defaulted\n";
	t2.printUniversal(); // 02:00:00
	t2.printStandard(); // 02:00:00 AM

	std::cout << "\n\nt3: hour and minute specified; second defaulted\n";
	t3.printUniversal(); // 21:35:00
	t3.printStandard(); // 21:35:00 AM

	std::cout << "\n\nt4: hour, minute and second specified\n";
	t4.printUniversal(); // 12:25:56
	t4.printStandard(); // 12:25:56 PM

	// attempt to initialize t5 with invalid values
	try {
		Time t5{27, 74, 99};
	}
	catch (const std::invalid_argument &ia) {
		std::cerr << "Exception while initializing t5: " << ia.what() << std::endl;
	}

	return 0;
}
