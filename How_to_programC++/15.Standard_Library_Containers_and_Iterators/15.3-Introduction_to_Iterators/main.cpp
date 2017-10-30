#include <iostream>
#include <iterator>

int main()
{
	std::istream_iterator<int> eois;
	std::istream_iterator<int> inputInt( std::cin );

	int number1(0), number2(0);

	/* read int from stdin */
	if (eois != inputInt) number1 = *inputInt;

	/* increment iterator position */
	++inputInt;

	/* read int from stdin */
	if (eois != inputInt) number2 = *inputInt;

	std::ostream_iterator<int> outputInt( std::cout );
        *outputInt = number1 + number2;

	std::cout << std::endl;

	return 0;
}
