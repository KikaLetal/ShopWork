#pragma once

#include "Object.h"

class WorkShift : private Object
{
public:
	WorkShift();
	WorkShift(int id, int employeeID, const string& date, const string& startTime, const string& endTime);
	int GetEmployeeID();
	string GetDate();
	string GetStartTime();
	string GetEndTime();
	void SetDate(string& date);
	void SetStartTime(string& time);
	void SetEndTime(string& time);
	string ToString();
	friend void printWorkShiftDebug(const WorkShift& p);

private:
	int employeeID;
	string	date;
	string	startTime;
	string endTime;
};

