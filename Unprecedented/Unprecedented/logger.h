#pragma once
/*
=================================================
UNPRECEDENTED
An Unprecedented approach to web dev
Original Author: Shawn Clake
Official Maintainer: Shawn Clake
Registered under: GNU license
=================================================
*/

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

#include <chrono>
#include <ctime>

using namespace std;
/**
Logger
File and/or console logger
*/
class Logger {



private:
	string name;
	bool doFile;
	bool doConsole;
	ofstream output;

public:

	Logger(string name, bool doFile = true, bool doConsole = false) { this->name = name; this->doFile = doFile; this->doConsole = doConsole; output.open(name + ".txt"); }

	void log(string message) {
	
		chrono::time_point<chrono::system_clock> instant;
		instant = chrono::system_clock::now();
		time_t tInstant = chrono::system_clock::to_time_t(instant);
		string time = ctime(&tInstant);

		if (doFile) {

			output << " * LOG: " << setw(12) << name << " [" << setw(24) << time.substr(0, (int)time.length() - 1) << "]: " << message << endl;

		}

		if (doConsole) {

			cout << " * LOG: " << setw(12) << name << " [" << setw(24) << time.substr(0, (int)time.length() - 1) << "]: " << message << endl;

		}


	}

	~Logger() { output.close(); }



};
