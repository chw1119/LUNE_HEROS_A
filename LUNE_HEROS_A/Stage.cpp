#include "Stage.h"

Stage::Stage(GameWindow* window)
{
	this->window = window;
}

GameWindow* Stage::GetWindow() const
{
	return window;
}

