//Задание.
//Реализовать базу данных ГАИ по штрафным квитанциям
//с помощью бинарного дерева.Ключом будет служить
//номер автомашины, значением узла — список правонарушений.Если квитанция добавляется в первый раз,
//то в дереве появляется новый узел, а в списке данные по
//правонарушению; если нет, то данные заносятся в существующий список.Необходимо также реализовать
//следующие операции :
//•	 Полная распечатка базы данных(по номерам машин
//	и списку правонарушений, числящихся за ними);
//•	 Распечатка данных по заданному номеру;
//•	 Распечатка данных по диапазону номеров.
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
struct Broken_ruls {
	string *list;
	int size;
	int number;
	void create() {
		this->size=1;
		this->list = new string[this->size];
		cout << "Enter broken ruls(end sentens enter';'): " << endl;
			getline(cin, this->list[0], ';');
	};
	void add() {
		this->size++;
		string *listss = new string[this->size];
		cout << "Enter broken ruls(end sentens enter';'): " << endl;
		for (int i = 0; i < size; i++) {
			if(i==this->size-1){
				getline(cin, listss[i], ';');
			}
			else {
				listss[i]=this->list[i];
			}
		}
		this->list = nullptr;
		this->list = listss;
	}
	void Show() {
		cout << "Broken ruls: ";
		for (int i = 0;i<this->size;i++) {
			cout<< this->list[i];
		}
	};
};
struct Node {
	Broken_ruls data;
	struct Node* left;
	struct Node* right;
};

Node* CreateNewNode(int data) {
	Node* newNode = new Node();
	newNode->data.number = data;
	newNode->data.create();
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = CreateNewNode(data);
	}
	else if (data < root->data.number) {
		root->left = Insert(root->left, data);
	}
	else if (data == root->data.number) {
		 root->data.add();
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(Node* root,  int data) {
	if (root == NULL) {
		return false;
	}
	else if (root->data.number == data) {
		root->data.Show();
		return true;
	}
	else if (data <= root->data.number) {
		return Search(root->left, data);
	}
	else {
		return Search(root->right, data);
	}
}
void ShowAll(Node* root) {
	if (root == NULL) return;
	else {
		ShowAll(root->left);
		cout <<"Number car "<< root->data.number << " |_| "; root->data.Show() ;
		cout << endl;
	}
	ShowAll(root->right);
}
int main() {
	int number;
	int end;
	int count;

	Node* root = NULL;
	cout << "------------------Fill data-------------------" << endl;
	cout << "Enter count" << endl;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << "Enter number of the car: " << endl;
		cin >> number;
		root = Insert(root, number);
	}
	cout << "-----------end---------------" << endl;
	cout << "-----------search number the car---------------" << endl;
	cout << "Enter number for search: " << endl;
	cin >> number;
	if (Search(root, number) == true) {
		cout << "Number: " << number << " Found" << endl;
	}
	else {
		cout << number << " Not found" << endl;
	}
	cout << "-----------end---------------" << endl;
	cout << "-----------show diapazon number the car---------------" << endl;
	cout << "Enter first number for search: " << endl;
	cin >> number;
	cout << "Enter last number for search: " << endl;
	cin >> end;
	cout << "===========================" << endl;
	for (;number<=end;number++) {
		if (Search(root, number) == true) {
			cout << "Number: " << number << " Found" << endl;
			cout << "===========================" << endl;
		}
	}
	cout << "-----------end---------------" << endl;
	cout << "-----------all baza number the car---------------" << endl;
	ShowAll(root);
	cout << "-----------end---------------" << endl;
	system("pause");
	return 0;
}