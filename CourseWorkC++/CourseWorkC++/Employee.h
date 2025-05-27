#pragma once

#include "Object.h"
#include "Product.h"
#include <string>

using namespace std;

class Employee : private Object
{
public:
	Employee();
	Employee(int ID, string _fullname, string _position, string _hireDate);
	string GetFullname();
	string GetPosition();
	string GetHireDate();
	void SetFullname(string& name);
	void SetPosition(string& pos);
	void SetHireDate(string& date);
	friend void printEmployeeDebug(const Employee& p);
private:
	string fullname;
	string position;
	string hireDate;

};

