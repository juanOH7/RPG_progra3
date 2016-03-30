#pragma once
#include "armor.h"
#include <string>

using std::string;

class robe:public armor
{
	double atkBonu;	
public:
	robe(string, double, double, double);
	robe();
	~robe();
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