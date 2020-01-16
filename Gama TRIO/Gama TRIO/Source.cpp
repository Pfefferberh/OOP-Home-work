//Опишіть класи "Swordsman" (Мечник), "Archer" (Лучник)і "Mage" (Маг), кожен з яких є екземпляром базового класу "Unit" (штука, елемент) в комп'ютерній грі, і може атакувати, ухилятись від атак і вмирати.
//
//У мечника 15 хіт - поінтів(життів), пошкодження при атаці 5, шанс ухилятись 60 % .
//Лучник: 12 hp, 4 dmg, 40 % dodge
//	Маг : 8 hp, 10 dmg, 30 % dodge
//
//
//	В main() створіть два масива(ворогуючі сторони) по три юніта в кожному, причому тип юніта(мечник, лучник чи маг) має задаватись випадково, при заповненні цих масивів.Тобто один раз запустивши вашу програму, може створитись три лучники проти мечника і двох магів, іншого - лучник, мечник і маг проти двох мечників і лучника і т.д.
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
public:
	string name;
	int health;
	int damage;
	int chans;
	
	static void show(unit team_one, unit team_two);
	void Set_health(int health) { this->health = health; };
	int Get_health() { return this->health; };
	unit() {};
	~unit() {};
};

class Swords :public unit
{
public:
	Swords() {
		this->name = "Swords";
		this->damage = 5;
		this->health = 15;
		this->chans = 60;
	};
	~Swords() {};
};
class Archer :public unit
{
public:
	Archer() {
		this->name = "Archer";
		this->damage = 10;
		this->health = 8;
		this->chans = 30;
	};
	~Archer() {};
};
class Withard :public unit
{
public:
	Withard() {
		this->name = "Withard";
		this->damage = 4;
		this->health = 12;
		this->chans = 40;
	};
	~Withard() {};
};

void unit::show(unit team_one, unit team_two)
{
	cout << team_two.name << " Health: " << team_two.health << endl;
	cout << team_one.name << " Health: " << team_one.health << endl;
}
void war(unit &team_one, unit &team_two);
void war(unit& team_one, unit  &team_two)
{
	//show(team_one, team_two);
	int chans_random = rand() % 100;
	cout << "-------------->>------------" << endl;
	if (chans_random > team_one.chans) {
		cout << team_two.name << " attacked " << team_one.name << endl;
		cout << "Health " << team_one.name <<": "<< team_one.Get_health()<<" - "<< team_two.name<<" damage: "<<team_two.damage<<endl;
		team_one.Set_health(team_one.Get_health() - team_two.damage);
		cout << "Health " << team_one.name << ": " << team_one.Get_health() << endl;
		if (team_one.Get_health()<=0) {
			cout << " Die " << endl;
		}
	}
	else {
		cout << " Blocking fate " << endl;
	}
	cout << "--------------<<------------" << endl;
	/*if (rand() % 100 > team_two.chans) {
		team_two.health = team_two.health - team_one.damage;
		cout << team_two.health << " - " << team_one.damage << endl;
		cout << team_one.name << " attacked " << team_two.name << endl;
		cout << "Health " << team_two.name << ": " << team_two.health << endl;
	}*/
}

void Fill_army(unit* army, int size) {
	int chans;
	for (int i = 0; i < size; i++) {
		chans = rand() % 3;
		if (chans == 1) {
			army[i] = Swords();
		}
		else if (chans == 2) {
			army[i] = Archer();
		}
		else {
			army[i] = Withard();
		}
	}
	for (int i = 0; i < size; i++) {
		cout << i + 1 << army[i].name << endl;
	}
}
int main() {
	srand(unsigned(time(NULL)));
	const int size = 3;
	int choise_aliance;
	int choise_enemy;
	unit* orc = new unit[size];
	unit* man = new unit[size];
	cout << "`````````````````````````Team 1``````````````````" << endl;
	Fill_army(orc, size);
	cout << "`````````````````````````Team 2``````````````````" << endl;
	Fill_army(man, size);
	cout << "`````````````````````````war``````````````````" << endl;
	for (int i = 0;i<10;i++) {
		cout << "Choise your unit: ";
		cin >> choise_aliance;
		cout << "Choise enemy unit: ";
		cin >> choise_enemy;
		if (man[choise_aliance-1].health > 0 ) {
			war(man[choise_aliance-1], orc[choise_enemy-1]);
		}
	}
	
	delete orc;
	delete man;
	system("pause");
	return 0;
}