#pragma once
#include <iostream>
#include <string>

using namespace std;
class Train
{
public:
	Train();
	Train(string route, int distance, int size);
	void ShowTrain();
	~Train();
private:
	class Car {
	private:
		string type;
		int passengers;
	public:
		Car() {
		}
		void Fill_car() {
			cout << "Type car: ";
			cin >> this->type;
			cout << "How many passengers: ";
			cin >> this->passengers;
		}
		void ShowCar() {
			cout << "Car - " << this->type << " : " << endl;
			cout << "	Type: " << this->type << endl;
			cout << "	Passengers: " << this->passengers << endl;
		}
	};
	string route;
	int distance;
	int size;
	Car* car;
};
