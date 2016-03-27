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

string melee::name()const
{
	return weapName;
}

double melee::getdurab()const
{
	return durab;
}

double melee::dmg()const
{
	return defaultDam;
}

string melee::type()const
{
	return typeAtk;
}
//Setters
void melee::name(string newname)
{
	weapName = newname;
}
void melee::setdurab(double newdurab)
{
	durab = newdurab;
}
void melee::dmg(double newdmg)
{
	defaultDam = newdmg;
}
void melee::type(string newtype)
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