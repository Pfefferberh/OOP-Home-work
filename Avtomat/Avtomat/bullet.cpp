#include "bullet.h"

bullet::bullet()					{	this->number = 0;		}
void bullet::Set_number(int number)	{	this->number = number;	}
int bullet::Get_number()			{	return this->number;	}
void bullet::Fires()
{
	if (rand() % 100 < 70) {	cout << "bullet number " << this->Get_number() << " have to coal " << endl;	}
	else {	cout << "bullet number " << this->Get_number() << " have not to coal " << endl;	}
}
