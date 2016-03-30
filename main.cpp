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
	warrior guerrero(nombre,1,50,30);
	warrior masterGuerrero("Grayson",4,90,55);
	mage mago(nombre,1,15,30,60);
	mage masterMago("Alatar",6,15,30,60);//Light o Dark
	do{
		if (tipo==1){
			cout<<"(Soy un guerrero, criado para matar, pupilo de Grayson. Puedo dormir ahora?) dices enojado."<<endl;
			cout<<"(Grayson? El famoso guerrero que nos abandono y traiciono cuando mas lo necesitabamos? Ese Grayson?) Tu reaccionas sorprendido:" <<endl;
			cout<<"(Traiciono? Que paso? No habia oido de el en años)."<<endl ;
			cout<<"(Se han oido rumores de que Grayson se ha unido al Culto del Terror, pero no te preocupes, aunque el no es querido aqui, nadie sabra que fuiste su pupilo." << endl;
			cout<<"Ten, aqui estan las llaves de tu habitacion; ve y descansa.)" << endl;
			break;
		}else if(tipo==2){
			cout<<"(Soy un mago, experto en las artes magicas, pupilo de Alatar. Puedo dormir ahora?) dices enojado."<<endl;
			cout<<"(Alatar? El famoso mago que nos abandono y traiciono cuando mas lo necesitabamos? Ese Alatar?) Tu reaccionas sorprendido:" <<endl;
			cout<<"(Traiciono? Que paso? No habia oido de el en años). "<<endl;
			cout<<"(Se han oido rumores de que Alatar se ha unido al Culto del Terror, pero no te preocupes, aunque el no es querido aqui, nadie sabra que fuiste su pupilo." <<endl;
			cout<<"Ten, aqui estan las llaves de tu habitacion; ve y descansa.)" << endl;
			break;
		}else{
			cout<<"(Eres malo para mentir, te conviene decirme la verdad, si quieres poder dormir.";
			cout<<"Eres guerrero o mago?)[1/2]: "<<endl;
			cin>>tipo;
		}
	}while(tipo!=1||tipo!=2);
	vector <melee*> ListaArmas(5); 
	vector <staff*> ListaStaffs(5); 
	vector <magic*> ListaSpells(5); 
	vector <robe*> ListaRobes(5); 
	vector <warrArmor*> ListaArmors(5);
	vector <enemy*> ListaEnemigos(5);	
	bool seguirDungeon1 = true;
	do
	{
		srand(time(NULL));
		cout <<"Te levantas, recuperado y con una mision. Estas decidido a buscar a tu maestro, cueste lo que cueste." <<endl;
		cout <<"Al pagarle al dueño tu deuda, le preguntas si tiene alguna idea de donde fue el ultimo paradero de tu maestro."<<endl;
		cout <<"El responde (Oi que estaba causando desastres en la Capilla del Tiempo, talvez hallas algo ahi). Le agradeces al dueño y te vas, decidido de lo que haras."<<endl;
		cout << "-----------CAPILLA DEL TIEMPO-----------" << endl;
		cout <<"La Capilla del Tiempo fue, en algun momento, un lugar pulcro, lejos de las reglas del mundo exterior. El tiempo aqui se mueve el doble de lento que en el resto del mundo"<< endl;
		cout <<"y mucha gente lo quiso usar para mantener su belleza. Ahora, es un desastre, toda su belleza ha sido reemplazada por oscuridad y monstruos." <<endl;
		cout <<"(EL Culto del Terror estuvo aqui, debo pasar por aqui y matar a todos los monstruos para reestablecer la belleza aqui). Con eso en mente, entras a la Capilla."<<endl;
		while (seguirDungeon1)
		{
			string seguir = "Y";
			bool ganarEXp;
			int Enemigo = 0;
			double numEn = rand()%3+1;
			int posArmSel, posArmaSel;	
			enemy antagonist("Eskeleto", 5, 2, 70);
			*ListaEnemigos[0] = antagonist;
			cout << "Te Enfrentas a " << numEn << "Eskeletos!!" <<endl;
			if (tipo == 1)
			{
				melee arma1("Axe", 23, 60, "Slash");
				*ListaArmas[0] = arma1;
				melee arma2("Katana", 12, 50, "Slash");
				*ListaArmas[1] = arma2;
				melee arma3("Broadsword", 20, 50, "Slash");
				*ListaArmas[2] = arma3;
				melee arma4("War Hammer", 50, 80, "Blunt");
				*ListaArmas[3] = arma4;
				melee arma5("Mace", 55, 90, "Blunt");
				*ListaArmas[4] = arma5;
				warrArmor set1("RingArmor", 120,40, 4);
				*ListaArmors[0] = set1;
				warrArmor set2("ThornArmor", 140, 60, 2);
				*ListaArmors[1] = set2;
				warrArmor set3("MightyArmor", 260, 60, 8);
				*ListaArmors[2] = set3;
				warrArmor set4("Savagermor", 90, 60, 5);
				*ListaArmors[3] = set4;
				warrArmor set5("SunArmor", 250, 60, 7);
				*ListaArmors[4] = set5;
				cout << "Seleccione Arma:"<<endl;
				do
				{
					for (int i = 0; i <  ListaArmas.size(); ++i)
					{
						cout << i+1 << ":" << ListaArmas[i]->toString() << endl;
					}
					cin >> posArmaSel;
					for (int i = 0; i <  ListaArmors.size(); ++i)
					{
						cout << i+1 << ":" << ListaArmors[i]->toString() << endl;
					}
					cin >> posArmSel;
					ganarEXp = combateWarrior(guerrero, *ListaArmas[posArmaSel-1],*ListaArmas[0], *ListaArmors[posArmSel - 1], *ListaEnemigos[Enemigo]);
					if (ganarEXp)
					{
						guerrero.levelUP();
						Enemigo++;
					}else{
						seguir = "n";
						break;
					}
					cout << "Continuar [Y/N]";
					cin >> seguir;
				} while (seguir == "Y" || seguir == "y");
			}
			else if (tipo == 2)
			{
			}
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