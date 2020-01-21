#pragma once
#include "bullet.h"
class Magazin
{
	const int size = 30;
	bullet* steck;
	int count_bullet=0;
	int random;
public:
	Magazin();
	~Magazin();
	bullet Get_bullet();
	void Fill();
	void Set_count_bullet();
};

