// CashRegister.cpp

#include<iostream>

using namespace std;

#include "CashRegister.h"

CashRegister::CashRegister(InventoryItem *i)
{
	item = i;
	quantity = 0;
}

CashRegister::CashRegister(InventoryItem *i, int q)
{
	item = i;
	quantity = q;
}

CashRegister::~CashRegister()
{
	// cout << "Deleting Objects..." << endl;
}

void CashRegister::updateInventory()
{
	item->recordSale(quantity);
}

void CashRegister::setItem(InventoryItem *i)
{
	item = i;
}

void CashRegister::setQuantity(int q)
{
	quantity = q;
}

int CashRegister::getQuantity() const
{
	return quantity;
}

double CashRegister::getCost() const
{
	return item->getCost();
}

double CashRegister::getUnitPrice() const
{
	double price;
	price = getCost() + getCost() * MARKUP;
	return price;
}

double CashRegister::getSubtotal() const
{
	double subtotal;
	subtotal = getUnitPrice() * quantity;
	return subtotal;
}

double CashRegister::getSalesTax() const
{
	double tax;
	tax = getSubtotal() * TAX_RATE;
	return tax;
}

double CashRegister::getTotal() const
{
	double total;
	total = getSubtotal() + getSalesTax();
	return total;
}