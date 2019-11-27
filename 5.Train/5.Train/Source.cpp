#include "Train.h"

int main() {

	/*Train polissya("Rivne - Lviv", 210, "Lux", 200);
	polissya.ShowTrain();*/

	/*const int SIZE = 3;
	Train trains[SIZE]{
		Train("Rivne - Lviv", 210, "Lux", 200),
		Train("Charkiv - Uzgorod", 1110, "Lux", 210),
		Train("Kyiv - Odessa ", 610, "DeLux", 400)
	};
*/
/*Train doom("Rivne - Lviv", 210,2);
doom.ShowTrain();*/
/*for (int i = 0; i < SIZE; i++) {
	trains[i].ShowTrain();
}
*/
	string cours;
	int way;
	int size;
	Train* dooms = new Train[2];
	for (int i = 0; i < 2; i++) {
		cout << "Enter name cours : ";
		cin >> cours;
		cout << "Enter long way : ";
		cin >> way;
		cout << "Enter count cars : ";
		cin >> size;
		dooms[i] = Train(cours, way, size);
	}
	for (int i = 0; i < 2; i++) {
		dooms[i].ShowTrain();
	}


	dooms = nullptr;
	delete[]dooms;
	system("pause");
	return 0;
}