#include "Shipment.h"
Shipment::Shipment(int id){
	this->ID = id;
	this->date = "0000-00-00";
	this->supplierName = "Unknown";
	this->products = List<Product>();
}
Shipment::Shipment(int id, const string& date, const string& supplierName, const List<Product>& products){
	this->ID = id;
	this->date = date;
	this->supplierName = supplierName;
	this->products = products;
}
Shipment::Shipment(int id, const string& date, const List<Product>& products) {
	this->ID = id;
	this->date = date;
	this->supplierName = "Unknown";
	this->products = products;
}
Shipment::Shipment(const string& jsonStr) {
	FromJson(jsonStr);
}
int Shipment::GetID() const {
	return ID;
}
string Shipment::GetDate(){
	return date;
}
string Shipment::GetSupplierName(){
	return supplierName;
}
int const Shipment::GetProductsLenght() {
	return products.GetSize();
}
List<Product> Shipment::GetProducts(){
	return products;
}
void Shipment::SetDate(const string& date){
	this->date = date;
}
void Shipment::SetSupplierName(const string supplierName){
	this->supplierName = supplierName;
}
void Shipment::SetProducts(const List<Product>& products){
	this->products = products;
}
void Shipment::AddProduct(const Product& product){
	this->products.Add(product);
}

string Shipment::ToJson() const {
	json j;
	j["ID"] = ID;
	j["date"] = date;
	j["supplierName"] = CC::CP1251_to_UTF8(supplierName);

	json productArray = json::array();
	for (int i = 0; i < products.GetSize(); ++i) {
		Product p = products.Get(i);
		productArray.push_back(json::parse(p.ToJson()));
	}

	j["Products"] = productArray;
	return j.dump(4); // визуал!
}

void Shipment::FromJson(const string& jsonStr) {
	json j = json::parse(jsonStr);

	ID = j.value("ID", 0);
	date = j.value("Date", "0000-00-00");
	supplierName = CC::UTF8_to_CP1251(j.value("SupplierName", "Unknown"));
	products.Clear();
	if (j.contains("Products") && j["Products"].is_array()) {
		for (const auto& item : j["Products"]) {
			Product p(item.dump());
			products.Add(p);
		}
	}
	
}

string Shipment::ToString() {
	string Output = "ID: " + to_string(ID) + ", поставка: " + date + ", от: " + supplierName + ", дата продажи: " + date + ", список товаров: \n";
	for (int i = 0; i < this->products.GetSize(); i++) {
		Output += this->products.Get(i).ToString() + "\n";
	}
	return Output;
}

string ShowInfo(const Shipment& ship) {
	string Output = "Поставка: \nдата: " + ship.date + "\n" + "поставщик: " + ship.supplierName;
	return Output;
}
