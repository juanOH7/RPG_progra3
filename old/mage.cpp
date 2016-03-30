#include "mage.h"
#include <iostream>
#include "character.h"
#include "armor.h"
#include "robe.h"
#include "weapon.h"
#include "staff.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
using std::cout;

mage::mage(string name, int level, int power, int intel, double HP):character(name, power, level, HP), intel(intel){
}
mage::~mage(){
}

string mage::toString()const{
	stringstream ss;
	ss << character::toString()<<", Tipo: Mago"<<", Inteligencia: "<<intel;
	return ss.str();
}

double mage::atk(staff equip, magic attuned,robe& wearing)const{
	return (equip.atkBonus(attuned.getBaseAtk()) + wearing.bono());
}

double mage::atkDefault(staff equip, robe& wearing)const{
	return (equip.atkDefault(power) + wearing.bono());
}

void mage::def(double incoming,robe& wearing){
	double diff = wearing.bono() - incoming;
	if (diff < 0){
		HP -= diff;
		wearing.defen(0);
	}
	else{
		wearing.defen(wearing.defen() - incoming);
	}
}

void mage::levelUP(){
	HP = (((2*120+31+(252/4))*level)/100) + level + 10;
	power = (  (  (  (2*30+20+(60/4) ) * level ) / 100 ) + 5);
	intel = (  (  (  (2*65+20+(230/4) ) * level ) / 100 ) + 5);
	level++;
}