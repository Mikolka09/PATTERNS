#pragma once

#include<iostream>
#include<string>
#include<list>

using namespace std;

class TextEditor
{
public:
	void createCode()
	{
		cout << "��������� ����" << endl;
	}

	void save()
	{
		cout << "���������� ����" << endl;
	}
};

class Compiller
{
public:
	void compile()
	{
		cout << "���������� ����������" << endl;
	}
};

class Debugger
{
public:
	void execute()
	{
		cout << "��������� ������ ������� � ������" << endl;
	}

	void finish()
	{
		cout << "�������� ����������" << endl;
	}
};

class VisualStudioFacade
{
	TextEditor* textEditor;
	Compiller* compiller;
	Debugger* debugger;
public:
	VisualStudioFacade()
	{
		textEditor = new TextEditor;
		compiller = new Compiller;
		debugger = new Debugger;
	}

	void start()
	{
		textEditor->createCode();
		textEditor->save();
		compiller->compile();
		debugger->execute();
	}
	void stop()
	{
		debugger->finish();
	}

};


//VisualStudioFacade* vs2019 = new VisualStudioFacade;
//vs2019->start();
//vs2019->stop();
