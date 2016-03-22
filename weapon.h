#pragma once
#include <string>
using std::string;

class weapon{
	string weapName;
	double durab;//Durability
	double defaultDam;
public:
	weapon(string ="NameHere", double = 1, double = 1);
	virtual string toString()const;
	virtual~weapon();
	virtual double atkBonus(double)const = 0;
};