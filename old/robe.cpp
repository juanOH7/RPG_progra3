#include "armor.h"
#include "robe.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

robe::robe(string armorName, double defaultDef, double durab, double atkBonu):armor(armorName, defaultDef, durab), atkBonu(atkBonu){}

robe::robe():armor("Naked", 1,1), atkBonu(1){}

robe::~robe(){
}

string robe::name()const
{
	return armorName;
}

double robe::defen()const
{
	return defaultDef;
}

double robe::getdurab()const
{
	return durab;
}

double robe::bon()const
{
	return atkBonu;
}

void robe::name(string newName)
{
	armorName = newName;
}

void robe::defen(double newdef)
{
	defaultDef = newdef;
}

void robe::setdurab(double newdurab)
{
	durab = newdurab;
}

void robe::bon(double newbon)
{
	atkBonu = newbon;
}

string robe::toString()const
{
	stringstream ss;
	ss << armor::toString() << "," << atkBonu;
	return ss.str();
}

double robe::bono()const
{
	return defaultDef * ((atkBonu * 0.01) + 1.00) + 0.15;
}
