#pragma once
#include <string>

using std::string;

class character{
protected:
	string name;
	int level,power;
	double HP;
public:
	character(string, int, int, double);
	~character();
	virtual string toString()const;
	virtual void levelUP()=0;
};