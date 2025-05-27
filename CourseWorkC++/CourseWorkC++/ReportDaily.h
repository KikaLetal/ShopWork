#pragma once

#include "Report.h"
#include "Store.h"

class ReportDaily : Report
{
public:
	ReportDaily();
	ReportDaily(string date);
	void CollectData(Store& store);
	void Write(ReportWriter& writer);
	string GetName();
private:
	string date;
	List<Sale> sales;
	List<Shipment> shipments;
	List<Product> expiredProducts;
	List<Employee> employeesOnShift;
};

