// main.cpp
// Test class Invoice. Using separate implementation from interface.
#include <iostream>
#include "Invoice.h"

// program execution begins with main
int main()
{
	// create invoice object
	Invoice article1( "Intel processor i7", "3.6 GHz, 24 MB L3, 12 MB L2, 8 MB L1", 
						3, 850 );
	
	// display invoice
	article1.displayInvoice();

	return 0;
} // end main
