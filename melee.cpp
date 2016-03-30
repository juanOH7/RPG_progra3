#include "melee.h"
#include "weapon.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

melee::melee(string weapName, double durab,double defaultDam, string typeAtk): weapon(weapName, durab, defaultDam), typeAtk(typeAtk){}

melee::melee():weapon("Fists", 0, 0), typeAtk("Blunt"){}

melee::~melee(){
}

//Getters

string melee::getName()const
{
	return weapName;
}

double melee::getDurab()const
{
	return durab;
}

double melee::getDmg()const
{
	return defaultDam;
}

string melee::getType()const
{
	return typeAtk;
}
//Setters
void melee::setName(string newname)
{
	weapName = newname;
}
void melee::setDurab(double newdurab)
{
	durab = newdurab;
}
void melee::setDmg(double newdmg)
{
	defaultDam = newdmg;
}
void melee::setType(string newtype)
{
	typeAtk = newtype;
}

string melee::toString()const
{
	stringstream ss;
	ss << weapon::toString() << "," << typeAtk;
	return ss.str();
}

double melee::atkBonus(double strength)const
{
	 return defaultDam * ((strength * 0.60) + 1.00);
}