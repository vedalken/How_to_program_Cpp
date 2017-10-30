#include <iostream>
#include <queue>

int main()
{
	std::queue<int> values;

	/* push elements */
	values.push(1);
	values.push(5);
	values.push(-10);

	std::cout << "Popping from queue: ";

	/* pop elements from queue */
	while ( !values.empty() )
	{
		std::cout << values.front() << ' ';
		values.pop();
	}

	std::cout << std::endl;
	return 0;
}
