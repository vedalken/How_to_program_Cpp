// main.cpp
// Logical operators-truth table.
#include <iostream>
using std::cout;
using std::boolalpha;	// alphabetic format display boolean values
using std::endl;

int main()
{
	// Display truth table of logical AND (&&) operator
	cout << boolalpha << "Logical AND (&&)"
		<< "\nfalse && false: "	<< ( false && false )
		<< "\nfalse && true: "	<< ( false && true )
		<< "\ntrue && false: "	<< ( true && false )
		<< "\ntrue && true: "	<< ( true && true)
		<< "\n\n";
	
	// Display truth table of logical OR (||) operator
	cout << "Logical OR (||)"
		<< "\nfalse || false: "	<< ( false || false )
		<< "\nfalse || true: "	<< ( false || true )
		<< "\ntrue || false: "	<< ( true || false )
		<< "\ntrue || true: "	<< ( true || true)
		<< "\n\n";
	
	// Display truth table of logical negation (!) operator
	cout << "Logical negation (!)"
		<< "\n!false: "	<< ( !false )
		<< "\n!true: "	<< ( !true )
		<< endl;

	return 0;
}// end main function
