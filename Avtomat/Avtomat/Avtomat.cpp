#include "Avtomat.h"

Avtomat::Avtomat()			{	}
void Avtomat::Set_magazin()	{	this->ready.Fill();	}
void Avtomat::Fire()		{	bullet fire= ready.Get_bullet();	fire.Fires();	ready.Set_count_bullet();	}
