#pragma once

#include<iostream>
#include<string>
#include<Windows.h>
#include<vector>


using namespace std;

class Strategy
{
public:
	virtual float move(int len) = 0;
};

class OnFootStrategy : public Strategy
{
	int speed = 3;
public:
	float move(int len) override
	{
		cout << "Выбор пешком" << endl;
		return (float)len / speed;
	}
};

class OnBusStrategy : public Strategy
{
	int speed = 40;
public:
	float move(int len) override
	{
		cout << "Выбор автобус" << endl;
		return (float)len / speed;
	}
};

class OnAutoStrategy : public Strategy
{
	int speed = 60;
public:
	float move(int len) override
	{
		cout << "Выбор авто" << endl;
		return (float)len / speed;
	}
};

class Navigator
{
	Strategy* strategy;
public:
	void setStrategy(Strategy* strategy)
	{
		this->strategy = strategy;
	}
	void getTime(int len)
	{
		float t = strategy->move(len);
		cout << "Расчетно время - " << t << " ч " << endl;
	}
};

//Navigator* navi = new Navigator;
//Strategy* strategy = nullptr;
//int len, n;
//cout << "Введите растояние: ";
//cin >> len;
//cout << "Вариант поездки: 1-Пешком, 2-На автобусе, 3-На авто" << endl;
//cin >> n;
//switch (n)
//{
//case 1:
//	strategy = new OnFootStrategy;
//	break;
//case 2:
//	strategy = new OnBusStrategy;
//	break;
//case 3:
//	strategy = new OnAutoStrategy;
//	break;
//default:
//	break;
//}
//
//navi->setStrategy(strategy);
//navi->getTime(len);

