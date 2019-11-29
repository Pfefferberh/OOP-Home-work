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

char Fish::ocean[10][12];

 int Fish::fish_count=0;
int main() {
	srand(unsigned(time(NULL)));
	int choise = 1;
	Fish first;
	Fish two;
	cout << "Enter 0 for exit " << endl;
	for (; choise<25;) {
		system("cls");
		cout << "Enter 0 for exit " << endl;
		cout << "Health "<< first .Get_number_fish()<<" fish : "<<first.Get_health() << endl;
		cout << "Health "<<two.Get_number_fish()<<" fish : "<<two.Get_health() << endl;

		Fish::Life_ocean();
		first.Move_fish(first.Get_x(), first.Get_y());
		two.Move_fish(two.Get_x(), two.Get_y());
		Fish::Show_ocean();
		Sleep(500);
		choise++;
	}

	
	


	system("pause");
	return 0;
}