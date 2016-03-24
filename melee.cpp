#include "melee.h"
#include "weapon.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

melee::melee(string weapName, double durab,double defaultDa, string typeAtk): weapon(weapName, durab, defaultDa), typeAtk(typeAtk){}

melee::~melee(){
}

string melee::toString()const
{
	stringstream ss;
	ss << weapon::toString() << "," << typeAtk;
	return ss.str();
}

double melee::atkBonus(double strength, double defaultDa)const
{
	 return defaultDa * ((strength * 0.60) + 1.00);
}