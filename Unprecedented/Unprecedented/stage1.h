/*
=================================================
UNPRECEDENTED
An Unprecedented approach to web dev
Original Author: Shawn Clake
Official Maintainer: Shawn Clake
Registered under: GNU license
=================================================
*/

/*

STAGE ONE
ASSEMBLES THE ELEMENTS VECTOR.


*/

// STACK OF ELEMENT'S
// (1) WHEN YOU FIND AN ACCEPTABLE OPENING TAG, INSERT THE ELEMENT INTO THE STACK. 
// (2) ADD CHARACTER BY CAHARCTER TO THE TOP STACK ELEMENT.
// (3) WHEN YOU FIND AN ACCEPTABLE CLOSING TAG, REMOVE THE TOP ELEMENT FROM THE STACK AND SAVE IT INTO ELEMENTS VECTOR.
// CONTINUE FROM STEP (2)

// ERROR CHECKING:
// PROPER TAGS checking BEFORE EVEN RUNNING THE PARSER

#ifndef __STAGE1__
#define __STAGE1__

#include <string>
#include <vector>
#include "element.h"
#include "elements.h"
#include "structureParser.h"
#include <stack>
#include "tagCheck.h"
#include <sstream>
#include "CustomTypes.h"
#include "logger.h"

using namespace std;

/**
Stage1
Translates a file into the unprecedented data structure
TODO:
 * Finish nesting
 * Fix bugs
 * Optomize

*/
class Stage1 : public StructureParser {

private:
	std::string input;
	std::vector<Element> parseStack;
	Elements FinalElements;
	Elements ELEMENTS;
	//DBValidCalls db;

public:
	Stage1(std::string input) { this->input = input; }
	bool run();
	bool tagCheck(const string& input);

	eCollection getIntermediate() {

		return ELEMENTS.getElements();

	}

	eCollection getFinalElements() {

		return FinalElements.getElements();

	}


	void handle(char current) {

		cout << current << "-";

		stringstream ss;

		string symbol;

		ss << current;
		ss >> symbol;

		//cout << "WE FOUND A CALL YAY:" << symbol << endl << endl;
		if (DBValidCalls::use().isPrefix(symbol)) {

			Logger::use().log("Found a prefix");

			string keyword = beforeBreak(getInput().substr(getPos() + 1));
			
			if (DBValidCalls::use().isCall(keyword) && (ELEMENTS.empty() || ELEMENTS.top().isClosed())) {

				if (!ELEMENTS.empty()) {

					Logger::use().log("ENDPOINT1: Moving element into final stack...");

					FinalElements.push(ELEMENTS.pop());

				}

				Logger::use().log("Found a call and an Element is closed on top of the stack.");
				Logger::use().log("CALL: " + keyword);

				int callLength = (int)keyword.length() + 1;

				/*Element* e = new Element();
				
				e->setCall(keyword);

				ELEMENTS.push(*e);*/

				ELEMENTS.createWithCall(keyword);

				addToPos(callLength + 1);

				return;

			}
			else if (DBValidCalls::use().isCall(keyword)) {

				//ELEMENTS.top().createWithCall(keyword);
				
				Logger::use().log("Found a nested call");
				Logger::use().log("CALL: " + keyword);

				string imbetween = beforeEndingTag(getInput().substr(getPos()), ELEMENTS.top().getCall());

				Logger::use().log("Creating nested stage1 object...");

				Stage1 nested(imbetween);

				Logger::use().log("Setting parsers input...");

				Logger::use().log("INPUT: " + imbetween);

				nested.setInput(imbetween);

				Logger::use().log("Running nested stage1 object...");

				nested.run();

				Logger::use().log("Grabbing result of nested stage1 object...");

				ELEMENTS.top().nested = nested.getFinalElements();

				addToPos((int)imbetween.length());

				Logger::use().log("Closing nested stage1 object instance...");

				return;

			}
			else if(!ELEMENTS.empty()) {

				//REGULAR HTML

				Logger::use().log("Found a call prefix without a valid call.. Assuming HTML...");

				if (!ELEMENTS.top().isClosed())
					ELEMENTS.top().addCharAfterOpen(current);
				else
					ELEMENTS.top().addCharAfterClose(current);

			}

		}
		else if (!ELEMENTS.empty()) {

			//cout << "BIGOH";

			if (subStrExistsFront(getInput().substr(getPos()), (ELEMENTS.top().getCall() + ">"))) {

				Logger::use().log("Found end of a call tag for the element at the top...");
				Logger::use().log("CALL: " + ELEMENTS.top().getCall());

				Logger::use().log("Setting top stack element to closed...");

				ELEMENTS.top().setClosed();

				addToPos((int)ELEMENTS.top().getCall().length() + 1);

				Logger::use().log("Finished the call...");

				return;

			}

			if (!ELEMENTS.top().isClosed())
				ELEMENTS.top().addCharAfterOpen(current);
			else
				ELEMENTS.top().addCharAfterClose(current);

		}

		nextPos();

		if (isFinished() && !ELEMENTS.empty()) {

			Logger::use().log("ENDPOINT2: Moving element into final stack...");

			FinalElements.push(ELEMENTS.pop());

		}

	}

};

bool Stage1::tagCheck(const string& input) {

	TagCheck checker(input);
	return checker.isBalanced();

}

bool Stage1::run() {

	Logger::use().log("Running stage1 instance...");

	if (!tagCheck(input)) {

		Logger::use().log("!!!!! Tags are incomplete");

		return false;

	}
		
	Logger::use().log("Running parse mechanism...");

	run34();

	//cout << "BIGOHHHHHHHHH";

	if (FinalElements.empty()) {
		cout << "empty" << endl;
	}
	else {
		cout << "NOT EMPTY" << endl;

		Element e = FinalElements.top();
		e.run();
		//cout << "C3P0HALLLLLLLLLLLLP";

		cout << endl << endl << e.getCall() << endl << e.getContent() << endl << e.getOutput();
	}

	return true;

}



#endif