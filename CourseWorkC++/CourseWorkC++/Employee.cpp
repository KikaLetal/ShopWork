#include "Employee.h"
#include <iostream>

Employee::Employee(){
	fullname = "";
	position = "";
	hireDate = "";
}
Employee::Employee(int ID, string _fullname, string _position, string _hireDate){
	fullname = _fullname;
	position = _position;
	hireDate = _hireDate;
}
string Employee::GetFullname(){
	return fullname;
}
string Employee::GetPosition(){
	return position;
}
string Employee::GetHireDate(){
	return hireDate;
}
void Employee::SetFullname(string& name){
	fullname = name;
}
void Employee::SetPosition(string& pos){
	position = pos;
}
void Employee::SetHireDate(string& date){
	hireDate = date;
}
void printEmployeeDebug(const Employee& p){
	std::cout << "[Debug] " << "Name: " << p.fullname
		<< ", Position: " << p.position << ", Hire Date: " << p.hireDate << std::endl;
}

