#pragma once

#include <string>
using namespace std;

class ReportWriter
{
	virtual void Write(const string& content) = 0;
};

