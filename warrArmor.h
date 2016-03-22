#pragma once
#include "armor.h"
#include <string>

using std::string;

class warrArmor:public armor
{
	double defBonu;	
public:
	warrArmor(string, double, double);
	~warrArmor();
	string toString()const;
	double bonoDef()const;
};