#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<fstream>

using namespace std;

class Visitor;

class IFigure
{
public:
	virtual void print() = 0;
	virtual void accept(Visitor* v) = 0;
};

class Point : public IFigure
{
public:
	int x, y;

	Point(int x, int y) :x(x), y(y) {}
	void print()
	{
		cout << "Point: X = " << x << ", Y = " << y << endl;
	}
	void accept(Visitor* v);

};

class Circle1 : public IFigure
{
public:
	int x, y, r;

	Circle1 (int x, int y, int r) :x(x), y(y), r(r) {}
	void print()
	{
		cout << "Circle1: X = " << x << ", Y = " << y << ", R = " << r << endl;
	}
	void accept(Visitor* v);

};

class Ractangle : public IFigure
{
public:
	int x1, y1, x2, y2;

	Ractangle(int x1, int y1, int x2, int y2) :x1(x1), y1(y1), x2(x2), y2(y2) {}
	void print()
	{
		cout << "Rectangle: P1(" << x1 << ", " << y1 << "), P2(" << x2 << ", " << y2 << ")" << endl;
	}
	void accept(Visitor* v);

};

class Visitor
{
public:
	virtual void visit(Point* p) = 0;
	virtual void visit(Circle1* c) = 0;
	virtual void visit(Ractangle* r) = 0;
};

class HTMLExportVisitor : public Visitor
{
	string fname;
public:
	HTMLExportVisitor(string fn) :fname(fn) {}
	void visit(Point* p)
	{
		string res = "";
		res += "<table><tr><td>Point</td><td>X=";
		char buff[10];
		_itoa(p->x, buff, 10);
		res += buff;
		res += "</td><td>Y=";
		_itoa(p->y, buff, 10);
		res += buff;
		res += "</td></tr></table>";
		ofstream out(fname, ios::app);
		out << res << endl;
		out.close();
	}
	void visit(Circle1* c)
	{
		string res = "";
		res += "<table><tr><td>Circle1</td><td>X=";
		char buff[10];
		_itoa(c->x, buff, 10);
		res += buff;
		res += "</td><td>Y=";
		_itoa(c->y, buff, 10);
		res += buff;
		res += "</td><td>R=";
		_itoa(c->r, buff, 10);
		res += buff;
		res += "</td></tr></table>";
		ofstream out(fname, ios::app);
		out << res << endl;
		out.close();
	}
	void visit(Ractangle* r)
	{
		string res = "";
		res += "<table><tr><td>Ractangle</td><td>P1(";
		char buff[10];
		_itoa(r->x1, buff, 10);
		res += buff;
		res += ", ";
		_itoa(r->y1, buff, 10);
		res += buff;
		res += ")</td><td>P2(";
		_itoa(r->x2, buff, 10);
		res += buff;
		res += ", ";
		_itoa(r->y2, buff, 10);
		res += buff;
		res += ")</td></tr></table>";
		ofstream out(fname, ios::app);
		out << res << endl;
		out.close();
	}
};

class TXTExportVisitor : public Visitor
{
	string fname;
public:
	TXTExportVisitor(string fn) :fname(fn) {}
	void visit(Point* p)
	{
		string res = "";
		res += "Point X = ";
		char buff[10];
		_itoa(p->x, buff, 10);
		res += buff;
		res += " Y = ";
		_itoa(p->y, buff, 10);
		res += buff;

		ofstream out(fname, ios::app);
		out << res << endl;
		out.close();
	}
	void visit(Circle1* c)
	{
		string res = "";
		res += "Circle1 X = ";
		char buff[10];
		_itoa(c->x, buff, 10);
		res += buff;
		res += " Y = ";
		_itoa(c->y, buff, 10);
		res += buff;
		res += " R = ";
		_itoa(c->r, buff, 10);
		res += buff;

		ofstream out(fname, ios::app);
		out << res << endl;
		out.close();
	}
	void visit(Ractangle* r)
	{
		string res = "";
		res += "Ractangle P1(";
		char buff[10];
		_itoa(r->x1, buff, 10);
		res += buff;
		res += ", ";
		_itoa(r->y1, buff, 10);
		res += buff;
		res += "), P2(";
		_itoa(r->x2, buff, 10);
		res += buff;
		res += ", ";
		_itoa(r->y2, buff, 10);
		res += buff;
		res += ")";
		ofstream out(fname, ios::app);
		out << res << endl;
		out.close();
	}
};

class Perimetr :public Visitor
{
public:
	void visit(Point* c)
	{
		cout << "No perimetr" << endl;
	}
	void visit(Circle1* c)
	{
		cout << "Per Cir = " << 3.14*(float)c->r*c->r << endl;
	}
	void visit(Ractangle* r)
	{
		cout << "Per Rect = " << 2 * abs(r->x1 - r->x2) + 2 * abs(r->y1 - r->y2) << endl;
	}
};

void Point::accept(Visitor* v)
{
	v->visit(this);
}

void Circle1::accept(Visitor* v)
{
	v->visit(this);
}

void Ractangle::accept(Visitor* v)
{
	v->visit(this);
}


//IFigure* arr[] = { new Point(2,4), new Circle1(3,6,5), new Ractangle(3,7,8,4) };
//for (auto f : arr)
//f->print();
//
//Visitor* visitor = new HTMLExportVisitor("index.html");
//for (auto f : arr)
//f->accept(visitor);
//
//visitor = new TXTExportVisitor("index.txt");
//for (auto f : arr)
//f->accept(visitor);
//
//visitor = new Perimetr;
//arr[1]->accept(visitor);
//arr[2]->accept(visitor);