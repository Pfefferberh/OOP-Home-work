//Побудувати клас для роботи з однозв’язним списком.Елемент списку містить наступну інформацію про автобус :
//
//номер автобуса;
//прізвище та ініціали водія;
//номер маршруту.
//Програма повинна забезпечувати :
//початкове формування двох списків :
//з даними про автобуси, які знаходяться в автопарку;
//з даними про автобуси, які знаходяться на маршрутах.
//При виїзді кождого автобуса з парку вводиться номер автобуса, і програма видаляє дані про цей автобус з списку автобусів, які знаходяться в автопарку, та записує ці дані в список автобусів, які знаходяться на маршруті.
//аналогічна операція виконується для списків, якщо якийсь автобус повертається в автопарк;
//по запиту видіються відомості про автобуси, які знаходяться в автопарку або на маршруті.

#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2, typename T3>
class BusStation
{
private:
	template <typename T1, typename T2, typename T3>
	class Bus
	{
	public:
		Bus* nextBus;
		T1 data1;
		T2 data2;
		T3 data3;
		Bus(T1 data1, T2 data2, T3 data3, Bus* nextBus = nullptr) {
			this->data1 = data1;
			this->data2 = data2;
			this->data3 = data3;
			this->nextBus = nextBus;
		};
		Bus() {};
		~Bus() {};
	};
	Bus <T1, T2, T3>* head;
	int size;
public:
	BusStation()
	{
		this->head = nullptr;
		this->size = 0;
	};
	int GetSize() {
		return this->size;
	}
	void Push(T1 data1, T2 data2, T3 data3) {
		if (head == nullptr) {
			head = new Bus <T1, T2, T3>(data1, data2, data3);
		}
		else
		{
			Bus <T1, T2, T3>* current = this->head;
			while (current->nextBus != nullptr)
			{
				current = current->nextBus;
			}
			current->nextBus = new Bus <T1, T2, T3>(data1, data2, data3);
		}
		this->size++;
	}
	void ShowData() {
		Bus <T1, T2, T3>* current = head;
		int counter = 0;
		while (current != nullptr) {
			cout << "Bus N" << counter + 1 << ":\n"
				<< "Bus's number: " << current->data1 << "\nDriver's name: " << current->data2 << "\nWay's number: " << current->data3 << endl;
			current = current->nextBus;
			counter++;
		}
	}
	void DeleteFirst() {

		Bus <T1, T2, T3>* temp = this->head;
		this->head = this->head->nextBus;
		delete temp;
		size--;
	}
	void AddFirst(T1 data1, T2 data2, T3 data3) {
		this->head = new Bus <T1, T2, T3>(data1, data2, data3, this->head);
		this->size++;
	}
	void RemoveByIndex(const int index) {
		if (index == 0) {
			DeleteFirst();
		}
		else {
			Bus <T1, T2, T3>* prev = this->head;
			for (int i = 0; i < index - 1; i++) {
				prev = prev->nextBus;
			}
			Bus <T1, T2, T3>* toDel = prev->nextBus;
			prev->nextBus = toDel->nextBus;
			delete toDel;
			size--;
		}
	};
	void Transfer(const int index, BusStation& other) {
		if (index < this->size) {
			if (index == 0) {
				other.AddFirst(this->head->data1, this->head->data2, this->head->data3);
				DeleteFirst();


			}
			else {
				Bus <T1, T2, T3>* prev = this->head;
				for (int i = 0; i < index - 1; i++) {
					prev = prev->nextBus;
				}

				Bus <T1, T2, T3>* toDel = prev->nextBus;
				other.AddFirst(toDel->data1, toDel->data2, toDel->data3);
				prev->nextBus = toDel->nextBus;
				delete toDel;
				this->size--;
			}
		}
		else
		{
			cout << "Wrong index!!\n";
		}
	};

	~BusStation() {

		DeleteFirst();
	};
};

void Menu() {
	system("cls");
	cout << "----------------------MENU---------------"<<endl;
	cout << "1 - Add bus\n2 - Show buses on park\n3 - Show busses on way\n4 - Transfer park to way\n5 - Transfer way to park\n0 - Exit\n";
	cout << "----------------------MENU---------------" << endl; 
	cout << "Your choice: " ;
}


int main() {
	bool exit = false;

	BusStation <string, string, int> parkList;
	BusStation <string, string, int> wayList;

	parkList.Push("AF5645DO", "Alyosha", 156);
	parkList.Push("BF8745JO", "Styopa", 437);
	parkList.Push("AF3705FO", "Misha", 850);
	parkList.Push("AD9999UO", "Kolya", 371);

	wayList.Push("HD9145HO", "Vanya", 171);
	wayList.Push("AD5613UO", "Vitalik", 784);
	wayList.Push("KD6767JO", "Volodya", 432);

	string busNumber;
	string driverName;
	int wayNumber = 0;
	int choice = 0;
	int removeNumber = 0;

	while (!exit)
	{
		Menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter bus's number: ";
			cin >> busNumber;
			cout << "Enter driver's name: ";
			cin >> driverName;
			cout << "Enter way's number: ";
			cin >> wayNumber;
			parkList.AddFirst(busNumber, driverName, wayNumber);
			cout << "Added to park list" << endl;
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "-------------------Park list-------------------\n";
			parkList.ShowData();
			cout << "-------------------Park list-------------------\n";
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "-------------------Way list-------------------\n";
			wayList.ShowData();
			cout << "-------------------Way list-------------------\n";
			system("pause");
			break;
		case 4:
			system("cls");
			if (parkList.GetSize() > 0) {
				cout << "-------------------Park list-------------------\n";
				parkList.ShowData();
				cout << "-------------------Park list-------------------\n";
				cout << "Enter bus's N: ";
				cin >> removeNumber;
				parkList.Transfer(removeNumber - 1, wayList);
				cout << "Transfered to way list\n";
			}
			else
			{
				cout << "Empty list!\n";
			}
			system("pause");
			break;
		case 5:
			system("cls");
			if (wayList.GetSize() > 0) {
				cout << "-------------------Way list-------------------\n";
				wayList.ShowData();
				cout << "-------------------Way list-------------------\n";
				cout << "Enter bus's N: ";
				cin >> removeNumber;
				wayList.Transfer(removeNumber - 1, parkList);
				cout << "Transfered to park list\n";
			}
			else
			{
				cout << "Empty list!\n";
			}
			system("pause");
			break;
		case 0:
			exit = true;
			break;
		default:
			cout << "Wrong choice!!! Try again.\n";
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}