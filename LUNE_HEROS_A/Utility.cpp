#include "Utility.h"

std::pair<int, int> Utility::GetFullScreenSize()
{
		SDL_DisplayMode dm;

		if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
		{
			SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
			exit(1);
		}

		int w, h;
		w = dm.w;
		h = dm.h;

		auto pair = std::pair<int, int>();

		pair.first = w;
		pair.second = h;

		return pair;
}

std::chrono::milliseconds Utility::GetCurrentMilliTimes()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
}

