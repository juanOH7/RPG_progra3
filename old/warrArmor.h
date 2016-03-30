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
	string name()const;
	double getdefen()const;
	double getdurab()const;
	double bon()const;
	//Setters
	void name(string);
	void setdefen(double);
	void setdurab(double);
	void bon(double);
};