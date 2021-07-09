#include "TitleStage.h"

static float bounding = 0.f;

TitleStage::TitleStage(GameWindow* window) : Stage(window)
{
	standardShader = new Shader("./resource/shaders/vertex/standardVertexShader.glsl", "./resource/shaders/fragment/standardFragmentShader.glsl");

	logoTexture = new Texture(TITLE_LOGO_FILE_ROUTE);
	backTexture = new Texture(BACKGROUND_FILE_ROUTE);

	titleLogo  = new Model(GetWindow(), standardShader, logoTexture);
	background = new Model(GetWindow(), standardShader, backTexture);

	//titleLogo - new Model();

	eventManager = new EventManager();


	eventManager->SetOnKeyDown(
		(std::function<void(SDL_Event*)>)[&](SDL_Event* event)->void
		{
			if (event->type == SDL_KEYDOWN)
			{
				auto key = event->key.keysym.sym;

				switch (key)
				{
				case SDLK_w:
					std::cout << "w pressed" << std::endl;
				default:
					break;
				}
			}
		}
	);
}


void TitleStage::Draw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
 
	int w;
	int h;

	SDL_GetWindowSize(GetWindow()->GetWindow(), &w, &h);

	//printf("w : %d h : %d", w, h);

	background->Resize(w, h);
	background->Draw();

	titleLogo->Resize(300, 300);
	titleLogo->Position(0.f, 120 + 20 * cos(bounding += 0.1));
	titleLogo->Draw();

	//std::cout << "123";
	
}

void TitleStage::Process(SDL_Event* event)
{

}


void TitleStage::Resize(float x, float y)
{

}