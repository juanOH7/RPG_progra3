#pragma once
#include "character.h"
#include "armor.h"
#include "warrArmor.h"
#include "weapon.h"
#include "melee.h"
#include <string>

using std::string;

class warrior:public character{
 public:
 	warrior(string, int, int,double);
 	virtual ~warrior();
 	virtual string toString()const;
 	double atk(melee)const;
 	void def(double ,warrArmor);
 	void levelUP();
};