// InventoryItem.cpp

#include<iostream>

using namespace::std;

#include"CashRegister.h"
#include"InventoryItem.h"

void InventoryItem::createDescription(int size, char *value)//
{
	// Allocate the default amount of memory for description.
	description = new char[size + 1];

	// Store a value in the memory.
	strcpy_s(description, size + 1, value);
}

// Constructor #1
InventoryItem::InventoryItem()
{
	//store an empty string in the description attribute.
	createDescription(DEFAULT_SIZE, "");

	//initialize cost and units.
	cost = 0.0;
	units = 0;
}

// Constructor #2
InventoryItem::InventoryItem(char * desc)
{
	//allocate memory and store the description.
	createDescription(strlen(desc), desc);

	//initialize cost and units.
	cost = 0.0;
	units = 0;
}

// Constructor #3
InventoryItem::InventoryItem(char * desc, double c, int u)
{
	//allocate memory and store the description.
	createDescription(strlen(desc), desc);

	//assign values to cost and units.
	cost = c;
	units = u;
}

InventoryItem::~InventoryItem()
{
	delete[] description;
}

void InventoryItem::setDescription(char * d)
{
	if (strlen(description) != strlen(d))
		delete[] description;

	createDescription(strlen(d), d);
}

void InventoryItem::setCost(double c)
{
	cost = c;
}

void InventoryItem::setUnits(int u)
{
	units = u;
}

void InventoryItem::setQtySold(int qs)
{
	qtySold = qs;
}

char * InventoryItem::getDescription() const
{
	return description;
}

double InventoryItem::getCost() const
{
	return cost;
}

int InventoryItem::getUnits() const
{
	return units;
}

void InventoryItem::recordSale(int qs)
{
	qtySold += qs;
	units -= qs;
}
