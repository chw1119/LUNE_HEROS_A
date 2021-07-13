#include "GameWindow.h"

GameWindow::GameWindow()
{
	bool success = true;

	window = SDL_CreateWindow("LUNE HEROS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	context = SDL_GL_CreateContext(window);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


	if (renderer == NULL)
	{
		printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Initialize GLEW
		glewExperimental = GL_TRUE;
		GLenum glewError = glewInit();
		if (glewError != GLEW_OK)
		{
			printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
		}

		//Use Vsync
		if (SDL_GL_SetSwapInterval(1) < 0)
		{
			printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
		}

		//Initialize OpenGL

		///glClearColor(0,0,0,1);
	}
}

GameWindow::GameWindow(const std::string& titleName, int xpos, int ypos, int xSize, int ySize, int bitFlags)
{
	bool success = true;

	window = SDL_CreateWindow(titleName.c_str(), xpos, ypos, 800, 600, bitFlags);

	context = SDL_GL_CreateContext(window);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


	if (renderer == NULL)
	{
		printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{

		MakeContextCurrent();

		//Initialize GLEW
		glewExperimental = GL_TRUE;
		GLenum glewError = glewInit();
		if (glewError != GLEW_OK)
		{
			printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
		}

		//Use Vsync
		if (SDL_GL_SetSwapInterval(1) < 0)
		{
			printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
		}

		//Initialize OpenGL

	}
}

void GameWindow::MakeContextCurrent()
{
	SDL_GL_MakeCurrent(window,context);
}

void GameWindow::Position(int xpos, int ypos)
{
	SDL_SetWindowPosition(window, xpos, ypos);
}

void GameWindow::Show()
{
	SDL_ShowWindow(window);
}

void GameWindow::Hide()
{
	SDL_HideWindow(window);
}

int GameWindow::Poll(SDL_Event* event)
{
	return SDL_PollEvent(event);
}

void GameWindow::FullScreen(bool isFull)
{
	if (isFull) {
		SDL_SetWindowFullscreen(window, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP);
	}
	else
	{
		SDL_SetWindowFullscreen(window, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
		
	}
}

void GameWindow::SetOpacity(float op)
{
	SDL_SetWindowOpacity(window, op);
}

float GameWindow::GetOpacity()
{
	float temp;

	SDL_GetWindowOpacity(window, &temp);

	return temp;
}

SDL_Window* GameWindow::GetWindow() const
{
	return window;
}

SDL_Renderer* GameWindow::GetRenderer() const
{
	return renderer;
}

void GameWindow::Resize(float xSize, float ySize)
{
	//SDL_SetWindowSize(window, (int)xSize, (int)ySize);

	glViewport(0, 0, xSize, ySize);
}
