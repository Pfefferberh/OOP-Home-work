#include "Ivent.h"

Ivent::Ivent()
{

	this->Change_ivent();
}

void Ivent::Set_text_ivent(string text)
{
	this->text_ivent = text;
}

void Ivent::Set_data(string data)
{
	this->data = data;
}

void Ivent::Set_priority()
{
	cout << "Enter priority :"<<endl;
	cout << "1 - Max ; "<<endl;
	cout << "2 - Midle ; "<<endl;
	cout << "3 - Min ; "<<endl;
	cin >> choise;
	switch (choise)
	{
		case 1:
			this->priority = "Max";
				break;
		case 2:
			this->priority = "Midle";
				break;
		case 3:
			this->priority = "Min";
				break;
	default:
		this->priority = "draft";
		cout << "Priority is draft " << endl;
		break;
	}
}

void Ivent::Set_priority(string priority)
{
	this->priority = priority;
}


void Ivent::Set_teg()
{
	cout << "Enter teg with # : ";
	cin >> this->teg;
}

void Ivent::Set_teg(string teg)
{
	this->teg = teg;
}

void Ivent::Change_ivent()
{
	choise = 45;
	string texts;
	for (; choise!=0;) {
		cout << "Choise create or change : " << endl;
		cout << "1 - text ivent " << endl;
		cout << "2 - date " << endl;
		cout << "3 - priority " << endl;
		cout << "4 - teg " << endl;
		cout << "0 - exit " << endl;
		cin >> choise;
		switch (choise)
		{
			case 1:
				cout << "Enter text: ";
				cin >> texts;
				this->Set_text_ivent(texts);
					break;
			case 2:
				cout << "Enter date: ";
				cin >> texts;
				this->Set_data(texts);
					break;
			case 3:
				this->Set_priority();
					break;
			case 4:
				this->Set_teg();
					break;
			case 0:
				choise = 0;
					break;
		default:
			break;
		}
	}
}

string Ivent::Get_text_ivent()
{
	return this->text_ivent;
}

string Ivent::Get_data()
{
	return this->data;
}

string Ivent::Get_priory()
{
	return this->priority;
}

string Ivent::Get_teg()
{
	return this->teg;
}

void Ivent::Save_file()
{
	ofstream myfile_two("Save.txt",ios::app);
	if (myfile_two.is_open())
	{
		myfile_two << this->Get_text_ivent()<<endl;
		myfile_two << this->Get_data() << endl;
		myfile_two << this->Get_priory() << endl;
		myfile_two << this->Get_teg() << endl;
	}
	else cout << "Unable to open file";
	myfile_two.close();
}

//void Ivent::Load_file()
//{
//	string temp;
//	ifstream myfile_two("Save.txt");
//	if (myfile_two.is_open())
//	{
//		getline(myfile_two,temp);
//		this->Set_text_ivent(temp);
//		getline(myfile_two, temp);
//		this->Set_data(temp);
//		getline(myfile_two, this->priority);
//		getline(myfile_two, this->teg);
//	}
//	else cout << "Unable to open file";
//	myfile_two.close();
//}

void Ivent::Show()
{
	cout<< this->Get_text_ivent() << endl;
	cout<< this->Get_data() << endl;
	cout<< this->Get_priory() << endl;
	cout<< this->Get_teg() << endl;
}

