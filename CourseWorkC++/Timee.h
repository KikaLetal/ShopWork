#pragma once
#include <string>
#include <ctime>
#include "List.h"
#include <iostream>

using namespace std;

class Timee
{
public:
	static string MYGetCurrentTime();
	static string MYGetCurrentYear();
	static string MYGetCurrentMonth();
	static string MYGetCurrentDay();
	static string MYDateConversion(const string& date);
	static string Trim(const string& s);
};

