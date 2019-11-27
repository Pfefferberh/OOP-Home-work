#include "Train.h"
Train::Train()
{
}
Train::Train(string route, int distance, int size)
{
	this->size = size;
	this->route = route;
	this->distance = distance;
	this->car = new Car[size];
	for (int i = 0; i < size; i++) {
		car[i].Fill_car();
	}
}
void Train::ShowTrain()
{
	cout << "Route: " << this->route << "\nDistance: " << this->distance << endl;
	for (int i = 0; i < size; i++) {
		cout << "-----------------" << this->route << "---------------" << endl;
		this->car[i].ShowCar();
		cout << "----------------------------------------" << endl;
	}
}
Train::~Train()
{
	car = nullptr;
	delete[]car;
}