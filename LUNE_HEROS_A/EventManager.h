#pragma once

#include <SDL.h>

namespace Event
{
	void MouseEventManager(SDL_Event* event);

	void WindowEventManager(SDL_Event* event);

	void KeyboardEventManager(SDL_Event* event);
}


#include "MouseEvent.h"
#include "WindowEvent.h"
#include "KeyboardEvent.h"