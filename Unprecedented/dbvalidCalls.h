#ifndef __DB_VALID_CALLS__
#define __DB_VALID_CALLS__

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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