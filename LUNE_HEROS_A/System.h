#ifndef _System
#define _System

#include "Stage.h"
#include "Looper.h"
#include "TitleStage.h"
#include "GameWindow.h"

class System
{
private:

	int loopDelay;
	int focusedStage;
	int lastFrameTime;

	GameWindow* window;




private:

	void CreateStage(int stageId);

public:

	System();
	System(GameWindow* window);
	System(GameWindow* window, int stageId);

	

};


#endif