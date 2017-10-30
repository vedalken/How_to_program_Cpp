#include <iostream>
#include <array>

class Base
{
public:
	virtual void print() const = 0; // pure virtual
};

class DerivedOne : virtual public Base
{
public:
	void print() const {
		std::cout << "DerivedOne\n";
	}		
};// end class DerivedOne

class DerivedTwo : virtual public Base
{
public:
	void print() const {
		std::cout << "DerivedTwo\n";
	}
};// end class DerivedTwo

class Multiple : public DerivedOne,
	         public DerivedTwo
{
public:
	void print() const {
		DerivedTwo::print();
	}
};// end class Multiple

int main()
{
	Multiple both;
	DerivedOne one;
	DerivedTwo two;
	std::array<Base *, 3> array;

	array[ 0 ] = &both;
	array[ 1 ] = &one;
	array[ 2 ] = &two;

	for ( const auto i : array )
		i->print();

	return 0;
}
