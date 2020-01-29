//������� �����& quot; Swordsman& quot; (������), & quot; Archer& quot; (������)�& quot; Mage& quot; (���), ����� � ���� �
//����������� ��������(����� ������������) �����& quot; Unit& quot; (�����, �������) � ����& #39; ������
//��, � ���� ���������, ��������� �� ���� � �������.
//� ������� 15 ��� - �����(�����), ����������� ��� ����� 5, ���� ��������� 60 % .
//������: 12 hp, 4 dmg, 40 % dodge
//��� : 8 hp, 10 dmg, 30 % dodge
//
//------------------------------------------------------------------------------------------------------------ -
//������� ���� & quot; Team& quot; (�������), � ����� � ����
//o ����� �������
//o ����� �� ������ �� ���(�� �����) ����,
//������� ��� ����(������, ������ �� ���) �� ���������� ���������, ���
//��������� �������(�� ������� ���).
//�������� ������ :
//o �������� �� � ������ � �� ���� ������
//o ������ ������� �������
//------------------------------------------------------------------------------------------------------------ -
//������� ���� & quot; Game& quot; (���), �� ������ 2 ������� ���������� �����
//������ ������� ���������� ����� : ��� ������� ����� ������� � ���� ����, ��� -
//������, ������ � ��� ����� ���� ������� � ������� � �.�(��� ������� ������� � ������
//	3).
//	������� ����� ��� �� ���������, ���� ���� ���� � ����� �� �� ��������.�
//	������� ��� ����� �������� ����������� ��� ���� ��������, �� ������� �����, ������
//	����� ���������� � ������ �� ���� ��������.����� �� ���������� ���������, ��
//	���������� ������ spacebar(������), ��� �� ����� ����������� ���� ����� �� ������.
//	� ���� ��� ��������, ��� ������� ���������(����� / �����, ���� / �������, ������ / ���� ��
//		��.).
//	...............................................................................................................
//	������� ��� : ����� ����(���, ������ �� ���) ������ ����� ������ ��������� �����
//	���� � ����� ����.
//	������, ���� ���� ������� :
//A11 - M21
//A12 - S22
//S13 - A23
//...�� �11 �� ������� �� ����� �23.
//���� ������ ����� ���� �� ��������, ��� ����� ���� �������� ��������� ���������

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Unit
{
public:
	void Show_unit() {
		cout << this->name << endl;
	}
	int Get_health() { return this->health; }
	int Get_atack() { return this->atack_damage; }
	int Get_block() { return this->dodge_block; }
	string Get_name() { return this->name; }
	void Set_health(int health) { this->health=health; }
protected:
	string name;
	int atack_damage;
	int dodge_block;
	int health;
};

class Swordsman:public Unit
{
public:
	Swordsman()
	{
		this->name = "Swordsman";
		this->atack_damage =5;
		this->dodge_block =60 ;
		this->health =15 ;
	}
	~Swordsman(){}
};
class Archer :public Unit
{
public:
	Archer()
	{
		this->name = "Archer";
		this->atack_damage = 4;
		this->dodge_block = 40;
		this->health = 12;
	}
	~Archer() {}
};
class Mage :public Unit
{
public:
	Mage()
	{
		this->name = "Mage";
		this->atack_damage = 10;
		this->dodge_block = 30;
		this->health = 8;
	}
	~Mage() {}
};
class Team
{
public:
	Team(string team, int count){
		this->name_team = team;
	for (int i = 0; i < count;i++) {  
		this->random = rand() % 3; this->Create_army(); 
		} 
	}
	Team(){}
	~Team(){}

	void Show_team() {
		for (unsigned int i = 0; i < this->army.size(); i++) {
			this->army[i].Show_unit();
		}
	}
	void Living_army() {
		for (unsigned int i = 0;i<this->army.size(); i++) {
			if (this->army[i].Get_health()< 1) {
			
				this->army.erase(army.begin()+i);
			}
			else {
				this->army[i].Show_unit();
			}
		}
	}
	vector<Unit> army;
private:
	string name_team;

	int random;
	void Create_army() {
		if (random == 0)
			this->army.push_back(Swordsman());
		else if (random == 1)
			this->army.push_back(Archer());
		else if (random ==2)
			this->army.push_back(Mage());
	}

};
class Game
{
public:
	Game(){
		this->Create_team();
		this->team_one=Team(enter_name, count_arm);
		this->Create_team();
		this->team_two = Team(enter_name, count_arm);
	}
	~Game(){}
	void War() {
		int atacking=rand()%3;
		int blocking = rand() % 3;

		this->team_one.Show_team();
		this->team_two.Show_team();

		cout << "              ATACK FIRST TEAM            " << endl;
		for (int i = 0;i<15;i++) {
			atacking = rand() % 3;
			for (; this->team_one.army[atacking].Get_health()<1; atacking = rand() % 3 );
			blocking = rand() % 3;
			blocking = this->choise_enemy(atacking);
			cout << "ATACKED -- " << this->team_one.army[atacking].Get_name() << endl;
			cout << "Blocked -- " << this->team_two.army[blocking].Get_name() << endl;
			cout << this->team_two.army[blocking].Get_health() <<" - "<<this->team_one.army[atacking].Get_atack() << endl;
			this->team_two.army[blocking].Set_health(this->team_two.army[blocking].Get_health() - this->team_one.army[atacking].Get_atack());
			cout << "HEALTH team_two " << this->team_two.army[blocking].Get_health() << endl;
			
			system("pause");
		}
	}
private:
	Team team_one;
	Team team_two;
	int count_arm;
	string enter_name;
	void Create_team() {
		cout << "Enter name team : ";
		cin >> this->enter_name;
		cout << "Enter count army : 3  " << endl;
		//cin >> this->count_arm;
		this->count_arm = 3;
	}


	int choise_enemy(int atacking) {
		bool stop_one = false;
		bool stop_two = false;
		for (int i = 0; stop_one == false; i++) {
			if (this->team_one.army[atacking].Get_name() == this->team_two.army[i].Get_name()&& this->team_two.army[i].Get_health() > 1) {
				return i;
			}
			else if (i>2) {
				cout << " there  " << endl;
				stop_one = true;
			}
		}
		
		for (int j = 0; stop_two == false; j++) {
			cout << "there in ";
			if (this->team_two.army[j].Get_health() > 1) {
				stop_two = true;
				return j;
			}
			else if (j > 2) {
				stop_two = true;
			}
		}
	}
};

int main() {
	srand(unsigned(time(NULL)));

	Game t;
	t.War();
	

	system("pause");
	return 0;
}