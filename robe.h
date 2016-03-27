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
	string name()const;
	double defen()const;
	double getdurab()const;
	double bon()const;
	//Setters
	void name(string);
	void defen(double);
	void setdurab(double);
	void bon(double);
};