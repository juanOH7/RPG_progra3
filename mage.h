#pragma once
#include "character.h"
#include <string>

using std::string;

class mage:public character{
 public:
 	mage(string, int, int);
 	virtual ~mage();
 	virtual string toString()const;
};