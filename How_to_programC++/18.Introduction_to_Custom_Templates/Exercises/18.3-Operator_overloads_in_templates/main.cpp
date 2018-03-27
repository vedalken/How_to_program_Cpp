#include <iostream>
#include "dummy.h"

template <typename T, typename U>
bool isEqual(T lhs, U rhs)
{
	return (lhs == rhs);
}

template <typename T, typename U>
void print(T t, U u)
{
	std::cout << t << " equals " << u  << "? "
		  << std::boolalpha << isEqual(t, u) << std::endl;
}

int main()
{
	// compare int values
	int aInt = 5;
	int bInt = 6;
	print(aInt, bInt);
	print(aInt, aInt);

	// compare double values
	double aDouble = 5.42342;
	double bDouble = 5.54435;
	print(aDouble, bDouble);
	print(aInt, aDouble);

	// compare mix values
	float aFloat = 1.3213;
	print(aFloat, aDouble);
	print(aFloat, bInt);

	// test dummy class
	Dummy aDummy(13);
	Dummy bDummy(13);

	std::cout << "Equal two dummy class: " << aDummy.get() 
	  	  << " and " << bDummy.get() << "? ";
	std::cout << isEqual(aDummy, bDummy) << std::endl;
	return 0;
}
