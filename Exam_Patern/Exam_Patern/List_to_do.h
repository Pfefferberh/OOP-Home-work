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
	void Save_list();
	void Load_list();
	void Sending();
	void Show_all();
	
	 class Mailling_list {
	public:
		virtual ~Mailling_list() {}
		virtual void Send_list()const = 0;
	};
	void mailing_list(Mailling_list* component);
	
};

class Mailling_list_send :public List_to_do::Mailling_list 
{
protected:
	Mailling_list* list_;
public:
	Mailling_list_send() {};
	Mailling_list_send(Mailling_list* list) : list_(list) {};
	void Send_list()const override;
};

class Facebook :public Mailling_list_send {
public:
	Facebook() {};
	Facebook(Mailling_list* list) : Mailling_list_send(list) {};
		void Send_list()const  override;
};

class Telegram :public Mailling_list_send {
public:
	Telegram() {};
	Telegram(Mailling_list* list) : Mailling_list_send(list) {};
	void Send_list()const  override;
};