#include "magic.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

magic::magic(string spellName, string typeMagic, double baseAtk): spellName(spellName) ,typeMagic(typeMagic), baseAtk(baseAtk){}

magic::~magic(){
}

string magic::toString()const
{
	stringstream ss;
	ss << spellName << "," << typeMagic << "," << baseAtk;
	return ss.str();
}

double magic::getBaseAtk()const
{
	return baseAtk;
}

string magic::getTypeMagic()const
{
	return typeMagic;
}