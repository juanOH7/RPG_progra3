#include "enemy.h"
#include "character.h"
#include "weapon.h"
#include "melee.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

enemy::enemy(string name, int power, int level, double HP):character(name, power, level,HP){}

enemy::~enemy(){}

string enemy::toString()const{
	stringstream ss;
	ss << character::toString()<<", Tipo: NPC";
	return ss.str();
}

double enemy::atk(melee arma)const{
	return arma.atkBonus(power);
}

void enemy::defNPC(double AtkaDef){
	HP -= AtkaDef;
}

void enemy::levelUP(int level1){
	HP = (((2*90+20+(252/4))*level1)/100) + level1 + 10;
	power = (  (  (  (2*12+6+(252/4) ) * level1 ) / 100 ) + 5);
}