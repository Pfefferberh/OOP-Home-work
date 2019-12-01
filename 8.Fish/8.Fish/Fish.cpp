#include "Fish.h"

void Fish::Mind_random_fish()
{
	bool cur_x = rand() % 2;
	bool cur_y = rand() % 2;
	if (cur_x == true) {
		this->x++;
	}
	else {
		this->x--;
	}
	if (cur_y == true) {
		this->y++;
	}
	else {
		this->y--;
	}
}

void Fish::Hunger_fish()
{
		if (this->x < this->curse_x && this->y== this->curse_y ) {
			this->x++;
		}
		else if (this->x < this->curse_x && this->y < this->curse_y ) {
			this->x++;
			this->y++;
			
		}
		else if (this->y < this->curse_y && this->x == this->curse_x ) {
			this->y++;
		
		}
		else if (this->x < this->curse_x && this->y > this->curse_y ) {
			this->x++;
			this->y--;
			
		}
		else if (this->x > this->curse_x&& this->y == this->curse_y ) {
			this->x--;
			
		}
		else if (this->x > this->curse_x&& this->y > this->curse_y ) {
			this->x--;
			this->y--;
			
		}
		else if (this->y > this->curse_y&& this->x == this->curse_x ) {
			this->y--;

		}
		else if (this->x > this->curse_x&& this->y < this->curse_y ) {
			this->x--;
			this->y++;
			
		}
}

void Fish::Find_plancton(int x, int y)
{
	int memb_x=0;
	int memb_y=0;
	int memb=0;
	int min=10000;

	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_x; j++) {
			if (ocean[i][j] == "* ") {
				memb_x = x - i;
				memb_y = y - j;
				memb_x *= memb_x;
				memb_y *= memb_y;
				memb = memb_x + memb_y;
				if (memb<min ) {
					min = memb;
					this->curse_x = i;
					this->curse_y = j;
				}
			}

		}
	}
}
void Fish::Problem_move_fish()
{
	if (this->x < 0) {
		this->x += 2;
	}
	else if (this->x >= size_x) {
		this->x -= 2;
	}
	if (this->y < 0) {
		this->y += 2;
	}
	else if (this->y >= size_y) {
		this->y -= 2;
	}
}

void Fish::Random_plancton()
{
	for (int i = 0; i < 3; i++) {
		plancton_x[i]= rand() % (size_x-2)+1;
		plancton_y[i]= rand() % (size_y-2)+1;
	}
}

void Fish::Set_size(int x, int y)
{
	size_x = x;
	size_y = y;
}

void Fish::Set_plancton(int x, int y)
{
	plancton_x[x] = rand() % (size_x-2);
	plancton_y[y] = rand() % (size_y-2);
}


Fish::Fish()
{
	this->x = rand() % size_x;
	this->y = rand() % size_y;
	this->curse_x = this->x;
	this->curse_y = this->y;
	this->health = 10;
	fish_count++;
	this->number_fish = fish_count;
	
}

void Fish::Create_ocean()
{
	ocean = new string *[size_x];
	for (int i = 0; i < size_x; i++) {
		ocean[i] = new string[size_y];
	}
}

void Fish::Delete_ocean()
{
	for (int i = 0; i < size_x; i++) {
		delete[]ocean[i];
	}
	delete[]ocean;
	ocean = nullptr;
}

void Fish::Life_ocean()
{
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
//			for (int g = 0; g < 3; g++) {
				if (i == plancton_x[0] && j == plancton_y[0]) {
					if (ocean[i][j] != fish_sumbol) {
						ocean[i][j] = "* ";
					}
					else if (ocean[i][j] == fish_sumbol) {
						Set_plancton(0,0);
						ocean[i][j] = ". ";
					}
				}
				else if (i == plancton_x[1] && j == plancton_y[1]) {
					if (ocean[i][j] != fish_sumbol) {
						ocean[i][j] = "* ";
					}
					else if (ocean[i][j] == fish_sumbol) {
						Set_plancton(1, 1);
						ocean[i][j] = ". ";
					}
				}
				else if (i == plancton_x[2] && j == plancton_y[2]) {
					if (ocean[i][j] != fish_sumbol) {
						ocean[i][j] = "* ";
					}
					else if (ocean[i][j] == fish_sumbol) {
						Set_plancton(2, 2);
						ocean[i][j] = ". ";
					}
				}
				else {
					ocean[i][j] = "  ";
				}
//			}
		}
	}

}

void Fish::Show_ocean()
{
	cout <<fish_count<< endl << endl << endl << endl;
	for (int i = 0; i < size_x; i++) {
		cout << "		";
		for (int j = 0; j < size_y; j++) {
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

int Fish::Get_health()
{
	if (this->health>0) {
		return this->health;
	}
	if (this->health<0) {
		return 0 ;
	}
}

int Fish::Get_number_fish()
{
	return this->number_fish;
}

void Fish::Move_fish()
{
	this->Find_plancton(Get_x(), Get_y());
	if (this->health > 0) {
		this->Hunger_fish();
		this->Problem_move_fish();
		if (ocean[this->x][this->y] != "* " ) {
			ocean[this->x][this->y] = fish_sumbol;
		}
		if (ocean[this->x][this->y] ==  "* " && ocean[this->x][this->y] != fish_sumbol) {
			ocean[this->x][this->y] = fish_sumbol;
			this->health += 10;
			if (this->health <= 10) {
				this->Find_plancton(Get_x(), Get_y());
			}
			else {
				this->Mind_random_fish();
			}
		}
		else  {
				this->Find_plancton(Get_x(), Get_y());
		}
	}
	if (this->health <= 0) {
		ocean[this->x][this->y] = "+ ";
	}
	this->health--;
}



Fish::~Fish()
{
}