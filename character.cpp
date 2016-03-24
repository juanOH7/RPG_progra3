#include "character.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

character::character(string name, int power, int level):name(name), power(power), level(level){
}
character::~character(){
}
string character::toString()const{
	stringstream ss;
	ss << "Character: "<<name<<", "<<power<<", "<<level;
	return ss.str();
}