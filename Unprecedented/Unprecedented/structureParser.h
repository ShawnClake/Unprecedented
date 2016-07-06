/*
=================================================
UNPRECEDENTED
An Unprecedented approach to web dev
Original Author: Shawn Clake
Official Maintainer: Shawn Clake
Registered under: GNU license
=================================================
*/

#ifndef __STRUCTURE_PARSER__
#define __STRUCTURE_PARSER__

#include "parser.h"
#include <string>
#include "tags.h"
#include <stack>
#include <sstream>
#include "dbvalidCalls.h"
#include "logger.h"

using namespace std;

/**
StructureParser
**Checks to ensure the structure is built correctly.
TODO:
*/
class StructureParser : public Parser, public TagCheck
{
	bool isBalanced2;
	stack<string> balancer;
	bool inOpen; // 0-Searching for open tag, 1-Searching for end tag


public:
	~StructureParser()
	{
	}

	StructureParser(const string& input) : TagCheck(input) {

		setInput(input);

		inOpen = false;
		isBalanced2 = true;

		run34();

	}

	bool isTagNamesComplete(string input) {


	}

	bool isBalanced3() {

		return isBalanced2 && isBalanced() && balancer.empty();


	}

	void handle(char current) override {

		stringstream ss;

		string symbol,
			element;

		ss << current;
		ss >> symbol;

		string keyword = beforeBreak(getInput().substr(getPos() + 1));

		if (!balancer.empty())
			element = balancer.top();

		if (IsOpen(current) && DBValidCalls::use().isCall(keyword)) {

			Logger::use().log("Found opening call: ");
			Logger::use().log(keyword);

			balancer.push(keyword);

		}

		else if (IsClosed(current)) {

			Logger::use().log("Found closed: ");
			Logger::use().log(getInput().substr(getPos() - element.length(), element.length()));

			if (getInput().substr(getPos() - element.length(), element.length()) == element) {

				Logger::use().log("Acceptable end call found");
				balancer.pop();

			}	
			else {

				Logger::use().log("Unacceptable end call found. Compilation has failed!");
				isBalanced2 = false;

			}
				


		}
			

		nextPos();

	}

};


#endif
