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
	DBValidCalls db;

public:
	Stage1(std::string input) { this->input = input; }
	bool run();
	bool tagCheck(const string& input);


	void handle(char current) {

		cout << current << "-";

		stringstream ss;

		string symbol;

		ss << current;
		ss >> symbol;

		//cout << "WE FOUND A CALL YAY:" << symbol << endl << endl;
		if (db.isPrefix(symbol)) {

			string keyword = beforeBreak(getInput().substr(getPos() + 1));
			
			if (db.isCall(keyword) && (ELEMENTS.empty() || ELEMENTS.top().isClosed())) {

				int callLength = (int)keyword.length() + 1;

				/*Element* e = new Element();
				
				e->setCall(keyword);

				ELEMENTS.push(*e);*/

				ELEMENTS.createWithCall(keyword);

				addToPos(callLength + 1);

				return;

			}
			else if (db.isCall(keyword)) {

				//ELEMENTS.top().createWithCall(keyword);
				
				string imbetween = beforeEndingTag(getInput().substr(getPos()));

				Stage1 nested(imbetween);

				addToPos((int)imbetween.length() + 1);

			}
			else {

				//REGULAR HTML

			}

		}
		else if (!ELEMENTS.empty()) {

			//cout << "BIGOH";

			if (subStrExistsFront(getInput().substr(getPos()), (ELEMENTS.top().getCall() + ">"))) {

				ELEMENTS.top().setClosed();

				FinalElements.push(ELEMENTS.pop());

				addToPos((int)FinalElements.top().getCall().length() + 1);

				cout << "YO WE FINISHED A CALL HERE";

				return;

			}


			ELEMENTS.top().addChar(current);

		}

		nextPos();

	}

};

bool Stage1::tagCheck(const string& input) {

	TagCheck checker(input);
	return checker.isBalanced();

}

bool Stage1::run() {

	if (!tagCheck(input))
		return false;

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