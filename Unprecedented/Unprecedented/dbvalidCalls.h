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
#include "fileIO.h"

#include "logger.h"

using namespace std;

/**
DBValidCalls
Handles the database for call, prefix grammar.
TODO:
 Convert to file based database rather than hard coded.
*/
class DBValidCalls
{
	vector<string> calls;


	vector<string> prefixes;


public:
	DBValidCalls()
	{
		
		Logger::use().log("Loading calls DB...");

		FileIO::readFileByLine(this->calls, string("callNames.txt"));

		Logger::use().log("Calls DB loaded");


		Logger::use().log("Loading prefixes DB...");

		FileIO::readFileByLine(prefixes, string("prefixNames.txt"));

		Logger::use().log("Prefixes DB loaded");

	};

	bool isCall(string call)
	{
		return find(calls.begin(), calls.end(), call) != calls.end();
	}

	bool isPrefix(string prefix)
	{
		return find(prefixes.begin(), prefixes.end(), prefix) != prefixes.end();
	}

	static DBValidCalls& use()
	{
		static DBValidCalls instance;
		return instance;
	}
};


#endif
