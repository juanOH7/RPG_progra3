#pragma once
#include <string>

using std::string;

class armor
{
	string armorName;
	double defaultDef;
	double durab;
public:
	armor(string, double, double);
	virtual~armor();
	virtual string toString()const;
	virtual double bonoDef()const = 0;
	virtual double bonoAtk()const = 0;
};