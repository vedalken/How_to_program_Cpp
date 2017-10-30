#include <iostream>	// include library for I/O commands

int main()
{
	int x = 0;
	int y = 2;
	int m = 7;
	std::cout << x << ", " << y << std::endl;

	int z = (++x, ++y, ++m);	// increment x and y; return rightmost value-y 
	std::cout << x << ", " << y << "; " << z << std::endl;
	
	z = (x > m)? x : m; 	// use greater number to save in z!
	std::cout << z << std::endl;
	std::cout << ((x>m) ? x:m) << std::endl;
	
	//std::cout << (x>m)? x:m ;	compile error!

	return 0;
}
