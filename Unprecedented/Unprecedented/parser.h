/*
=================================================
UNPRECEDENTED
An Unprecedented approach to web dev
Original Author: Shawn Clake
Official Maintainer: Shawn Clake
Registered under: GNU license
=================================================
*/

#ifndef __PARSER__
#define __PARSER__

#include <string>
#include <algorithm>
#include "Validator.h"

using namespace std;

/**
Parser
The base class for parsing unprecedented formats.
TODO:
Optomizations!
*/
class Parser {

private:
	string input;

	int length;
	int position;

	char symbol;

	bool complete;

	Validator validator;

public:

	bool substrExists(const std::string& content, const std::string& search) { return (((int)content.find(search) > -1)); }

	int subStrExistsFront(const std::string& content, const std::string& search) { 
		return (((int)content.substr(0, (int)search.length()).find(search) > -1 ? (int)search.length() : 0)); 
	}

	string beforeBreak(const std::string& content) {

		int breakPoint = (int)content.find_first_not_of(validator.strAlphaNumeric());

		if (breakPoint <= 0)
			return "";

		return content.substr(0, breakPoint);

	}

	/*string beforeEndingTag(std::string content) {

		//For making the nested substr:
		int findEnd = 1; //When findEnd = 0 we found the end of the substr we want. Each < tag adds one, each > subtracts one.

		int check = 0;

		while (findEnd != 0 && check != -1) {

			check += (int)content.substr(check).find_first_of("<>");

			if (check != -1) {

				char sym = content[check];

				if (sym == '<')
					findEnd++;
				else if (sym == '>')
					findEnd--;

			}

		}

		if (findEnd != 0)
			return "";

		int breakPoint = (int)content.substr(0, check).find_last_not_of(validator.strAlphaNumeric());

		return content.substr(0, breakPoint);

	}*/

	string beforeEndingTag(std::string content) {

		//For making the nested substr:
		int findEnd = 1; //When findEnd = 0 we found the end of the substr we want. Each < tag adds one, each > subtracts one.

		int check = 1;

		while (findEnd != 0 && check != -1) {

			check += (int)content.substr(check).find_first_of("<>");

			if (check != -1) {

				char sym = content[check];

				if (sym == '<')
					findEnd++;
				else if (sym == '>')
					findEnd--;

			}

		}

		if (findEnd != 0)
			return "";

		//int breakPoint = (int)content.substr(0, check).find_last_not_of(validator.strAlphaNumeric());

		return content.substr(0, check + 1/*breakPoint*/);

	}

	virtual void handle(char current) {}

	void run34() {

		if (input == "" || position != 0 || symbol != NULL || length == NULL || complete != false)
			return;

		while (!complete) {

			setSymbol();

			handle(symbol);

			complete = isFinished();

		}

	}

	void setInput(string input) {

		this->input = input;
		length = (int)input.length();
		position = 0;
		symbol = NULL;
		complete = false;

	}

	void nextPos() {

		position++;

	}

	void addToPos(int pos) {

		if(position + pos <= length)
			position += pos;

	}

	void setSymbol() {

		symbol = input[position];

	}

	bool isFinished() {

		return (position == length);

	}

	int getPos() {

		return position;

	}

	string getInput() {

		return input;

	}

	string strReverse(string str) {

		reverse(str.begin(), str.end());

		return str;

	}

};

#endif