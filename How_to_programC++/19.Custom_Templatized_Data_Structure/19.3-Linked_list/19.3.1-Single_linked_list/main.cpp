#include <iostream>
#include <string>
#include "list.h"

void instructions();

template <typename T>
void testList( List<T>& listObject, const std::string& a_typeName);

int main()
{
    List<int> integerList;
    testList(integerList, "integer");

    List<double> doubleList;
    testList(doubleList, "double");

    return 0;    
}

void instructions()
{
    std::cout << "Enter one of the following:\n"
	      << "  1 to insert at beginning of list\n"
	      << "  2 to insert at end of list\n"
	      << "  3 to delete from beginning of list\n"
	      << "  4 to delete from end of list\n"
	      << "  5 to end list processing\n";
}

template <typename T>
void testList( List<T>& listObject, const std::string& a_typeName)
{
    std::cout << "Testing a List of " << a_typeName << " values.\n";
    instructions();

    T value;
    int choice;

    do {
	std::cout << "? ";
	std::cin >> choice;

	switch (choice)
	{
	    case 1:
		// insert at beginning
		std::cout << "Enter " << a_typeName << ": ";
		std::cin >> value;
		listObject.insertFront(value);
		listObject.print();
		break;
	    case 2:
		// insert at end
		std::cout << "Enter " << a_typeName << ": ";
		std::cin >> value;
		listObject.insertBack(value);
		listObject.print();
		break;
	    case 3:
		// remove from beginning
		value = 0;
		if (listObject.removeFront(&value)) {
		    std::cout << value << " removed from front of the list.\n";
		}

		listObject.print();
		break;
	    case 4:
		// remove from end
		value = 0;
		if (listObject.removeBack(&value)) {
		    std::cout << value << " removed from back of the list.\n";
		}

		listObject.print();
		break;
	    default:
		break;
	}
    } while (choice < 5);

    std::cout << "End list test\n\n";
} // end function testList
