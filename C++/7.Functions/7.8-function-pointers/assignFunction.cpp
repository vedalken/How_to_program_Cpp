#include <iostream>
#include <array>
#include <iomanip>

int foo() { return 0; }
int goo() { return 0; }
double gfoo() { return 0.0; }

auto fooo( double x ) -> decltype(x) 
{ return x;}

template <typename T1, typename T2>
bool ascending( T1 t1, T2 t2 )
{ 
	return t1 < t2; 
}

template <typename T1, typename T2>
bool descending( T1 t1, T2 t2 )
{
	return t1 > t2;
}

template <typename T, std::size_t N>
void selectionSort( std::array<T,N> &aArray, bool (*pSortOrder)(T,T) = descending )
{
	for (size_t startIndex = 0; startIndex < N; ++startIndex)
	{
		size_t targetIndex = startIndex;
		for (size_t currentIndex = targetIndex + 1; currentIndex < N;
				++currentIndex)
		{
			
			if (pSortOrder(aArray.at(currentIndex), aArray.at(targetIndex)) )
				targetIndex = currentIndex;
		}

		std::swap( aArray.at(startIndex), aArray.at(targetIndex) );
	}
}// end selectionSort template

template <typename T, std::size_t N>
void printArray( const std::array<T,N> & arry )
{
	for (const auto &el : arry)
		std::cout << std::setw( 3 ) << el;

	std::cout << '\n';
}

int main()
{
	int (*pFoo)() = foo;
	int (*pGoo)() = goo;
	double (*pGFoo)();
	pGFoo = gfoo;
	pFoo = goo;
	
	double dValue = 3.1415926;
	auto (*pFooo)(double) = fooo;
	
	std::cout << "pFoo = " << pFoo 
		<< "\npGoo = " << pGoo 
		<< "\npGFoo = " << pGFoo 
		<< "\npFooo value = " << pFooo(dValue) << std::endl;
	
	std::array<int,10> arry = {1,2,3,4,5,6,7,8,9,10};
	selectionSort( arry );
	printArray( arry );

	selectionSort( arry, ascending );
	printArray( arry );

	return 0;
}
