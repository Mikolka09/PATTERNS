#pragma once

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Logger
{
private:
	string message;
	Logger(){}
	static Logger* obj;
public:
	~Logger()
	{
		obj = nullptr;
	}
	static Logger* getInstance();
	void sendMessage(string message);

};

Logger* Logger::obj = nullptr;

Logger* Logger::getInstance()
{
	if (!obj)
		obj = new Logger;
	return obj;
}

void Logger::sendMessage(string message)
{
	this->message = message;
	ofstream out("log.txt", ios::app);
	out << this->message << " - " << __DATE__ << " - " << __TIME__ << endl;
	out.close();
}



//Logger* log = Logger::getInstance();
//log->sendMessage("Error #12");
//log->sendMessage("Error #15");
//log->sendMessage("Error #11");
//log->sendMessage("Error #14");
//delete log;
//
//Logger* log2 = Logger::getInstance();
//log2->sendMessage("Error #13");
