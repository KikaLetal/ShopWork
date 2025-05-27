#pragma once

#include "Report.h"
#include "Error.h"
#include "ReportWriter.h"
#include "List.h"

class ReportBug : public Report
{
public:
	void AddError(const Error& error);
	void Write(ReportWriter& writer);
	string GetName();
private:
	List<Error> BugReport;
};

