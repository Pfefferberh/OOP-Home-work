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
	cout << "			ADD IVENT" << endl;
	this->list_ivent.push_back(Ivent());
}

void List_to_do::Delete_ivent()
{
	j = 0;
	cout << "				DELETE IVENT" << endl;
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

bool List_to_do::Seach_text()
{
	j = 0;
	cout << "			 SEARCH of text " << endl;
	cout << "Enter text : ";
	cin >> member;
	for (auto i = this->list_ivent.begin(); i != this->list_ivent.end(); ++i) {
		if (member == this->list_ivent[j].Get_text_ivent()) {
			cout << "FIND :  " << this->list_ivent[j].Get_text_ivent() << endl;
			return true;
		}
		j++;
	}
	return false;
}


void List_to_do::Seach_data()
{
	j = 0;
	cout << "			 SEARCH of date " << endl;
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
	j = 0;
	cout << "			 SEARCH of priority " << endl;
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
	j = 0;
	cout << "			 SEARCH of teg " << endl;
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

void List_to_do::Save_list()
{
	j = 0;
	for (auto i = this->list_ivent.begin(); i != this->list_ivent.end(); ++i) {
		this->list_ivent[j].Save_file();
		j++;
	}
	cout << "			 SAVED " << endl;
}

void List_to_do::Load_list()
{
	this->list_ivent.clear();
	Ivent memb;
	string temp;
	ifstream myfile_two("Save.txt");

	if (myfile_two.is_open())
	{
		while (myfile_two) {
			getline(myfile_two, temp);
			memb.Set_text_ivent(temp);
			getline(myfile_two, temp);
			memb.Set_data(temp);
			getline(myfile_two, temp);
			memb.Set_priority(temp);
			getline(myfile_two, temp);
			memb.Set_teg(temp);
			this->list_ivent.push_back(memb);
		}
		this->list_ivent.pop_back();
	}

	else cout << "Unable to open file" << endl;
	myfile_two.close();
	cout << "			  LOADED " << endl;
}

void List_to_do::Sending()
{
	Mailling_list* to_somebody = new Mailling_list_send();
	Mailling_list* facebook = new Facebook(to_somebody);
	Mailling_list* telegram = new Telegram(facebook);
	cout << "			 MAILLING LISTS " << endl;
		cout << "Choise whom sending : " << endl;
		cout << "1 - to somebody " << endl;
		cout << "2 - to somebody & facebook " << endl;
		cout << "3 - to somebody & facebook & telegram " << endl;
		cin >> j;
		switch (j)
		{
		case 1:
			mailing_list(to_somebody);
			break;
		case 2:
			mailing_list(facebook);
			break;
		case 3:
			mailing_list(telegram);
			break;
		default:
			break;
		}
	
	delete to_somebody;
	delete facebook;
	delete telegram;
}

void List_to_do::Show_all()
{
	j = 0;
	cout << "		    Show all ivent " << endl;
	for (auto i = this->list_ivent.begin(); i != this->list_ivent.end(); ++i) {
		cout << "          " << j + 1 << endl;
		this->list_ivent[j].Show();
		j++;
	}
}

void List_to_do::Editing()
{
	this->Show_all();
	cout << "Enter number the ivent : ";
	cin >> j;
	j--;
	if (j < this->list_ivent.size()) {	
		this->list_ivent[j].Change_ivent();
	}
	else {
		cout << "Ivent not to be  " << endl;
	}
}

void List_to_do::mailing_list(Mailling_list* component)
{
 component->Send_list();
}

void  Mailling_list_send:: Send_list() const
{
	cout << "Send to somebody " << endl;
}

void Facebook::Send_list() const
{
	this->list_->Send_list();
	cout << "Send to Facebook" << endl;
}

void Telegram::Send_list() const
{
	this->list_->Send_list();
	cout << "Send to Telegram" << endl;
}
