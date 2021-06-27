#pragma once

#include <SDL.h>

namespace Event
{
	

	void MouseEventManager(SDL_Event* event);

	void WindowEventManager(SDL_Event* event);

	void KeyboardEventManager(SDL_Event* event);
	
	
	void ProcessEvent(SDL_Event* event) 
	{
		MouseEventManager(event);

		WindowEventManager(event);

		KeyboardEventManager(event);
	}
}


#include "MouseEvent.h"
#include "WindowEvent.h"
#include "KeyboardEvent.h"