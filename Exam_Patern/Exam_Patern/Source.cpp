#include"List_to_do.h"
#include"My_lib.h"
List_to_do* List_to_do::list_to_do = nullptr;
int main() {
	List_to_do *one= List_to_do::GetInstance();
	one->Create_ivent();
	one->Seach_data();


	return 0;
}