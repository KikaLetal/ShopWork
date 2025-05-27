#pragma once

#include "Object.h"
#include "Serializable.h"

using namespace std;

class Product : private Object, protected Serializable
{
public:
	Product();
	Product(int id, string& name, double price, int quantity);
	string GetName();
	double GetPrice();
	int GetQuantity();
	string GetExpirationDate();
	void SetName(string& name);
	void SetPrice(double price);
	void SetQuantity(int quantity);
	void SetExpirationDate(string& date);
	bool operator==(Product& other);
	string ToString();
	friend void printProductDebug(const Product& p);


private:
	string Name;
	string ExpirationDate;
	int Quantity;
	double Price;

};

