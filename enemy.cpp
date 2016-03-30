#include "enemy.h"
#include "character.h"
#include "weapon.h"
#include "melee.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

enemy::enemy(string name, int power, int level, double HP):character(name, power, level,HP){}

enemy::~enemy(){
}

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

void enemy::setName(string newName)
{
	name = newName;
}
void enemy::setForce(int newForce){
	power = newForce;
}
void enemy::setLevel(int newLevel){
	level = newLevel;
}
void enemy::setHP(double newHP)
{
	HP = newHP;
}


void enemy::levelUP(){
	HP = (((2*90+20+(252/4))*level)/100) + level + 10;
	power = (  (  (  (2*12+6+(252/4) ) * level ) / 100 ) + 5);
}