#ifndef _LOGIC
#define _LOGIC

#include "Stage.h"
#include "Looper.h"
#include "TitleStage.h"
#include "GameWindow.h"

class Logic
{
private:

	int loopDelay;
	int focusedStage;
	int lastFrameTime;

	Looper* looper;
	GameWindow* window;

	TitleStage* titleStage;


private:

	void CreateStage(int stageId);

public:

	Logic();
	Logic(GameWindow* window);
	Logic(GameWindow* window, int stageId);

	

};


#endif