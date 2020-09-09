#pragma once

#include<iostream>
#include<string>
#include<list>

using namespace std;

class Component
{
protected:
	string name;
	static int t;
public:
	Component(string n):name(n){}
	virtual void add(Component* comp){}
	virtual void print()
	{
		for (size_t i = 0; i < t; i++)
		{
			cout << "    ";
		}
		cout << name << endl;
	}
};

int Component::t = 0;

class Folder :public Component
{
	list<Component*> components;
public:
	Folder(string n):Component(n){}
	void add(Component* comp)
	{
		components.push_back(comp);
	}
	void print()
	{
		for (size_t i = 0; i < t; i++)
		{
			cout << "    ";
		}
		cout << "Folder: " << name << endl;
		t++;
		for (auto c : components)
			c->print();
		t--;
	}
};

class File :public Component
{

public:
	File(string n):Component(n){}

};


//Component* fs = new Folder("FileSystem");
//Component* folder1 = new Folder("Folder 1");
//Component* folder2 = new Folder("Folder 2");
//Component* folder3 = new Folder("Folder 3");
//Component* file1 = new File("File 1");
//Component* file2 = new File("File 2");
//Component* file3 = new File("File 3");
//
//fs->add(folder1);
//fs->add(folder2);
//fs->add(file1);
//folder1->add(folder3);
//folder3->add(file2);
//folder3->add(file3);
//
//fs->print();
