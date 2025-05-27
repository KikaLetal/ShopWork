#pragma once

#include "Report.h"
#include "Product.h"
#include "List.h"

class ReportExpired : public Report
{
public:
	void SetExpiredProducts(const List<Product>& productList);
	void Write(ReportWriter& writer);
	string GetName();
private:
	List<Product> expiredProducts;
};

