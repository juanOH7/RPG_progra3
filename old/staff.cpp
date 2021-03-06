#include "staff.h"
#include "weapon.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

staff::staff(string weapName, double durab, double defaultDam,string typeMagic, double atkModifier):weapon(weapName, durab, defaultDam), typeMagic(typeMagic), atkModifier(atkModifier){}

staff::staff(int intel):weapon("Fists", 1, 1), typeMagic("Light"), atkModifier(intel){}

staff::~staff(){
}

//Getters

string staff::name()const
{
	return weapName;
}

double staff::getdurab()const
{
	return durab;
}

double staff::dmg()const
{
	return defaultDam;
}

string staff::type()const
{
	return typeMagic;
}

double staff::dmgMod()const
{
	return atkModifier;
}
//Setters
void staff::name(string newname)
{
	weapName = newname;
}
void staff::setdurab(double newdurab)
{
	durab = newdurab;
}
void staff::dmg(double newdmg)
{
	defaultDam = newdmg;
}
void staff::type(string newtype)
{
	typeMagic = newtype;
}

void staff::dmgMod(double newMod)
{
	atkModifier = newMod;
}

string staff::toString()const
{
	stringstream ss;
	ss << staff::toString() << "," << typeMagic << "," << atkModifier;
	return ss.str();
}

double staff::atkBonus(double baseAtk)const 
{
	double bono = (atkModifier * 0.01) + 1.00;
	return baseAtk * bono;
}

double staff::atkDefault(double strength)const//si no tiene magia usa su fuerza de Character
{
	return defaultDam * ((strength * 0.60) + 1.00);
}