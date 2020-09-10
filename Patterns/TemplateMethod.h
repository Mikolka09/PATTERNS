#pragma once
#include<iostream>
#include<string>


using namespace std;

class HouseBuilder
{
protected:
	virtual void buildWall() = 0;
	virtual void buildDoor() = 0;
	virtual void buildWindows(int count) = 0;
	virtual void hookBuildLift() = 0;
	virtual void buildRoof() = 0;
public:
	void buildHouse(int wind)
	{
		buildWall();
		buildDoor();
		buildWindows(wind);
		hookBuildLift();
		buildRoof();
	}
	virtual string getHouse() { return ""; }
};

class StandartHouse: public HouseBuilder
{
	string house = "";
public:
	void buildWall()
	{
		house += "Глинянные стены\n";
	}
	void buildDoor()
	{
		house += "Деревянные двери\n";
	}
	void buildWindows(int count)
	{
		house += "Обычные окна - ";
		char buff[10];
		_itoa(count, buff, 10);
		house += buff;
		house += "\n";
	}
	void hookBuildLift()
	{

	}
	void buildRoof()
	{
		house += "Соломенная крыша\n";
	}
	string getHouse() { return house; }
};

class SuperHouse : public HouseBuilder
{
	string house = "";
public:
	void buildWall()
	{
		house += "Каменные стены\n";
	}
	void buildDoor()
	{
		house += "Гаражные ворота\n";
	}
	void buildWindows(int count)
	{
		house += "Пластиковые окна - ";
		char buff[10];
		_itoa(count, buff, 10);
		house += buff;
		house += "\n";
	}
	void hookBuildLift()
	{
		house += "Лист на 10-ть человек\n";
	}
	void buildRoof()
	{
		house += "Оцинкованная крыша\n";
	}
	string getHouse() { return house; }
};

//HouseBuilder* stHouse = new StandartHouse;
//stHouse->buildHouse(4);
//cout << stHouse->getHouse() << endl;
//
//HouseBuilder* stHouse2 = new SuperHouse;
//stHouse2->buildHouse(28);
//cout << stHouse2->getHouse() << endl;


