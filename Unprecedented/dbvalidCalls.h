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

using namespace std;

/**
DBValidCalls
Handles the database for call, prefix grammar.
TODO:
 Convert to file based database rather than hard coded.
*/
class DBValidCalls {

private:

	vector<string> calls = {
	
		"crackers", "apple", "pineapple"
	
	};


	vector<string> prefixes = {
	
		"cookie", "panini", "strudle", "<"

	};


public:
	bool isCall(string call) { return find(calls.begin(), calls.end(), call) != calls.end(); }

	bool isPrefix(string prefix) { return find(prefixes.begin(), prefixes.end(), prefix) != prefixes.end(); }



};


#endif