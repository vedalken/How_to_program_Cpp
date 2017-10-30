// HeartRates.cpp
// HeartRates class implementation.
#include <iostream>
#include <string>
#include "HeartRates.h"	// HeartRates class forward declaration
using std::cout;
using std::endl;
using std::string;

// initialization of data members: first name, last name and date of birth
HeartRates::HeartRates(string fName, string lName, int yearOfBirth)
{
	setFirstName(fName);
	setLastName(lName);
	setYear(yearOfBirth);
}

// first name manipulation and retrieving information
void HeartRates::setFirstName(string fName) { firstName = fName; }
string HeartRates::getFirstName() { return firstName; }

// first name manipulation and retrieving information
void HeartRates::setLastName(string lName) { lastName = lName; }
string HeartRates::getLastName() { return lastName; }

// set and get year of birth
void HeartRates::setYear(int yearOfBirth) { dateOfBirth = yearOfBirth; }
int HeartRates::getYear() { return dateOfBirth; }

// calculate person's age in years
int HeartRates::getAge()
{
	int y = 2012;

	// calculate person's age in years
	return (y - getYear());
}

// calculate maximal heart rate for individual person
int HeartRates::getMaxHeartRate()
{
	// heart rate
	int heartRate = 220;

	return (heartRate - getAge());
}

// calculate target heart rate
int HeartRates::getTargetHeartRate()
{
	// target heart rate is a range of 50% to 85%
	// we use mean value 70%
	return (0.7 * getMaxHeartRate());  
}

// getting information on person's health
void HeartRates::displayHealth()
{
	cout <<"\nFirst name: "			<< getFirstName() 
		<< "\nLast name: "			<< getLastName()
		<< "\nAge: "				<< getAge() 
		<< "\nMax heart rate: "		<< getMaxHeartRate()
		<< "\nTarget heart rate: "	<< getTargetHeartRate()
		<< endl;
}





