#include <iostream>
#include <bitset>

int main()
{
	std::bitset<8> foo(0x2);
	
	std::cout << "all bits: " << foo << std::endl;

	foo.set(4); // set 5th bit to 1
	foo.flip(5); // flip 6th bit
	foo.reset(5); // reset 6th bit

	std::cout
		<< "\nBit 4: " << foo.test(4)
		<< "\nBit 5: " << foo.test(5)
		<< "\nall bits: " << foo << std::endl;

	return 0;
}
