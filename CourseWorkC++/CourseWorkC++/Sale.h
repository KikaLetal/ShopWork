#pragma once

#include "Object.h"
#include "Product.h"

using namespace std;

class Sale : private Object
{
public:
	Sale();
	Sale(int ID, int productID, int quantitySold, string date, double totalAmount);
	int	GetProductID();
	int GetQuantitySold();
	string GetDate();
	double GetTotalAmount();
	void SetQuantitySold(string& name);
	void SetDate(double price);
	void SetTotalAmount(int quantity);
	bool operator==(Product& other);
	string ToString();
	friend void printSaleDebug(const Sale& p);


private:
	int productID;
	int quantitySold;
	string date;
	double totalAmount;
};

