#include <iostream>

int main()
{
	// 5 = 0101
	std::cout << 5u << ", base 10: 5." << std::endl;
	
	// 1 byte can take 2^8 = 256 values, starting from 
	// 0 to 255. In 1 byte representation 10 = 0000 1010,
	// -10 = 2^8-1 + 1 - 10 = 255 - 10 = 245
	// where first substraction with 1 comes from accurate counting bits
	// (from zero to 255), addition with 1 cames from negation operator
	// with bits, ex. +0 = 0000, -0=1111 but +0 and -0 had to be the same!
	// With adding 1 to 1111 overflow occur, and bits are fliped to 0000.
	//
	// In 4 byte representation, 10 = 0000...0000...1010, and thus having (8bits*4)=32bits.
	// 2^(4*8) =  2^32 = 4294...96 starting from 0 to 4294...95.
	// Now, -10 = 2^32-1+1-10 = 4294...86 in base 10!
	std::cout << -10 << ", base 10: 4294...86."<< std::endl;
	
	// unsigned integer has higher precedence than signed integer
	// Calculated result is: 5 + 4294...86 = 4294...91 which is -5 !
	std::cout << "Summing both numbers, the result is: ";
	std::cout << 5u - 10 << std::endl;	

	return 0;
}
