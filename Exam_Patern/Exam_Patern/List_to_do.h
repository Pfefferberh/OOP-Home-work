#pragma once
#include "My_lib.h"
#include "Ivent.h"

class List_to_do
{
	string member;
	int j = 0;
protected: 
	List_to_do() { this->Create_ivent(); }
	vector <Ivent> list_ivent;
	static List_to_do* list_to_do;
public:
	List_to_do(List_to_do & other) = delete;
	void operator=(const List_to_do&) = delete;
	static List_to_do* GetInstance();

	void Create_ivent();
	void Delete_ivent();
	void Seach_data();
	void Seach_priorety();
	void Seach_teg();
	/*void Get_list();
	void Sending();*/
	class Mailling_list;
};
