#pragma once

#include <iostream>
#include <stdexcept>

template<class T>
class Storage8
{
public:
	void set(int index, const T& value)
	{
		if ( index < 0 || index > 8 )
			throw std::out_of_range("Array index out of range");
		m_array[ index ] = value;
	}

	const T& get(int index) const
	{
		if ( index < 0 || index > 8 )
			throw std::out_of_range("Array index out of range");
		return m_array[index];
	}
private:
	T m_array[8];
};

// bolean class specialization
template<> // no template parameters
class Storage8<bool>
{
public:
	Storage8() : m_value(0)
	{
	}

	void set(int index, bool value)
	{
		if ( index < 0 || index > 8 )
			throw std::out_of_range("Array index out of range");
		
		unsigned char mask = (1 << index);
		if (value) m_value |= mask;
		else       m_value &= ~mask;
	}

	bool get(int index) const
	{
		if ( index < 0 || index > 8 )
			throw std::out_of_range("Array index out of range");
		
		unsigned char mask = (1 << index);
		
		return (m_value & mask);
	}
private:
	unsigned char m_value;
};

typedef Storage8<int> Storage8int;
