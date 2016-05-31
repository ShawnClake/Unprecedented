/*
=================================================
UNPRECEDENTED
An Unprecedented approach to web dev
Original Author: Shawn Clake
Official Maintainer: Shawn Clake
Registered under: GNU license
=================================================
*/

#ifndef __ELEMENT_TYPE__
#define __ELEMENT_TYPE__

#include "elementTypes.h"

/**
ElementType
Stores what type each element is for ease of processing later.
*Extended by element*
*/
class ElementType : public ElementTypes {

private:
	std::string type;

public:

	ElementType() { type = this->default; }
	std::string getType() { return this->type; }

	bool isType(std::string type) { return type == this->type; }
	bool isHtml() { return this->type == "html"; }
	bool isScript() { return this->type == "script"; }
	bool isStyle() { return this->type == "style"; }

	void setHtml() { this->type = "html"; }
	void setScript() { this->type = "script"; }
	void setStyle() { this->type = "style"; }

	void setType(std::string type) { this->type = type; }

};


#endif