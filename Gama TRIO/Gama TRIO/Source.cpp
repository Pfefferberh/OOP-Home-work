//Опишіть класи "Swordsman" (Мечник), "Archer" (Лучник)і "Mage" (Маг), кожен з яких є екземпляром базового класу 
//"Unit" (штука, елемент) в комп'ютерній грі, і може атакувати, ухилятись від атак і вмирати.
//
//У мечника 15 хіт - поінтів(життів), пошкодження при атаці 5, шанс ухилятись 60 % .
//Лучник: 12 hp, 4 dmg, 40 % dodge
//	Маг : 8 hp, 10 dmg, 30 % dodge
//
//
//	В main() створіть два масива(ворогуючі сторони) по три юніта в кожному, причому тип юніта(мечник, лучник чи маг) має задаватись випадково, 
//при заповненні цих масивів.Тобто один раз запустивши вашу програму, може створитись три лучники проти мечника і двох магів, іншого - лучник, мечник і маг проти двох мечників і лучника і т.д.
//
//	Далі в циклі земулюйте бій між ними, поки бійці однієї з сторін всі не загинуть.В консоль при цьому виводьте повідомлення хто кого атакував, чи вдалась атака, скільки життя залишилось у жертви чи вона загинула.Нехай бій відбувається поступово, по натиснення клавіші spacebar(пробіла), щоб ми могли спостерігати його атака за атакою.
//
//	В кінці бою оголосіть, яка команда перемогла(перша / друга, синя / червона, альянс / орки - як вже ваша фантазія вам підскаже).
//
//	Не забудьте здійснити приведення типів там, де це необхідно.
//
//
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class unit
{
	string fraction;
public:
	string name;
	int health;
	int damage;
	int chans;
	void Set_health(int health) { this->health = health; };
	int Get_health() { return this->health; };
	int Get_damage() { return this->damage; };
	string Get_fraction() { return this->fraction; };
	void Set_fraction(string fraction) { this->fraction=  fraction; };
	unit() {};
	~unit() {};
};
class Swords :public unit
{
public:
	Swords(string fraction) {
		this->name = "Swords";
		this->damage = 5;
		this->health = 15;
		this->chans = 60;
		this->Set_fraction( fraction);
	};
	~Swords() {};
};
class Archer :public unit
{
public:
	Archer(string fraction) {
		this->name = "Archer";
		this->damage = 10;
		this->health = 8;
		this->chans = 30;
		this->Set_fraction(fraction);
	};
	~Archer() {};
};
class Withard :public unit
{
public:
	Withard(string fraction) {
		this->name = "Withard";
		this->damage = 4;
		this->health = 12;
		this->chans = 40;
		this->Set_fraction(fraction);
	};
	~Withard() {};
};

void show(unit* man, unit* orc,int size)
{
	string name;
	cout << " Health:         Health:          " << endl;
	for (int i = 0; i < size; i++) {
		if (man[i].Get_health()<0 || orc[i].Get_health() < 0) {
			name = "Died";
			if (man[i].Get_health() < 0 ) {
				cout <<man[i].Get_fraction()<<": "<< man[i].name << " " << name << "       " << orc[i].Get_fraction() << ": " << orc[i].name << " " << orc[i].Get_health() << endl;
			}
			else if (orc[i].Get_health() < 0) {
				cout << man[i].Get_fraction() << ": " << man[i].name << " " << man[i].Get_health() << "       " << orc[i].Get_fraction() << ": " << orc[i].name << " " << name << endl;
			}
		}
		else {
			cout << man[i].Get_fraction() << ": " << man[i].name << " " << man[i].Get_health() << "       " << orc[i].Get_fraction() << ": " << orc[i].name << " " << orc[i].Get_health() << endl;
		}
	}
	cout << endl;
}
void war(unit& team_one, unit  &team_two)
{
	int chans_random = rand() % 100;
	cout << "-------------->>------------" << endl;
	if (chans_random > team_two.chans) {
		cout << team_one.name << " attacked " << team_two.name << endl;
		cout << "Health " << team_two.name <<": "<< team_two.Get_health()<<" - "<< team_one.name<<" damage: "<< team_one.Get_damage()<<endl;
		team_two.Set_health(team_two.Get_health() - team_one.Get_damage());
		cout << "Health " << team_two.name << ": " << team_two.Get_health() << endl;
		if (team_two.Get_health()<=0) {
			cout << " Die " << endl;
		}
	}
	else {
		cout << " Blocking fate " << endl;
	}
	cout << "--------------<<------------" << endl;
}

void Fill_army(unit* army, int size) {
	int chans;
	string fraction;
	cout << "Enter the fraction ";
	cin >>  fraction;
	for (int i = 0; i < size; i++) {
		chans = rand() % 3;
		if (chans == 0) {
			army[i] = Swords(fraction);
		}
		else if (chans == 1) {
			army[i] = Archer(fraction);
		}
		else {
			army[i] = Withard(fraction);
		}
	}
	for (int i = 0; i < size; i++) {
		cout << i + 1 << army[i].name << endl;
	}
}
bool Victory(unit* army, int size,bool over) {
	int victory=0;
	for (int i = 0; i < size; i++) 
	{	if (army[i].Get_health() <= 0) { victory++; } }
	if (victory == 3) {
		cout << "VICTORY " << army->Get_fraction() << endl;
		return over = true; }
	else { return over = false; }
}
//void You_turn(int choise_aliance ,int choise_enemy , unit* orc, unit* man,bool over,int size) {
//	cout << "Choise your unit(man): ";
//	cin >> choise_aliance;
//	cout << "Choise enemy unit(orc): ";
//	cin >> choise_enemy;
//	if (orc[choise_enemy - 1].health > 0) {
//		war(man[choise_aliance - 1], orc[choise_enemy - 1]);
//	}
//	else {
//		cout << orc[choise_enemy - 1].name << " died " << endl;
//	}
//	over = Victory(orc, size, over);
//	system("pause");
//}
int main() {
	srand(unsigned(time(NULL)));
	bool over = false;
	const int size = 3;
	int choise_aliance=0;
	int choise_enemy=0;
	unit* orc = new unit[size];
	unit* man = new unit[size];

	cout << "````````````````````Your fraction```````````````````````" << endl;
	Fill_army(man, size);
	cout << "````````````````````Comp fraction```````````````````````" << endl;
	Fill_army(orc, size);
	
	for (int i = 0;over==false;i++) {
		show(man, orc,size);
		cout << "`````````````````````````war``````````````````" << endl;
			cout << "Your turn                   raund " << i+1 << endl;
			for (; man[choise_aliance].Get_health() < 1; choise_aliance = rand() % 3);
			for (; orc[choise_enemy].Get_health() <1; choise_enemy = rand() % 3);
				war(man[choise_aliance ], orc[choise_enemy]);
			over = Victory(orc, size, over);
			cout << ".............................................." << endl << endl;
		if(over == false) {
			choise_aliance = 1;
			choise_enemy = 1;
			cout << "Comp turn                   raund " << i +1 << endl;
			for (; orc[choise_aliance].Get_health() <1 ; choise_aliance = rand() % 3);
			for (; man[choise_enemy].Get_health() <1  ; choise_enemy = rand() % 3);
				war(orc[choise_aliance ], man[choise_enemy ]);
			over = Victory(man, size, over);
			cout << ".............................................." << endl;
		}
		system("pause");
		system("cls");
	}
	orc = nullptr;
	man = nullptr;
	delete orc;
	delete man;
	system("pause");
	return 0;
}