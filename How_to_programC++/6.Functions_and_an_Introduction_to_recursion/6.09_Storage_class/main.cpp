// main.cpp
// Use global, local and static variables. Same functions
// for displaying hidding values of global, local and static 
// variables from outer scope variable.
#include <iostream>
using namespace std;

// function prototype
void useLocal();
void useStaticLocal();
void useGlobal();

int x = 1; // global variable

int main()
{
	cout << "\nglobal x in main is " << x << endl;

	int x = 5; // local variable; shadowing global variable
	cout << "\nlocal x in main x is " << x << endl;

	{ // define inner scope variable; hidding outer scope variable x
		int x = 7;
		cout << "\nlocal inner scope x in main is " << x << endl;
	}// destroy automatic storage inner scope variable x

	cout << "\nlocal outer scope x in main is " << x << endl;

	useLocal();			// use local variable x
	useStaticLocal();	// use static variable x
	useGlobal();		// use global variable x
	useLocal();			// again function call for local, static and global variable
	useStaticLocal();
	useGlobal();
	
	cout << "\nlocal x in main is " << x << endl;

	return 0;	
}


// Declare local variable with same name as in outer scope of main.
// Display message, increment value, and display again message.
// After exiting function, variable x is destroyed.
void useLocal() 
{
	int x = 24; //local variable with local ({}) scope
	cout << "\nlocal x is " << x << " after entering function useLocal." << endl;

	x++; // increment local value

	cout << "local x is " << x << " before exiting function useLocal." << endl;
}// destroy x variable 


// Declare local static variable x. Variable is initialized once, and is destroyed 
// when program ends execution (static variable remains in memory until program
// exits). Multiple function call, static variable change values, memory address 
// remain unchanged.
void useStaticLocal() 
{
	static int x = 15; // initialize first time useStaticLocal is called
	
	cout << "\nlocal static x is " << x << " after entering function useStaticLocal." << endl;
	
	x++;

	cout << "local static x is " << x << " before exiting function useStaticLocal." << endl;
}// x is not destroyed, just current unreachable until next function call


// Use global variable on each call. Display message before and after variable change.
void useGlobal()
{
	cout << "\nglobal x is " << x << " after entering function useGlobal." << endl;
	
	x *= 10;

	cout << "global x is " << x << " before exiting function useGlobal." << endl;
}



