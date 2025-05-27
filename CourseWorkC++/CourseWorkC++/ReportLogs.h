#pragma once

#include "Report.h"
#include "ReportWriter.h"
#include <string>
#include "List.h"

using namespace std;

class ReportLogs : public Report
{
public:
	void AddLog(const string& entry);
	void Write(ReportWriter& writer);
	string GetName();
private:
	List<string> logEntries;
};

