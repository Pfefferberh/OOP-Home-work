//Создать класс СПРАВОЧНИК со следующими полями :
//1. Название фирмы;
//2. Владелец;
//3. Телефон;
//4. Адрес;
//5. Род деятельности.
//Реализовать следующие возможности :
//1. Поиск по названию;
//2. Поиск по владельцу;
//3. Поиск по номеру телефона;
//4. Поиск по роду деятельности;
//5. Показ всех записей и добавление.
//Вся информация, должна сохранятся в бинарном файле, должна быть реализована
//возможность добавления новых данных.


#include<iostream>
#include<string>
#include<fstream>


using namespace std;

class Directory {
private:
	string company_name;
	string owner;
	string phone;
	string address;
	string work;
public:

	Directory(string company_name = " ", string owner = " ", string phone = " ", string address = " ", string work = " ") {	}

	void Fill() {
		cout << " Company name : ";
		cin.ignore();
		getline(cin, company_name);
		cout << " Owner        : ";
		getline(cin, owner);
		cout << " Phone        : ";
		getline(cin, phone);
		cout << " Address      : ";
		getline(cin, address);
		cout << " Work         : ";
		getline(cin, work);
	}
	void Show_directory() {
		cout << " Company name : " << this->company_name << endl;
		cout << " Owner        : " << this->owner << endl;
		cout << " Phone        : " << this->phone << endl;
		cout << " Address      : " << this->address << endl;
		cout << " Work         : " << this->work << endl;
	}

	void Copy(Directory& other) {
		this->company_name = other.company_name;
		this->owner = other.owner;
		this->phone = other.phone;
		this->address = other.address;
		this->work = other.work;
	}
	string Getname() { return this->company_name; }
	string Getowner() { return this->owner; }
	string Getphone() { return this->phone; }
	string Getwork() { return this->work; }

};

void Create_object(Directory my_directory[], int size) {

	for (int i = 0; i < size; i++) {
		my_directory[i].Fill();
	}
	cout << "\n\n ______________________________________________________________" << endl;

	cout << "\t ================ DIRECTORY ================\n" << endl;
	for (int i = 0; i < size; i++) {
		cout << " # " << i + 1 << endl;
		my_directory[i].Show_directory();
	}
}

void Search_for_name(Directory my_directory[], int size) {
	bool exit = false;
	string name;
	cout << "\n Enter company name: ";
	/*cin.ignore();
	getline(cin, name);*/
	cin >> name;
	for (int i = 0; i < size; i++) {
		if (my_directory[i].Getname() == name) {
			my_directory[i].Show_directory();
			exit = true;
			//break;
		}
	}
	if (!exit) cout << "No result" << endl;
}

void Search_for_owner(Directory my_directory[], int size) {
	bool exit = false;
	string owner;
	cout << "\n Enter company owner: ";
	/*cin.ignore();
	getline(cin, name);*/
	cin >> owner;
	for (int i = 0; i < size; i++) {
		if (owner == my_directory[i].Getowner()) {
			my_directory[i].Show_directory();
			exit = true;
			//break;
		}
	}
	if (!exit) cout << " No result" << endl;
}

void Search_for_phone(Directory my_directory[], int size) {
	bool exit = false;
	string phone;
	cout << "\n Enter company phone: ";
	/*cin.ignore();
	getline(cin, name);*/
	cin >> phone;
	for (int i = 0; i < size; i++) {
		if (phone == my_directory[i].Getphone()) {
			my_directory[i].Show_directory();
			exit = true;
			//break;
		}
	}
	if (!exit) cout << " No result" << endl;
}

void Search_for_work(Directory my_directory[], int size) {
	bool exit = false;
	string work;
	cout << "\n Enter company word: ";
	/*cin.ignore();
	getline(cin, name);*/
	cin >> work;
	for (int i = 0; i < size; i++) {
		if (work == my_directory[i].Getwork()) {
			my_directory[i].Show_directory();
			exit = true;
			//break;
		}
	}
	if (!exit) cout << "No result" << endl;
}

void Create_new(Directory*& my_directory, int& size) {
	Directory* new_directory = new Directory[size + 1];
	for (int i = 0; i < size; i++) {
		new_directory[i].Copy(my_directory[i]);
	}
	new_directory[size].Fill();
	delete[] my_directory;
	my_directory = new_directory;
	size++;
}

void Write_to_file(Directory my_directory[], int size) {

	string path = "text.txt";
	ofstream writeFile;

	writeFile.open(path, ios::binary);

	writeFile << size << endl;
	for (int i = 0; i < size; i++) {
		writeFile.write((char*)&my_directory[i], sizeof(Directory));
	}
	writeFile.close();
}

int main()
{
	int size;
	cout << " Enter size directory : ";
	cin >> size;
	Directory* my_directory = new Directory[size];

	Create_object(my_directory, size);

	Write_to_file(my_directory, size);

	cout << "\n --> Search_for_name  : " << endl;
	Search_for_name(my_directory, size);
	cout << "\n --> Search_for_owner : " << endl;
	Search_for_owner(my_directory, size);
	cout << "\n --> Search_for_phone : " << endl;
	Search_for_phone(my_directory, size);
	cout << "\n --> Search_for_work  : " << endl;
	Search_for_work(my_directory, size);

	system("pause");
	return 0;
}