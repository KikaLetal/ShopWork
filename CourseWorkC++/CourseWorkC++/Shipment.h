#pragma once
 
#include "Object.h"
#include <string>
#include "List.h"
#include "Product.h"

using namespace std;

class Shipment : private Object
{
public:
	Shipment();
	Shipment(int id, const string& date, const string& supplierName, const List<Product>& products);
		string GetDate();
		string GetSupplierName();
		List<Product> GetProducts();
		void SetDate(const string& date);
		void SetSupplierName(const string supplierName);
		void SetProducts(const List<Product>& products);
		void AddProduct(const Product& product);
		friend void printShipmentDebug(const Shipment& p);
		string ToString();
private:
	string date;
	string supplierName;
	List<Product> products;

};

