#pragma once

#include<iostream>
#include<string>
#include<Windows.h>
#include<vector>


using namespace std;

class Collegue;

class Mediator
{
public:
	virtual void send(string message, Collegue* collegue) = 0;
};

class Collegue
{
protected:
	Mediator* mediator;
public:
	Collegue(Mediator* mediator):mediator(mediator){}
	virtual void send(string message)
	{
		mediator->send(message, this);
	}

	virtual void notify(string message) = 0;
};

class SellerCollegue : public Collegue
{
public:
	SellerCollegue(Mediator* mediator):Collegue(mediator){}
	void notify(string message) override
	{
		cout << "Сообщение продавцу: " << message << endl;
	}
};

class ProgrammerCollegue : public Collegue
{
public:
	ProgrammerCollegue(Mediator* mediator) : Collegue(mediator) {}
	void notify(string message) override
	{
		cout << "Сообщение программисту: : " << message << endl;
	}
};

class TesterCollegue : public Collegue
{
public:
	TesterCollegue(Mediator* mediator) : Collegue(mediator) {}
	void notify(string message) override
	{
		cout << "Сообщение тестировщику: : " << message << endl;
	}
};

class ManagerMediator : public Mediator
{
public:
	Collegue* seller;
	Collegue* programmer;
	Collegue* tester;
	void send(string message, Collegue* collegue) override
	{
		if (collegue == seller)
			programmer->notify(message);
		else if (collegue == programmer)
			tester->notify(message);
		else if (collegue == tester)
			seller->notify(message);
	}
};


//ManagerMediator* manager = new ManagerMediator;
//Collegue* seller = new SellerCollegue(manager);
//Collegue* programmer = new ProgrammerCollegue(manager);
//Collegue* tester = new TesterCollegue(manager);
//
//manager->seller = seller;
//manager->programmer = programmer;
//manager->tester = tester;
//
//seller->send("Есть заказ, нужно сделать программу!");
//programmer->send("Программа готова, можно тестить!");
//tester->send("Программа протестирована, можно продавать!");