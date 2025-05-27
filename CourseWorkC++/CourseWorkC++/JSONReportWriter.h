#pragma once
#include "ReportWriter.h"

class JSONReportWriter : public ReportWriter
{
public:
	JSONReportWriter() = default;
	void Write(const string& content) override;
	~JSONReportWriter() = default;
};

