// main.cpp
// Set date using struct object.
#include <iostream>
#include "DateStruct.h" // DateStruct struct object
#include "Date.h" // Date class object 
using std::cout;
using std::endl;

// function prototype
void setDate( DateStruct &, int month, int day, int year );
void getDate( DateStruct & );

int main()
{
	// create struct myDate
	DateStruct sMyDate = 
		{ .nMonth = 10, .nDay = 23, .nYear = 2034 };
	
	// display my date
	getDate( sMyDate );

	// set new date
	setDate( sMyDate, 4, 7, 2013 );

	// display new date
	getDate( sMyDate );

	Date cTomorrow;
	cTomorrow.setDate( 4, 8, 2013 ); // set date
	
	return 0;	
}// end main

// set date
void setDate( DateStruct &sDate, int m, int d, int y )
{
	sDate.nMonth = m;
	sDate.nDay = d;
	sDate.nYear = y;
}//end setDate function

// display date
void getDate( DateStruct &sDate )
{
	cout << "Date (m/d/yyyy): " 
		<< sDate.nMonth << "/" << sDate.nDay << "/" << sDate.nYear 
		<< endl;
}// end getDate function
