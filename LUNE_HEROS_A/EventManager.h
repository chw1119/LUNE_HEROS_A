#ifndef _EVENT
#define _EVENT

#include <SDL.h>
#include <functional>


class EventManager
{
private:
	std::function<void(SDL_Event*)> onMouseUp   = nullptr;
	std::function<void(SDL_Event*)> onMouseDown = nullptr;
	std::function<void(SDL_Event*)> onMouseMove = nullptr;


	std::function<void(SDL_Event*)> onKeyDown   = nullptr;
	std::function<void(SDL_Event*)> onKeyUp     = nullptr;

public:

	EventManager();

	void SetOnMouseUp(std::function<void(SDL_Event*)> func);
	void SetOnMouseDown(std::function<void(SDL_Event*)> func);
	void SetOnMouseMove(std::function<void(SDL_Event*)> func);

	void SetOnKeyDown(std::function<void(SDL_Event*)> func);
	void SetOnKeyUp(std::function<void(SDL_Event*)> func);

	const std::function<void(SDL_Event*)> operator[] (const std::string& str);
};


#endif