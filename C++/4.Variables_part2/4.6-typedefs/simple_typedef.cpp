#include <iostream>

int main()
{
	typedef long miles;	// define miles as alias for long
	typedef long speed; // define some speed

	miles nDistance = 2500;
	speed nMHz;
	nMHz = nDistance; // syntactically correct! Conceptually not making sense!

	std::cout << "Distance: " << nDistance << std::endl;
	std::cout << "MHz: " << nMHz << std::endl;
	
	return 0;
}
