// maximum.h
// Maximum function template definition

template <typename T> 
T maximum( T value1, T value2, T value3 )
{
	T maximalValue = value1; // assume maximal value is value1

	// determine whether value2 is greater than maximalValue
	if (maximalValue < value2)
		maximalValue = value2; // value1 is not maximal

	// determine wheter value3 is greater than maximalValue
	if (maximalValue < value3)
		maximalValue = value3; // value1, value2 are not maximal
	
	return maximalValue; // return maximal value
}
