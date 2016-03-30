#pragma once
#include "weapon.h"
#include <string>

using std::string;

class staff:public weapon{
	string typeMagic;//Dark y Light
	double atkModifier;//Porcentaje 
public:
	staff(string, double, double, string, double);
	staff(int);
	virtual ~staff();
	virtual string toString()const;
	double atkBonus(double)const;
	double atkDefault(double)const;//mago sin magia usa staff para atacar
	//getters
	string getName()const;
	double getDurab()const;
	double getDmg()const;
	string getType()const;
	double getDmgMod()const;
	//Setters
	void setName(string);
	void setDurab(double);
	void setDmg(double);
	void setType(string);
	void setDmgMod(double);
};