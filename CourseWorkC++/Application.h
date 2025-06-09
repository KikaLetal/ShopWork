#pragma once
#include "Report.h"
#include "ReportProducts.h"
#include "ReportBug.h"
#include "ReportDaily.h"
#include "Store.h"
#include "Timee.h"

class Application
{
public:
	Application();
	~Application();
	void OnStart();
	void Run();
	void OnExit();
	void MakeShipment();
	Product MakeNewProductCard(const string& Category = "", const string& Name = "");
	void MakeReport();
	void ProductsOperations();
	void GenerateReport(Report* report);  //RTTI
	void ShowAllProducts();

private:
	Store store;
	ReportProducts reportProducts;
	ReportBug reportBug;
	ReportDaily reportDaily;
};

