/*
=================================================
UNPRECEDENTED
An Unprecedented approach to web dev
Original Author: Shawn Clake
Official Maintainer: Shawn Clake
Registered under: GNU license
=================================================
*/

#ifndef __ELEMENT_TYPES__
#define __ELEMENT_TYPES__

#include <string>

/**
ElementTypes
Base class for types of elements

TODO:
Implmentation
*/
class ElementTypes {

protected:
	std::string default;

public:
	ElementTypes() { this->default = "html"; }



};


#endif