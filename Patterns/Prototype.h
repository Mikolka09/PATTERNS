#pragma once

#include<iostream>
#include<string>

using namespace std;

class IFigura
{
public:
	virtual IFigura* clone() = 0;
	virtual void print() = 0;
};

class Rectangle : public IFigura
{
	int w, h;
public:
	Rectangle(int w, int h): w(w), h(h){}
	IFigura* clone() override
	{
		return new Rectangle(w, h);
	}
	void print() override
	{
		cout << "Rectangle" << endl;
		cout << "W: " << w << endl;
		cout << "H: " << h << endl;
	}
};

class Circle :public IFigura
{
	int r;
public:
	Circle(int r) :r(r) {}
	IFigura* clone() override
	{
		return new Circle(r);
	}
	void print() override
	{
		cout << "Circle" << endl;
		cout << "R: " << r << endl;
	}
};

//void method(IFigura* fig)
//{
//	fig->print();
//	IFigura* copy = fig->clone();
//	copy->print();
//
//}
//
//IFigura* rect = new Rectangle(10, 23);
//method(rect);
//IFigura* cir = new Circle(25);
//method(cir);

