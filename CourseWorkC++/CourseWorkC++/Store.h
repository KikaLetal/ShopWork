#pragma once

#include "Product.h"
#include "Shipment.h"
#include "EMployee.h"
#include "Sale.h"
#include "WorkShift.h"
#include "List.h"

class Store
{
public:
	void AddProduct(const Product& product);
	void EditProduct(int productID, const Product& updatedProduct);
	void RemoveProduct(int productID);
	Product FindProduct(int productID);
	void RemoveExpiredProducts();
	List<Product> GetExpiredProducts();
	void AddShipment(const Shipment& shipment);
	List<Shipment> GetShipmentsByDate (const string& date);
	void AddEmployee(const Employee& employee);
	void RemoveEmployee(int employeeID) ;
	void EditEmployee(int employeeID, const Employee& updatedEmployee) ;
	Employee FindEmployee(int employeeID) ;
	void AddSale(const Sale& sale) ;
	List<Sale> GetSalesByDate(const string& date) ;
	void AddShift(const WorkShift& shift) ;
	List<WorkShift>	GetShiftsByDate(const string& date) ;
	void LoadData() ;
	void SaveData() ;
	void LoadProducts() ;
	void LoadEmployees() ;
	void LoadShifts() ;
	void LoadSales() ;
	void LoadShipments() ;
	void SaveProducts() ;
	void SaveEmployees() ;
	void SaveShifts() ;
	void SaveSales() ;
	void SaveShipments() ;
private:
	List<Product> products ;
	List<Employee> employees ; 
	List<WorkShift> shifts ;
	List<Sale> sales ;
	List<Shipment> shipments ;

};

