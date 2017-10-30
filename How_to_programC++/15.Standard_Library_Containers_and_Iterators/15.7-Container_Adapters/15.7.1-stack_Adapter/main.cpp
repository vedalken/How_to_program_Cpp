#include <iostream>
#include <stack>
#include <list>
#include <vector>

template <typename T> void pushElement(T &a_stackRef);
template <typename T> void popElement(T &a_stackRef);

int main()
{
	/* default deque as undelying container */
	std::stack<int> intDequeStack;

	/* vector as underlying continer */
	std::stack<int, std::vector<int>> intVectorStack;

	/* list as underlying container */
	std::stack<int, std::list<int>> intListStack;

	std::cout << "Pushing onto intDequeStack: ";    pushElement(intDequeStack);
	std::cout << "\nPushing onto intVectorStack: "; pushElement(intVectorStack);
	std::cout << "\nPushing onto intListStack: ";   pushElement(intListStack);
	
	std::cout << "\n\nPopping from intDequeStack: "; popElement(intDequeStack);
	std::cout << "\nPopping from intVectorStack: ";  popElement(intVectorStack);
	std::cout << "\nPopping from intListStack: ";    popElement(intListStack);
	std::cout << std::endl;

	return 0;
}

template<typename T>
void pushElement(T &a_stackRef)
{
	for (int i = 0; i < 10; ++i) 
	{
		a_stackRef.push(i);
		std::cout << a_stackRef.top() << ' ';
	}
}

template<typename T>
void popElement(T &a_stackRef)
{
	while ( !a_stackRef.empty() )
	{
		std::cout << a_stackRef.top() << ' ';
		a_stackRef.pop();
	}
}
