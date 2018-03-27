#ifndef STACK_H
#define STACK_H

#include <deque>

template<typename T>
class Stack
{
public:
	// top element on stack
	T& top()
	{
		return m_stack.front();
	}

	// add element on stack
	void push(const T& a_value)
	{
		m_stack.push_front(a_value);
	}

	// remove element from stack
	void pop()
	{
		m_stack.pop_front();
	}

	// determine Stack is empty
	bool empty() const
	{
		return m_stack.empty();
	}

	// return stack size
	size_t size() const
	{
		return m_stack.size();
	}

private:
	std::deque<T> m_stack;
};

#endif
