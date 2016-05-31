/*
=================================================
UNPRECEDENTED
An Unprecedented approach to web dev
Original Author: Shawn Clake
Official Maintainer: Shawn Clake
Registered under: GNU license
=================================================
*/

// Array of elements
#ifndef __ELEMENTS__
#define __ELEMENTS__

#include "element.h"
#include <vector>
#include <iostream>

/**
Elements
Extension class for a vector suited to Elements.
"Collection of elements"
*/
class Elements {

private:
	std::vector<Element> elements;

public:

	vector<Element> getElements() {

		return elements;

	}

	void create() {

		push(*(new Element));

	}

	void createWithCall(const string& call) {

		create();
		top().setCall(call);

	}

	void push(Element element) {

		elements.push_back(element);

	}

	Element& top() {
		
		if(!empty())
			return elements.back();

	}

	bool empty() {

		return elements.empty();

	}

	Element pop() {

		if (!empty()) {
			Element e = top();
			elements.pop_back();
			return e;
		}

	}

	int size() {
		return elements.size();
	}

};

#endif