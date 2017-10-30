#include <iostream>
#include <bitset>
#include <cstdint>

int main()
{
	// bit mask
	const uint32_t mask = 0XF; // 0000 0000 0000 1111
	
	std::cout << "Enter a number: ";
	int32_t num;
	std::cin >> num;
	std::cout << "num: " << std::bitset<32>(num) << std::endl;
	std::cout << "mask: " << std::bitset<32>(mask) << std::endl;

	// remove high bits
	num &= mask;

	std::cout << "masked num: " << std::bitset<32>(num) << std::endl;
	
	return 0;
}
