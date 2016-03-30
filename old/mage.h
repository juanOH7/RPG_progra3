#pragma once
#include "character.h"
#include "armor.h"
#include "robe.h"
#include "magic.h"
#include "weapon.h"
#include "staff.h"
#include <string>

using std::string;

class mage:public character{
	int intel;
 public:
 	mage(string="name", int=1, int=1, int=1,double=1.0);
 	virtual ~mage();
 	virtual string toString()const;
 	double atk(staff, magic, robe&)const;
 	double atkDefault(staff,robe&)const;//NO MAGIC
 	void def(double ,robe&);
 	void levelUP();
};