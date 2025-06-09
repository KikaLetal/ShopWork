#pragma once
#include "JSONReportWriter.h" 
#include <string>
using namespace std;

class Report
{
public:
	virtual void Write() = 0;
	virtual string GetName() = 0;
	virtual ~Report() {};

};

