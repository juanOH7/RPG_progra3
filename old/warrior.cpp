#include "warrior.h"
#include "character.h"
#include "armor.h"
#include "warrArmor.h"
#include "weapon.h"
#include "melee.h"
#include <string>
#include <iostream>
#include <sstream>
using std::string;
using std::cout;
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
	cout << armadura.bono() << "\n";
	cout << AtkaDef << "\n";
	if (diff < 0){
		cout << diff << "\n";
		HP += diff;
		cout << "menos Health" << "\n";
		cout << HP<< "\n";
		armadura.setdefen(0);
	}
	else{
		cout << armadura.getdefen() << "\n";
		double nueveDef = armadura.bono() - AtkaDef;
		armadura.setdefen(nueveDef);
		cout << armadura.getdefen() << "\n";

	}
}


void warrior::levelUP(){
	HP = (((2*400+41+(252/4))*level)/100) + level + 10;
	power = (  (  (  (2*12+6+(252/4) ) * level ) / 100 ) + 5);
	level++;
}