#ifndef _BUTTON
#define _BUTTON


#include <SDL.h>
#include <functional>

#include "Model.h"
#include "Shader.h"
#include "GameWindow.h"
#include "Texture.h"

class Button : public Model
{
private:
	Texture* standerdTexture = nullptr;	
	Texture* activatedTexture = nullptr;

	bool isSelected = false;

	std::function<void(void)> selectedFunc;
	std::function<void(void)> nonSelectedFunc;

public:
	Button(GameWindow* window, Shader* shader, Texture* sTexture, Texture* aTexture);

	void Process(SDL_Event* event);
	
	virtual void Bind();
	virtual void Draw();

	void SetOnSelect(std::function<void(void)> func);
	void SetOnNotSelect(std::function<void(void)> func);

};


#endif