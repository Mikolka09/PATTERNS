#pragma once

#include<iostream>
#include<string>

using namespace std;

class Handler
{
protected:
	Handler* nextHandler;
public:
	Handler(){}
	Handler(Handler* hn):nextHandler(hn){}
	virtual void sendPayment(int sum) = 0;
	Handler* setHandler(Handler* nh) { nextHandler = nh; return nextHandler; }
};


class Client
{
	Handler* nextHandler;
public:
	Client(){}
	Client(Handler* nh) :nextHandler(nh) {}
	void sendPayment(int sum)
	{
		if (nextHandler)
			nextHandler->sendPayment(sum);
	}
	Handler* setHandler(Handler* nh) { nextHandler = nh; return nextHandler; }
};

class EconomistHandler :public Handler
{
	
public:
	EconomistHandler(){}
	EconomistHandler(Handler* nh) :Handler(nh) {}
	void sendPayment(int sum)
	{
		if (sum > 1000)
			nextHandler->sendPayment(sum);
		else
			cout << "Платеж проведен экономистом!" << endl;
	}

};


class BuhgalterHandler :public Handler
{
	
public:
	BuhgalterHandler(){}
	BuhgalterHandler(Handler* nh) :Handler(nh) {}
	void sendPayment(int sum)
	{
		if (sum > 5000)
			nextHandler->sendPayment(sum);
		else
			cout << "Платеж проведен бухгалтером!" << endl;
	}

};

class DirectorHandler :public Handler
{
	Handler* nextHandler;
public:
	DirectorHandler(){}
	DirectorHandler(Handler* nh) :Handler(nh) {}
	void sendPayment(int sum)
	{
		if (sum > 10000)
		{
			if (nextHandler)
				nextHandler->sendPayment(sum);
			else
				cout << "Нужен совет директоров, а у нас его нет!" << endl;
		}
		else
			cout << "Платеж проведен директором!" << endl;
	}

};


//Client* client = new Client(new EconomistHandler(new BuhgalterHandler(new DirectorHandler(nullptr))));
//Client* client = new Client;
//client->
//setHandler(new EconomistHandler)->
//setHandler(new BuhgalterHandler)->
//setHandler(new DirectorHandler);
//
//client->sendPayment(500);
