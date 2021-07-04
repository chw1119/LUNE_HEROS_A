#pragma once

#define VERSION_MAJOR 0
#define VERSION_MINOR 1

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <glew.h>
#include <iostream>

#include <fstream>
#include <sstream>

#include "Init.h"
#include "Model.h"
#include "Utility.h"
#include "Resizable.h"
#include "LivingModel.h"
#include "GameWindow.h"

//#include "EventManager.h"

#pragma comment(lib,"Opengl32.lib")

#pragma comment(lib,"SDL2.lib")

#pragma comment(lib,"SDL2_image.lib")

#pragma comment(lib,"glu32.lib")

#pragma comment(lib,"glew32.lib")
