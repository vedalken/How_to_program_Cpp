// tmp.cpp
// Check how reference works...
#include <iostream>
int main()
{
	using std::cout;
	using std::endl;

	int iii = 0;
	int& r = iii; // r == 0
	cout << "address of iii: " << &iii << '\n'
		<< "address of r: " << &r << '\n'
		<< "value of iii: " << iii << '\n'
		<< "value of r: " << r << '\n';
	
	int jjj = 2;
	r = jjj; // does not change reference!
	cout << "address of iii: " << &iii << '\n'
		<< "address of r: " << &r << '\n'
		<< "value of iii: " << iii << '\n'
		<< "value of r: " << r << '\n';
	
	int kkk = 3;
	const int& ref = 1; // legal, not so obvious!
	cout << "&kkk: " << &kkk << '\n'
		<< "&ref: " << &ref << endl;
	return 0;	
}
