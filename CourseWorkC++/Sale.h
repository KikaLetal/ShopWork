#pragma once

#include "Object.h"
#include "Serializable.h"
#include <iostream>
#include <string>
#include "json.hpp"
#include "CoddingConverter.h"

using namespace std;
using json = nlohmann::json;
using CC = CoddingConverter;

class Sale : private Object, protected Serializable
{
public:
	Sale();
	Sale(int id, int productID, int quantitySold, const string& date, double totalAmount);
	Sale(const string& jsonStr);

	int GetID() const;
	int	GetProductID();
	int GetQuantitySold();
	string GetDate();
	double GetTotalAmount();

	void SetProductID(int productID);
	void SetQuantitySold(int quantitySold);
	void SetDate(const string& date);
	void SetTotalAmount(double totalAmount);

	bool operator==(const Sale& other) const;
	string ToString();

	string ToJson() const override;
	void FromJson(const string& jsonStr) override;

private:
	int productID;
	int quantitySold;
	string date;
	double totalAmount;
};

