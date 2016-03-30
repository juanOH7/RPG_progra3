#pragma once
#include "armor.h"
#include <string>

using std::string;

class warrArmor:public armor
{
	double defBonu;	
public:
	warrArmor(string, double, double, double);
	warrArmor();
	~warrArmor();
	string toString()const;
	double bono()const;
	//Getters
	string getName()const;
	double getDefen()const;
	double getDurab()const;
	double getBon()const;
	//Setters
	void setName(string);
	void setDefen(double);
	void setDurab(double);
	void setBon(double);
};