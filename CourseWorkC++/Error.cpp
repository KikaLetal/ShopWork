#include "Error.h"

Error::Error(){
	this->source = "Unknown";
	this->message = "Nothing";
	this->timestamp = Timee::MYGetCurrentTime();
}
Error::Error(string source, string message){
	this->source = source;
	this->message = message;
	timestamp = Timee::MYGetCurrentTime();
}
string Error::GetSource(){
	return source;
}
string Error::MyGetMessage(){
	return message;
}
string Error::GetTimestamp(){
	return timestamp;
}
string Error::ToJson() const {
	json j;
	j["source"] = CC::CP1251_to_UTF8(source);
	j["message"] = CC::CP1251_to_UTF8(message);
	j["timestamp"] = CC::CP1251_to_UTF8(timestamp);
	return j.dump(4); // визуал!
}

void Error::FromJson(const string& jsonStr) {
	json j = json::parse(jsonStr);
	source = CC::UTF8_to_CP1251(j.value("source", "Unknown"));
	message = CC::UTF8_to_CP1251(j.value("message", "Nothing"));
	timestamp = CC::UTF8_to_CP1251(j.value("timestamp", "0000-00-00"));
}
string Error::ToString(){
	return "Cообщение ошибки: " + message + " ошибка произошла в " + source + " время ошибки: " + timestamp;
}