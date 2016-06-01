/*
=================================================
UNPRECEDENTED
An Unprecedented approach to web dev
Original Author: Shawn Clake
Official Maintainer: Shawn Clake
Registered under: GNU license
=================================================
*/

#ifndef __DB_VALID_CALLS__
#define __DB_VALID_CALLS__

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include "logger.h"

using namespace std;

/**
DBValidCalls
Handles the database for call, prefix grammar.
TODO:
 Convert to file based database rather than hard coded.
*/
class DBValidCalls {

private:

	vector<string> calls;


	vector<string> prefixes;


public:
	DBValidCalls() { 
	
		Logger::use().log("Opening calls DB...");

		ifstream calls("callNames.txt");
		
		Logger::use().log("Loading calls DB...");

		if (calls.is_open()) {

			string call;

			while (getline(calls, call)) {

				Logger::use().log("Adding call: " + call);

				this->calls.push_back(call);

				Logger::use().log(call + " added successfully");

			}

		}

		calls.close();

		Logger::use().log("Calls DB loaded");

		Logger::use().log("Opening prefixes DB...");

		ifstream prefixes("prefixNames.txt");

		Logger::use().log("Loading prefixes DB...");

		if (prefixes.is_open()) {

			string prefix;

			while (getline(prefixes, prefix)) {

				Logger::use().log("Adding prefix: " + prefix);

				this->prefixes.push_back(prefix);

				Logger::use().log(prefix + " added successfully");

			}


		}
		
		prefixes.close();

		Logger::use().log("Prefixes DB loaded");

	};

	bool isCall(string call) { return find(calls.begin(), calls.end(), call) != calls.end(); }

	bool isPrefix(string prefix) { return find(prefixes.begin(), prefixes.end(), prefix) != prefixes.end(); }

	static DBValidCalls& use() {
		static DBValidCalls instance;
		return instance;
	}

};


#endif