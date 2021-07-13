#ifndef _UTILITY
#define _UTILITY

#include <SDL.h>
#include <chrono>
#include <utility>
#include <iostream>
#include <ctime>
#include <sys/timeb.h>

using std::cout; using std::endl;



class Utility 
{
public:

	static std::pair<int, int> GetMouseLocation();
	static std::pair<int, int> GetFullScreenSize();
	static std::chrono::milliseconds GetCurrentMilliTimes();
};


#endif