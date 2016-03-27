#include "armor.h"
#include "warrArmor.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

warrArmor::warrArmor(string armorName, double defaultDef, double durab, double defBonu):armor(armorName, defaultDef, durab), defBonu(defBonu){}

warrArmor::warrArmor():armor("Naked", 0, 0) , defBonu(0){}

warrArmor::~warrArmor(){
}

string warrArmor::name()const
{
	return armorName;
}

double warrArmor::defen()const
{
	return defaultDef;
}

double warrArmor::getdurab()const
{
	return durab;
}

double warrArmor::bon()const
{
	return defBonu;
}

void warrArmor::name(string newName)
{
	armorName = newName;
}

void warrArmor::defen(double newdef)
{
	defaultDef = newdef;
}

void warrArmor::setdurab(double newdurab)
{
	durab = newdurab;
}

void warrArmor::bon(double newbon)
{
	defBonu = newbon;
}


string warrArmor::toString()const
{
	stringstream ss;
	ss << armor::toString() << "," << defBonu;
	return ss.str();
}

double warrArmor::bono()const
{
	return defaultDef * ((defBonu * 0.01) + 1.00) + 0.15;
}
