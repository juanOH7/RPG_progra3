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
	string getName()const;
	double getDurab()const;
	double getDmg()const;
	string getType()const;
	//Setters
	void setName(string);
	void setDurab(double);
	void setDmg(double);
	void setType(string);
};
