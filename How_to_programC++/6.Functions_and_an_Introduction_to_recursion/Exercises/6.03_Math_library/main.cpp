// main.cpp
// Program tests standard C++ math library function calls.
#include <iostream>
#include <cmath>
// use explicit "std::" to runtime library for used function/class calls
// defined in header files

int main()
{
	// initialize two values
	int number = -5; 
	double val = 0.95; // some value, less than 1
	double val1 = 2.3; // some value
	double val2 = 5.6; // some value

	std::cout << "abs("		<< number 	<< ") = " 	<< std::abs( number ) 		<< std::endl;
	std::cout << "fabs("	<< number 	<< ") = " 	<< std::fabs( number )		<< std::endl;
	std::cout << "floor("	<< val2 	<< ") = " 	<< std::floor( val2 )		<< std::endl;
	std::cout << "ceil("	<< val1 	<< ") = " 	<< std::ceil( val1 )		<< std::endl;

	std::cout << "exp(" 	<< number 	<< ") = " 	<< std::exp( number ) 		<< std::endl;
	std::cout << "pow(10," 	<< number 	<< ") = " 	<< std::pow( 10, number ) 	<< std::endl;
	std::cout << "sin(" 	<< number 	<< ") = " 	<< std::sin( number ) 		<< std::endl;
	std::cout << "cos(" 	<< number 	<< ") = " 	<< std::cos( number ) 		<< std::endl;
	std::cout << "tan("		<< number 	<< ") = " 	<< std::tan( number ) 		<< std::endl;
	std::cout << "asin(" 	<< val 		<< ") = "	<< std::asin( val )			<< std::endl;
	std::cout << "acos(" 	<< val 		<< ") = "	<< std::acos( val ) 		<< std::endl;
	std::cout << "atan(1.0) = "						<< std::atan( val ) 		<< std::endl;	

	std::cout << "sin(0) = " << std::sin( 0 ) << std::endl;
	std::cout << "cos(0) = " << std::cos( 0 ) << std::endl;
	std::cout << "tan(0) = " << std::tan( 0 ) << std::endl;
	std::cout << "cosh(0) = " << std::cosh( 0 ) << std::endl;
	std::cout << "sinh(0) = " << std::sinh( 0 ) << std::endl;


	return 0;	
}
