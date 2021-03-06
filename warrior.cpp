#include "warrior.h"
#include "character.h"
#include "armor.h"
#include "warrArmor.h"
#include "weapon.h"
#include "melee.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

warrior::warrior(string name, int power, int level, double HP):character(name, power, level,HP){}

warrior::~warrior(){}

string warrior::toString()const{
	stringstream ss;
	ss << character::toString()<<", Tipo: Guerrero";
	return ss.str();
}

double warrior::atk(melee arma)const{
	return arma.atkBonus(power);
}

void warrior::def(double AtkaDef,warrArmor& armadura){
	double diff = armadura.bono() - AtkaDef;
	if (diff < 0){
		HP += diff;
		armadura.setDefen(0);
	}
	else{
		armadura.setDefen(armadura.getDefen() - AtkaDef);
	}
}


void warrior::levelUP(){
	HP = (((2*400+41+(252/4))*level)/100) + level + 10;
	power = (  (  (  (2*12+6+(252/4) ) * level ) / 100 ) + 5);
	level++;
}