#pragma once

#include<iostream>
#include<string>

using namespace std;

class Component
{
public:
	virtual string getName() = 0;
};

class Engine :public Component
{

};

class Transmission :public Component
{

};

class BodyType : public Component
{

};

class GasEngine :public Engine
{
public:
	string getName() override
	{
		return "Gas Engine";
	}
};

class DiselEngine :public Engine
{
public:
	string getName() override
	{
		return "Disel Engine";
	}
};

class ElectricEngine :public Engine
{
public:
	string getName() override
	{
		return "Electric Engine";
	}
};

class MechanicTransmission :public Transmission
{
public:
	string getName() override
	{
		return "Mechanic Transmission";
	}
};

class AutomaticTransmission :public Transmission
{
public:
	string getName() override
	{
		return "Automatic Transmission";
	}
};

class RobotTransmission :public Transmission
{
public:
	string getName() override
	{
		return "Robot Transmission";
	}
};

class SedanBodyType :public BodyType
{
public:
	string getName() override
	{
		return "Sedan BodyType";
	}
};

class UniversalBodyType : public BodyType
{
public:
	string getName() override
	{
		return "Universal BodyType";
	}
};

class CrossoverBodyType : public BodyType
{
public:
	string getName() override
	{
		return "Crossover BodyType";
	}
};

class BolidBodyType : public BodyType
{
public:
	string getName() override
	{
		return "Bolid BodyType";
	}
};

class Car
{
	Engine* engine = nullptr;
	Transmission* transmission = nullptr;
	BodyType* bodytype = nullptr;
public:
	Car() {}
	~Car()
	{
		if (engine)
			delete engine;
		if (transmission)
			delete transmission;
		if (bodytype)
			delete bodytype;
	}
	void setEngine(Engine* en) { engine = en; }
	void setTransmission(Transmission* tm) { transmission = tm; }
	void setBodyType(BodyType* bt) { bodytype = bt; }
	void print()
	{
		cout << "Engine: " << engine->getName() << endl;
		cout << "Transmission: " << transmission->getName() << endl;
		cout << "BodyType: " << bodytype->getName() << endl;
	}
};

class ICarFactory
{
public:
	virtual Engine* createEngine() = 0;
	virtual Transmission* createTransmission() = 0;
	virtual BodyType* createBodyType() = 0;
};

class SportCar :public ICarFactory
{
public:
	virtual Engine* createEngine() { return new GasEngine; }
	virtual Transmission* createTransmission() { return new RobotTransmission; }
	virtual BodyType* createBodyType() { return new BolidBodyType; }
};

class Telega :public ICarFactory
{
public:
	virtual Engine* createEngine() {  }
	virtual Transmission* createTransmission() {  }
	virtual BodyType* createBodyType() { return new BolidBodyType; }
};

class CarConfigurator
{
	ICarFactory* factory = nullptr;
public:
	~CarConfigurator() { delete factory; }
	CarConfigurator(ICarFactory* f) : factory(f){}
	void setConfiguration(ICarFactory* f) { factory = f; }
	void configurate(Car* car)
	{
		car->setEngine(factory->createEngine());
		car->setTransmission(factory->createTransmission());
		car->setBodyType(factory->createBodyType());
	}
};
