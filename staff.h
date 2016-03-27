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
	string name()const;
	double getdurab()const;
	double dmg()const;
	string type()const;
	double dmgMod()const;
	//Setters
	void name(string);
	void setdurab(double);
	void dmg(double);
	void type(string);
	void dmgMod(double);
};