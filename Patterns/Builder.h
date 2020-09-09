#pragma once

#include<iostream>
#include<string>
#include <vector>

using namespace std;


class MCComponent
{
public:
	virtual string toString() const = 0;

};

class Radio : public MCComponent
{
public:
	string toString() const override
	{
		return "Radio";
	}
};

class CD : public MCComponent
{
public:
	string toString() const override
	{
		return "CD";
	}
};

class BlueRay : public MCComponent
{
public:
	string toString() const override
	{
		return "BlueRay";
	}
};

class Subwoofer : public MCComponent
{
public:
	string toString() const override
	{
		return "Subwoofer";
	}
};

class MusicCenter
{
public:
	vector<MCComponent*> parts;
	void print()
	{
		cout << "Music Center Parts" << endl;
		for (int i = 0; i < parts.size(); i++)
		{
			cout << parts[i]->toString() << endl;
		}
		cout << endl;
	}
};

class Manual
{
	int i = 1;
	string text = "MANUAL for MUSIC CENTER\n";
public:
	void addText(string text)
	{
		char buff[10];
		this-> text += _itoa(i++, buff, 10);
		this->text += ". ";
		this->text += text;
	}
	string getText() { return text; }

};

class Builder
{
public:
	virtual ~Builder(){}
	virtual void createRadio() const = 0;
	virtual void createCD() const = 0;
	virtual void createBR() const = 0;
	virtual void createSW() const = 0;
};

class MusicCenterBuilder : public Builder
{
	MusicCenter* mc;
public:
	MusicCenterBuilder()
	{
		reset();
	}

	void reset()
	{
		if (mc)
			delete mc;
		mc = new MusicCenter();
	}

	void createRadio() const override
	{
		mc->parts.push_back(new Radio);
	}
	void createCD() const override
	{
		mc->parts.push_back(new CD);
	}
	void createBR() const override
	{
		mc->parts.push_back(new BlueRay);
	}
	void createSW() const override
	{
		mc->parts.push_back(new Subwoofer);
	}

	MusicCenter* getResult()
	{
		MusicCenter* result = mc;
		mc = nullptr;
		return result;
	}
};

class ManualBuilder: public Builder
{
	Manual* manual;
public:
	ManualBuilder()
	{
		reset();
	}
	void reset()
	{
		if (manual)
			delete manual;
		manual = new Manual();
	}

	void createRadio() const override
	{
		manual->addText("Для включения радио нажмите 2\n");
	}
	void createCD() const override
	{
		manual->addText("Для включения СД нажмите 4, затем 6\n");
	}
	void createBR() const override
	{
		manual->addText("Для включения БР нажмите 5, подержите и отпустите\n");
	}
	void createSW() const override
	{
		manual->addText("Для включения СВ нажмите 8\n");
	}

	Manual* getResult()
	{
		Manual* result = manual;
		manual = nullptr;
		return result;
	}
};

class Director
{
	Builder* builder;
public:
	void setBuilder(Builder* builder)
	{
		this->builder = builder;
	}

	void BuildMaxiMC()
	{
		builder->createRadio();
		builder->createCD();
		builder->createSW();
		builder->createBR();
	}

	void BuildMiniMC()
	{
		builder->createRadio();
		builder->createCD();
	}
};



//Director* director = new Director();
//MusicCenterBuilder* builderMC = new MusicCenterBuilder;
//director->setBuilder(builderMC);
//director->BuildMaxiMC();
//
///*builderMC->createRadio();
//builderMC->createBR();
//builderMC->createSW();
//builderMC->createSW();*/
//
//MusicCenter* mc = builderMC->getResult();
//mc->print();
//
//ManualBuilder* builderManual = new ManualBuilder;
//director->setBuilder(builderManual);
//director->BuildMaxiMC();
//
//Manual* manual = builderManual->getResult();
//cout << manual->getText() << endl;
