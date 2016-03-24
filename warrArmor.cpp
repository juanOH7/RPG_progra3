#include "armor.h"
#include "warrArmor.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

warrArmor::warrArmor(string armorName, double defaultDef, double durab, double defBonu):armor(armorName, defaultDef, durab), defBonu(defBonu){}

warrArmor::~warrArmor(){
}

string warrArmor::toString()const
{
	stringstream ss;
	ss << armor::toString() << "," << defBonu;
	return ss.str();
}

double warrArmor::bonoDef(double defaultDef, double defBonu)const
{
	return defaultDef * ((defBonu * 0.01) + 1.00) + 0.15;
}
