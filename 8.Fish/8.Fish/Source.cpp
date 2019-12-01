//Завдання 3.
//Створити клас Риба з наступними полями
// координати(х, у)
// поле здоров’я(чим більше значення, тим більш сита риба); при значенні 0 риба
//помирає
//статичними полями :
// океан(озеро), де можуть переміщатися екземпляри класу Риба : двовимірний масив
// число живих екземплярів риб
//та методами :
// конструктор(и)
// метод зображення риби
// метод приховування риби
// метод переміщення риби
//Протестувати роботу класу : створити декілька екземплярів риб, помістити їх у &quot; океан&quot; ,
//вивести на екран кількість екземплярів риб.
//Передбачити переміщення риб по &quot; океану&quot; .З кожним переміщенням почуття голоду риб
//росте(здоров’я зменшується).
//*Удосконалити клас Риба.У &quot; океані&quot; &quot; ростуть&quot; водорості.Риби збільшують своє
//здоров’я, якщо при переміщенні натрапляють на водорість.
#include <windows.h>
#include "Fish.h"

string ** Fish::ocean;
int Fish::plancton_x[3];
int Fish::plancton_y[3];
int Fish::size_x;
int Fish::size_y;
string Fish::fish_sumbol= "<x";
int Fish::fish_count = 0;

int main() {
	srand(unsigned(time(NULL)));
	int choise = 1;
	int size_x = 0;
	int size_y = 0;
	cout << "Enter the size vertucal for ocean window : ";
	cin >> size_x;
	cout << "Enter the size horuzontal for ocean window : ";
	cin >> size_y;
	Fish::Set_size(size_x, size_y);
	Fish::Create_ocean();
	
	Fish first;
	Fish two;
	Fish tree;
	
	Fish::Random_plancton();
	Fish::Life_ocean();

	first.Find_plancton(first.Get_x(), first.Get_y());
	cout << "-------------------" << endl;
	two.Find_plancton(two.Get_x(), two.Get_y());
	tree.Find_plancton(two.Get_x(), two.Get_y());

	for (; choise<100;) {
		system("cls");
		cout << "Enter 0 for exit " << endl;
		cout << "Health "<< first .Get_number_fish()<<" fish : "<<first.Get_health() << endl;
		cout << "Health "<<two.Get_number_fish()<<" fish : "<< two.Get_health() << endl;
		cout << "Health "<< tree.Get_number_fish()<<" fish : "<< tree.Get_health() << endl;

		Fish::Life_ocean();
		first.Move_fish();
		two.Move_fish();
		tree.Move_fish();
	
		Fish::Show_ocean();
		//Sleep(50);
		choise++;
	}

	
	
	Fish::Delete_ocean();

	system("pause");
	return 0;
}