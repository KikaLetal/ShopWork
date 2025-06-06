#include "Error.h"
#include <ctime>

Error::Error(){
	codeID = 0;
	source = "����������";
	message = "��� ���������";
	timestamp = GetCurrentTime();
}
Error::Error(int codeID, string source, string message){
	codeID = codeID;
	source = source;
	message = message;
	timestamp = GetCurrentTime();
}
int Error::GetCode(){
	return codeID;
}
string Error::GetSource(){
	return source;
}
string Error::GetMessage(){
	return message;
}
string Error::GetTimestamp(){
	return timestamp;
}
string Error::ToString(){
	return "��� ������: " + to_string(codeID) + " ��������� ������: " + message + " ������ ��������� � " + source + " ����� ������: " + timestamp;
}

string Error::GetCurrentTime() {
	time_t now = time(nullptr);
	char buf[64];
	strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
	return string(buf);
}