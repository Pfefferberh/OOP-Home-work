//Описати клас Студент(ім’я, курс, оцінка у 100 - бальній системі).Перевизначити для
//класу оператор виводу у потік.
//Визначити функцію заповнення вектору(деку) студентів довільними даними
//Визначити функцію виводу вмісту вектору(деку).
//Впорядкувати вектор(дек) за іменами студентів по зростанню.
//Відсортувати вектор(дек) за прізвищами студентів
//Знайти кількість студентів, що добре навчаються(бал& gt; = 74)
//Cкопіювати студентів, що добре навчаються у інший контейнер(вектор, дек чи список)
//Встановити у перші три елементи вектору(деку) студентів самих молодших курсів за
//зростанням(partial_sort_copy).
//Зберегти інформацію про студентів у текстовому файлі
//Почитати інформацію про студентів з файлу у контейнер

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Student {
	string surname;
	int curse;
	int points;
public:
	Student() {
		cout << "Enter surname : "; cin >> this->surname;
		cout << "Enter curse : "; cin >> this->curse;
		cout << "Enter points : "; cin >> this->points;
	};
	Student(string stud, int curs, int point) {
		this->curse = curs;
		this->points = point;
		this->surname = stud;
	}

	void Fill() {

	}
	void Show() {
		cout << "------------------------" << endl;
		cout << "Surname : " << this->surname << endl;
		cout << "Curse : " << this->curse << endl;
		cout << "Points : " << this->points << endl;
		cout << "------------------------" << endl;
	}

	string GetSurmane() {
		return this->surname;
	}
	int GetMark() {
		return this->points;
	}
	int GetGroup() {
		return this->curse;
	}
	void SetSurname(string sur) {
		this->surname = sur;
	}

	~Student() {};
};



void SortByName(vector<Student>& students) {
	for (int j = 0; j < students.size() - 1; j++) {
		for (int i = 0; i < students.size() - 1; i++) {
			if (students[i].GetSurmane() > students[i + 1].GetSurmane()) {
				swap(students[i], students[i + 1]);
			};
		}
	}
}
vector<Student> GetGoodStudents(vector<Student>& students) {
	vector<Student> goodStudents;
	int count = 0;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].GetMark() > 76) {
			goodStudents.push_back(students[i]);
			count++;
		};
	}
	return goodStudents;
}

void ShowAll(vector<Student> magesine) {
	for (int i = 0; i < magesine.size(); i++) {
		magesine[i].Show();
	}
}

void WriteFile(vector<Student> magasine) {
	ofstream out;          // ïîòîê äëÿ çàïèñè
	out.open("stud.txt"); // îêðûâàåì ôàéë äëÿ çàïèñè
	if (out.is_open())
	{
		for (int i = 0; i < magasine.size(); i++) {
			out << magasine[i].GetSurmane() << endl;
			out << magasine[i].GetGroup() << endl;
			out << magasine[i].GetMark() << endl;
		}
	}
	out.close();
}

void ReadFile(vector<Student> magasine) {
	int point;
	int grop;
	string name;
	ifstream in("stud.txt"); // îêðûâàåì ôàéë äëÿ ÷òåíèÿ
	if (in.is_open())
	{
		while (in >> name >> grop >> point)
		{
			magasine.push_back(Student(name, grop, point));
		}
	}
	in.close();
}

int main() {
	bool exit = false;
	vector<Student> magesine;
	vector<Student> students;
	int choise;
	while (!exit) {
		cout << "1. Add student" << endl;
		cout << "2. Show student" << endl;
		cout << "3. Sort by name student" << endl;
		cout << "4. Find and show good student" << endl;
		cout << "5. Write in file" << endl;
		cout << "6. Read from file" << endl;
		cout << "0. Exit" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			magesine.push_back(Student());
			break;
		case 2:
			ShowAll(magesine);
			break;
		case 3:
			SortByName(magesine);
			break;
		case 4:
			students = GetGoodStudents(magesine);
			cout << "count good student " << students.size() << endl;
			ShowAll(students);
			break;
		case 5:
			WriteFile(magesine);
			break;
		case 6:
			ReadFile(magesine);
			break;
		case 0:
			exit = true;
			break;
		}

	}
	system("pause");
	return 0;
}