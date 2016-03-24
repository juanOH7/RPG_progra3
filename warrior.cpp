#include "warrior.h"
#include "character.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

warrior::warrior(string name, int power, int level):character(name, power, level){
}
warrior::~warrior(){
}
string warrior::toString()const{
	stringstream ss;
	ss << character::toString();
	return ss.str();
}