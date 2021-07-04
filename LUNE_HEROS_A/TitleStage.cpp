#include "TitleStage.h"

TitleStage::TitleStage(GameWindow* window) : Stage(window)
{
	standardShader = Shader("./resource/shaders/vertex/standardVertexShader.glsl", "./resource/shaders/fragment/standardFragmentShader.glsl");

	logoTexture = Texture(TITLE_LOGO_FILE_ROUTE);
	backTexture = Texture(BACKGROUND_FILE_ROUTE);

	titleLogo = Model(window, &standardShader, &logoTexture);
	background = Model(window, &standardShader, &backTexture);


	//titleLogo - new Model();
}


void TitleStage::Draw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
 
	int w;
	int h;

	SDL_GetWindowSize(GetWindow()->GetWindow(), &w, &h);


	//printf("w : %d h : %d", w, h);

	background.Resize(w, h);
	background.Draw();

	titleLogo.Resize(300, 300);
	titleLogo.Position(0.f, 100 + 10 * abs(cos(Utility::GetCurrentMilliTimes().count()/100000)));
	titleLogo.Draw();

	SDL_GL_SwapWindow(GetWindow()->GetWindow());
}

void TitleStage::Process(SDL_Event* event)
{

}


void TitleStage::Resize(float x, float y)
{

}