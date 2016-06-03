#pragma once

#include "logger.h"
#include "CustomTypes.h"
#include "element.h"

using namespace std;

class ElementDebug
{
	Logger* outputStructure;

public:

	ElementDebug()
	{
		this->outputStructure = new Logger("[debug]structure");
	}

	void printToFile(eCollection elements, string parent = "Null") const
	{
		while (!elements.empty())
		{
			Element e = elements.back();

			string nested = e.nested.empty() ? "NO" : "YES";

			string contentAfterClose = e.getAfterClose() == "" ? "NULL" : e.getAfterClose();

			string contentAfterOpen = e.getAfterOpen() == "" ? "NULL" : e.getAfterOpen();

			outputStructure->log("");
			outputStructure->log("=======" + e.getCall() + "=======");
			outputStructure->log(" *Parent Element: " + parent);
			outputStructure->log(" *Content After Opening Tag: " + contentAfterOpen);
			outputStructure->log(" *Content After Closing Tag: " + contentAfterClose);
			outputStructure->log(" *Has nested: " + nested);
			outputStructure->log("=======" + e.getCall() + "=======");
			outputStructure->log("");

			elements.pop_back();

			if (!e.nested.empty())
			{
				printToFile(e.nested, e.getCall());
			}
		}
	}
};
