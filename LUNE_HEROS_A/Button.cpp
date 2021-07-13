#include "Button.h"
//

Button::Button(GameWindow* window, Shader* shader, Texture* sTexture, Texture* aTexture)
	: Model(window, shader, sTexture), standerdTexture(sTexture), activatedTexture(aTexture)
{
	eventManager = new EventManager();

	eventManager->SetOnMouseMove([&](SDL_Event* event) 
		{
			if (event->type == SDL_MOUSEMOTION)
			{
				auto window = GetWindow()->GetWindow();

				int w, h;

				SDL_GL_GetDrawableSize(window, &w, &h);


				int x, y;

				SDL_GetMouseState(&x, &y);

				isSelected = false;

				if (x > (w / 2) + GetXPos() - GetXSize() / 2 && x < (w / 2) + GetXPos() + GetXSize() / 2)
				{
					if (y > (h / 2) + GetYPos() - GetYSize() / 2 && y < (h / 2) + GetYPos() + GetYSize() / 2)
					{
						isSelected = true;

						if (selectedFunc != nullptr)
						{
							selectedFunc();
						}
						
					}
				}
				
				if (!isSelected)
				{
					if (nonSelectedFunc != nullptr)
					{
						nonSelectedFunc();
					}
				}

			}
		}
	);
}

void Button::Process(SDL_Event* event)
{
	eventManager->Process(event);
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

bool Button::GetIsSelected() const
{
	return isSelected;
}
