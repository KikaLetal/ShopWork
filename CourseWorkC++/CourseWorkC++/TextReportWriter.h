#pragma once
#include "ReportWriter.h"

class TextReportWriter : public ReportWriter
{
public:
	TextReportWriter() = default;
	void Write(const string& content) override;
	~TextReportWriter() = default;
};

