// main.cpp
// Calculating total sales of five different products with different
// prices. Read two pairs: product number and quanitity sold.
// Display total retail value of all products sold.
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	// Total retail value of sold products
	float totalRetailValue = 0.0;

	while (true)
	{
		int productNumber;
		int quantitySold;

		// Read product number and quantity sold
		cout << "\nEnter product number (1-5) and quantity: (enter -1 to quit)  ";
		cin >> productNumber >> quantitySold;
		
		// sentinel controled repetition
		if (productNumber == -1 || quantitySold == -1) 
			break;
		
		float currentProduct; // current value of all products sold
	
		// Check each product - each product have different value
		switch (productNumber) 
		{
			case 1:	// first product
				currentProduct = quantitySold * 2.98; // multiply quantity by price of a product
				break;

			case 2: // second product
				currentProduct = quantitySold * 4.50;
				break;

			case 3: // third product
				currentProduct = quantitySold * 9.98;
				break;

			case 4: // fourth product
				currentProduct = quantitySold * 4.49;
				break;

			case 5: // fifth product
				currentProduct = quantitySold * 6.87;
				break;

			default: 
				continue; // back to loop
		}

		totalRetailValue += currentProduct;
	} 

	cout << "\nTotal retail value: " << totalRetailValue << endl;

	return 0;
}
