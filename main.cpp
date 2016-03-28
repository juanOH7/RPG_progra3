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
#include "enemy.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
bool combateWarrior(warrior&, melee, melee,warrArmor& ,enemy&);
bool combateMage(mage&, staff, melee,robe&,magic ,enemy&);
string introNombre();
int introTipo(string nombre);

int main(int argc, char const *argv[]){
	/*cout << "stuff"<< "\n";
	melee v;
	cout << v.toString()<< "\n";
	cout << "stuff2"<< "\n";
	mage a("ds", 0,0,0);
	warrior b("cr",0,0,0);
	cout << a.toString()<<endl;
	cout << b.toString()<<endl;*/
	bool terminoJUego = true;
	string nombre = introNombre();
	cout<<endl;
	int tipo=introTipo(nombre);
	do{
		if (tipo==1){
			melee a("WS0", 100, 3, "Slash");
			warrior guerrero(nombre,1,50,30);
			warrior masterGuerrero("Grayson",4,90,55);
			cout<<"(Soy un guerrero, criado para matar, pupilo de Grayson. Puedo dormir ahora?) dices enojado."<<endl;
			break;
		}else if(tipo==2){
			mage mago(nombre,1,15,30,60);
			mage masterMago("Alatar",6,15,30,60);//Light o Dark
			cout<<"(Soy un mago, experto en las artes magicas, pupilo de Alatar. Puedo dormir ahora?) dices enojado."<<endl;
			break;
		}else{
			cout<<"(Eres malo para mentir, te conviene decirme la verdad, si quieres poder dormir.";
			cout<<"Eres guerrero o mago?)[1/2]: "<<endl;
			cin>>tipo;
		}
	}while(tipo!=1||tipo!=2);
	do
	{
		//string weapName, double durab,double defaultDam, string typeAtk
		srand(time(NULL));
		melee Default("Large Sword", 20, 20, "Slash");
		if (tipo == 1){
			
		}else if(tipo == 2){
			
		}
	} while (terminoJUego);
	return 0;
}

bool combateWarrior(warrior& Usuario, melee offense, melee ofenseNPC,warrArmor& defense,enemy& NPC){
	double Damage;
	while(!Usuario.isDead() && !NPC.isDead()){
		if (!Usuario.isDead()){
			Damage = Usuario.atk(offense);//COuts bitte!
			NPC.defNPC(Damage);
		}
		if (!NPC.isDead()){
			Damage = NPC.atk(offense);
			Usuario.def(Damage, defense);
		}
	}
	if (Usuario.isDead()){
		return false;
	}else{
		return true;
	}
}

bool combateMage(mage& Usuario, staff baculo, melee offense,robe& rob,magic spell,enemy& NPC){
	double Damage;
	while(!Usuario.isDead() && !NPC.isDead()){
		if (!Usuario.isDead()){
			Damage = Usuario.atk(baculo,spell,rob);//COuts bitte!
			NPC.defNPC(Damage);
		}
		if (!NPC.isDead()){
			Damage = NPC.atk(offense);
			Usuario.def(Damage, rob);
		}
	}
	if (Usuario.isDead()){
		return false;
	}else{
		return true;
	}
}



string introNombre(){
	string nombre;
	cout<<"(He llegado...por fin) dices a ti mismo, al entrar a esta nueva ciudad."; 
	cout<<"Ha sido un camino largo y complicado, pero al final puedes contemplar un merecido descanso."; 
	cout<<"Entras a una cabina para descansar, y consultas al dueño de la cabina. El te pregunta:"; 
	cout<<"(Cual es tu nombre?): "<<endl;
	cin>>nombre;
	return nombre;
}
int introTipo(string nombre){
	int tipo;
	cout<<"("<<nombre<<", Me llamo "<<nombre<<", y deseo una habitacion para descansar y recuperarme.)"; 
	cout<<"El dueño te mira de manera sospechosa: (Hmmm, tu cara me parece conocida."; 
	cout<<"Te dare la habitacion, pero primero necesito tu profesion."; 
	cout<<"Eres guerrero o mago?)[1/2]: "<<endl;
	cin>>tipo;
	return tipo;
}