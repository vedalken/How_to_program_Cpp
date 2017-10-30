#include <iostream>
#include <queue>

int main()
{
	std::priority_queue<double> priorities;

	/* push elements */
	priorities.push(100.34);
	priorities.push(54.13);
	priorities.push(1.0);

	std::cout << "Popping from priorities: ";

	/* pop element from priority queue */
	while ( !priorities.empty() )
	{
		std::cout << priorities.top() << ' ';
		priorities.pop();
	}

	std::cout << std::endl;
	return 0;
}
