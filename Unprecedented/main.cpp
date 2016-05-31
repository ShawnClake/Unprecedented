#include <iostream>
#include <iomanip>
#include <string>
#include "Validator.h"
#include "tagCheck.h"
#include "dbvalidCalls.h"
#include "stage1.h"

using namespace std;



string searcher(string& content, string& search) {

	return (((int)content.find(search) > -1) ? "YES" : "NOPE");

}

int main() {

	/*string content = "", search = "";

	cout << "Enter a string: ";

	getline(cin, content);

	cout << endl << "Enter a string to search for: ";

	getline(cin, search);

	cout << endl << searcher(content, search) << endl << endl;*/

	Validator validator;

	string input = "";

	cout << "Enter a numerical numba: ";

	getline(cin, input);

	if (validator.isAlphaNumeric(input))
		cout << "THAT'S A NUMBA WOOP WOOP" << endl << endl;
	else
		cout << "YOU EEG THAT'S NOT AN NUMBA. GO BACK TO KINDEEGARDEN" << endl << endl;
	//cout << validator.isNumeric(input) ? "THAT'S A NUMBA WOOP WOOP" : "YOU EEG THAT'S NOT AN NUMBA. GO BACK TO KINDEEGARDEN" << endl;

	TagCheck tag(input);

	if (tag.isBalanced()) {

		cout << "TAGS ARE VERIFIED" << endl << endl;

	}
	else {

		cout << "TAGS ARE INCOMPLETE" << endl << endl;

	}

	DBValidCalls ValidCalls;

	if (ValidCalls.isCall(input)) {

		cout << "VALID CALL" << endl << endl;

	}
	else {

		cout << "NOT VALID CALL" << endl << endl;

	}

	if (ValidCalls.isPrefix(input)) {

		cout << "VALID PREFIX" << endl << endl;

	}
	else {

		cout << "NOT VALID PREFIX" << endl << endl;

	}

	Stage1 stage1(input);

	cout << stage1.strReverse(input) << endl << endl;

	stage1.setInput(input);

	stage1.run();

	return 0;
}