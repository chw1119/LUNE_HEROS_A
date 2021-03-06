#ifndef __GAME_WINDOW
#define  __GAME_WINDOW

#include <SDL.h>
#include <glew.h>
#include <iostream>

#include "Resizable.h"

class GameWindow : public Resizable
{
private:

	SDL_Window* window;
	SDL_Renderer* renderer;


	SDL_GLContext context;

public:
	GameWindow();

	GameWindow(const std::string& titleName, int xpos, int ypos, int xSize, int ySize, int bitFlags);

	void Show();

	void Hide();

	void FullScreen(bool isFull);

	void SetOpacity(float op);

	void MakeContextCurrent();

	void Position(int xpos, int ypos);

	int Poll(SDL_Event* event);

	float GetOpacity();

	SDL_Window* GetWindow() const;

	SDL_Renderer* GetRenderer()const;

	virtual void Resize(float xSize, float ySize) override;
};



#include "EventManager.h"
#endif
