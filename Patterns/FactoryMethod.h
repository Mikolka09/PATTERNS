#pragma once
#include<iostream>
#include<string>

using namespace std;


//Product
class Transport
{
public:
	virtual ~Transport(){}
	virtual void delivery(string adress) = 0;
	virtual string getName() = 0;

};

//Concret Product
class Track :public Transport
{
public:
	void delivery(string adress)override
	{
		cout << "Груз доставлен по адресу " << adress << endl;
	}
	string getName()
	{
		return "Использован грузовик, ";
	}
};

class Ship :public Transport
{
public:
	void delivery(string adress)override
	{
		cout << "Груз доставлен по адресу " << adress << endl;
	}
	string getName()
	{
		return "Использован корабль, ";
	}
};

class Plan :public Transport
{
public:
	void delivery(string adress)override
	{
		cout << "Груз доставлен по адресу " << adress << endl;
	}
	string getName()
	{
		return "Использован самолет, ";
	}
};

class Creator
{
public:
	virtual ~Creator() {}
	virtual Transport* createTransport() = 0;
	Transport* create()
	{
		Transport* transport = this->createTransport();
		return transport;
	}
};

class TrackCreator : public Creator
{
public:
	Transport* createTransport() override
	{
		return new Track;
	}
};

class ShipCreator : public Creator
{
public:
	Transport* createTransport() override
	{
		return new Ship;
	}
};

class PlanCreator : public Creator
{
public:
	Transport* createTransport() override
	{
		return new Plan;
	}
};



/*Creator* creator = new TrackCreator;
Transport* track = creator->create();
cout << track->getName();
track->delivery("in Nikolaev");

creator = new ShipCreator;
Transport* ship = creator->create();
cout << ship->getName();
ship->delivery("in Kiev");*/


/*Creator* creator;
Transport* transport;
int n;
cout << "1-Track, 2 Ship, 3-Plan: ";
cin >> n;
switch (n)
{
case 2:
creator = new ShipCreator;
break;
case 3:
creator = new PlanCreator;
break;
default:
creator = new TrackCreator;
break;
}
transport = creator->create();
cout << transport->getName();
transport->delivery("in Kiev");*/
