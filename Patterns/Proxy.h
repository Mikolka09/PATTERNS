#pragma once

#include<iostream>
#include<string>
#include<list>
#include<map>

using namespace std;

class IPage
{
public:
	virtual string getPage(int key) = 0;
};

class DataBase: public IPage
{
	map<int, string> pages;
public:
	DataBase()
	{
		pages[1] = "Page 1";
		pages[2] = "Page 2";
		pages[3] = "Page 3";
		pages[4] = "Page 4";
		pages[5] = "Page 5";
		pages[6] = "Page 6";
	}

	string getPage(int key) override
	{
		cout << "Взятое из базы" << endl;
		if (pages.count(key))
			return pages[key];
		else
			return "no page";
	}
};

class DataBaseProxy:public IPage
{
	map<int, string>cash;
	DataBase* base;
public:
	string getPage(int key) override
	{
		if (cash.count(key))
		{
			cout << "Взятое с кэша" << endl;
			return cash[key];
		}
		else
		{
			base = new DataBase;
			string page = base->getPage(key);
			cash[key] = page;
			delete base;
			return page;

		}
	}
};

//DataBaseProxy* dbproxy = new DataBaseProxy;
//
//int i = 1;
//while (i)
//{
//	cout << "Страница: ";
//	cin >> i;
//	cout << dbproxy->getPage(i) << endl;
//}
