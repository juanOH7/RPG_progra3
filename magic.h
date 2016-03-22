#pragma once
#include <string>

using std::string;

class magic
{
	string spellName;
	string typeMagic;
	double baseAtk;
public:
	magic();
	~magic();
	string toString()const;
	double getBaseAtk()const;
	string getTypeMagic()const;
};