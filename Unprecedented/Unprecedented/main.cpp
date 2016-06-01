/*
=================================================
                UNPRECEDENTED
	  An Unprecedented approach to web dev
	      Original Author: Shawn Clake
	    Official Maintainer: Shawn Clake
		  Registered under: GNU license
		     Main Version: V0.00.01
=================================================
*/


/*
To the reader,

This is not yet a functional program. It is still in initial development.
I hope to have a working prototype by June 30th however that is subject
  to minor or drastic change.

Please feel free to add pull requests for changes to my code. If something
  is badly coded or unoptomized please let me know, but also provide a why
  and a method to fix the problem.

This is my first major project which has gone through months of vigerous
  planning and organizing. I am new to github, so please go easy on me
  with respect to major project structure and github structure.

Thanks,
Shawn Clake
*/

/*
 ***
Unprecedented is best explained by seeing it in action. If I feel interested
  at some point, I will try and detail a description of what unprecedented is.

Source File commenting... in progress......
 ***
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "Validator.h"
#include "tagCheck.h"
#include "dbvalidCalls.h"
#include "stage1.h"
#include "logger.h"
#include "elementDebug.h"

using namespace std;

//public Logger logger("unprecedented", true, true);

/**
searcher
Finds whether a substr exists in a string
@Params string content, string search
@Return string
*/
string searcher(string& content, string& search) {

	return (((int)content.find(search) > -1) ? "YES" : "NOPE");

}

/**
main
Entry point. Currently functioning as a test driver.
@Params
@Return int
*/
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

	/*if (validator.isAlphaNumeric(input))
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

	}*/

	Logger::use().log("Receiving input string");
	Logger::use().log(input);

	Stage1 stage1(input);

	cout << stage1.strReverse(input) << endl << endl;

	stage1.setInput(input);

	stage1.run();

	Logger::use().log("FINISHED PARSING");

	ElementDebug debugger;

	Logger::use().log("Creating output file...");

	debugger.printToFile(stage1.getFinalElements());

	Logger::use().log("Output file created...");

	Logger::use().log("Stopping program...");

	//Logger logger("01unprecedented", true, true);
	

	/*logger.log("PROGRAM INIT");

	DBValidCalls db;

	logger.log("PROGRAM END");*/

	return 0;
}