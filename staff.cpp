#include "staff.h"
#include "weapon.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

staff::staff(string weapName, double durab, double defaultDa,string typeMagic, double atkModifier):weapon(weapName, durab, defaultDa), typeMagic(typeMagic), atkModifier(atkModifier){}

staff::~staff(){
}

string staff::toString()const
{
	stringstream ss;
	ss << staff::toString() << "," << typeMagic << "," << atkModifier << "%";
	return ss.str();
}

double staff::atkBonus(double baseAtk)const 
{
	double bono = (atkModifier * 0.01) + 1.00;
	return baseAtk * bono;
}

double staff::atkDefault(double strength)const//si no tiene magia usa su fuerza de Character
{
	return defaultDa * ((strength * 0.60) + 1.00);
}