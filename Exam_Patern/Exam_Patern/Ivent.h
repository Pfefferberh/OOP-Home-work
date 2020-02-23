#pragma once
#include"My_lib.h"

class Ivent
{
	string text_ivent;
	string data;
	string priority="draft";
	string teg;
	bool done;
	int choise;
public: 
	Ivent();
	void Set_text_ivent(string text);
	void Set_data(string data);
	void Set_priority();
	void Set_teg();
	void Change_ivent();
	string Get_text_ivent();
	string Get_data();
	string Get_priory();
	string Get_teg();
	/*void Save_file();
	void Load_file();*/
};

