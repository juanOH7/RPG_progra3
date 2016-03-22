#pragma once
#include <string>

class character{
	string name;
	int level;
public:
	character(string name,int level = 1);
	~character();
};