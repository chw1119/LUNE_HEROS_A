#include "EventManager.h"

EventManager::EventManager()
{

}

void EventManager::SetOnMouseUp(std::function<void(SDL_Event*)> func)
{
	onMouseUp = func;
}

void EventManager::SetOnMouseDown(std::function<void(SDL_Event*)> func)
{
	onMouseDown = func;
}

void EventManager::SetOnMouseMove(std::function<void(SDL_Event*)> func)
{
	onMouseMove = func;
}

void EventManager::SetOnKeyDown(std::function<void(SDL_Event*)> func)
{
	onKeyDown = func;
}

void EventManager::SetOnKeyUp(std::function<void(SDL_Event*)> func)
{
	onKeyUp = func;
}

const std::function<void(SDL_Event*)> EventManager::operator[](const std::string& str)
{

	if (str.compare("onMouseUp")) 
	{
		return onMouseUp;
	}

	if (str.compare("onMouseDown"))
	{
		return onMouseDown;
	}

	if (str.compare("onMouseMove"))
	{
		return onMouseMove;
	}

	if (str.compare("onKeyUp"))
	{
		return onKeyUp;
	}

	if (str.compare("onKeyDown"))
	{
		return onKeyDown;
	}

	return nullptr;
}
