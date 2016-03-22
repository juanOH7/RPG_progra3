#include "weapon.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

weapon::weapon(string weapName, double durab, double defaultDam): weapName(weapName), durab(durab), defaultDam(defaultDam)s{}

weapon::~weapon(){
}

string weapon::toString() const
{
	stringstream ss;
	ss << weapName << "," << durab <<"," << defaultDam;
	return ss.str();
}