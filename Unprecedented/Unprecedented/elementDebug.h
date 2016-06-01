#pragma once

#include <string>
#include "logger.h"
#include "elements.h"
#include "CustomTypes.h"
#include "element.h"

using namespace std;

class ElementDebug {

private:
	Logger* outputStructure;

public:

	ElementDebug() {

		this->outputStructure = new Logger ("[debug]structure");

	}

	void printToFile(eCollection elements, string parent = "Null") {

		

		while (!elements.empty()) {

			Element e = elements.back();

			string nested = e.nested.empty() ? "NO" : "YES";

			outputStructure->log("");
			outputStructure->log("=======" + e.getCall() + "=======");
			outputStructure->log(" *Parent Element: " + parent);
			outputStructure->log(" *Content After Opening Tag: " + e.getAfterOpen());
			outputStructure->log(" *Content After Closing Tag: " + e.getAfterClose());
			outputStructure->log(" *Has nested: " + nested);
			outputStructure->log("=======" + e.getCall() + "=======");
			outputStructure->log("");

			elements.pop_back();

			if (!e.nested.empty()) {

				printToFile(e.nested, e.getCall());

			}

		}

			


	}
	

};