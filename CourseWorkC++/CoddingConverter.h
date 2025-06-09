#pragma once
#include "SafeWindows.h"
#include <string>

using namespace std;

class CoddingConverter
{
public:
    static string CP1251_to_UTF8(const std::string& str1251);
    static string UTF8_to_CP1251(const std::string& utf8str);
};

