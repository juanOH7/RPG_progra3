#pragma once
#include "weapon.h"
#include <string>

using std::string;

class melee:public weapon{
	string typeAtk;//Blunt > Armor > Robe / Armor > Slash > Robe
public:
	melee(string, double, double, string);
	melee();
	virtual~melee();
	virtual string toString()const;
	double atkBonus(double)const;
	//Getters
	string name()const;
	double getdurab()const;
	double dmg()const;
	string type()const;
	//Setters
	void name(string);
	void setdurab(double);
	void dmg(double);
	void type(string);
};
