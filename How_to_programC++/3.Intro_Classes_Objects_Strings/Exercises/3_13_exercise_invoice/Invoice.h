// Invoice.h
// Invoice class definition contains data members for a general store.
#include <string> // for string declaration
using std::string;

class Invoice 
{
	private:
		string partName;		// name of a part in a store
		string partDescription; // part description
		int quantity;			// quantify of the item being purchased
		int pricePerItem;		// a price per item
	public:
		// constructor initialize data members
		Invoice (string name, string description, int numberOfItems, int price);
		
		// set and get part name
		void setPartName(string name);
		string getPartName();
		
		// set and get part description
		void setPartDescription(string description);
		string getPartDescription();
		
		// set and get quantity of the item
		void setQuantityOfItems(int quantifyItem);
		int getQuantityOfItems();

		// set and get price per item
		void setPricePerItem(int price);
		int getPricePerItem();

		// get invoice amount
		// multiply price per item and quantity of items
		int getInvoiceAmount();

		// display invoice 
		void displayInvoice();
};
