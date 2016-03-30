#include "armor.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

armor::armor(string armorName,double defaultDef, double durab): armorName(armorName), defaultDef(defaultDef),durab(durab){} 

armor::~armor(){
}

string armor::toString()const
{
	stringstream ss;
	ss << armorName << "," << defaultDef <<"," << durab;
	return ss.str();
}
