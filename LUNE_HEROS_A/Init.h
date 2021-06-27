﻿#pragma once


#include <SDL.h>
#include <glew.h>

#include <iostream>

#include "GameWindow.h"

namespace Initialize 
{
	inline int OpenGLInit()
	{
		bool success = true;
		GLenum error = GL_NO_ERROR;

		//Initialize Projection Matrix
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		//Check for error
		error = glGetError();
		if (error != GL_NO_ERROR)
		{
			printf("Error initializing OpenGL! %s\n", gluErrorString(error));
			success = false;
			return -1;
		}

		//Initialize Modelview Matrix
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//Check for error
		error = glGetError();
		if (error != GL_NO_ERROR)
		{
			printf("Error initializing OpenGL! %s\n", gluErrorString(error));
			success = false;

			return -1;
		}

	}

	inline int SdlInit(GameWindow** window)
	{

		bool success = true;
		char errorLogBuffer[512];

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			std::cout << "SDL INIT FAILURE";

			SDL_LogError(0, errorLogBuffer);


			return -1;

		}

		*window = new GameWindow();

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	}

	inline int Init(GameWindow** window)
	{
		int r1 = SdlInit(window);

		if (r1 < 0) {
			std::cout << "SDL INITIALIZATION FAILURE." << std::endl;

			exit(1);
		}

		int r2 = OpenGLInit();


		if (r2 < 0) {
			std::cout << "OPENGL INITIALIZATION FAILURE." << std::endl;

			exit(1);
		}

		std::cout << "INITIALIZATION SUCCESS." << std::endl;

		return 0;
	}
}