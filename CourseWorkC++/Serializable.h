#pragma once
#include <string>

using namespace std;

class Serializable
{
protected:
	~Serializable() = default;
    virtual string ToJson() const = 0;
    virtual void FromJson(const string& jsonStr) = 0;
};

