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
	virtual void Fill() =0;
	unit() {};
	~unit() {};
};

class Swords :public unit
{
public:
	Swords() { Fill(); };
	~Swords() {};
	void Fill ()override {
		this->name = "Swords";
		this->damage = 5;
		this->health = 15;
		this->chans = 60;
	}
};
class Archer :public unit
{
public:
	Archer() { Fill(); };
	~Archer() {};
	void Fill()override {
		this->name = "Archer";
		this->damage = 10;
		this->health = 8;
		this->chans = 30;
	};
};
class Withard :public unit
{
public:
	Withard() { Fill(); };
	~Withard() {};
	void Fill()override {
		this->name = "Withard";
		this->damage = 4;
		this->health = 12;
		this->chans = 40;
	};
};

class Player {
	string name;
	int health;
public:
	void Fill(unit* vehicles) {
		vehicles->Fill();
		this->name=vehicles->name;
		this->health =vehicles->health;
	}
	string Get_name() { return this->name; };
	int Get_health() { return this->health; };
};
void war(unit* team_one, unit* team_two)
{
	//show(team_one,team_two);
	if (rand() % 100 > team_one->chans) {
		team_one->health = team_one->health - team_two->damage;
		cout << team_two->name << " attacked " << team_one->name << endl;
		cout << "Health " << team_one->name << ": " << team_one->health << endl;
	}

	if (rand() % 100 > team_two->chans) {
		team_two->health = team_two->health - team_one->damage;
		cout << team_one->name << " attacked " << team_two->name << endl;
		cout << "Health " << team_two->name << ": " << team_two->health << endl;
	}

}
void show(Player team_one, Player team_two)
{
	cout << team_two.Get_name() << " Health: " << team_two.Get_health() << endl;
	cout << team_one.Get_name() << " Health: " << team_one.Get_health() << endl;
}

void Fill_army(Player* army, int size) {
	Swords swords;
	Archer archer;
	Withard withard;
	int chans;
	for (int i = 0; i < size; i++) {
		chans = rand() % 3;
		if (chans == 1) {
			army[i].Fill(&swords);
		}
		else if (chans == 2) {
			army[i].Fill(&archer);
		}
		else {
			army[i].Fill(&withard);
		}
	}
	for (int i = 0; i < size; i++) {
		cout << i + 1 << army[i].Get_name() << endl;
	}
}
int main() {
	srand(unsigned(time(NULL)));
	const int size = 3;
	Player orc[size];
	Player man[size];
	Fill_army(orc,size);
	Fill_army(man,size);
	for (int i = 0;i<3;i++) {
		show(orc[i],man[i]);
	}
	system("pause");
	return 0;
}