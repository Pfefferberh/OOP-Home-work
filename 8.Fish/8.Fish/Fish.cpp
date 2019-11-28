#include "Fish.h"

void Fish::Mind_fish()
{
	bool curse_x = rand() % 1;
	bool curse_y = rand() % 2;
	if (curse_x == true) {
		this->x++;
	}
	else {
		this->x--;
	}
	if (curse_y == true) {
		this->y++;
	}
	else {
		this->y--;
	}
}

void Fish::Problem_move_fish()
{
	if (this->x < 0) {
		this->x += 2;
	}
	else if (this->x > 9) {
		this->x -= 2;
	}
	if (this->y < 0) {
		this->y += 2;
	}
	else if (this->y > 9) {
		this->y -= 2;
	}
}

Fish::Fish()
{
	this->x = rand() % 9;
	this->y = rand() % 11;
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
	cout << endl << endl << endl << endl;
	for (int i = 0; i < 10; i++) {
		cout << "		";
		for (int j = 0; j < 12; j++) {
			cout << ocean[i][j] << "  ";
		}
		cout << endl;
	}
}

int Fish::Get_x()
{
	return this->x;
}

int Fish::Get_y()
{
	return this->y;
}

void Fish::Move_fish(int x,int y)
{
	this->Mind_fish();
	this->Problem_move_fish();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			if (i == x && y == j) {
				ocean[i][j] = '<';
			}
		}
	}
}



Fish::~Fish()
{
}