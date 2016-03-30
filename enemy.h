#pragma once
#include "character.h"
#include "weapon.h"
#include "melee.h"
#include <string>

using std::string;

class enemy:public character{
 public:
 	enemy(string = "NPCNameHere", int=20, int=1,double=1);
 	virtual ~enemy();
 	virtual string toString()const;
 	double atk(melee)const;
 	void defNPC(double);
 	void levelUP();
 	void setName(string);
	void setForce(int);
	void setLevel(int);
	void setHP(double);
};