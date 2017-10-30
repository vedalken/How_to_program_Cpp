#include <iostream>
#include <map>

int main()
{
	std::multimap<int, double, std::less<int>> multiPairs;

	std::cout << "There are currently " << multiPairs.count(15)
		<< " pairs with key 15 in the multimap";

	/* insert two value_type objects in pairs */
	multiPairs.insert( std::make_pair(15, 2.7) );
	multiPairs.insert( std::make_pair(15, 12.0) );

	std::cout << "\nAfter inserts, there are " << multiPairs.count(15)
		<< " pairs with key 15 in the multimap";

	/* insert multiple pairs */
	multiPairs.insert( std::make_pair( 30, 111.11 ) );
	multiPairs.insert( std::make_pair( 10, 65.34 ) );
	multiPairs.insert( std::make_pair( 100, 1.1 ) );
	multiPairs.insert( std::make_pair( -6, 6.76 ) );
	multiPairs.insert( std::make_pair( 5, 33.33 ) );

	std::cout << "\n\nMultimap pairs contains:\nKey\tValue\n";

	for (const std::pair<int,double> &mapItem : multiPairs)
		std::cout << mapItem.first << '\t' << mapItem.second << '\n';

	std::cout << std::endl;

	return 0;
}
