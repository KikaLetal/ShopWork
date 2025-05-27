#pragma once

#include "Report.h" 
#include "Product.h"
#include "List.h"
#include "ReportWriter.h"

class ReportProducts : public Report
{
public:
	void SetProducts(const List<Product>& productList);
	void Write(ReportWriter& writer);
	string GetName();
private:
	List<Product> products;
};

