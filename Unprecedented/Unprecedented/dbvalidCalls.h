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
	
		ifstream calls("callNames.txt");
		
		if (calls.is_open()) {

			string call;

			while (getline(calls, call))
				this->calls.push_back(call);

		}

		calls.close();

		ifstream prefixes("prefixNames.txt");

		if (prefixes.is_open()) {

			string prefix;

			while (getline(prefixes, prefix))
				this->prefixes.push_back(prefix);

		}
		
		prefixes.close();


	};

	bool isCall(string call) { return find(calls.begin(), calls.end(), call) != calls.end(); }

	bool isPrefix(string prefix) { return find(prefixes.begin(), prefixes.end(), prefix) != prefixes.end(); }



};


#endif