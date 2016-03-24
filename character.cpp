#include "character.h"
#pragma once
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Person::Person(string name, int level):name(name), level(level){
}
Person::~Person(){
}