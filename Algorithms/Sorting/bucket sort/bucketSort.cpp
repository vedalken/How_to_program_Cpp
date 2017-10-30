#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>	// std::abs
#include <stdexcept>	// std::out_of_range
using namespace std;

void printVector( const vector<int> & );
void printBuckets( const vector< vector<int> > & );
void bucketSort( vector<int> & );
size_t extractDigit( int digit, int n );
int totalDigits( int n );
void gatherBuckets( vector<int> &, const vector< vector<int> > &);
int getMaxDigits( const vector<int> &);
void fillBuckets( const vector<int> &, vector< vector<int> > &, const int);

int main(int argc, char* argv[])
{
	const int vecSize = 11;
	vector<int> vec;

	for ( size_t i = 0; i < vecSize; ++i )
		vec.push_back( vecSize - i );
	
	printVector( vec );
	bucketSort( vec );
	printVector( vec );
	
	return 0;	
}

void printVector( const vector<int> & vec )
{
	for ( size_t index = 0; index < vec.size(); ++index )
		cout << setw( 5 ) << vec[ index ];
	cout << endl;
}

void printBuckets( const vector< vector<int> > & bucket )
{
	// number of rows
	size_t rows = bucket.size();

	// set row number to iterate only once over 1D array
	if ( rows == bucket[0].size() ) rows = 1;
		 
	for (size_t row = 0; row < rows; ++row)
	{
		// number of columns
		size_t cols = bucket[0].size();

		for (size_t column = 0; column < cols; ++column)
			cout << setw( 5 ) << bucket[ row ][ column ];
		
		cout << endl;
	}
}// end function printBucket

// bucket sort
void 
bucketSort( vector<int> & vec )
{
	// constant number of buckets
	// or number of rows
	static const int buckets = 10;
	
	// maximal number of digits contained in a vector 
	int maxDigits = getMaxDigits( vec ); 	

	// the bucket sort algorithm
	// first fill the bucket array based on element's one 
	// digit value  (least significant bit) and repeat the 
	// process for each subsequent digit position (tens, hundreds, etc.)
	for (int digit = 1; digit <= maxDigits; ++digit)
	{
		// create buckets (total size: 10 times vec length)
		vector< vector<int> > bucket( buckets, vector<int>() );
		
		// distribution pass
		fillBuckets( vec, bucket, digit );		
		
		// gathering pass
		gatherBuckets( vec, bucket );
	}
}
// end function bucketSort

// extract digit 'digit' from number 'n': (digit > 0)
size_t extractDigit( int digit, int n )
{
	if ( digit < 1 ) return -1; 

	// only one digit must left (when digit=1)
	while ( digit > 1 && n > 0 ) 
	{
		n /= 10;
		--digit;
	}
	
	// extract remaining digits	
	return n % 10;
}

// extract total number of digits
int totalDigits( int n )
{
	int mark = 1;
	int digits = 0;

	for ( ; mark < n; mark *= 10, ++digits ) ;
	
	return digits;	
}

// gather buckets from two dimensional (bucket) array denoted as `s'
// into one dimensional array denoted as `t'
void gatherBuckets( vector<int> & t, const vector< vector<int> > & s)
{
	int index = 0;
	size_t buckets = s.size(); // total buckets = 10
	
	// 1D array, collect first row buckets 
	if ( buckets == s[0].size() ) 
		buckets = 1;
		
	// collect buckets in particlar order
	for (size_t bucket = 0; bucket < buckets; ++bucket)
	{
		size_t cols = s[ bucket ].size();
		
		for (size_t element = 0; element < cols; ++element)
		{
			t[ index ] = s[ bucket ][ element ];
			++index;
		}
		
	}
}// end function gatherBuckets

// determine value with maximal number of digits
int getMaxDigits( const vector<int> &vec )
{
	// current maximal is the first value
	int max = abs( vec.front() );
	
	for (size_t element = 0; element < vec.size(); ++element)
	{
		if ( vec[ element ] > max )
			max = abs( vec[ element ] );
	}
	
	// return number of digits	
	return totalDigits( max );	
}


// fill the buckets from the vector 
void 
fillBuckets( const vector<int> &vec, vector< vector<int> > &buckets, const int digit)
{
	for (size_t index = 0; index < vec.size(); ++index)
	{
		// extract a digit from vector 
		size_t d = extractDigit( digit, vec[index] );

		try
		{
			buckets.at( d ).push_back( vec[index] );
		}
		catch ( const out_of_range &oor )
		{
			cout << "Our of Range error: " << oor.what() << '\n'
				<< "Exiting." << endl;
			return;
		}
	}
}// end function fillBuckets

