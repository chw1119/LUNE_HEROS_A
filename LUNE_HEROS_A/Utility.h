#ifndef _UTILITY
#define _UTILITY

#include "./modules/SDL2-devel-2.0.14-VC/SDL2-2.0.14/include/SDL.h"
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