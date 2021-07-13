#pragma once

#define VERSION_MAJOR 0
#define VERSION_MINOR 4

#define SDL_MAIN_HANDLED

#include "./modules/SDL2-devel-2.0.14-VC/SDL2-2.0.14/include/SDL.h"
#include "./modules/glew-2.1.0-win32/glew-2.1.0/include/GL/glew.h"
#include "./modules/SDL2_image-devel-2.0.5-VC/SDL2_image-2.0.5/include/SDL_image.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "Init.h"
#include "Model.h"
#include "Utility.h"
#include "Stage.h"
#include "TitleStage.h"
#include "Resizable.h"
#include "LivingModel.h"
#include "GameWindow.h"

//#include "EventManager.h"

#pragma comment(lib,"Opengl32.lib")

#pragma comment(lib,"SDL2.lib")

#pragma comment(lib,"SDL2_image.lib")

#pragma comment(lib,"glu32.lib")

#pragma comment(lib,"glew32.lib")
