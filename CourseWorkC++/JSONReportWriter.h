#pragma once
#include <iostream>
#include <string>
#include <string>
#include "json.hpp"
#include <fstream>
#include <filesystem>
#include "SafeWindows.h"

using namespace std;
using json = nlohmann::json;
namespace fs = std::filesystem;

const std::string JSON_REPORTS_FOLDER = "x64/Debug/reports/";

class JSONReportWriter
{
public:
	JSONReportWriter(const string& filename);
	void Write(const string& content);
	~JSONReportWriter();
private:
	ofstream outFile;
};

