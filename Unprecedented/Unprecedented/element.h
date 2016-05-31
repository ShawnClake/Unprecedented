/*
=================================================
UNPRECEDENTED
An Unprecedented approach to web dev
Original Author: Shawn Clake
Official Maintainer: Shawn Clake
Registered under: GNU license
=================================================
*/

#ifndef __ELEMENT__
#define __ELEMENT__

#include <vector>
#include <string>
#include "elementProps.h"
#include "elementException.h"
#include "elementType.h"
#include "elementParser.h"


//#include "elements.h"
//#include <iomanip>

using namespace std;

/**
Element
Houses the properties and content for each element. An element is a tag block.

ie. <crackers hello how're you crackers> yup i'm a dog
 is all one element.
ie. <banana (banana)contentAfterOpening <strudle (strudle)contentAfterOpening strudle> (strudle)contentAfterClosing banana> (banana)contentAfterClosing
 is all one element.
*/
class Element : public ElementType, ElementParser {

public:

private:

	ElementProps props;

	//ElementType type;

	ElementException exception;

	//Elements nested;

	std::string
		call,
		content,
		output,
		contentAfterOpening, // <crackers (crackers)contentAfterOpening <banana (banana)contentAfterOpening <strudle (strudle)contentAfterOpening strudle> (strudle)contentAfterOpoening banana> (banana)contentAfterClosing crackers> (crackers)contentAfterOpening
		contentAfterClosing;

	int errors;

	bool
		isException,
		closed;

public:

	vector<Element> nested;

	Element();

	bool didError() { return errors != 0; }

	int getErrorCount() { return this->errors; }

	std::string getOutput() { return this->output; }

	void run();

	void setProps(ElementProps props) { this->props = props; }
	void setContents(std::string content) { this->content = content; }
	void setCall(string call) { this->call = call; }

	string getCall() { return call; }
	string getContent() { return content; }
	//string getOutput() { return output; }

	void addCharAfterOpen(char c) { this->contentAfterOpening += c; }
	void addCharAfterClose(char c) { this->contentAfterClosing += c; }

	void setClosed() { closed = true; }
	bool isClosed() { return closed; }

	void setAfterOpen(std::string content) { contentAfterOpening = content; }
	void setAfterClose(std::string content) { contentAfterClosing = content; }

	std::string getAfterOpen() { return contentAfterOpening; }
	std::string getAfterClose() { return contentAfterClosing; }


private:

	void addError() { errors++; }


};

Element::Element() {

	call = "";
	content = "";
	output = "";
	contentAfterClosing = "";
	contentAfterOpening = "";
	closed = false;

	errors = 0;
	isException = false;

}

void Element::run() {

	output = content;

}

#endif