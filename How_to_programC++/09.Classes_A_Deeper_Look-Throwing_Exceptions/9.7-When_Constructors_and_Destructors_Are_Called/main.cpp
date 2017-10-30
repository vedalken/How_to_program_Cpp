// Order in which contructors and destructors are called
#include <iostream>
#include <cstdlib>
#include "CreateAndDestroy.h"

void create(void);

CreateAndDestroy first( 1, "(global before main)" );

int main()
{
	std::cout << "\nMAIN FUNCTION: EXECUTION BEGINS\n";
	CreateAndDestroy second( 2, "(local automatic in main)");
	static CreateAndDestroy third( 3, "(local static in main)");
	
	// create objects
	create();

	std::cout << "\nMAIN FUNCTION: EXECUTION RESUMES\n";
	CreateAndDestroy forth( 4, "(local automatic in main)");

	std::cout << "\nMAIN FUNCTION: EXECUTION ENDS\n";
	std::cout << "exit...\n";
	std::exit(1);
	
	return 0;
}

// Function to create objects
void create(void)
{
	std::cout << "\nCREATE FUNCTION: EXECUTION BEGINS\n";
	CreateAndDestroy fifth( 5, "(local automatic in create)" );
	static CreateAndDestroy sixth( 6, "(local static in create)" );
	CreateAndDestroy seventh( 7, "(local automatic in create)" );
	std::cout << "\nCREATE FUNCTION: EXECUTION ENDS\n";
}
