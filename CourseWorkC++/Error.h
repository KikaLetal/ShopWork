#pragma once

#include <string>
#include "json.hpp"
#include "serializable.h"
#include "CoddingConverter.h"
#include "Timee.h"

using namespace std;
using json = nlohmann::json;
using CC = CoddingConverter;

class Error: protected Serializable
{
public:
	Error();
	Error(string source, string message);
	string GetSource();
	string MyGetMessage();
	string GetTimestamp();
	string ToJson() const override;
	void FromJson(const string& jsonStr) override;
	string ToString();
private:
	string source;
	string message;
	string timestamp;
};

