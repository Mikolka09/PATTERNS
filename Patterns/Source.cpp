#include<iostream>
#include<string>
#include"FactoryMethod.h"
#include"AbstractFactory.h"

using namespace std;

int main()
{
	setlocale(0, "");

	Car* car = new Car;
	CarConfigurator* config = new CarConfigurator(new SportCar);
	//config->setConfiguration(new SportCar);
	config->configurate(car);

	car->print();


	

	system("pause");
}