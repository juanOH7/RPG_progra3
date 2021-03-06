main.exe: main.o character.o weapon.o armor.o warrior.o mage.o magic.o staff.o warrArmor.o melee.o robe.o enemy.o
	g++ main.o character.o weapon.o armor.o warrior.o mage.o magic.o staff.o warrArmor.o melee.o robe.o enemy.o -o rpg 
	
main.o:	main.cpp character.h weapon.h armor.h warrior.h mage.h magic.h staff.h warrArmor.h melee.h robe.h enemy.h
	g++ -c main.cpp 

character.o:	character.cpp character.h
	g++ -c character.cpp 

enemy.o:	enemy.h enemy.cpp character.h
	g++ -c enemy.cpp

weapon.o:	weapon.cpp weapon.h 
	g++ -c weapon.cpp

armor.o:	armor.cpp armor.h 
	g++ -c armor.cpp 

warrior.o:	warrior.cpp warrior.h character.h
	g++ -c warrior.cpp

mage.o:	mage.cpp mage.h character.h
	g++ -c mage.cpp 

magic.o:	magic.cpp magic.h 
	g++ -c magic.cpp

staff.o:	staff.cpp staff.h weapon.h
	g++ -c staff.cpp 

warrArmor.o:	warrArmor.cpp warrArmor.h armor.h
	g++ -c warrArmor.cpp

robe.o:	robe.cpp robe.h armor.h
	g++ -c robe.cpp

melee.o:	melee.cpp melee.h weapon.h
	g++ -c melee.cpp 	