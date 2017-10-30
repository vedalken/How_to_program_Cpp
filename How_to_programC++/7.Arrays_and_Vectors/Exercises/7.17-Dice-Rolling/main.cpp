// main.cpp
// Simulate two rolling dices N times.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using std::cout; // iostream header
using std::endl;
using std::fixed;
using std::setw; // iomanip header
using std::setprecision;
using std::srand; //cstdlib header
using std::rand;
using std::time; //ctime header

// generate number of a rolling die
inline int nRollDie() { return ( 1 + rand() % 6 ); }

int main()
{
	srand( time(0) ); // seed generator

	const int nNumOfDiceToss = 10000; 	// number of tossing die
	int an2Dice[ nNumOfDiceToss ];		// array of two dice sum
	
	// simulate two rolling dices
	for ( int roll = 0; roll < nNumOfDiceToss; ++roll )
	{
		int nDie1 = nRollDie(); // first dice rolling
		int nDie2 = nRollDie(); // second dice rolling
		an2Dice[ roll ] = nDie1 + nDie2;
	}
	
	// count frequency for two dice toss
	int anDiceFreq[ 13 ] = {};

	for ( int roll = 0; roll < nNumOfDiceToss; ++roll )
		++anDiceFreq[ an2Dice[ roll ] ];
	
	// total sum of rolling dice
	int nTotalSum = 0;
	
	for ( int i = 0; i < 13; ++i )
		nTotalSum += anDiceFreq[ i ];
	
	// display frequency of two dices
	cout << setw(2) << "n" << setw(7) << "freq" << setw(7) << "ratio" << endl;
	
	for ( int freq = 2; freq < 13; ++freq )
	{
		// probability
		const double nProb = 
			static_cast<double>( anDiceFreq[ freq ] ) / nTotalSum;

		cout << setw(2) << freq << ":" << setw(7) << anDiceFreq[ freq ] 
			 << fixed << setprecision(2) << setw(7) << nProb << endl;
	}
	return 0;
}//end main
