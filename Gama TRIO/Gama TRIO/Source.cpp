//������� ����� "Swordsman" (������), "Archer" (������)� "Mage" (���), ����� � ���� � ����������� �������� ����� "Unit" (�����, �������) � ����'������ ��, � ���� ���������, ��������� �� ���� � �������.
//
//� ������� 15 ��� - �����(�����), ����������� ��� ����� 5, ���� ��������� 60 % .
//������: 12 hp, 4 dmg, 40 % dodge
//	��� : 8 hp, 10 dmg, 30 % dodge
//
//
//	� main() ������� ��� ������(��������� �������) �� ��� ���� � �������, ������� ��� ����(������, ������ �� ���) �� ���������� ���������, ��� ��������� ��� ������.����� ���� ��� ���������� ���� ��������, ���� ���������� ��� ������� ����� ������� � ���� ����, ������ - ������, ������ � ��� ����� ���� ������� � ������� � �.�.
//
//	��� � ���� ��������� �� �� ����, ���� ���� ���� � ����� �� �� ��������.� ������� ��� ����� �������� ����������� ��� ���� ��������, �� ������� �����, ������ ����� ���������� � ������ �� ���� ��������.����� �� ���������� ���������, �� ���������� ������ spacebar(������), ��� �� ����� ����������� ���� ����� �� ������.
//
//	� ���� ��� ��������, ��� ������� ���������(����� / �����, ���� / �������, ������ / ���� - �� ��� ���� ������� ��� �������).
//
//	�� �������� �������� ���������� ���� ���, �� �� ���������.
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