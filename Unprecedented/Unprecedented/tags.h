/*
=================================================
UNPRECEDENTED
An Unprecedented approach to web dev
Original Author: Shawn Clake
Official Maintainer: Shawn Clake
Registered under: GNU license
=================================================
*/

#ifndef __TAGS__
#define __TAGS__


/**
Tags
Utility functions for acceptable unprecedented tags:
 ( ) < > { } [ ]
IsOpen, IsClosed, Matches
*/
class Tags
{
public:
	static bool IsOpen(char symbol)
	{
		if (symbol == '(' || symbol == '{' || symbol == '[' || symbol == '<')
			return true;
		return false;
	}

	static bool IsClosed(char symbol)
	{
		if (symbol == ')' || symbol == '}' || symbol == ']' || symbol == '>')
			return true;
		return false;
	}

	static bool Matches(char symbol, char openSymbol)
	{
		return ((openSymbol == '(' && symbol == ')')
			|| (openSymbol == '{' && symbol == '}')
			|| (openSymbol == '[' && symbol == ']')
			|| (openSymbol == '<' && symbol == '>'));
	}
};


#endif
