#pragma once

#include <string>
#include "ReportWriter.h"
using namespace std;

class Report
{
public:
	virtual void Write(ReportWriter& writer) = 0;
	virtual string GetName() = 0;
	~Report();

};

