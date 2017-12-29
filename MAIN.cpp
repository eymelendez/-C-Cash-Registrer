// MAIN.cpp 

#include <iostream>
#include <iomanip>

using namespace std;

#include "CashRegister.h"
#include "InventoryItem.h"

int main()
{
	int numSelected;//int variable holds number selected
	int qtySelected;//double variable holds number of items ordered
	char again = 'Y';//char variable holds answer (y or n)

					 //double subTotal;
	const int NUM_ITEMS = 5; //      

							 //array containing inventory items
	InventoryItem inventory[] =
	{
		InventoryItem("Hammer", 6.95, 12),
		InventoryItem("Wrench", 8.75, 20),
		InventoryItem("Pliers", 3.75, 10),
		InventoryItem("Ratchet", 7.95, 14),
		InventoryItem("Screwdriver", 2.50, 22)
	};

	//format output
	cout << fixed << showpoint << setprecision(2);

	while (again == 'Y' || again == 'y')
	{
		//display current inventory
		cout << "Listing of current inventory" << endl;
		cout << " " << endl;

		//table format
		cout << setw(7) << "Item Number"
			<< setw(17) << "Description"
			<< setw(8) << "Cost" << setw(8)
			<< setw(17) << "Units on Hand\n";
		cout << "------------------------------------------------------------\n";

		//for loop display allowing to display contents of array into table format
		for (int i = 0; i < NUM_ITEMS; i++)
		{
			cout << setw(7) << i;
			cout << setw(17) << inventory[i].getDescription();
			cout << setw(10) << "$" << inventory[i].getCost();
			cout << setw(8) << inventory[i].getUnits() << endl;
		}
		cout << "" << endl;
		cout << "" << endl;

		// prompt user to input inventory number purchase
		cout << "Please enter the item number of the inventory item you wish to purchase: ";
		cin >> numSelected;
		cout << endl;

		// validation loop
		while ((numSelected < 0) || (numSelected > 4))
		{
			cout << "Invalid Selection. Please enter an inventory item number 0-4: ";
			cin >> numSelected;
		}

		// verify the requested item is available or not
		if (inventory[numSelected].getUnits() > 0)
		{
			//prompt for quantity of items wished to purchase
			cout << "Please enter the quantity you wish to purchase: ";
			cin >> qtySelected;
			cout << endl;

			//validation loop
			while (qtySelected > inventory[numSelected].getUnits() || qtySelected < 1)
			{
				cout << "Invalid quantity. Please enter quantity less than or equal to " << inventory[numSelected].getUnits() << " units: ";
				cin >> qtySelected;
			}

			CashRegister sale = CashRegister(&inventory[numSelected], qtySelected);//
			cout << " " << endl;

			//display subtotal, tax, and total
			cout << "Total cost (30% markup on above listed cost included): " << endl;
			cout << " " << endl;

			//create a sale object for this transaction
			//specify the item cost, but use the default
			//tax rate of 6 percent
			//CashRegister sale2(CashRegister sale); //???
			// display results
			cout << "Subtotal:\t $" << sale.getSubtotal() << endl;
			cout << "Sales tax:\t $" << sale.getSalesTax() << endl;
			cout << "Total:\t\t $" << sale.getTotal() << endl;

			//update inventory
			sale.updateInventory();
		}
		else
		{
			cout << "No quantity on hand for " << inventory[numSelected].getDescription() << endl;
		}

		//allow user to make another purchase
		cout << "\nWould you like to make another purchase? ";
		cin >> again;
	}

	system("pause");
	return 0;

} // end main. 15 de agosto de 2017 - Successful!

/*Output:

Listing of current inventory

Item Number      Description    Cost   Units on Hand
------------------------------------------------------------
0           Hammer         $6.95      12
1           Wrench         $8.75      20
2           Pliers         $3.75      10
3          Ratchet         $7.95      14
4      Screwdriver         $2.50      22


Please enter the item number of the inventory item you wish to purchase: 0

Please enter the quantity you wish to purchase: 2


Total cost (30% markup on above listed cost included):

Subtotal:        $18.07
Sales tax:       $1.08
Total:           $19.15

Would you like to make another purchase? Y
Listing of current inventory

Item Number      Description    Cost   Units on Hand
------------------------------------------------------------
0           Hammer         $6.95      10
1           Wrench         $8.75      20
2           Pliers         $3.75      10
3          Ratchet         $7.95      14
4      Screwdriver         $2.50      22


Please enter the item number of the inventory item you wish to purchase: 2

Please enter the quantity you wish to purchase: 3


Total cost (30% markup on above listed cost included):

Subtotal:        $14.63
Sales tax:       $0.88
Total:           $15.50

Would you like to make another purchase? N
Press any key to continue . . .
*/


