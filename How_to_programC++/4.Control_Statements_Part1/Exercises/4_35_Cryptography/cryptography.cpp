// cryptography.cpp
// Encrypte 4 digit positive number. To every digit add 7,
// and swap second digit with last, and first with penultimate.
#include <iostream>
using std::cout;
using std::endl;

// function encrypte number
void encryper( int number )
{
	const short add = 7777; // every digit add 7
	short encrypteNumber;	// encrypted number

	encrypteNumber = number + add;
	
	int numberOfDigits 	= 4;	// default number of digits
	int decimal 		= 1e3; 	// maximal decimal positioanl value after addition with 7777

	if (encrypteNumber > 9999) { 
		numberOfDigits = 5;
		decimal = 1e4;
	}
	
	cout << decimal << endl;
	cout << encrypteNumber << endl;

	int digit;					// current digit
	int tmp1, tmp2, tmp3, tmp4; // temporary digit, from most significant to less significant
	int tmp5 = 0; 				// last digit (if!) 
	int counter = 1;

	// perform main encryption algorithm
	while (counter <= numberOfDigits) // count only for 5 digit number
	{
		// current digit after division with decimal
		// integer division!
		digit = encrypteNumber / decimal;
		cout << digit << endl;

		if (counter == 1) // first digit
		{ 
			tmp1 = digit; 
		}
		else if (counter == 2) // second digit
		{ 
			tmp2 = digit; 
		}
		else if (counter == 3) 	// swap first and third digit
		{
			int tmp = tmp1;	// temporary save first digit
			tmp1 = digit;	
			tmp3 = tmp;
		}
		else if (counter == 4) // swap second and fourth digit
		{
			int tmp = tmp2; // temprary save second digit
			tmp2 = digit;
			tmp4 = tmp;
		}
		else {
			if (numberOfDigits == 5) {
				tmp5 = digit;
			}
		}

		// reminder after division - current new number
		encrypteNumber %= decimal;

		// next positional value
		decimal /= 10;	
		
		// increment counter
		++counter;
	} // end while loop

	// Display encrypted digits
	if (numberOfDigits > 4) {
		cout << tmp1 << tmp2 << tmp3 << tmp4 << tmp5 << endl;
	}
	else {
		cout << tmp1 << tmp2 << tmp3 << tmp4 << endl;
	}

} // end encryper function






