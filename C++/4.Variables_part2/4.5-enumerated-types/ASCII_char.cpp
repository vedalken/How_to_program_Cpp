#include <iostream>

int main()
{
	using namespace std;

	for (int x = 0; x < 128; x++ ) {
		cout << x << ". " << (char)x << " ";
	}

	cin.get();

	return 0;	
}
