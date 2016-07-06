#pragma once
/*
=================================================
UNPRECEDENTED
An Unprecedented approach to web dev
Original Author: Shawn Clake
Official Maintainer: Shawn Clake
Registered under: GNU license
=================================================
*/

#include "elementV2.h"
#include <vector>
#include <iostream>

/**
Elements
Extension class for a vector suited to Elements.
"Collection of elements"
*/
class ElementsV2
{
	vector<ElementV2> elements;

public:

	vector<ElementV2> getElements() const
	{
		return elements;
	}

	void create()
	{
		push(*(new ElementV2));
	}

	void createWithCall(const string& call)
	{
		create();
		top().setCall(call);
	}

	void push(ElementV2 element)
	{
		elements.push_back(element);
	}

	ElementV2& top()
	{
		if (!empty())
			return elements.back();
	}

	bool empty() const
	{
		return elements.empty();
	}

	ElementV2 pop()
	{
		if (!empty())
		{
			ElementV2 e = top();
			elements.pop_back();
			return e;
		}

	}

	int size() const
	{
		return elements.size();
	}
};
