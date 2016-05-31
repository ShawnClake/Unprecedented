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
class Tags {

private:


public:
	bool IsOpen(char symbol)
	{
		if (symbol == '(' || symbol == '{' || symbol == '[' || symbol == '<')
			return true;
		else
			return false;
	}

	bool IsClosed(char symbol)
	{
		if (symbol == ')' || symbol == '}' || symbol == ']' || symbol == '>')
			return true;
		else
			return false;
	}

	bool Matches(char symbol, char openSymbol)
	{
		return  ((openSymbol == '(' && symbol == ')')
			|| (openSymbol == '{' && symbol == '}')
			|| (openSymbol == '[' && symbol == ']')
			|| (openSymbol == '<' && symbol == '>'));
	}

};


#endif
