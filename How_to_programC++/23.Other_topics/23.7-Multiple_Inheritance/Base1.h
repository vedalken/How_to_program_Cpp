#pragma once

class Base1
{
public:
	Base1( int value )
		: _value( value )
	{
		// empty
	}

	int getValue() const { return _value; }
protected:
	int _value;
};
