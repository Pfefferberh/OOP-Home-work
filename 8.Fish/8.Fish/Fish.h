#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Fish
{
	static char ocean[10][12];
	static int fish_count;
	int x;
	int y;
	int health; 
	int number_fish; 

	void Mind_fish();
	void Problem_move_fish();
public:
	Fish();
	static void Life_ocean();
	static void Show_ocean();
	
	void Move_fish(int x, int y);
	

	int Get_x();
	int Get_y();
	int Get_health();
	int Get_number_fish();

	~Fish();
};