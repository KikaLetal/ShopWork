#pragma once

#include "Report.h"
#include "JSONReportWriter.h"
#include "TextReportWriter.h"
#include "ReportProducts.h"
#include "ReportExpired.h"
#include "ReportLogs.h"
#include "ReportBug.h"
#include "ReportDaily.h"
#include "Store.h"

class Application
{
public:

	Application();
	~Application();
	void OnStart();
	void Run();
	void GenerateReport(Report* report);  //RTTI

private:

	Store store;
	ReportProducts reportProducts;
	ReportExpired reportExpired;
	ReportLogs reportLogs;
	ReportBug reportBug;
	ReportDaily reportDaily;
	JSONReportWriter jsonWriter;
	TextReportWriter textWriter;
};

