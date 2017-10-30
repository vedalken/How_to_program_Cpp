#include <iostream>
#include <map>

int main()
{
	std::map<int, double, std::less<int>> pairs;

	/* insert multiple pairs */
	pairs.insert( std::make_pair( 30, 111.11 ) );
	pairs.insert( std::make_pair( 10, 65.34 ) );
	pairs.insert( std::make_pair( 100, 1.1 ) );
	pairs.insert( std::make_pair( -6, 6.76 ) );
	pairs.insert( std::make_pair( 5, 33.33 ) );

	std::cout << "\n\nMap pairs contains:\nKey\tValue\n";

	for (auto mapItem : pairs)
		std::cout << mapItem.first << '\t' << mapItem.second << '\n';

	/* insert new pairs */
	pairs[40] = 9999.9;
	pairs[25] = 78543.54;
	
	std::cout << "\n\nAfter subscript operations, pairs contains:\nKey\tValue\n";

	for (auto mapItem : pairs)
		std::cout << mapItem.first << '\t' << mapItem.second << '\n';

	std::cout << std::endl;

	return 0;
}
