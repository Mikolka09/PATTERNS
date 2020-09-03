#pragma once

#include<iostream>
#include<string>

using namespace std;

class Water;

class IWaterState
{
public:
	virtual void heat(Water* water) = 0;
	virtual void frost(Water* water) = 0;
};

class Water
{
	IWaterState* state;
public:
	Water(IWaterState* ws):state(ws){}
	void setState(IWaterState* ws)
	{
		if (state && state != ws)
		{
			delete state;
			state = ws;
		}
	}
	void heat()
	{
		state->heat(this);
	}
	void frost()
	{
		state->frost(this);
	}
};

class SolidWaterState :public IWaterState
{
public:
	void heat(Water* water) override;
	
	void frost(Water* water) override
	{
		cout << "Продолжаем замораживать лед" << endl;
	}
};

class LiquidWaterState : public IWaterState
{
public:
	void heat(Water* water) override;
	
	void frost(Water* water) override
	{
		cout << "Вода превращается в лед" << endl;
		water->setState(new SolidWaterState);
	}
};

class GasWaterState : public IWaterState
{
public:
	void heat(Water* water) override
	{
		cout << "Повышаем температуру пара" << endl;
	}
	void frost(Water* water) override
	{
		cout << "Пар конденсируется" << endl;
		water->setState(new LiquidWaterState);
	}
};

void SolidWaterState::heat(Water* water)
{
	cout << "Лед плавится" << endl;
	water->setState(new LiquidWaterState);
}

void LiquidWaterState::heat(Water* water)
{
	cout << "Вода превращается в пар" << endl;
	water->setState(new GasWaterState);
}

//Water* water = new Water(new SolidWaterState);
//water->heat();
//water->heat();
//water->heat();
//water->frost();
//water->frost();
//water->frost();
//delete water;


