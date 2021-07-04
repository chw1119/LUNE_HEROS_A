#ifndef _STAGE
#define _STAGE

#include "GameWindow.h"
#include "Drawable.h"
#include "Resizable.h"

class Stage : public Drawable, Resizable
{

private:
	GameWindow* window;

public:

	Stage(GameWindow* window);

	GameWindow* GetWindow()const;


	virtual void Draw() = 0;

	virtual void Process(SDL_Event* event) = 0;

	virtual void Resize(float x, float y) = 0;

};


#endif