//#include <iostream>
//
//using namespace std;
//class List
//{
//public:
//	List();
//	~List();
//	void push_back(int number, int way, string name, string surname);
//	int Get_size() { return this->Size; };
//	
//private:
//	class Node
//	{
//	public:
//		Node* pNext;
//		int number;
//		int way;
//		string name;
//		string surname;
//		Node(int number = NULL, int way = NULL, string name = "", string surname = "", Node* pNext=nullptr)
//		{
//			this-> number= number;
//			this-> way= way;
//			this-> name= name;
//			this-> surname= surname;
//			this->pNext = pNext;
//		}
//	};
//	int Size;
//	Node* head;
//public:
//	int& operator[](const int index) {
//		Node* current = this->head;
//		for (int counter = 0; current != nullptr; counter++)
//		{
//			if (counter == index) {
//				cout<<current->name<<endl;
//				cout<<current->surname<<endl;
//				cout<<current->way<<endl;
//				return current->number;
//			}
//			current = current->pNext;
//		}
//	};
//
//};
//
//List::List()
//{
//	Size = 0;
//	head = nullptr;
//}
//
//List::~List()
//{
//}
//
//void List::push_back(int number=NULL, int way = NULL, string name="", string surname="")
//{
//	if (head == nullptr) {
//		head = new Node (number,way,name,surname);
//	}
//	else {
//		Node* current=this->head;
//		while (current->pNext!=nullptr)
//		{
//			current = current->pNext;
//		}
//		current->pNext = new Node(number, way, name, surname);
//	}
//	Size++;
//}
//
//
//int main() {
//	List lst;
//	lst.push_back(7,5,"jj","kk");
//	lst.push_back(5);
//	//lst.push_back(45);
//	//cout << lst[1] << endl;
//	lst[0];
//	lst[1];
//	system("pause");
//	return 0;
//}


#include <iostream>

using namespace std;
template<typename T, typename Y>
class List
{
public:
	List();
	~List();

	int Get_size() { return this->Size; };
	char operator[](const int index);

	void DeleteFirst();
	void Delete_index(const int index);
	void Delete_index_for (const int index, List lst);
	void ClearList();

	void push_back(T number = T(), T way = T(), Y name = Y(), Y surname = Y());
	

private:
	template<typename T, typename Y>
	class Node
	{
	public:
		Node* pNext;
		T number;
		T way;
		Y name;
		Y surname;
		int Get_number() { return this->number; };
		int Get_way() { return this->way; };
		string Get_name() { return this->name; };
		string Get_surname() { return this->surname; };

		Node(T number = T(), T way = T(), Y name = Y(), Y surname = Y(), Node* pNext = nullptr)
		{
			this->number = number;
			this->way = way;
			this->name = name;
			this->surname = surname;
			this->pNext = pNext;
		}
	};
	int Size;
	Node <T, Y>* head;
};

template<typename T, typename Y>
List<T,Y>::List()
{
	Size = 0;
	head = nullptr;
}
template<typename T, typename Y>
List<T, Y>::~List()
{
	DeleteFirst();
}

template<typename T, typename Y>
char List<T, Y>::operator[](const int index) {
	Node<T, Y>* current = this->head;
	for (int counter = 0; current != nullptr; counter++)
	{
		if (counter == index && counter <= Size) {
			cout << " ---------BUS---------------" << endl;
			cout << "Name : " << current->name << endl;
			cout << "Surname : " << current->surname << endl;
			cout << "Way : " << current->way << endl;
			cout << "Number : " << current->number << endl;
			return '.';
		}
		current = current->pNext;
	}
	cout << "Element " << index << " dont be" << endl;
	return '.';
}

template<typename T, typename Y>
void List<T, Y>::DeleteFirst()
{
	Node<T,Y>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}
template<typename T, typename Y>
void List<T, Y>::Delete_index(const int index) {
	if (index == 0) {
		DeleteFirst();
	}
	else {
		Node <T, Y>* previus = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previus = previus->pNext;
		}
		Node <T, Y>* to_del = previus->pNext;
		previus->pNext = to_del->pNext;
		delete to_del;
		Size--;
	}
}
template<typename T, typename Y>
void List<T, Y>::Delete_index_for(const int index,List lst)
{
	Node <T, Y>* to_del = head;
	if (index == 0) {
		int number= to_del->Get_number();
		int way=to_del->Get_way();
		string name =to_del->Get_name();
		string surname =to_del->Get_surname();
		lst.push_back(number, way, name, surname);
		//DeleteFirst();
	}
	else {
		Node <T, Y>* previus = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previus = previus->pNext;
		}
		to_del = previus->pNext;


			Node<T, Y>* current = lst.head;
			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node<T, Y>(previus->Get_number(), previus->Get_way(), previus->Get_name(), previus->Get_surname());
		lst.Size++;


		/*previus->pNext = to_del->pNext;
		delete to_del;
		Size--;*/
	}
}
template<typename T, typename Y>
void List<T, Y>::ClearList() {
	while (Size)
	{
		DeleteFirst();
	}
}

template<typename T, typename Y>
void List<T, Y>::push_back(T number , T way, Y name , Y surname)
{
	if (head == nullptr) {
		head = new Node<T, Y>(number, way, name, surname);
	}
	else {
		Node<T, Y>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T, Y>(number, way, name, surname);
	}
	Size++;
}

void menu() {
	List <int, string> baza;
	List <int, string> on_the_way;
	string fill_name;
	string fill_surname;
	int fill_way;
	int fill_number;
	int choise = 0;
	int choise_for_swith = 0;
	bool exit = true;
	for (; exit == true;) {
		cout << "----------------- Meny baza ----------------" << endl;
		cout << "1. Create new bus info in baza" << endl;
		cout << "2. Delete bus info baza" << endl;
		cout << "3. Bus driving from baza " << endl;
		cout << "4. Bus driving into baza " << endl;
		cout << "5. Show info about bus on the way " << endl;
		cout << "6. Show info about bus in the baza " << endl;
		cout << "0. Exit " << endl;
		cin >> choise_for_swith;
		switch (choise_for_swith)
		{
		case 1:
			cout << "Enter number of bus " << endl;
			cin >> fill_number;
			cout << "Enter way of bus " << endl;
			cin >> fill_way;
			cout << "Enter name " << endl;
			cin >> fill_name;
			cout << "Enter surname " << endl;
			cin >> fill_surname;
			baza.push_back(fill_number, fill_way, fill_name, fill_surname);
			break;
		case 2:
			cout << "Enter the nomber deleting bus " << endl;
			cin >> choise;
			baza.Delete_index(choise);
			break;
		case 3:
			on_the_way.push_back(1,1,"a","a");
			on_the_way[0];
			cout << "Enter the nomber driving bus " << endl;
			cin >> choise;
			baza.Delete_index_for(choise,on_the_way);
		
			break;
		case 4:
			cout << "Enter the nomber driving bus " << endl;
			cin >> choise;
			on_the_way.Delete_index_for(choise, baza);
			break;
		case 5:
			for (int i = 0; i < on_the_way.Get_size();i++) {
				on_the_way[i];
			}
			break;
		case 6:
			for (int i = 0; i < baza.Get_size(); i++) {
				baza[i];
			}
			break;
		case 0:
			exit = false;
			break;
		default:
			break;
		}
	}
}

int main() {
	menu();

	system("pause");
	return 0;
}
