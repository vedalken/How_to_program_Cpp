// main.cpp
// Problem: Saleperson Salary Ranges
// The salesperson each receive $200 per week plus
// 9% of their gross sales for that week e.g.
// salesperson who grosses $5000 in sales in a week receives
// $200 plus 9 procent of $5000, or total $650.
// Program generates random sales gross for each employee.
// Number of employee is set to 100.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using std::cout; // iostream
using std::endl;
using std::setw; // iomanip
using std::srand; // cstdlib
using std::rand;
using std::time; // ctime

int main()
{
	srand( time(0) ); // initialize seed

	// number of employee working in sales
	// array contains salesperson's salary for that week
	const int nNumberOfEmployees = 10000;
	const int nMaxSalesGross	 = 9000; // maximal sales gross per week
	int anEmployeeSalary[ nNumberOfEmployees ] = {};

	// initialize sales gross for each salesperson
	for ( int i = 0; i < nNumberOfEmployees; ++i )
		anEmployeeSalary[ i ] = rand() % nMaxSalesGross;

	const int nSalaryPerWeek 	= 200; 	// constant salary for each salesperson 
	const double dGrossProcent	= 0.09;	// 9 procent of sales gross is added to each person salary 
	
	// calculate each salesperson salary
	for ( int i = 0; i < nNumberOfEmployees; ++i ) 
	{
		anEmployeeSalary[ i ] = 
			static_cast< int >( dGrossProcent * anEmployeeSalary[ i ] ) + nSalaryPerWeek; 
	}
	

	// count employee salary
	// 200-299
	// 300-399
	// ...
	// 1000 and over
	const int nFreqSize = 11;			// array frequency size
	int anFrequency[ nFreqSize ] = {}; 	// initialize to 0 
	
	for ( int i = 0; i < nNumberOfEmployees; ++i )
	{
		int nFreq;
		nFreq = anEmployeeSalary[ i ] / 100; // integer division
		
		// if employee salary is reached curtain limit, 
		// frequency is set as maximal for the table displayed
		if ( nFreq > nFreqSize - 1 )
			nFreq = nFreqSize - 1;

		++anFrequency[ nFreq ];
	}
	
	// display frequency
	for ( int nFreq = 2; nFreq < nFreqSize; ++nFreq )
	{
		if ( nFreq == 0 )
			cout << setw(8) << "0-99:";
		else if ( nFreq == nFreqSize - 1 )
			cout << setw(8) << ">1000:";
		else 
			cout << nFreq*100 << "-" << (nFreq+1)*100 - 1 << ":"; 
		
		cout << setw(6) << anFrequency[ nFreq ] << endl; 
	}

	return 0;	
}//end main
