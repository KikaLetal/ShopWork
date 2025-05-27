#pragma once

#include <string>

using namespace std;

class Error
{
public:
	Error();
	Error(int codeID, string source, string message);
	int GetCode();
	string GetSource();
	string GetMessage();
	string GetTimestamp();
	string ToString();
private:
	int codeID;
	string source;
	string message;
	string timestamp;
	string GetCurrentTime();
};

