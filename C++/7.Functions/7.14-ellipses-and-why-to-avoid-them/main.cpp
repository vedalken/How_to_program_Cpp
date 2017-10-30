#include <iostream>
#include <cstdarg>

double findAverage( const int, ... );

int main()
{
	std::cout << "Average: " << findAverage(5, 1, 2, 3, 4, 5) << std::endl;
	std::cout << "Average: " << findAverage(6, 1, 2, 3, 4, 5, 6) << std::endl;

	return 0;
}

double findAverage( const int countArgs, ... )
{
	long sum = 0;

	// we access the ellipses through a va_list macro
	va_list list;

	// initialize va_list through va_start macro
	va_start(list, countArgs);
	
	// loop over ellipses arguments
	for (int arg = 0; arg < countArgs; ++arg)
	{
		// sum integer arguments and shift to next argument
		sum += va_arg(list,int);
	}

	// clean up va_list
	va_end(list);

	return static_cast<double>(sum) / countArgs;
}
