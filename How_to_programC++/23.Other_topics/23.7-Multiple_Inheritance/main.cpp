#include <iostream>
#include "Derived.h"

int main()
{
	Base1 base1(10);
	Base2 base2('Z');
	Derived derived(7, 'A', 3.5);


	// print data member of base-class objects
	std::cout << "Object base1 contains integer " << base1.getValue()
		<< "\nObject base2 contains character " << base2.getValue()
		<< "\nObject derived contains " << derived << std::endl;

	std::cout << "\nData members of Derived can be accessed individually: "
		<< "\ninteger:     " << derived.Base1::getValue()
		<< "\ncharacter:   " << derived.Base2::getValue()
		<< "\nreal number: " << derived.getReal() << std::endl;

	// threat Derived as a Base1 object
	Base1 *base1Ptr = &derived;
	std::cout << "base1Ptr->getValue() yields " << base1Ptr->getValue() << '\n';

	Base2 *base2Ptr = &derived;
	std::cout << "base2Ptr->getValue() yields " << base2Ptr->getValue() << '\n';

	return 0;
}
