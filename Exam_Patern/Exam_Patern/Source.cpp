#include"List_to_do.h"
#include"My_lib.h"
List_to_do* List_to_do::list_to_do = nullptr;
int main() {
	List_to_do *one= List_to_do::GetInstance();
	//one->Create_ivent();
	//one->Seach_data();
	//one->Sending();
	//one->Save_list();
	one->Load_list();
	one->Show_all();
	delete one;
	return 0;
}