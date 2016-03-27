#include "character.h"
#include "weapon.h"
#include "warrior.h"
#include "robe.h"
#include "mage.h"
#include "armor.h"
#include "warrArmor.h"
#include "magic.h"
#include "melee.h"
#include "staff.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[]){
	cout << "stuff"<< "\n";
	melee v;
	cout << v.toString()<< "\n";
	cout << "stuff2"<< "\n";
	mage a("ds", 0,0,0);
	cout << a.toString();
	return 0;
}