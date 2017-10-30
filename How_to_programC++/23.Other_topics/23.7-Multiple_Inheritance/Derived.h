#pragma once
#include <iostream>
#include "Base1.h"
#include "Base2.h"

class Derived : public Base1,
	        public Base2
{
	friend std::ostream& operator<<( std::ostream&, const Derived & );
public:
	Derived( int, char, double );

	double getReal() const { return _real; }
private:
	double _real;
};
