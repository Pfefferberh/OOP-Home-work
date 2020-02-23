#include "List_to_do.h"

List_to_do* List_to_do::GetInstance()
{
	if (list_to_do == nullptr) {
		list_to_do = new List_to_do();
	}
	return list_to_do;
}

void List_to_do::Create_ivent()
{
	this->list_ivent.push_back(Ivent());
}

void List_to_do::Delete_ivent()
{
	cout << " Delete ivent" << endl;
	cout << "Enter date : ";
	cin >> member;
	for (auto i = this->list_ivent.begin(); i != this->list_ivent.end(); ++i) {
		if (member == this->list_ivent[j].Get_data()) {
			cout << "FIND :  " << this->list_ivent[j].Get_data() << endl;
			this->list_ivent.erase(i);
		}
		j++;
	}

}


void List_to_do::Seach_data()
{
	cout << "          SEARCH of date ";
	cout << "Enter date : ";
	cin >> member;
	for (auto i = this->list_ivent.begin(); i != this->list_ivent.end(); ++i) {
		if (member== this->list_ivent[j].Get_data()) {
			cout << "FIND :  "<<this->list_ivent[j].Get_data() << endl;
			cout << "Text :  " << this->list_ivent[j].Get_text_ivent() << endl << endl;
		}
		j++;
	}
}

void List_to_do::Seach_priorety()
{
	cout << "          SEARCH of priority ";
	cout << "Enter priority Max or Midle or Min or draft : ";
	cin >> member;
	for (auto i = this->list_ivent.begin(); i != this->list_ivent.end(); ++i) {
		if (member == this->list_ivent[j].Get_priory()) {
			cout << "FIND :  " << this->list_ivent[j].Get_priory() << endl ;
			cout << "Text :  " << this->list_ivent[j].Get_text_ivent() << endl << endl;
		}
		j++;
	}
}

void List_to_do::Seach_teg()
{
	cout << "          SEARCH of teg ";
	cout << "Enter teg with # : ";
	cin >> member;
	for (auto i = this->list_ivent.begin(); i != this->list_ivent.end(); ++i) {
		if (member == this->list_ivent[j].Get_teg()) {
			cout << "FIND :  " << this->list_ivent[j].Get_teg() << endl;
			cout << "Text :  " << this->list_ivent[j].Get_text_ivent() << endl << endl;
		}
		j++;
	}
}
