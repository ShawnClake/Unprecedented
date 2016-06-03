/*
=================================================
UNPRECEDENTED
An Unprecedented approach to web dev
Original Author: Shawn Clake
Official Maintainer: Shawn Clake
Registered under: GNU license
=================================================
*/

#ifndef __ELEMENT_PARSER__
#define __ELEMENT_PARSER__

#include "parser.h"

/**
ElementParser
*Potentially replaced by stage1*
*/
class ElementParser : Parser
{
protected:
	ElementParser(const string& input, int length, int position, char symbol, bool complete, const Validator& validator)
		: Parser(input, length, position, symbol, complete, validator)
	{
	}

	ElementParser(): Parser() {}

	~ElementParser()
	{
	}
};


#endif
