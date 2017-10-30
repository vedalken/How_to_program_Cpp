#include <iostream>

struct Advertising
{
	int nAllAds;
	int nClickAds;
	float fEarnMoneyForOneAds;
};

void PrintStatisticInfo(Advertising sAds);

int main()
{
	using namespace std;
	
	Advertising sAds;

	cout << "Number of advertisments:  ";
	cin >> sAds.nAllAds;

	cout << "Number of clicked advertisments: ";
	cin >> sAds.nClickAds;

	cout << "Money earned from one advertisment: ";
	cin >> sAds.fEarnMoneyForOneAds;
	
	cout << endl;
	// print information
	PrintStatisticInfo(sAds);

	return 0;
}

// sAds is local variable
void PrintStatisticInfo(Advertising sAds)
{
	using namespace std;
	
	cout << "Number of ads: " << sAds.nAllAds << endl;
	
	// casting
	float fClickRatio = static_cast<float>(sAds.nClickAds) / sAds.nAllAds;
	
	short int nProcentFactor = 100;
	cout << "Procentage of clicked ads: " << fClickRatio * nProcentFactor << endl;
		
	// Earned money
	cout << "Total earnings: $" << sAds.fEarnMoneyForOneAds * sAds.nClickAds << endl;
}

