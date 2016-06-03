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

/**
ElementTypes
Base class for types of elements

TODO:
Implmentation
*/
class ElementTypes
{
protected:
	~ElementTypes()
	{
	}

	std::string tdefault;

public:
	ElementTypes()
	{
		this->tdefault = "html";
	}
};


#endif
