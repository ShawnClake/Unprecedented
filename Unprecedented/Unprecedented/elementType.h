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
class ElementType : public ElementTypes
{
protected:
	~ElementType()
	{
	}

private:
	std::string type;

public:

	ElementType()
	{
		type = this->tdefault;
	}

	string getType() const
	{
		return this->type;
	}

	bool isType(string type) const
	{
		return type == this->type;
	}

	bool isHtml() const
	{
		return this->type == "html";
	}

	bool isScript() const
	{
		return this->type == "script";
	}

	bool isStyle() const
	{
		return this->type == "style";
	}

	void setHtml()
	{
		this->type = "html";
	}

	void setScript()
	{
		this->type = "script";
	}

	void setStyle()
	{
		this->type = "style";
	}

	void setType(string type)
	{
		this->type = type;
	}
};


#endif
