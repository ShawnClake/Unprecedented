#ifndef __ELEMENT__
#define __ELEMENT__

#include <string>
#include "elementProps.h"
#include "elementException.h"
#include "elementType.h"
#include "elementParser.h"
#include "elements.h"
//#include <iomanip>

using namespace std;

class Element : public Elements, ElementType, ElementParser {

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

	void addChar(char c) { this->content += c; }

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
	closed = false;

	errors = 0;
	isException = false;

}

void Element::run() {

	output = content;

}

#endif