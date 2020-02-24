#include"List_to_do.h"
#include"My_lib.h"
List_to_do* List_to_do::list_to_do = nullptr;

void menu(List_to_do* one) {
	int choise = 45;
	int choise_two;
	int choise_three;
	for (; choise != 0;) {
		system("cls");
		cout << "Choise function : " << endl;
		cout << "1 - Create " << endl;
		cout << "2 - Editing " << endl;
		cout << "3 - Show " << endl;
		cout << "4 - Seach " << endl;
		cout << "5 - Work with file " << endl;
		cout << "6 - Send " << endl;
		cout << "0 - exit " << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			one->Create_ivent();
			system("pause");
			break;
		case 2:
			one->Editing();
			system("pause");
			break;
		case 3:
			one->Show_all();
			system("pause");
			break;
		case 4:
			cout << "Choise how seach : " << endl;
			cout << "1 - text " << endl;
			cout << "2 - date " << endl;
			cout << "3 - priority " << endl;
			cout << "4 - teg " << endl;
			cin >> choise_two;
			switch (choise_two)
			{
			case 1:
				one->Seach_text();
				break;
			case 2:
				one->Seach_data();
				break;
			case 3:
				one->Seach_priorety();
				break;
			case 4:
				one->Seach_teg();
				break;
			default:
				break;
			}
			system("pause");
			break;
		case 5:
			cout << "Enter : " << endl;
			cout << "1 - save " << endl;
			cout << "2 - load " << endl;
			cin >> choise_three;
			switch (choise_three)
			{
			case 1:
				one->Save_list();
				break;
			case 2:
				one->Load_list();
				break;
			default:
				break;
			}
			system("pause");
			break;
		case 6:
			one->Sending();
			system("pause");
			break;
		case 0:
			choise = 0;
			break;
		default:
			break;
		}
	}
	delete one;
}

int main() {
	List_to_do *one= List_to_do::GetInstance();
	menu(one);

	return 0;
}