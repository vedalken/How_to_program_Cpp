#include <iostream>

class Test
{
public:
	void print() {
		std::cout << "In func\n";
	}

	void print(int val) {
		std::cout << val << std::endl;
	}

	int value;
};

void arrowStar( Test * );
void arrowStar( Test *, int );
void dotStar( Test * );

inline int foo() 
{
	return 5;
}

int main()
{
	Test test;
	test.value = 8;
	arrowStar( &test );
	arrowStar( &test, -16 );
	dotStar( &test );

	std::cout << "Address of function foo(): " << reinterpret_cast<void *>(foo) << std::endl;
	return 0;
}// end main

void arrowStar( Test *testPtr )
{
	void ( Test::*memPtr )() = &Test::print;
	( testPtr->*memPtr )();
}

void arrowStar( Test *testPtr, int a_value )
{
	void ( Test::*const memPtr )(int) = &Test::print;
	( testPtr->*memPtr )(a_value);
}

void dotStar( Test *testPtr )
{
	int Test::*const vPtr = &Test::value;
	std::cout << (*testPtr).*vPtr << std::endl;
}
