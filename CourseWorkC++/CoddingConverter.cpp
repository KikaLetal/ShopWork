#include "CoddingConverter.h"

string CoddingConverter::CP1251_to_UTF8(const string& str1251) {
    int wlen = MultiByteToWideChar(1251, 0, str1251.c_str(), (int)str1251.size(), nullptr, 0);
    std::wstring wstr(wlen, 0);
    MultiByteToWideChar(1251, 0, str1251.c_str(), (int)str1251.size(), &wstr[0], wlen);

    int utf8len = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), wlen, nullptr, 0, nullptr, nullptr);
    string utf8str(utf8len, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), wlen, &utf8str[0], utf8len, nullptr, nullptr);

    return utf8str;
}

string CoddingConverter::UTF8_to_CP1251(const string& utf8str) {
    int wlen = MultiByteToWideChar(CP_UTF8, 0, utf8str.c_str(), (int)utf8str.size(), nullptr, 0);
    std::wstring wstr(wlen, 0);
    MultiByteToWideChar(CP_UTF8, 0, utf8str.c_str(), (int)utf8str.size(), &wstr[0], wlen);

    int len1251 = WideCharToMultiByte(1251, 0, wstr.c_str(), wlen, nullptr, 0, nullptr, nullptr);
    string str1251(len1251, 0);
    WideCharToMultiByte(1251, 0, wstr.c_str(), wlen, &str1251[0], len1251, nullptr, nullptr);

    return str1251;
}