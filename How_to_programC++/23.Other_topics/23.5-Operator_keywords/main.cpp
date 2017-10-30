#include <iostream>
#include <ciso646>

int main()
{
	bool a(true);
	bool b(false);
	int c(2);
	int d(3);

	std::cout << std::boolalpha;

	std::cout << "a = " << a << "; b = " << b
		  << "; c = " << c << "; d = " << d;

	std::cout << "\n\nLogical operator keywords:"
	          << "\n    a and a: " << ( a and a )
	          << "\n    a and b: " << ( a and b )
		  << "\n    a or a:  " << ( a or a )
		  << "\n    a or b:  " << ( a or b )
		  << "\n    not a:   " << ( not a )
		  << "\n    not b:   " << ( not b )
		  << "\na not_eq b:  " << ( a not_eq b );

	std::cout << "\n\nBitwise operator keywords:"
		  << "\n   c bitand d: " << ( c bitand d )
		  << "\n   c bitor d:  " << ( c bitor d )
		  << "\n   c xor d:    " << ( c xor d )
		  << "\n   compl c:    " << ( compl c )
		  << "\n c and_eq d:   " << ( c and_eq d )
		  << "\n c or_eq d:    " << ( c or_eq d )
		  << "\n c xor_eq d:   " << ( c xor_eq d )
		  << std::endl;

	return 0;
}
