#pragma once
#include "character.h"
#include <string>

using std::string;

class warrior:public character{
 public:
 	warrior(string, int, int);
 	virtual ~warrior();
 	virtual string toString()const;
};