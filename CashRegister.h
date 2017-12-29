/*Edwin Y. Melendez Lopez #89139
Raudo E. Columna Manon  #86724

CECS 3212 Sec. 20
15 de agosto de 2017
Profesora Claudia Talavera

Pag. 808 Cap. 13 Cash Register Exercise*/

/*Descrition of Exercise:


Design a  CashRegister  class that can be used with the  InventoryItem  class discussed in this chapter. 
The  CashRegister  class should perform the following:   

1. Ask the user for the item and quantity being purchased.
2. Get the item’s cost from the  InventoryItem  object.
3. Add a 30% profit to the cost to get the item’s unit price.
4. Multiply the unit price times the quantity being purchased to get the purchase subtotal.    
5. Compute a 6% sales tax on the subtotal to get the purchase total.
6. Display the purchase subtotal, tax, and total on the screen.
7. Subtract the quantity being purchased from the  onHand  variable of the InventoryItem  class object.

Implement both classes in a complete program. Feel free to modify the  InventoryItem  class in any way necessary.   

Input Validation: Do not accept a negative value for the quantity of items being purchased.

*/


// CashRegister.h



#pragma once

#include<iostream>

using namespace::std;

#include "InventoryItem.h"

const double TAX_RATE = 0.06;
const double MARKUP = .30;

class CashRegister
{

public:

	CashRegister(InventoryItem *); // Constructor
	CashRegister(InventoryItem *, int);
	~CashRegister(); // Destructor

	void setItem(InventoryItem *);
	void setQuantity(int);
	void updateInventory();

	int getQuantity() const;
	double getCost() const;
	double getUnitPrice() const;
	double getSubtotal() const;
	double getSalesTax() const;
	double getTotal() const;

private:
	InventoryItem *item;
	int quantity;
};