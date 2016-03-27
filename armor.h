#pragma once
#include <string>

using std::string;

class armor
{
protected:
	string armorName;
	double defaultDef;
	double durab;
public:
	armor(string, double, double);
	virtual~armor();
	virtual string toString()const;
	virtual double bono()const = 0;
};