#pragma once
#include "armor.h"
#include <string>

using std::string;

class warrArmor:public armor
{
	double defBonu;	
public:
	warrArmor(string, double, double, double);
	~warrArmor();
	string toString()const;
	double bonoDef(double, double)const;
};