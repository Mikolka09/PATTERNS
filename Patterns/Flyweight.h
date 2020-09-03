#pragma once

#include<iostream>
#include<string>
#include<list>
#include<map>

using namespace std;

class House
{
protected:
	int floor;
public:
	virtual void built(float sh, float d) = 0;
};

class PanelHouse : public House
{
public:
	PanelHouse() { floor = 9; }
	void built(float sh, float d) override
	{
		cout << "ѕостроен панельный дом из " << floor << " этажей, с координатами "
			<< sh << "* широты и " << d << "* долготы" << endl;
	}
};

class BrickHouse : public House
{
public:
	BrickHouse() { floor = 5; }
	void built(float sh, float d) override
	{
		cout << "ѕостроен кирпичный дом из " << floor << " этажей, с координатами "
			<< sh << "* широты и " << d << "* долготы" << endl;
	}
};

class HouseFactory
{
	map<string, House*> houses;
public:
	HouseFactory()
	{
		houses["Panel"] = new PanelHouse;
		houses["Brick"] = new BrickHouse;
	}

	House* getHouse(string key)
	{
		if (houses.count(key))
			return houses[key];
		else
			return nullptr;
	}
};


//float sh = 30.3, d = 29.4;
//
//HouseFactory* houseFactory = new HouseFactory;
//
//for (size_t i = 0; i < 10; i++)
//{
//	House* panelHouse = houseFactory->getHouse("Panel");
//	if (panelHouse != nullptr)
//		panelHouse->built(sh, d);
//	sh += 0.3;
//	d += 0.2;
//}
//cout << endl;
//for (size_t i = 0; i < 10; i++)
//{
//	House* brickHouse = houseFactory->getHouse("Brick");
//	if (brickHouse != nullptr)
//		brickHouse->built(sh, d);
//	sh += 0.2;
//	d += 0.4;
//}