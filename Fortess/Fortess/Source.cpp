//Описати клас "Fortress" (Фортеця).
//
//Для початку, напишіть клас "Shooter" (стрілець), який буде містити два поля : назва аммуніції та її кількість.
//Він може виконати дію "постріл" і витратити для цього одиницю амуніції, повідомляючи в консоль, як вона називалась.
//А також може здійснити дію "дати амуніцію", яка встановлюватиме назву і кількість амуніції, отримуючі ці дані через параметри.
//
//Стрілець має три дочірні класи : "Archer" (Лучник), "Ranger" (Рейнджер)та "Catapult" (Катапульта), які заміщають дію "постріл",
//доповнюючи повідомлення в консоль інформацією про те, хто саме з них вистрілив.Перші два повинні стріляти стрілами, а катапульта - каменями.
//
//Від перших двох породжується клас "ArcherTower" (Cтрілкова вежа), у якої запас амуніції має бути один(спільний) для обох :
//лучника і рейнджера(подумайте, який механізм множинного успадкування тут варто застосувати).
//
//Від класів "стрілкова вежа" і "катапульта" має походити клас "Fortress".Лише в її конструкторі мають поставлятись стріли для стрілкової вежі і камені для катапульти.
//Додайте до фортеці ще кілька полів - товщина стін, стан воріт у відсотках, і т.д. - по вашому бажанню та фантазії.
//
//Більше ніяких допоміжних методів чи об'єктів створювати не потрібно. 
//В кожного з полів чи методів у цій ієрархії має бути встановлений максимальний рівень захисту, 
//і успадкування має відбуватись по найвищо-допустимому по захисту специфікаторові доступу. Але таким, щоб в main() можна було виконати наступне: 
//
//- створити об'єкт фортеці 
//- вистрілити тричі лучником, двічі рейнджером і раз з катапульти
//Отже, всього має бути 6 класів, вінцем творіння і фінальним дитям серед них є клас "Фортеця", 
//лише один об'єкт якої буде створено. Зверніть на це увагу - 6 класів описано, всі використовуються. Але об'єкт у всій програмі один.
//
//ПРИМІТКИ!Коли створюватиметься фортеця, доставте в стрілкову вежу лише 4 стріли, тоді буде явно видно, 
//що на другий постріл рейнджеру стріл не вистачить, оскільки лучник перед тим витратив 3 із 4 - х стріл.


#include<iostream>
#include<string>
using namespace std;

class Shooter 
{
public:
	string nameAmmunition;
	int quantityAmmunition;

	Shooter(string nameAmmunition = "weapon", int quantityAmmunition = 1)
	{
		this->nameAmmunition = nameAmmunition;
		this->quantityAmmunition = quantityAmmunition;
	}

	void Fire() {
		if (this->quantityAmmunition > 0) {
			this->quantityAmmunition--;
			cout << "fired by " << this->nameAmmunition << ", remains: " << this->quantityAmmunition << endl;
		}
		else cout << "Not enough ammunition" << endl;
	}

	void GiveAmmo(string nameAmmunition, int quantityAmmunition) {
		this->nameAmmunition = nameAmmunition;
		this->quantityAmmunition = quantityAmmunition;
	}

};

class Archer : virtual public Shooter
{
public:
	Archer(string nameAmmunition = "arrow", int quantityAmmunition = 1)
	{
		Archer::GiveAmmo(nameAmmunition, quantityAmmunition);
	}

	void Fire() {
		cout << "Archer ";
		Shooter::Fire();
	}
};

class Ranger : virtual public Shooter
{
public:
	Ranger(string nameAmmunition = "arrow", int quantityAmmunition = 1)
	{
		Ranger::GiveAmmo(nameAmmunition, quantityAmmunition);
	}

	void Fire() {
		cout << "Ranger ";
		Shooter::Fire();
	}
};

class Catapult : public Shooter
{
public:
	Catapult(string nameAmmunition = "stone", int quantityAmmunition = 1)
	{
		Catapult::GiveAmmo(nameAmmunition, quantityAmmunition);
	}

	void Fire() {
		cout << "Catapult ";
		Shooter::Fire();
	}
};

class ArcherTower : public Archer, public Ranger
{
public:
	ArcherTower(string nameAmmunition = "stone", int quantityAmmunition = 1) {}
};

class Fortress : public ArcherTower, public Catapult
{
public:
	Fortress(int quantityArrow = 0, int quantityStone = 1) {
		ArcherTower::quantityAmmunition = quantityArrow;
		Catapult::quantityAmmunition = quantityStone;
	}
};

int main() {
	
	Fortress fortress(4, 4);

	fortress.Archer::Fire();
	fortress.Archer::Fire();
	fortress.Archer::Fire();

	fortress.Ranger::Fire();
	fortress.Ranger::Fire();

	fortress.Catapult::Fire();

	system("pause");
	return 0;
}