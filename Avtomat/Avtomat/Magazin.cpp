#include "Magazin.h"

Magazin::Magazin()				{	this->steck = new bullet[this->size];	this->Fill();	}
Magazin::~Magazin()				{	steck = nullptr;	delete steck;						}
bullet Magazin::Get_bullet()	{	return this->steck[this->count_bullet];					}
void Magazin::Fill(){
	this-> random = rand() % 100;
	for (; this->count_bullet < this->size; this->count_bullet++) {	random++;	steck[this->count_bullet].Set_number(random);	}
	count_bullet--;
}
void Magazin::Set_count_bullet(){	this->count_bullet--;	}
