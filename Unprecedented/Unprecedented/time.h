#pragma once

#include <string>
#include <chrono>

using namespace std;

class Time
{

public:
	static string getCurrentStamp()
	{
		
		chrono::time_point<chrono::system_clock> instant;
		instant = chrono::system_clock::now();
		auto tInstant = chrono::system_clock::to_time_t(instant);
		return ctime(&tInstant);

	}

};
