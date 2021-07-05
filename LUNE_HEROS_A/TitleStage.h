#ifndef _TITLE_STAGE
#define _TITLE_STAGE

#define TITLE_LOGO_FILE_ROUTE "./resource/images/LuneHeroTitle.png"
#define BACKGROUND_FILE_ROUTE "./resource/images/titleBackground.jpg"


#include <SDL.h>

#include "Stage.h"
#include "Model.h"
#include "Shader.h"
#include "Texture.h"
#include "Utility.h"
#include "LivingModel.h"

class TitleStage : public Stage
{

private:

	Shader* standardShader;

	Texture* logoTexture;
	Texture* backTexture;

	Model* titleLogo;
	Model* background;


public:
	TitleStage(GameWindow* window);

	virtual void Draw();

	virtual void Process(SDL_Event* event);

	virtual void Resize(float x, float y);
};



#endif