#include "Store.h"

Product Store::ConstructProduct(const string& category, const string& name, double price, int quantity, const string& date) {
	int lastID = GetActualID(products);
	cout << lastID << endl;
	Product result(lastID, category, name, price, quantity, date);
	return result;
}
void Store::SetOverprice(const int& ID, const double& overprice) {
	products.Get(ID).SetOverprice(overprice);
}
void Store::ReleaseProduct(const int& ID, const int& count) {
	int lastID = GetActualID(sales);
	Sale sale(lastID, ID, count, Timee::MYGetCurrentTime(), products.Get(ID).GetPrice() * count);
	AddSale(sale);
	products.Get(ID).SetQuantity(products.Get(ID).GetQuantity()-count);
}
void Store::AddProduct(const Product& product){
	products.Add(product.GetID(), product);
}
void Store::EditProduct(int productID, const Product& updatedProduct){
	bool wasChanged = false;
	if (products.ContainsKey(productID)) {
		products.Replace(productID, updatedProduct);
		wasChanged = true;
	}
	if (wasChanged == false) {
		//ошибка
	}
}
void Store::RemoveProduct(int productID){
	bool wasDeleted = false;
	if (products.ContainsKey(productID)) {
		products.Remove(productID);
		wasDeleted = true;
	}
	if (wasDeleted == false) {
		//ошибка
	}
}

void Store::RemoveExpiredProducts(){
	string today = Timee::MYGetCurrentTime();
	List<Product> allProducts = products.DictToList();
	for (int i = 0; i < allProducts.GetSize(); i++) {
		Product curProduct = allProducts.Get(i);
		if (curProduct.GetExpirationDate() < today) {
			products.Remove(curProduct.GetID());
		}
	}
}
Shipment Store::ConstructShipment(const string& date, const List<Product>& products, const string& supplierName) {
	int lastID = GetActualID(shipments);
	Shipment shipment(lastID);
	if (supplierName != "") {
		shipment.SetDate(date);
		shipment.SetSupplierName(supplierName);
		shipment.SetProducts(products);
	}
	else {
		shipment.SetDate(date);
		shipment.SetSupplierName(supplierName);
		shipment.SetProducts(products);
	}

	return shipment;
}
void Store::AddShipment(const Shipment& shipment){
	shipments.Add(shipment.GetID(), shipment);
}
List<Shipment> Store::GetShipmentsByDate(const string& date){
	List<Shipment> result = List<Shipment>();
	List<Shipment> allShipments = shipments.DictToList();
	for (int i = 0; i < allShipments.GetSize(); i++) {
		Shipment curShipment = allShipments.Get(i);
		if (curShipment.GetDate() == date) {
			result.Add(curShipment);
		}
	}
	return result;
}

void Store::AddSale(const Sale& sale){
	sales.Add(sale.GetID(), sale);
}

List<Sale> Store::GetSalesByDate(const string& date){
	List<Sale> result = List<Sale>();
	List<Sale> allSales = sales.DictToList();
	for (int i = 0; i < allSales.GetSize(); i++) {
		Sale curSale = allSales.Get(i);
		if (curSale.GetDate() == date) {
			result.Add(curSale);
		}
	}
	return result;
}

List<Product> Store::GetProductsList() const{
	List<Product> productsCopy = products.DictToList();
	return productsCopy;
}

Dictionary<int, Product> Store::GetProducts() const {
	return products;
}

Dictionary<int, string> Store::GetCategories(){
	Dictionary<int, string> result = Dictionary<int, string>();
	List<Product> allProducts = products.DictToList();
	for (int i = 0; i < allProducts.GetSize(); i++) {
		Product curProduct = allProducts.Get(i);
		if (result.ContainsValue(curProduct.GetCategory()))
			continue;
		result.Add(GetActualID(result), curProduct.GetCategory());
	}
	return result;
}
void Store::LoadData(){
	try
	{
		LoadProducts();
		LoadSales();
		LoadShipments();
	}
	catch (const std::exception& e)
	{
		throw;
	}
}
void Store::SaveData(){
	try
	{
		SaveProducts();
		SaveSales();
		SaveShipments();
	}
	catch (const std::exception& e)
	{
		throw;
	}
}
void Store::LoadProducts(){
	std::ifstream file(JSON_DATA_FOLDER+"products.json");
	if (!file.is_open()) {
		//ошибка 
		std::cerr << "[Ошибка] Не удалось открыть файл: " << JSON_DATA_FOLDER + "products.json" << std::endl;
		throw runtime_error("[Ошибка] Не удалось открыть файл: Products");
	}

	json jArray;
	file >> jArray;
	file.close();

	for (const auto& jItem : jArray) {
		std::string jsonStr = jItem.dump();
		Product p(jsonStr);
		products.Add(p.GetID(), p);
	}
}
void Store::LoadSales(){
	std::ifstream file(JSON_DATA_FOLDER+"sales.json");
	if (!file.is_open()) {
		std::cerr << "[Ошибка] Не удалось открыть файл: " << JSON_DATA_FOLDER + "sales.json" << std::endl;
		throw runtime_error("[Ошибка] Не удалось открыть файл: Sales");
	}

	json jArray;
	file >> jArray;
	file.close();

	for (const auto& jItem : jArray) {
		Sale s(jItem.dump());
		sales.Add(s.GetID(), s);
	}
}
void Store::LoadShipments(){
	std::ifstream file(JSON_DATA_FOLDER + "shipments.json");
	if (!file.is_open()) { 
		std::cerr << "[Ошибка] Не удалось открыть файл: " << JSON_DATA_FOLDER + "shipments.json" << std::endl;
		throw runtime_error("[Ошибка] Не удалось открыть файл: Shipments");
	}

	json jArray;
	file >> jArray;
	file.close();

	for (const auto& jItem : jArray) {
		Shipment sh(jItem.dump());
		shipments.Add(sh.GetID(), sh);
	}
}
void Store::SaveProducts(){
	std::ofstream file(JSON_DATA_FOLDER + "products.json");
	if (!file.is_open()) {
		// ошибка
		throw runtime_error("[Ошибка] Не удалось сохранить данные: Products");
	}

	List<Product> allProducts = products.DictToList();

	json jArray = json::array();
	for (int i = 0; i < allProducts.GetSize(); i++) {
		const Product& p = allProducts.Get(i);
		Product pCopy = p;
		jArray.push_back(json::parse(p.ToJson()));
	}
	file << jArray.dump(4);
	file.close();
}
void Store::SaveSales(){
	std::ofstream file(JSON_DATA_FOLDER + "sales.json");
	if (!file.is_open()) {
		throw runtime_error("[Ошибка] Не удалось сохранить данные: Sales");
	}

	List<Sale> allSales = sales.DictToList();

	json jArray = json::array();
	for (int i = 0; i < allSales.GetSize(); i++) {
		jArray.push_back(json::parse(allSales.Get(i).ToJson()));
	}

	file << jArray.dump(4);
	file.close();
}
void Store::SaveShipments(){
	std::ofstream file(JSON_DATA_FOLDER + "shipments.json");
	if (!file.is_open()) {
		throw runtime_error("[Ошибка] Не удалось сохранить данные: Shipments");
	}

	List<Shipment> allShipments = shipments.DictToList();

	json jArray = json::array();
	for (int i = 0; i < allShipments.GetSize(); i++) {
		jArray.push_back(json::parse(allShipments.Get(i).ToJson()));
	}

	file << jArray.dump(4);
	file.close();
}