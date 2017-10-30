// HeartRates.h
// HeartClass definition.
// Class is used for statistical information on peoples health.
// Uses first name, last name and date of birth of a person.
#include <string>
using std::string;

// class Heart declaration for population heart rates
// for individual person (data member)
class HeartRates
{	
	public:
		// constructor initialize data members firstName, lastName and dateOfBirth
		// int that order (first name, last name, year)
		HeartRates(string, string, int);
		// function sets and gets first name of a person
		void setFirstName(string);
		string getFirstName();
		// function sets and gets last name of a person
		void setLastName(string);
		string getLastName();
		// get and set year of birth
		void setYear(int);
		int getYear();
		// function gets persion's age
		int getAge();
		// function gets person's maximum heart rate
		int getMaxHeartRate();
		// function gets person's target heart rate
		int getTargetHeartRate();
		// display information
		void displayHealth();

	private:
		// first name of studied person
		string	firstName;
		// last name of studied person
		string	lastName;
		// data member of another class Date; using date of birth of a person
		int dateOfBirth;
};
