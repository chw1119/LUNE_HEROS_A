#include "Button.h"
//

Button::Button(GameWindow* window, Shader* shader, Texture* sTexture, Texture* aTexture)
	: Model(window, shader, sTexture), standerdTexture(sTexture), activatedTexture(aTexture)
{

}

void Button::Process(SDL_Event* event)
{

}
