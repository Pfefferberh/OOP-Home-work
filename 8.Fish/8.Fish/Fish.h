#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

class Fish
{
	static char ocean[10][12];
	static int fish_count;
	int x;
	int y;
	int curse_x ;
	int curse_y ;
	int health; 
	int number_fish; 

	static int plancton_x[3];
	static int plancton_y[3];

	void Mind_random_fish();
	
	void Hunger_fish();
	void Problem_move_fish();


	static void Set_plancton(int x,int y);
	
public:
	Fish();
	static void Life_ocean();
	static void Show_ocean();
	static void Random_plancton();

	void Find_plancton(int x, int y);
	void Find_plancton();
	
	void Move_fish();

	int Get_x();
	int Get_y();
	int Get_health();
	int Get_number_fish();

	~Fish();
 };