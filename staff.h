#pragma once
#include "weapon.h"
#include <string>

using std::string;

class staff:public weapon{
	string typeMagic;//Dark y Ligth
	double atkModifier;//Porcentaje 
public:
	staff(string, double, double, string, double);
	virtual ~staff();
	virtual string toString()const;
	double atkBonus(double)const;
	double atkDefault(double)const;//mago sin magia usa staff para atacar
};