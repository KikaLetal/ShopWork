#pragma once

#include <iostream>
#include "Object.h"
#include "Serializable.h"
#include <string>
#include "json.hpp"
#include "CoddingConverter.h"

using namespace std;
using json = nlohmann::json;
using CC = CoddingConverter;

class Product : private Object, protected Serializable
{
public:
	Product();
	Product(int id, const string& category, const string& name, double price, int quantity, const string& date);
	Product(const string& jsonStr);

	int GetID() const;
	string GetName();
	double GetPrice();
	int GetQuantity();
	string GetExpirationDate();
	string GetCategory();
	double GetOverprice();

	void SetID(int newID);
	void SetName(const string& name);
	void SetPrice(double price);
	void SetQuantity(int quantity);
	void SetExpirationDate(const string& date);
	void SetCategory(const string& category);
	void SetOverprice(const double& overprice);

	bool operator==(const Product& other) const;
	string ToString();

	string ToJson() const override;
	void FromJson(const string& jsonStr) override;

	friend string ShowInfo(const Product& prod);

private:
	string Name;
	string Category;
	string ExpirationDate;
	int Quantity;
	double Price;
	double Overprice;

};

