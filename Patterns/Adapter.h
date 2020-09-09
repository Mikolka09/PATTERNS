#pragma once

#include<iostream>
#include<string>

using namespace std;

namespace Adapter
{
	//Target
	class ITransport
	{
	public:
		virtual void drive() = 0;
	};

	class Car:public ITransport
	{
	public:
		void drive()
		{
			cout << "Машина едет" << endl;
		}

	};

	//Client
	class Driver
	{
	public:
		void travel(ITransport* transport)
		{
			transport->drive();
		}
	};

	//Adaptee
	class Camel
	{
	public:
		void move()
		{
			cout << "Верблюд идет по пустыне" << endl;
		}
	};

	class Ship
	{
	public:
		void swimm()
		{
			cout << "Корабыль плывет" << endl;
		}
	};

	//Adapter
	class CamelToTransport : public ITransport
	{
		Camel* camel;
	public:
		CamelToTransport(Camel* c):camel(c){}
		void drive()override
		{
			camel->move();
		}

		
	};

	//Adapter
	class ShipToTransport : public ITransport
	{
		Ship* ship;
	public:
		ShipToTransport(Ship* s) :ship(s) {}
		void drive()override
		{
			ship->swimm();
		}

	};


}


//Adapter::Car* car = new Adapter::Car;
//Adapter::Driver* driver = new Adapter::Driver;
//driver->travel(car);
//cout << endl;
//Adapter::Camel*camel = new Adapter::Camel;
//Adapter::ITransport* camelTransport = new Adapter::CamelToTransport(camel);
//driver->travel(camelTransport);
//cout << endl;
//Adapter::Ship*ship = new Adapter::Ship;
//Adapter::ITransport*shipTransport = new Adapter::ShipToTransport(ship);
//driver->travel(shipTransport);