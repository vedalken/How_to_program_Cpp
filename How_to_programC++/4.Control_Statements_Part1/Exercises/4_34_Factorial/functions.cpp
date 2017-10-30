// Function implementation of factorial
long factorial( unsigned n )
{
	long		result	= 1; // factorial result
	unsigned	counter = 1; // counts number of multiplications

	// Compute factorial
	while (counter <= n)
	{
		result *= counter;
		++counter;
	}

	return result;
}// end function factorial

// Exponential function with argument x and precision prec
// Using Taylor approximation with series.
double exponential(double x, double prec )
{
	double		roundError = 1.0;	// initial value of rounding error
	double		sum	= 1; 			// current sum
	unsigned 	i = 1;

	double	inverseFactorial;	// 1/(n!)
	double	tmp;				// temporary sum
	double 	tmpx = x;			// temporary value of x


	while (roundError > prec)
	{
		// Inverse factorial i.e. 1/(n!)
		inverseFactorial =  1.0 / factorial(i); 	
		
		// Temporary sum
		tmp = sum;
		
		// Sum values
		sum += tmpx * inverseFactorial;
		
		// Temporary argument in sumation 
		tmpx *= x;	

		// Estimation of rounding error.. if last value contribute
		// less then user inserted precision (prec), then break the
		// loop!
		roundError = sum - tmp;
		
		// Increment counter
		++i;
	}

	return sum;
}
