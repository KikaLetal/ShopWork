#include "Product.h"

Product::Product(){
	this->ID = -1;
	this->Name = "Unknown";
	this->ExpirationDate = "0000-00-00";
	this->Quantity = 0;
	this->Price = 0.0;
	this->Category = "Unknown";
	this->Overprice = 0.0;
}
Product::Product(int id, const string& category, const string& name, double price, int quantity, const string& date){
	this->ID = id;
	this->Name = name;
	this->ExpirationDate = date;
	this->Quantity = quantity;
	this->Price = price;
	this->Category = category;
	this->Overprice = 0.0;
}
Product::Product(const string& jsonStr) {
	FromJson(jsonStr);
}
int Product::GetID() const {
	return ID;
}
string Product::GetName(){
	return Name;
}
double Product::GetPrice(){
	return Price;
}
int Product::GetQuantity(){
	return Quantity;
}
string Product::GetExpirationDate(){
	return ExpirationDate;
}
string Product::GetCategory() {
	return Category;
}
double Product::GetOverprice() {
	return Overprice;
}
void Product::SetID(int newID) {
	ID = newID;
}
void Product::SetName(const string& name){
	Name = name;
}
void Product::SetPrice(double price){
	Price = price;
}
void Product::SetQuantity(int quantity){
	Quantity = quantity;
}
void Product::SetExpirationDate(const string& date){
	ExpirationDate = date;
}
void Product::SetCategory(const string& category) {
	Category = category;
}
void Product::SetOverprice(const double& overprice) {
	Overprice = overprice;
}
bool Product::operator==(const Product& other) const{
	return Name == other.Name &&
		Price == other.Price &&
		Quantity == other.Quantity &&
		ExpirationDate == other.ExpirationDate;
}
string Product::ToString(){
	return "ID: " + to_string(ID) + ", товар: " + Name + ", категория: " + Category + ", количество: " + to_string(Quantity) + ", цена товара: " + to_string(Price) + ", наценка: " + to_string(Overprice) + ", выйдет срок годности: " + ExpirationDate;
}

string Product::ToJson() const {

	json j;
	j["ID"] = ID;
	j["Name"] = CC::CP1251_to_UTF8(Name);
	j["Price"] = Price;
	j["Overprice"] = Overprice;
	j["Quantity"] = Quantity;
	j["Category"] = CC::CP1251_to_UTF8(Category);
	j["ExpirationDate"] = CC::CP1251_to_UTF8(ExpirationDate);
	return j.dump(4); // визуал!
}

void Product::FromJson(const string& jsonStr) {
	json j = json::parse(jsonStr);
	ID = j.value("ID", 0);
	Name = CC::UTF8_to_CP1251(j.value("Name", "Unknown"));
	Price = j.value("Price", 0.0);
	Quantity = j.value("Quantity", 0);
	Overprice = j.value("Overprice", 0.0);
	Category = CC::UTF8_to_CP1251(j.value("Category", "Unknown"));
	ExpirationDate = CC::UTF8_to_CP1251(j.value("ExpirationDate", "0000-00-00"));
}

string ShowInfo(const Product& prod) {
	string Output = "Товар:";
	Output.append("\n").append("название товара: ").append(prod.Name);
	Output.append("\n").append("категория товара: ").append(prod.Category);
	Output.append("\n").append("количество для поставки: ").append(to_string(prod.Quantity));
	Output.append("\n").append("стоимость товара: ").append(to_string(prod.Price));
	Output.append("\n").append("наценка товара: ").append(to_string(prod.Overprice));
	Output.append("\n").append("день истечения срока годности: ").append(prod.ExpirationDate).append("\n");
	return Output;
}