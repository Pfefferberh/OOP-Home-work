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

public:
	Fish();
	static void Life_ocean();
	static void Show_ocean();
	int Get_x();
	int Get_y();
	static void Move_fish(int x, int y);


	~Fish();
};