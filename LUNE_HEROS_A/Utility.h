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

	inline static std::pair<int, int> GetMouseLocation();
	inline static std::pair<int, int> GetFullScreenSize();
	inline static std::chrono::milliseconds GetCurrentMilliTimes();
};


#endif