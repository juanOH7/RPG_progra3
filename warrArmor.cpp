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

string warrArmor::getName()const
{
	return armorName;
}

double warrArmor::getDefen()const
{
	return defaultDef;
}

double warrArmor::getDurab()const
{
	return durab;
}

double warrArmor::getBon()const
{
	return defBonu;
}

void warrArmor::setName(string newName)
{
	armorName = newName;
}

void warrArmor::setDefen(double newdef)
{
	defaultDef = newdef;
}

void warrArmor::setDurab(double newdurab)
{
	durab = newdurab;
}

void warrArmor::setBon(double newbon)
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
