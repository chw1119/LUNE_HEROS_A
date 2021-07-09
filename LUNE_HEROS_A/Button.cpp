#include "Button.h"
//

Button::Button(GameWindow* window, Shader* shader, Texture* sTexture, Texture* aTexture)
	: Model(window, shader, sTexture), standerdTexture(sTexture), activatedTexture(aTexture)
{

}

void Button::Process(SDL_Event* event)
{

}

void Button::Bind()
{

}

void Button::Draw()
{
}

void Button::SetOnSelect(std::function<void(void)> func)
{
	selectedFunc = func;
}

void Button::SetOnNotSelect(std::function<void(void)> func)
{
	nonSelectedFunc = func;
}
