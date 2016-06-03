#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "logger.h"

using namespace std;

class FileIO
{
	


public:

	template <typename T>
	static void readFileByLine(vector<T>& stored, const string & fileName) {

		Logger::use().log("Creating file IO instance for " + fileName);

		ifstream file(fileName);

		if (file.is_open())
		{
			T line;

			while (getline(file, line))
			{
				Logger::use().log("Reading line: " + line);

				stored.push_back(line);

				Logger::use().log(line + " added successfully");
			}
		}

		Logger::use().log("Removing file IO instance for " + fileName);

		file.close();

	}

	static ofstream createFileOutput(const string & fileName)
	{
	
		ofstream file(fileName);
		return file;

	}

	static void writeLine (ofstream & file, const string & line)
	{
		
		file << line;

	}

	static void closeFileOutput(ofstream & file)
	{
		
		file.close();

	}


};