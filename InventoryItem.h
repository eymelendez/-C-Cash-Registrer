// InventoryItem.h

#pragma once

#include<iostream>

using namespace::std;

#include"InventoryItem.h"

#include <cstring> //needed for strlen and strcpy

const int DEFAULT_SIZE = 51;

class InventoryItem
{
public:
	InventoryItem();
	InventoryItem(char *desc);
	InventoryItem(char *desc, double c, int u);
	~InventoryItem();

	void setDescription(char *d);
	void setCost(double c);
	void setUnits(int u);
	void setQtySold(int qs);

	char *getDescription() const;
	double getCost() const;
	int getUnits() const;
	void recordSale(int qs);

private:
	char *description; //item description
	double cost; //item cost
	int units; //Number of units on hand
	int qtySold;

	void InventoryItem::createDescription(int size, char *value);
};


