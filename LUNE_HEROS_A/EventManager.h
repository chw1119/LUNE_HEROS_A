#ifndef _EVENT
#define _EVENT

#include <SDL.h>
#include <functional>


class EventManager
{
private:

	bool KEYS[322];
	bool isMouseClicked;

	float mousePosX;
	float mousePosY;

	std::function<void(SDL_Event*)> onMouseUp   = nullptr;
	std::function<void(SDL_Event*)> onMouseDown = nullptr;
	std::function<void(SDL_Event*)> onMouseMove = nullptr;


	std::function<void(SDL_Event*)> onKeyDown   = nullptr;
	std::function<void(SDL_Event*)> onKeyUp     = nullptr;

	std::function<void(SDL_Event*)> windowEvent = nullptr;

public:

	EventManager();

	void SetOnMouseUp(std::function<void(SDL_Event*)> func);
	void SetOnMouseDown(std::function<void(SDL_Event*)> func);
	void SetOnMouseMove(std::function<void(SDL_Event*)> func);

	void SetOnKeyDown(std::function<void(SDL_Event*)> func);
	void SetOnKeyUp(std::function<void(SDL_Event*)> func);

	void SetWindowEvent(std::function<void(SDL_Event*)> func);

	bool GetIsKeyDown(int index) const;
	void SetIsKeyDown(int index, bool isDown);

	bool GetIsMouseDown()const;
	void SetIsMouseDown(bool is);

	void Process(SDL_Event* event);

	const std::function<void(SDL_Event*)> operator[] (const std::string& str);
};


#endif