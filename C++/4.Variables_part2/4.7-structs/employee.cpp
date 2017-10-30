#include <iostream>

struct Employee	// define structure
{
	int	nID;	// struct variables are not initialized-contain junk!
	int	nAge;	
	float	fWage; 
};

int main()
{
	Employee sJoe;	// Create en Employee struct for Joe
	sJoe.nID = 45;	// initialize nID within sJoe
	sJoe.nAge = 32;
	sJoe.fWage = 12.56;

	Employee sFrank; // Create an Employee struct for Frank
	sFrank.nID = 18;
	sFrank.nAge = 29;
	sFrank.fWage = 124.75;

	if (sFrank.nAge < sJoe.nAge)
		std::cout << "Frank is younger than Joe." << std::endl;

	// Frank got a promotion
	sFrank.fWage += 2.50;
	
	// Today is Joe's birthday 
	sJoe.nAge++;

	return 0;
}
