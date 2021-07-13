#ifndef __GAME_WINDOW
#define  __GAME_WINDOW

#include "./modules/SDL2-devel-2.0.14-VC/SDL2-2.0.14/include/SDL.h"
#include "./modules/glew-2.1.0-win32/glew-2.1.0/include/GL/glew.h"
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

	void Process();

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
