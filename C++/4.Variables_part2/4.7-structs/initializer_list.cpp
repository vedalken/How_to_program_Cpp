#include <iostream>

struct Employee
{
	int nID;
	int nAge;
	float fWage;
};

struct Company
{
	Employee sCEO;	// Employee is a struct within the Company struct
	int nNumberOfEmployees;
};

int main()
{
	using namespace std;

	// initializer list
	Employee sJoe = {65, 54, 70000.0f}; //nID = 1, nAge=54, fWage=70000.0

	cout << "Joe's age: "<< sJoe.nAge << endl << endl;
	
	Company sCo1 = {{1, 30, 80000.0f}, 5};
	cout << "Number of employees: " << sCo1.nNumberOfEmployees << endl;

	return 0;
}
