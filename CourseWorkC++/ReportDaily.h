#pragma once

#include "Report.h"
#include "Store.h"
#include "json.hpp"
#include "List.h"
#include <string>
#include "CoddingConverter.h"
#include "JSONReportWriter.h"
#include "Timee.h"

using namespace std;
using json = nlohmann::json;
using CC = CoddingConverter;

class ReportDaily : public Report
{
public:
	ReportDaily();
	ReportDaily(string date);
	void CollectData(Store& store);
	void Write() override;
	string GetName() override;
private:
	string date;
	List<Sale> sales;
	List<Shipment> shipments;
};

