#pragma once
#include "weapon.h"
#include <string>

using std::string;

class melee:public weapon{
	string typeAtk;//Blunt > Armor > Robe / Armor > Slash > Robe
public:
	melee(string, double, double, string);
	virtual~melee();
	virtual string toString()const;
	double atkBonus(double, double)const;
};
