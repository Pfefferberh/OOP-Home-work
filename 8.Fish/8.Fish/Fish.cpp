#include "Fish.h"


Fish::Fish()
{
}

void Fish::Life_ocean()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			ocean[i][j] = '`';
		}
	}
}

void Fish::Show_ocean()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			cout << ocean[i][j] << "  ";
		}
		cout << endl;
	}
}

int Fish::Get_x()
{
	x = rand() % 9 ;
	return x;
}

int Fish::Get_y()
{
	y = rand() % 10 + 1;
	return y;
}

void Fish::Move_fish(int x,int y)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			//ocean[i][j] = '~';
			if (i == x && y == j) {
				ocean[i][j] = '<';
			}
		}
	}
}

Fish::~Fish()
{
}