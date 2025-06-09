#pragma once

#include "Product.h"
#include "Shipment.h"
#include "Sale.h"
#include "List.h"
#include "Dictionary.h"
#include <fstream>
#include "json.hpp"
#include <string>
#include "CoddingConverter.h"
#include "Timee.h"

#include <filesystem>
namespace fs = std::filesystem;

using json = nlohmann::json;
using namespace std;

const string JSON_DATA_FOLDER = "x64/Debug/data/";

class Store
{
public:
	Product ConstructProduct(const string& category, const string& name, double price, int quantity, const string& date);
	void SetOverprice(const int& ID, const double& overprice);
	void ReleaseProduct(const int& ID, const int& count);
	void AddProduct(const Product& product);
	void EditProduct(int productID, const Product& updatedProduct);
	void RemoveProduct(int productID);
	void RemoveExpiredProducts();
	Shipment ConstructShipment(const string& date, const List<Product>& products, const string& supplierName);
	void AddShipment(const Shipment& shipment);
	List<Shipment> GetShipmentsByDate (const string& date);
	void AddSale(const Sale& sale) ;
	List<Sale> GetSalesByDate(const string& date) ;
	List<Product> GetProductsList() const;
	Dictionary<int, Product> GetProducts() const;
	Dictionary<int, string> GetCategories();
	void LoadData() ;
	void SaveData() ;
	void LoadProducts() ;
	void LoadSales() ;
	void LoadShipments() ;
	void SaveProducts() ;
	void SaveSales() ;
	void SaveShipments() ;
	template <typename T>
	int GetActualID(Dictionary<int, T>& dict) {
		int id = 0;
		while (dict.ContainsKey(id)) {
			id++;
		}
		return id;
	};
private:
	Dictionary<int, Product> products;
	Dictionary<int, Sale> sales;
	Dictionary<int, Shipment> shipments;
};

