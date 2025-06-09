#pragma once
 
#include "Object.h"
#include <string>
#include "List.h"
#include "Product.h"
#include "json.hpp"
#include "CoddingConverter.h"


using namespace std;
using json = nlohmann::json;
using CC = CoddingConverter;

class Shipment : private Object, protected Serializable
{
public:
	Shipment() = default;
	Shipment(int id);
	Shipment(int id, const string& date, const string& supplierName, const List<Product>& products);
	Shipment(int id, const string& date, const List<Product>& products);
	Shipment(const string& jsonStr);

	int GetID() const;
	string GetDate();
	string GetSupplierName();
	const int GetProductsLenght();
	List<Product> GetProducts();

	void SetDate(const string& date);
	void SetSupplierName(const string supplierName);
	void SetProducts(const List<Product>& products);

	string ToJson() const override;
	void FromJson(const string& jsonStr) override;

	void AddProduct(const Product& product);
	string ToString();
	friend string ShowInfo(const Shipment& ship);
private:
	string date;
	string supplierName;
	List<Product> products;
};

