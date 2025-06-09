#pragma once

#include "Report.h"
#include "Error.h"
#include "List.h"
#include "json.hpp"
#include "CoddingConverter.h"
#include "JSONReportWriter.h"
#include "Timee.h"

using namespace std;
using json = nlohmann::json;
using CC = CoddingConverter;

class ReportBug : public Report
{
public:
	void AddError(const Error& error);
	void Write() override;
	string GetName() override;
private:
	List<Error> BugReport;
};

