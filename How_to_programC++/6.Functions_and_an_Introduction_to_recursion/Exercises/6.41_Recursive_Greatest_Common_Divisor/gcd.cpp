// Calculate greatest common divisor
int gcd( int a, int b )
{
	if (b == 0)
		return a; // greatest common divisor
	else 
		return gcd( b, a%b );
}
