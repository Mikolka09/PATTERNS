#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include"FactoryMethod.h"
#include"AbstractFactory.h"
#include"Builder.h"

using namespace std;

int main()
{
	setlocale(0, "");

	
	Director* director = new Director();
	MusicCenterBuilder* builderMC = new MusicCenterBuilder;
	director->setBuilder(builderMC);
	director->BuildMaxiMC();

	/*builderMC->createRadio();
	builderMC->createBR();
	builderMC->createSW();
	builderMC->createSW();*/

	MusicCenter* mc = builderMC->getResult();
	mc->print();

	ManualBuilder* builderManual = new ManualBuilder;
	director->setBuilder(builderManual);
	director->BuildMaxiMC();

	Manual* manual = builderManual->getResult();
	cout << manual->getText() << endl;


	
	system("pause");
}