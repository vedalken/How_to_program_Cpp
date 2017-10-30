// Invoice.cpp
// Invoice class implementation for separating from interface.
#include <iostream>
#include <string>
#include "Invoice.h"
using std::string;
using std::cout;
using std::endl;

// Constructor invoice class-initialize data members
Invoice::Invoice(string name, string description, int numberOfItems, int price)
{
	setPartName( name );
	setPartDescription( description );
	setQuantityOfItems( numberOfItems );
	setPricePerItem( price );
}

// function sets and gets part name
void Invoice::setPartName( string name ) { partName = name;	}
string Invoice::getPartName() { return partName; }

// function sets and gets part description
void Invoice::setPartDescription( string description ) { 
	partDescription = description; 
}
string Invoice::getPartDescription() { return partDescription; }

// function sets and gets quantity of items
void Invoice::setQuantityOfItems( int numberOfItems ) 
{
	// perform validation
	if (numberOfItems >= 0)
		quantity = numberOfItems;
	
	if (numberOfItems < 0) 
	{
		quantity = 0;
		cout << "Invalid quantity! Set to 0." << endl;
	}
}

int Invoice::getQuantityOfItems() { return quantity; }

// function sets and gets price per item
void Invoice::setPricePerItem( int price ) 
{
	if (price >= 0) 
		pricePerItem = price; 

	if (price < 0) 
	{
		price = 0;
		cout << "Invalid price! Set to 0." << endl;
	}
}
int Invoice::getPricePerItem() { return pricePerItem; }

// function gets invoice amount
int Invoice::getInvoiceAmount() { return quantity*pricePerItem; }

// display invoice information
void Invoice::displayInvoice()
{
	cout <<"\n-----INVOICE-----" 
		<< "\nPart Name:\t"		<< getPartName()
		<< "\nDescription:\t"	<< getPartDescription() 
		<< "\nQuantity:\t"		<< getQuantityOfItems() 
		<< "\nPrice per Item:\t"<< getPricePerItem()
		<< "\nTotal amount:\t"	<< getInvoiceAmount() << endl;
}

