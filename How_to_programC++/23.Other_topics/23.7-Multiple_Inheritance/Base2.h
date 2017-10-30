#pragma once

class Base2
{
public:
	Base2( char latter )
		: _latter( latter )
	{
		// empty
	}

	char getValue() const { return _latter; }
protected:
	char _latter;
};
