#pragma once
#include <string>

using std::string;

class magic
{
	string spellName;
	string typeMagic;
	double baseAtk;
public:
	magic(string, string, double);
	~magic();
	string toString()const;
	//Getters
	string getSpellName()const;
	double getBaseAtk()const;
	string getTypeMagic()const;
	//Setters
	void setSpellName(string);
	void setBaseAtk(double);
	void setTypeMagic(string);
};