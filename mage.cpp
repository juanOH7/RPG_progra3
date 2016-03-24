#include "mage.h"
#include "character.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

mage::mage(string name, int level, int power):character(name, power, level){
}
mage::~mage(){
}
string mage::toString()const{
	stringstream ss;
	ss << character::toString();
	return ss.str();
}