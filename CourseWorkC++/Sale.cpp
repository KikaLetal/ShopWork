#include "Sale.h"

Sale::Sale(){
	this->ID = -1;
	this->productID = 0;
	this->quantitySold = 0;
	this->date = "0000-00-00";
	this->totalAmount = 0;
}
Sale::Sale(int ID, int productID, int quantitySold, const string& date, double totalAmount){
	this->ID = ID;
	this->productID = productID;
	this->quantitySold = quantitySold;
	this->date = date;
	this->totalAmount = totalAmount;
}
Sale::Sale(const string& jsonStr) {
	FromJson(jsonStr);
}
int Sale::GetID() const {
	return ID;
}
int	Sale::GetProductID(){
	return productID;
}
int Sale::GetQuantitySold(){
	return quantitySold;
}
string Sale::GetDate(){
	return date;
}
double Sale::GetTotalAmount(){
	return totalAmount;
}
void Sale::SetProductID(int productID){
	this->productID = productID;
}
void Sale::SetQuantitySold(int quantitySold){
	this->quantitySold = quantitySold;
}
void Sale::SetDate(const string& date){
	this->date = date;
}
void Sale::SetTotalAmount(double totalAmount){
	this->totalAmount = totalAmount;
}
bool Sale::operator==(const Sale& other) const{
	return productID == other.productID &&
		quantitySold == other.quantitySold &&
		date == other.date &&
		totalAmount == other.totalAmount;
}

string Sale::ToJson() const {
	json j;
	j["ID"] = ID;
	j["ProductID"] = productID;
	j["QuantitySold"] = quantitySold;
	j["Date"] = CC::CP1251_to_UTF8(date);
	j["TotalAmount"] = totalAmount;
	return j.dump(4); // визуал!
}

void Sale::FromJson(const string& jsonStr) {
	json j = json::parse(jsonStr);
	ID = j.value("ID", 0);
	productID = j.value("ProductID", 0);
	quantitySold = j.value("QuantitySold", 0);
	date = CC::UTF8_to_CP1251(j.value("Date", "0000-00-00"));
	totalAmount = j.value("TotalAmount", 0.0);
}

string Sale::ToString(){
	return "ID: " + to_string(ID) + ", проданный товар: " + to_string(productID) + ", продано: " + to_string(quantitySold) + ", дата продажи: " + date + ", на сумму: " + to_string(totalAmount);
}

