#include "Timee.h"

string Timee::Trim(const string& s) {
	size_t start = 0;
	while (start < s.size() && isspace(static_cast<unsigned char>(s[start]))) {
		++start;
	}

	if (start == s.size()) {
		return "";  // строка состоит только из пробелов
	}

	size_t end = s.size() - 1;
	while (end > start && isspace(static_cast<unsigned char>(s[end]))) {
		--end;
	}

	return s.substr(start, end - start + 1);
}

string Timee::MYGetCurrentTime() {
	time_t now = time(nullptr);
	struct tm timeInfo;
	char buf[64];
	localtime_s(&timeInfo, &now);
	strftime(buf, sizeof(buf), "%Y-%m-%d", &timeInfo);
	return string(buf);
}

string Timee::MYGetCurrentYear() {
	time_t now = time(nullptr);
	struct tm timeInfo;
	char buf[64];
	localtime_s(&timeInfo, &now);
	strftime(buf, sizeof(buf), "%Y", &timeInfo);
	return string(buf);
}

string Timee::MYGetCurrentMonth() {
	time_t now = time(nullptr);
	struct tm timeInfo;
	char buf[64];
	localtime_s(&timeInfo, &now);
	strftime(buf, sizeof(buf), "%m", &timeInfo);
	return string(buf);
}

string Timee::MYGetCurrentDay() {
	time_t now = time(nullptr);
	struct tm timeInfo;
	char buf[64];
	localtime_s(&timeInfo, &now);
	strftime(buf, sizeof(buf), "%d", &timeInfo);
	return string(buf);
}

string Timee::MYDateConversion(const string& date) {
	string Year, Month, Day, Cur;
	List<string> DateElements;
	if (date == "") {
		return MYGetCurrentTime();
	}
	for (int i = 0; i < date.length(); i++) {
		if (date[i] == ':' || date[i] == '.' || date[i] == '-' || date[i] == ' ') {
			if (DateElements.GetSize() < 2) {
				Cur = Trim(Cur);
				if (Cur.size() <= 2 || Cur.size() == 4) {
					if (Cur.size() == 1){
						Cur = "0" + Cur;
					}
					DateElements.Add(Cur);
					Cur = "";
					continue;
				}
				else {
					return "!Не верный формат даты";
				}
				
			}
			else 
				return "!Не верное число аргументов";
		}
		Cur += date[i];
	}

	if (Cur != "") {
		if (Trim(Cur).size() == 1) {
			Cur = "0" + Cur;
		}
		DateElements.Add(Cur);
	}

	if (DateElements.GetSize() == 0) {
		return "!неудалось разобрать строку";
	}

	if (DateElements.Get(0).size() == 4) {
		Year = DateElements.Get(0);
		if (DateElements.GetSize() > 1) {
			Month = DateElements.Get(1);
		}
		else
			Month = MYGetCurrentMonth();
		if (DateElements.GetSize() > 2) {
			Day = DateElements.Get(2);
		}
		else
			Day = MYGetCurrentDay();

	}
	else {
		Day = DateElements.Get(0);
		if (DateElements.GetSize() > 1) {
			Month = DateElements.Get(1);
		}
		else
			Month = MYGetCurrentMonth();
		if (DateElements.GetSize() > 2) {
			Year = DateElements.Get(2);
		}
		else
			Year = MYGetCurrentYear();
	}

	if (stoi(Day) >= 32 || stoi(Month) >= 13)
		return "!Дата вышла за пределы реальных значений";

	if (Trim(Day).size() != 2 || Trim(Month).size() != 2 || Trim(Year).size() != 4)
		return "!Не верный формат даты";

	return Trim(Year) + "-" + Trim(Month) + "-" + Trim(Day);
}


