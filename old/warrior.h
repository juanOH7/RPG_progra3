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
 	warrior(string = "NameHere", int=20, int=1,double=1);
 	virtual ~warrior();
 	virtual string toString()const;
 	double atk(melee)const;
 	void def(double ,warrArmor&);
 	void levelUP();
};