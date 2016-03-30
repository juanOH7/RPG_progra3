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
void dungeon(warrior& ,mage& ,int , int , bool&, int );
string introNombre();
int introTipo(string nombre);
void capillaTiempo();
int menuArmadura();
int menuArma();
int menuTunica();
int menuBaston();
int menuMagia();
void panteonPoder();
void sanctoRemordimiento();

int main(int argc, char const *argv[]){
	bool terminoJUego = true;
	string nombre = introNombre();
	cout<<endl;
	int tipo=introTipo(nombre);
	srand(time(NULL));
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
	bool seguirDungeon1 = true;
	bool seguirDungeon2 = true;
	bool seguirDungeon3 = true;
	do{
		int numDung = 1;
		capillaTiempo();
		while (seguirDungeon1){
			int numEn=rand()%4+2;
			dungeon(guerrero, mago,numDung, tipo, seguirDungeon1, numEn);
		}
		numDung = 2;
		panteonPoder();
		while (seguirDungeon2)
		{
			int numEn=rand()%4+2;
			dungeon(guerrero, mago,numDung, tipo, seguirDungeon2, numEn);
		}
		numDung = 3;
		sanctoRemordimiento();
		while (seguirDungeon3)
		{
			int numEn=rand()%4+2;
			dungeon(guerrero, mago,numDung, tipo, seguirDungeon3, numEn);
		}
		terminoJUego = false; 
	} while (terminoJUego);
	return 0;
}

bool combateWarrior(warrior& Usuario, melee offense, melee offenseNPC,warrArmor& defense,enemy& NPC){
	double Damage;
	while(!Usuario.isDead() && !NPC.isDead()){
		if (!Usuario.isDead()){
			Damage = Usuario.atk(offense);//COuts bitte!
			NPC.defNPC(Damage);
		}
		if (!NPC.isDead()){
			Damage = NPC.atk(offenseNPC);
			Usuario.def(Damage, defense);
		}
	}
	if (Usuario.isDead()){
		return false;
	}else{
		return true;
	}
}
bool combateMage(mage& Usuario, staff baculo, melee offenseNPC,robe& rob,magic spell,enemy& NPC){
	double Damage;
	while(!Usuario.isDead() && !NPC.isDead()){
		if (!Usuario.isDead()){
			Damage = Usuario.atk(baculo,spell,rob);//COuts bitte!
			NPC.defNPC(Damage);
		}
		if (!NPC.isDead()){
			Damage = NPC.atk(offenseNPC);
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
int menuArmadura(){
	int opc;
	cout<<"1. Armadura del Anillo"<<endl;
	cout<<"2. Armadura de Espinas"<<endl;
	cout<<"3. Armadura de Poder"<<endl;
	cout<<"4. Armadura Salvaje"<<endl;
	cout<<"5. Armadura Solar"<<endl;
	cout<<"Seleccione su armadura: ";
	cin>>opc;
	if (opc<1||opc>5){
		return -1;
	}else{
		return opc;
	}
}
int menuArma(){
	int opc;
	cout<<"1. Hacha"<<endl;
	cout<<"2. Katana"<<endl;
	cout<<"3. Sable"<<endl;
	cout<<"4. Martillo de Guerra"<<endl;
	cout<<"5. Mazo"<<endl;
	cout<<"Seleccione su arma: ";
	cin>>opc;
	if (opc<1||opc>5){
		return -1;
	}else{
		return opc;
	}
}
int menuTunica(){
	int opc;
	cout<<"1. Encantado"<<endl;
	cout<<"2. Adornado"<<endl;
	cout<<"3. Del Poder"<<endl;
	cout<<"4. Salvaje"<<endl;
	cout<<"5. Reforzado"<<endl;
	cout<<"Seleccione su Túnica: ";
	cin>>opc;
	if (opc<1||opc>5){
		return -1;
	}else{
		return opc;
	}
}
int menuBaston(){
	int opc;
	cout<<"1. Tecnologico"<<endl;
	cout<<"2. Elemental"<<endl;
	cout<<"3. De la Fuerza"<<endl;
	cout<<"4. Feroz"<<endl;
	cout<<"5. Reforzado"<<endl;
	cout<<"Seleccione su baston: ";
	cin>>opc;
	if (opc<1||opc>5){
		return -1;
	}else{
		return opc;
	}
}
int menuMagia(){
	int opc;
	cout<<"1. Fuego"<<endl;
	cout<<"2. Fuerza"<<endl;
	cout<<"3. Confusion"<<endl;
	cout<<"4. Maldicion"<<endl;
	cout<<"5. Multiplicacion"<<endl;
	cout<<"Seleccione su Magia ";
	cin>>opc;
	if (opc<1||opc>5){
		return -1;
	}else{
		return opc;
	}
}
void capillaTiempo(){
	cout <<"Te levantas, recuperado y con una mision. Estas decidido a buscar a tu maestro, cueste lo que cueste." <<endl;
	cout <<"Al pagarle al dueño tu deuda, le preguntas si tiene alguna idea de donde fue el ultimo paradero de tu maestro."<<endl;
	cout <<"El responde (Oi que estaba causando desastres en la Capilla del Tiempo, talvez hallas algo ahi). Le agradeces al dueño y te vas, decidido de lo que haras."<<endl;
	cout << endl;
	cout << "-----------CAPILLA DEL TIEMPO-----------" << endl;
	cout <<"La Capilla del Tiempo fue, en algun momento, un lugar pulcro, lejos de las reglas del mundo exterior. El tiempo aqui se mueve el doble de lento que en el resto del mundo"<< endl;
	cout <<"y mucha gente lo quiso usar para mantener su belleza. Ahora, es un desastre, toda su belleza ha sido reemplazada por oscuridad y monstruos." <<endl;
	cout <<"(EL Culto del Terror estuvo aqui, debo pasar por aqui y matar a todos los monstruos para reestablecer la belleza aqui). Con eso en mente, entras a la Capilla."<<endl;
	cout << endl;
}

void dungeon(warrior& Usuario1,mage& Usuario2,int numDung, int tipo, bool& seguirDungeon, int numEn)
{
	bool ganarEXp;
	enemy antagonist;
	if (numDung == 1)
	{
		antagonist.setName("Esqueleto");
		antagonist.setForce(5);
		antagonist.setLevel(5);
		antagonist.setHP(100);
	}else if(numDung == 2)
	{
		antagonist.setName("Caballero");
		antagonist.setForce(5);
		antagonist.setLevel(5);
		antagonist.setHP(200);
	}else if(numDung == 3)
	{
		antagonist.setName("Ogro");
		antagonist.setForce(5);
		antagonist.setLevel(5);
		antagonist.setHP(400);
	}
	warrArmor armadura;
	melee arma, armaEnemigo;
	robe tunica;
	staff baston(0);
	magic magia;
	if (numDung == 1)
	{
		cout << "Te Enfrentas a "<<numEn<<" Esqueletos!!" <<endl;

	}else if(numDung == 2)
	{
		cout << "Te Enfrentas a "<<numEn<<" Caballeros!!" <<endl;

	}else if(numDung == 3)
	{
		cout << "Te Enfrentas a "<<numEn<<" Ogros!!" <<endl;
	}
	if (tipo == 1){
		int seleccionarArmadura=menuArmadura();
		do{
			if (seleccionarArmadura==1){
				armadura.setName("RingArmor");
				armadura.setDefen(120);
				armadura.setDurab(40);
				armadura.setBon(4);
				cout<<"Agarras la armadura del anillo, y te sientes protegido."<<endl;
				break;
			}else if (seleccionarArmadura==2){
				armadura.setName("ThornArmor");
				armadura.setDefen(140);
				armadura.setDurab(60);
				armadura.setBon(2);
				cout<<"Agarras la armadura de espinas, y te sientes protegido."<<endl;
				break;
			}else if (seleccionarArmadura==3){
				armadura.setName("MightyArmor");
				armadura.setDefen(260);
				armadura.setDurab(60);
				armadura.setBon(8);
				cout<<"Agarras la armadura del poder, y te sientes protegido."<<endl;
				break;
			}else if (seleccionarArmadura==4){
				armadura.setName("Savagermor");
				armadura.setDefen(90);
				armadura.setDurab(60);
				armadura.setBon(5);
				cout<<"Agarras la armadura salvaje, y te sientes protegido."<<endl;
				break;
			}else if (seleccionarArmadura==5){
				armadura.setName("SunArmor");
				armadura.setDefen(250);
				armadura.setDurab(60);
				armadura.setBon(7);
				cout<<"Agarras la armadura solar, y te sientes protegido."<<endl;
				break;
			}else{
				cout<<"Opcion Invalida"<<endl;
				seleccionarArmadura=menuArmadura();
			}
		}while(seleccionarArmadura!=1&&seleccionarArmadura!=2&&seleccionarArmadura!=3&&seleccionarArmadura!=4&&seleccionarArmadura!=5);
		int seleccionarArma=menuArma();
		do{
			if (seleccionarArma==1){
				arma.setName("Axe");
				arma.setDurab(23);
				arma.setDmg(60);
				arma.setType("Slash");
				cout<<"Agarras el hacha, y te preparas para luchar."<<endl;
				armaEnemigo.setName("Katana");
				armaEnemigo.setDurab(6);
				armaEnemigo.setDmg(15);
				armaEnemigo.setType("Slash");
				break;
			}else if (seleccionarArma==2){
				arma.setName("Katana");
				arma.setDurab(12);
				arma.setDmg(50);
				arma.setType("Slash");
				cout<<"Agarras la katana, y te preparas para luchar."<<endl;
				armaEnemigo.setName("Broadsword");
				armaEnemigo.setDurab(10);
				armaEnemigo.setDmg(15);
				armaEnemigo.setType("Slash");
				break;
			}else if (seleccionarArma==3){
				arma.setName("Broadsword");
				arma.setDurab(20);
				arma.setDmg(50);
				arma.setType("Slash");
				cout<<"Agarras el sable, y te preparas para luchar."<<endl;
				armaEnemigo.setName("War Hammer");
				armaEnemigo.setDurab(15);
				armaEnemigo.setDmg(30);
				armaEnemigo.setType("Blunt");
				break;
			}else if (seleccionarArma==4){
				arma.setName("War Hammer");
				arma.setDurab(50);
				arma.setDmg(80);
				arma.setType("Blunt");
				cout<<"Agarras el martillo, y te preparas para luchar."<<endl;
				armaEnemigo.setName("Mace");
				armaEnemigo.setDurab(25);
				armaEnemigo.setDmg(45);
				armaEnemigo.setType("Blunt");
				break;
			}else if (seleccionarArma==5){
				arma.setName("Mace");
				arma.setDurab(55);
				arma.setDmg(90);
				arma.setType("Blunt");
				cout<<"Agarras el mazo, y te preparas para luchar."<<endl;
				armaEnemigo.setName("Axe");
				armaEnemigo.setDurab(12);
				armaEnemigo.setDmg(35);
				armaEnemigo.setType("Slash");
				break;
			}else{
				cout<<"Opcion Invalida"<<endl;
				seleccionarArma=menuArma();
			}
		}while(seleccionarArma!=1&&seleccionarArma!=2&&seleccionarArma!=3&&seleccionarArma!=4&&seleccionarArma!=5);
		do{
			double Damage = Usuario1.atk(arma);
			cout << "Haces Daño de: "<<Damage << " a  tu Enemigo"<<endl;
			Damage = antagonist.atk(armaEnemigo);
			cout << "Recibes un daño de:" << Damage << endl;
			if (!antagonist.isDead())
			{
				cout << "Sobrevives el ataque" <<endl;	
			}
			ganarEXp = combateWarrior(Usuario1, arma, armaEnemigo, armadura, antagonist);
			if (ganarEXp){
				if (numDung == 1)
				{
					antagonist.setName("Esqueleto");
					antagonist.setHP(1000);
				}else if(numDung == 2)
				{
					antagonist.setName("Caballero");
					antagonist.setHP(3000);					
				}else if(numDung == 3)
				{
					antagonist.setName("Ogro");
					antagonist.setHP(4000);
				}
				cout << "Has vencido a tu Enemigo" <<endl;
				Usuario1.levelUP();
				cout << "Level UP" << endl;
				cout << Usuario1.toString() << endl;
				numEn--;
			}else{
				break;
			}
		}while (numEn > 0 );
		seguirDungeon = false;
	}
	else if (tipo == 2){
		int seleccionarTunica=menuTunica();
		do{
			if (seleccionarTunica==1){
				tunica.setName("Enchanted");
				tunica.setDefen(120);
				tunica.setDurab(40);
				tunica.setBon(4);
				cout<<"Agarras la tunica encantada, y te sientes protegido."<<endl;
				break;
			}else if (seleccionarTunica==2){
				tunica.setName("Embellished");
				tunica.setDefen(140);
				tunica.setDurab(60);
				tunica.setBon(2);
				cout<<"Agarras la tunica adornada, y te sientes protegido."<<endl;
				break;
			}else if (seleccionarTunica==3){
				tunica.setName("Power");
				tunica.setDefen(230);
				tunica.setDurab(60);
				tunica.setBon(8);
				cout<<"Agarras la tunica del poder, y te sientes protegido."<<endl;
				break;
			}else if (seleccionarTunica==4){
				tunica.setName("Savage");
				tunica.setDefen(90);
				tunica.setDurab(60);
				tunica.setBon(5);
				cout<<"Agarras la tunica salvaje, y te sientes protegido."<<endl;
				break;
			}else if (seleccionarTunica==5){
				tunica.setName("Reinforced");
				tunica.setDefen(250);
				tunica.setDurab(60);
				tunica.setBon(7);
				cout<<"Agarras la tunica reforzada, y te sientes protegido."<<endl;
				break;
			}else{
				cout<<"Opcion Invalida"<<endl;
				seleccionarTunica=menuTunica();
			}
		}while(seleccionarTunica!=1&&seleccionarTunica!=2&&seleccionarTunica!=3&&seleccionarTunica!=4&&seleccionarTunica!=5);
		int seleccionarBaston=menuBaston();
		do{
			if (seleccionarBaston==1){
				baston.setName("Technology");
				baston.setDurab(23);
				baston.setDmg(60);
				baston.setType("Light");
				baston.setDmgMod(2);
				cout<<"Agarras el baston tecnologico, y te preparas para luchar."<<endl;
				armaEnemigo.setName("Katana");
				armaEnemigo.setDurab(6);
				armaEnemigo.setDmg(15);
				armaEnemigo.setType("Slash");
				break;
			}else if (seleccionarBaston==2){
				baston.setName("Elemental");
				baston.setDurab(12);
				baston.setDmg(25);
				baston.setType("Light");
				baston.setDmgMod(25);
				cout<<"Agarras la baston elemental, y te preparas para luchar."<<endl;
				armaEnemigo.setName("Broadsword");
				armaEnemigo.setDurab(10);
				armaEnemigo.setDmg(15);
				armaEnemigo.setType("Slash");
				break;
			}else if (seleccionarBaston==3){
				baston.setName("Force");
				baston.setDurab(20);
				baston.setDmg(25);
				baston.setType("Dark");
				baston.setDmgMod(25);
				cout<<"Agarras el baston de la fuerza, y te preparas para luchar."<<endl;
				armaEnemigo.setName("War Hammer");
				armaEnemigo.setDurab(15);
				armaEnemigo.setDmg(30);
				armaEnemigo.setType("Blunt");
				break;
			}else if (seleccionarBaston==4){
				baston.setName("Ferocious");
				baston.setDurab(25);
				baston.setDmg(25);
				baston.setType("Dark");
				baston.setDmgMod(30);
				cout<<"Agarras el martillo, y te preparas para luchar."<<endl;
				armaEnemigo.setName("Mace");
				armaEnemigo.setDurab(25);
				armaEnemigo.setDmg(45);
				armaEnemigo.setType("Blunt");
				break;
			}else if (seleccionarBaston==5){
				baston.setName("Reinforced");
				baston.setDurab(55);
				baston.setDmg(90);
				baston.setType("Light");
				baston.setDmgMod(35);
				cout<<"Agarras el mazo, y te preparas para luchar."<<endl;
				armaEnemigo.setName("Axe");
				armaEnemigo.setDurab(12);
				armaEnemigo.setDmg(35);
				armaEnemigo.setType("Slash");
				break;
			}else{
				cout<<"Opcion Invalida"<<endl;
				seleccionarBaston=menuBaston();
			}
		}while(seleccionarBaston!=1&&seleccionarBaston!=2&&seleccionarBaston!=3&&seleccionarBaston!=4&&seleccionarBaston!=5);
		int seleccionarMagia=menuMagia();
		do{
			if (seleccionarMagia==1){
				magia.setSpellName("Fire");
				magia.settypeMagic("Light");
				magia.setBaseAtk(80);
				cout<<"Te preparas con la magia de fuego, es hora de luchar!."<<endl;
				break;
			}else if (seleccionarMagia==2){
				magia.setSpellName("Strength");
				magia.settypeMagic("Light");
				magia.setBaseAtk(100);
				cout<<"Te preparas con la magia de fuerza, es hora de luchar!."<<endl;
				break;
			}else if (seleccionarMagia==3){
				magia.setSpellName("Confusion");
				magia.settypeMagic("Dark");
				magia.setBaseAtk(40);
				cout<<"Te preparas con la magia de confusion, es hora de luchar!."<<endl;
				break;
			}else if (seleccionarMagia==4){
				magia.setSpellName("Curse");
				magia.settypeMagic("Dark");
				magia.setBaseAtk(70);
				cout<<"Te preparas con la magia de maldicion, es hora de luchar!."<<endl;
				break;
			}else if (seleccionarMagia==5){
				magia.setSpellName("Multiplication");
				magia.settypeMagic("Light");
				magia.setBaseAtk(90);
				cout<<"Te preparas con la magia de multiplicacion, es hora de luchar!."<<endl;
				break;
			}else{
				cout<<"Opcion Invalida"<<endl;
				seleccionarMagia=menuMagia();
			}
		}while(seleccionarMagia!=1&&seleccionarMagia!=2&&seleccionarMagia!=3&&seleccionarMagia!=4&&seleccionarMagia!=5);
		do{
			double Damage = Usuario2.atk(baston,magia,tunica);
			cout << "Haces Daño de: "<<Damage << " a  tu Enemigo"<<endl;
			Damage = antagonist.atk(armaEnemigo);
			cout << "Recibes un daño de:" << Damage << endl;
			if (!antagonist.isDead())
			{
				cout << "Sobrevives el ataque" <<endl;	
			}
			ganarEXp = combateMage(Usuario2, baston, armaEnemigo, tunica,magia, antagonist);
			if (ganarEXp){
				Usuario2.levelUP();
				cout << "has vencido a tu Enemigo!" << endl;
				cout << "Level UP" << endl;
				cout << Usuario2.toString() << endl;
				numEn--;
				if (numDung == 1)
				{
					antagonist.setName("Esqueleto");
					antagonist.setHP(400);
				}else if(numDung == 2)
				{
					antagonist.setName("Caballero");
					antagonist.setHP(400);
				}else if(numDung == 3)
				{
					antagonist.setName("Ogro");
					antagonist.setHP(400);
				}
			}else{
				break;
			}
		}while (numEn > 0);
		seguirDungeon = false;	
	}
}
void panteonPoder(){
	cout<<"Al salir, ves pizadas en el suelo, que llevan hacia un solo lugar, el Panteon del Poder"<<endl;
	cout<<"PANTEON DEL PODER"<<endl;
	cout<<"El Panteon del Poder poseia viejas reliquias, armas y libros sobre magia, usados por leyendas en tiempo pasados. Ahora, esta vacia."<<endl; 
	cout<<"Es obvio que el Culto ha pasado por aqui, ya que hay mas monstruos, y hay que eliminarlos para poder empezar la restauracion del lugar."<<endl;
}
void sanctoRemordimiento(){
	cout<<"SANCTO DE REMORDIMIENTO"<<endl;
	cout<<"(No quiero estar aqui...), el Sancto de Remordimiento es famoso por la leyenda de que al entrar, enfrentas a tus monstruos internos."<<endl; 
	cout<<"Dada tu experiencia pasada en estos lugares, sabes que esos monstruos fueron colocados aqui por el Culto de Terror. Hora de pelear!"<<endl;
}