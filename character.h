#pragma once
#include <string>

using std::string;

class character{
	string name;
	int level, power;
public:
	character(string, int, int);
	~character();
	virtual string toString()const;
};