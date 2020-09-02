#pragma once

#include<iostream>
#include<string>

using namespace std;

class ILanguage
{
public:
	virtual void build() = 0;
	virtual void execute() = 0;
};

class CPPLanguage :public ILanguage
{
public:
	void build() override
	{
		cout << "����������� ��� � ������� ����������� �++ � �������� ���" << endl;
	}

	void execute() override
	{
		cout << "��������� ����������� *.��� ����" << endl;
	}
};

class HTMLLanguage :public ILanguage
{
public:
	void build() override
	{
		cout << "����� ��� � ��������� ���������" << endl;
	}

	void execute() override
	{
		cout << "��������� �������� � ��������" << endl;
	}
};

class Programmer
{
protected:
	ILanguage* language;
public:
	Programmer(ILanguage* lang): language(lang){}
	void setLanguage(ILanguage* lang)
	{
		language = lang;
	}
	void doWork()
	{
		language->build();
		language->execute();
	}
	virtual void getSalary() = 0;

};

class FreelanceProgrammer : public Programmer
{
public:
	FreelanceProgrammer(ILanguage* lang):Programmer(lang){}
	void getSalary() override
	{
		cout << "�������� ������ �� ����������� ������" << endl;
	}
};

class OfficeProgrammer : public Programmer
{
public:
	OfficeProgrammer(ILanguage* lang) :Programmer(lang) {}
	void getSalary() override
	{
		cout << "�������� �������� � ����� ������" << endl;
	}
};


//Programmer* freelancer = new FreelanceProgrammer(new CPPLanguage);
//freelancer->doWork();
//freelancer->getSalary();
//cout << endl;
//
//freelancer->setLanguage(new HTMLLanguage);
//freelancer->doWork();
//freelancer->getSalary();
//cout << endl;
//
//Programmer* officeProger = new OfficeProgrammer(new CPPLanguage);
//officeProger->doWork();
//officeProger->getSalary();
//cout << endl;
