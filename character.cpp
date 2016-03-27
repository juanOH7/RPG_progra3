#include "character.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

character::character(string name, int power, int level, double HP):name(name), power(power), level(level),HP(HP){
}
character::~character(){
}
string character::toString()const{
	stringstream ss;
	ss << "Character: " << name << ", " << HP << ", " << power << ", " << level;
	return ss.str();
}