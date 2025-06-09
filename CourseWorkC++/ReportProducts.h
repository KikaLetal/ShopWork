#pragma once

#include "Report.h" 
#include "Product.h"
#include "json.hpp"
#include "List.h"
#include <string>
#include "CoddingConverter.h"
#include "JSONReportWriter.h"
#include "Timee.h"
#include "Store.h"

using namespace std;
using json = nlohmann::json;
using CC = CoddingConverter;

class ReportProducts : public Report
{
public:
	void SetProducts(Store& store);
	void Write() override;
	string GetName() override;
private:
	List<Product> products;
};

